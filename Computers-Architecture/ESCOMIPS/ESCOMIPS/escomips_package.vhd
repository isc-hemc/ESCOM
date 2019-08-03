library ieee;

use ieee.std_logic_1164.all;

package escomips_package is

	component control_unit is generic( n : integer := 4; m : integer := 20; k : integer := 32 );
		port(
			microcode : out std_logic_vector( m - 1 downto 0 );
			addr_bus : in std_logic_vector( n - 1 downto 0 );
			flags : in std_logic_vector( n - 1 downto 0 );
			cp_code : in std_logic_vector( n downto 0 );
			clear, clock, lf : in std_logic
		);
	end component;

	component stack is generic( n : integer := 16; m : integer := 7 );
		port(
			pc_output : out std_logic_vector( n - 1 downto 0 );
			sp_output : out std_logic_vector( 2 downto 0 );
			data : in std_logic_vector( n - 1 downto 0 );
			clear, clock, wpc, up, down : in std_logic
		);
	end component;

	component register_file is generic( n : integer := 16 );
		port(
			write_reg, read_reg_1, read_reg_2, shamt : in std_logic_vector ( 3 downto 0 );
			read_data_1, read_data_2 : out std_logic_vector ( n - 1 downto 0 );
			write_data : in std_logic_vector ( n - 1 downto 0 );
			clear, clock, wr, she, dir : in std_logic
		);
	end component;

	component alu is generic( n : integer := 16 );
		port(
			output : inout std_logic_vector ( n - 1 downto 0 );
			flag_z, flag_c, flag_n, flag_ov : out std_logic;
			operation : in std_logic_vector ( 1 downto 0 );
			a, b : in std_logic_vector ( n - 1 downto 0 );
			sel_a, sel_b : in std_logic
		);
	end component;

	component ram is generic( n : integer := 6 );
		port(
			data_in : in std_logic_vector( 15 downto 0 );
			output : out std_logic_vector( 15 downto 0 );
			addr: in std_logic_vector( n - 1 downto 0 );
			clock, wd : in std_logic
		);
	end component;

	component rom is generic( n : integer := 6 );
		port(
			addr_bus : in std_logic_vector( n - 1 downto 0 );
			output : out std_logic_vector( 24 downto 0 )
		);
	end component;

	component digital_clock is generic( n : integer := 26 );
		port(
			clock_output : out std_logic;
			clock, clear : in std_logic
		);
	end component;

	component digital_clear is
		port(
			clear_output : out std_logic;
			clear, clock : in std_logic
		);
	end component;

end escomips_package;

package body escomips_package is

end escomips_package;
