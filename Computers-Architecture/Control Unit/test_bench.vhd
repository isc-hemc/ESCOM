library ieee;
library std;

use ieee.std_logic_textio.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;
use std.textio.all;

entity test_bench is
end test_bench;

architecture behavior of test_bench is

    -- Component Declaration for the Unit Under Test (UUT)

    component main
    port(
         microcode : out std_logic_vector( 19 downto 0 );
         addr_bus : in std_logic_vector( 3 downto 0 );
         flags : in std_logic_vector( 3 downto 0 );
         cp_code : in std_logic_vector( 4 downto 0 );
         clear : in std_logic;
         clock : in std_logic;
         lf : in std_logic
        );
    end component;


   --Inputs
   signal addr_bus : std_logic_vector( 3 downto 0 ) := ( others => '0' );
   signal flags : std_logic_vector( 3 downto 0 ) := ( others => '0' );
   signal cp_code : std_logic_vector( 4 downto 0 ) := ( others => '0' );
   signal clear : std_logic := '0';
   signal clock : std_logic := '0';
   signal lf : std_logic := '0';

 	--Outputs
   signal microcode : std_logic_vector( 19 downto 0 );

   -- Clock period definitions
   constant clock_period : time := 10 ns;

begin

	-- Instantiate the Unit Under Test (UUT)
   uut: main port map(
          microcode => microcode,
          addr_bus => addr_bus,
          flags => flags,
          cp_code => cp_code,
          clear => clear,
          clock => clock,
          lf => lf
        );

   -- Clock process definitions
   clock_process :process
   begin
		clock <= '0';
		wait for clock_period/2;
		clock <= '1';
		wait for clock_period/2;
   end process;


      stim_proc: process
		file file_vectors : text;
		variable line_vectors : line;
		variable var_op_code : std_logic_vector( 4 downto 0 );
		variable var_func_code : std_logic_vector( 3 downto 0 );
		variable var_flags : std_logic_vector( 3 downto 0 );
		variable var_clear : std_logic;
		variable var_lf : std_logic;

		file file_results : text;
		variable line_results : line;
		variable var_microcode : std_logic_vector( 19 downto 0 );
		variable str : string( 1 to 20 );

		begin
			file_open( file_vectors, "Vectors.txt", read_mode );
			file_open( file_results, "Results.txt", write_mode );

			str := "      OPERATION CODE";
			write( line_results, str, right, str'length + 1 );
			str := "       FUNCTION CODE";
			write( line_results, str, right, str'length + 1 );
			str := "               FLAGS";
			write( line_results, str, right, str'length + 1 );
			str := "               CLEAR";
			write( line_results, str, right, str'length + 1 );
			str := "                  LF";
			write( line_results, str, right, str'length + 1 );
			str := "           MICROCODE";
			write( line_results, str, right, str'length + 1 );
			--str := "      LEVEL";
			--write( line_results, str, right, str'length + 1 );
			writeline( file_results, line_results );

			wait for 100 ns;

			for i in 0 to 51 loop
				readline( file_vectors, line_vectors );
				read( line_vectors, var_op_code );
				cp_code <= var_op_code;
				read( line_vectors, var_func_code );
				addr_bus <= var_func_code;
				read( line_vectors, var_flags );
				flags <= var_flags;
				read( line_vectors, var_clear );
				clear <= var_clear;
				read( line_vectors, var_lf );
				lf <= var_lf;

				wait until rising_edge( clock );

				var_microcode := microcode;
				write( line_results, var_op_code, right, 21 );
				write( line_results, var_func_code, right, 21 );
				write( line_results, var_flags, right, 21 );
				write( line_results, var_clear, right, 21 );
				write( line_results, var_lf, right, 21 );
				write( line_results, var_microcode, right, 21 );

				writeline( file_results, line_results );
			end loop;
			file_close( file_results );
			file_close( file_vectors );
      wait;
   end process;
END;
