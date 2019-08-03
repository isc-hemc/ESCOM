library ieee;
library work;

use work.control_unit_package.all;
use ieee.std_logic_1164.all;

entity control_unit is generic( n : integer := 4; m : integer := 20; k : integer := 32 );
	port(
		microcode : out std_logic_vector( m - 1 downto 0 );
		addr_bus : in std_logic_vector( n - 1 downto 0 );
		flags : in std_logic_vector( n - 1 downto 0 );
		cp_code : in std_logic_vector( n downto 0 );
		clear, clock, lf : in std_logic
	);
end control_unit;

architecture ar_control_unit of control_unit is

	signal R_TYPE, BEQ, BNEQ, BLT, BLE, BGT, BGET, EQ, NEQ, LT, LET, TG, GET : std_logic;
	signal functionMicrocode, operationMicrocode : std_logic_vector( m - 1 downto 0 );
	signal flagsOut : std_logic_vector( 3 downto 0 );
	signal muxCode : std_logic_vector( n downto 0 );
	signal sdopc, sm, na : std_logic;
	
	begin

	StateRegister : state_register 
		generic map( n => n )
		port map( flags_out => flagsOut, 
					 flags_in => flags, 
					 clock => clock, 
					 clear => clear, 
					 lf => lf );
					 
	muxCode <= "00000" when( sdopc = '0' ) else cp_code;
	
	OperationROM : operation_memory
		generic map( k => k, m => m )
		port map( output => operationMicrocode, 
					 addr_bus => muxCode );
		
	Condition_Block : condition 
		generic map( n => n )
		port map( flags => flagsOut, 
					 EQ => EQ, 
					 NEQ => NEQ, 
					 LT => LT, 
					 LET => LET, 
					 TG => TG, 
					 GET => GET );

	FunctionROM : function_memory 
		generic map( k => k, m => 20 )
		port map( output => functionMicrocode, 
					 addr_bus => addr_bus );

	Level_Block : level 
		port map( clock => clock, 
					 clear => clear, 
					 na => na );
	
	Decoder_Block : decoder 
		port map( cp_code => cp_code, 
					 R_TYPE => R_TYPE, 
					 BEQ => BEQ, 
					 BNEQ => BNEQ, 
					 BLT => BLT, 
					 BLE => BLE, 
					 BGT => BGT, 
					 BGET => BGET );
	
	Control_Unit : asm 
		port map( R_TYPE => R_TYPE, 
					 BEQ => BEQ, 
					 BNEQ => BNEQ, 
					 BLT => BLT, 
					 BLE => BLE, 
					 BGT => BGT, 
					 BGET => BGET, 
					 EQ => EQ, 
					 NEQ => NEQ, 
					 LT => LT, 
					 LET => LET, 
					 TG => TG, 
					 GET => GET, 
					 clock => clock, 
					 clear => clear, 
					 na => na, 
					 sdopc => sdopc, 
					 sm => sm );
	
	microcode <= functionMicrocode when( sm = '0' ) else operationMicrocode;
	
end ar_control_unit;

