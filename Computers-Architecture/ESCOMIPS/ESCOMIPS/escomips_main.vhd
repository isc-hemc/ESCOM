library ieee;
library work;

use work.control_unit_package.all;
use work.escomips_package.all;
use ieee.std_logic_1164.all;

entity escomips_main is generic( n : integer := 16; m : integer := 7 );
	port(
		escomips_output : out std_logic_vector( n - 1 downto 0 );
		clear, clock : in std_logic
	);
end escomips_main;

architecture ar_escomips of escomips_main is

	signal STACK_OUTPUT, BUS_SIGN, BUS_ADDRESS, READ_DATA_1, READ_DATA_2, ALU_OUTPUT, RAM_OUTPUT : std_logic_vector( 15 downto 0 );
	signal BUS_SDMP, BUS_SWD, BUS_SEXT, BUS_SOP1, BUS_SOP2, BUS_SDMD, BUS_SR : std_logic_vector( n - 1 downto 0 );
	signal CLOCK_DIVISOR, CLEAR_OUTPUT, SDMP, SR2, SWD, SEXT, SOP1, SOP2, SDMD, SR : std_logic;
	signal ALUOP, BUS_SR2, CU_FLAGS : std_logic_vector( 3 downto 0 );
	signal WPC, UP, DW, SHE, DIR, WR, WD, LF : std_logic;
	signal ROM_OUTPUT : std_logic_vector( 24 downto 0 );
	signal MICROCODE : std_logic_vector( 19 downto 0 );
	signal SP : std_logic_vector( 2 downto 0 );

begin

	ControlUnit : control_unit
		generic map( n => 4, m => 20, k => 32 )
		port map(
			microcode => MICROCODE,
			addr_bus => ROM_OUTPUT( 3 downto 0 ),
			flags => CU_FLAGS,
			cp_code => ROM_OUTPUT( 24 downto 20 ),
			clear => CLEAR_OUTPUT,
			clock => CLOCK_DIVISOR,
			lf => LF
		);
		
	Stack_Block : stack
		generic map( n => n, m => m )
		port map(
			pc_output => STACK_OUTPUT,
			sp_output => SP,
			data => BUS_SDMP,
			clear => CLEAR_OUTPUT,
			clock => CLOCK_DIVISOR,
			wpc => WPC,
			up => UP,
			down => DW
		);
		
	RegisterFile : register_file
		generic map( n => n )
		port map(
			write_reg => ROM_OUTPUT( 19 downto 16 ),
			read_reg_1 => ROM_OUTPUT( 15 downto 12 ),
			read_reg_2 => BUS_SR2,
			shamt => ROM_OUTPUT( 7 downto 4 ),
			read_data_1 => READ_DATA_1,
			read_data_2 => READ_DATA_2,
			write_data => BUS_SWD,
			clear => CLEAR_OUTPUT,
			clock => CLOCK_DIVISOR,
			wr => WR,
			she => SHE,
			dir => DIR
		);
		
	Arithmetic_Logic_Unit : alu
		generic map( n => n )
		port map(
			output => ALU_OUTPUT,
			flag_z => CU_FLAGS(1),
			flag_c => CU_FLAGS(0),
			flag_n => CU_FLAGS(2),
			flag_ov => CU_FLAGS(3),
			operation => ALUOP( 1 downto 0 ),
			a => BUS_SOP1,
			b => BUS_SOP2,
			sel_a => ALUOP(3),
			sel_b => ALUOP(2)
		);
		
	Data_Memory : ram
		generic map( n => 6 )
		port map(
			data_in => READ_DATA_2,
			output => RAM_OUTPUT,
			addr => BUS_SDMD( 5 downto 0 ),
			clock => CLOCK_DIVISOR,
			wd => WD
		);
		
	Program_Memory : rom
		generic map( n => 6 )
		port map(
			addr_bus => STACK_OUTPUT( 5 downto 0 ),
			output => ROM_OUTPUT
		);
		
	DigitalClock : digital_clock
		generic map( n => 26 )
		port map(
			clock => clock,
			clear => CLEAR_OUTPUT,
			clock_output => CLOCK_DIVISOR
		);
		
	DigitalClear : digital_clear
		port map(
			clear_output => CLEAR_OUTPUT,
			clear => clear,
			clock => clock
		);
		
	SDMP <= MICROCODE(19);
	UP <= MICROCODE(18);
	DW <= MICROCODE(17);
	WPC <= MICROCODE(16);
	SR2 <= MICROCODE(15);
	SWD <= MICROCODE(14);
	SEXT <= MICROCODE(13);
	SHE <= MICROCODE(12);
	DIR <= MICROCODE(11);
	WR <= MICROCODE(10);
	SOP1 <= MICROCODE(9);
	SOP2 <= MICROCODE(8);
	ALUOP(3) <= MICROCODE(7);
	ALUOP(2) <= MICROCODE(6);
	ALUOP(1) <= MICROCODE(5);
	ALUOP(0) <= MICROCODE(4);
	SDMD <= MICROCODE(3);
	WD <= MICROCODE(2);
	SR <= MICROCODE(1);
	LF <= MICROCODE(0);
	
	BUS_SDMP <= ROM_OUTPUT( 15 downto 0 ) when( SDMP = '0' ) else BUS_SR;
	BUS_SR2 <= ROM_OUTPUT( 11 downto 8 ) when( SR2 = '0' ) else ROM_OUTPUT( 19 downto 16 );
	BUS_SWD <= ROM_OUTPUT( 15 downto 0 ) when( SWD = '0' ) else BUS_SR;
	BUS_SIGN <= ROM_OUTPUT(11) & ROM_OUTPUT(11) & ROM_OUTPUT(11) & ROM_OUTPUT(11) & ROM_OUTPUT( 11 downto 0 );
	BUS_ADDRESS <= "0000" & ROM_OUTPUT( 11 downto 0 );
	BUS_SEXT <= BUS_SIGN when( SEXT = '0' ) else BUS_ADDRESS;
	BUS_SOP1 <= READ_DATA_1 when( SOP1 = '0' ) else STACK_OUTPUT;
	BUS_SOP2 <= READ_DATA_2 when( SOP2 = '0' ) else BUS_SEXT;
	BUS_SDMD <= ALU_OUTPUT when( SDMD = '0' ) else ROM_OUTPUT( 15 downto 0 );
	BUS_SR <= RAM_OUTPUT when( SR = '0' ) else ALU_OUTPUT;
	
	-- ESCOMIPS output.
	escomips_output <= STACK_OUTPUT( 7 downto 0 ) & RAM_OUTPUT( 7 downto 0 );

end ar_escomips;

