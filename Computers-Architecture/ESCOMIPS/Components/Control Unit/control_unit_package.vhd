library ieee;
use ieee.std_logic_1164.all;

package control_unit_package is

	component state_register is generic ( n : integer := 4 );
		port (
			flags_out : out std_logic_vector( n - 1 downto 0 );
			flags_in : in std_logic_vector( n - 1 downto 0 );
			clock, clear, lf : in std_logic
		);
	end component;
	
	component operation_memory is generic( k : integer := 32; m : integer := 20 ); 
		port(
			output : out std_logic_vector( m - 1 downto 0 );
			addr_bus : in std_logic_vector( 4 downto 0 )
		);
	end component;

	component level is 
		port(
			clock, clear : in std_logic;
			na : out std_logic
		);
	end component;
	
	component function_memory is generic( k : integer := 32; m : integer := 20 ); 
		port(
			output : out std_logic_vector( m - 1 downto 0 );
			addr_bus : in std_logic_vector( 3 downto 0 )
		);
	end component;
	
	component decoder is 
		port(
			cp_code : in std_logic_vector( 4 downto 0 );
			R_TYPE : out std_logic;
			BEQ : out std_logic;
			BNEQ : out std_logic;
			BLT : out std_logic;
			BLE : out std_logic;
			BGT : out std_logic;
			BGET : out std_logic
		);
	end component;
	
	component asm is
		port(
			R_TYPE, BEQ, BNEQ, BLT, BLE, BGT, BGET : in std_logic;
			EQ, NEQ, LT, LET, TG, GET : in std_logic;
			clock, clear, na : in std_logic;
			sdopc, sm : out std_logic
		);
	end component;
	
	component condition is generic ( n : integer := 4 );
		port(
			flags : in std_logic_vector( n - 1 downto 0 );
			EQ, NEQ, LT, LET, TG, GET : out std_logic
		);
	end component;
	
end package;

package body control_unit_package is
 
end control_unit_package;