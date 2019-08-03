library ieee;
library std;

use ieee.std_logic_textio.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;
use std.textio.all;

entity test_bench is
end test_bench;

architecture behavior of test_bench is

    component rom
    port(
         addr_bus : in  std_logic_vector( 15 downto 0 );
         output : out  std_logic_vector( 24 downto 0 )
        );
    end component;


   --Inputs
   signal addr_bus : std_logic_vector( 15 downto 0 ) := ( others => '0' );

 	--Outputs
   signal output : std_logic_vector( 24 downto 0 );

begin
	-- Instantiate the Unit Under Test (UUT)
   uut: rom port map (
          addr_bus => addr_bus,
          output => output
        );

   -- Stimulus process
   -- manual_sim : process
	--	begin
	--		wait for 50 ns;
	--		addr_bus <= x"000";
	--		wait for 50 ns;
	--		addr_bus <= x"001";
	--		wait for 50 ns;
	--		addr_bus <= x"002";
	--		wait for 50 ns;
	--		addr_bus <= x"003";
	--		wait for 50 ns;
	--		addr_bus <= x"004";
	--		wait for 50 ns;
	--		addr_bus <= x"002";
	--		wait for 50 ns;
	--		addr_bus <= x"003";
	--		wait;
	--	end process;

	file_sim : process
		file file_vectors : text;
		variable line_vector : line;
		variable var_addr_bus : std_logic_vector( 15 downto 0 ); -- Address bus.

		file file_results : text;
		variable line_result : line;
		variable var_opcode : std_logic_vector( 4 downto 0 ); -- opcode column.
		variable var_19_16 : std_logic_vector( 3 downto 0 ); -- 19 ... 16 bits column.
		variable var_15_12 : std_logic_vector( 3 downto 0 ); -- 15 ... 12 bits column.
		variable var_11_08 : std_logic_vector( 3 downto 0 ); -- 11 ... 8 bits column.
		variable var_07_04 : std_logic_vector( 3 downto 0 ); -- 7 ... 4 bits column.
		variable var_03_00 : std_logic_vector( 3 downto 0 ); -- 3 ... 0 bits column.
		variable str : string( 1 to 9 );

		begin
		  file_open( file_vectors, "Vectors.txt", read_mode );
		  file_open( file_results, "Results.txt", write_mode );

		  str := "  ADDRESS";
		  write( line_result, str, right, str'length + 1 );
		  str := "   OPCODE";
		  write( line_result, str, right, str'length + 1 );
		  str := "  19...16";
		  write( line_result, str, right, str'length + 1 );
		  str := "  15...12";
		  write( line_result, str, right, str'length + 1 );
		  str := "  11...08";
		  write( line_result, str, right, str'length + 1 );
		  str := "  07...04";
		  write( line_result, str, right, str'length + 1 );
		  str := "  03...00";
		  write( line_result, str, right, str'length + 1 );
		  writeline ( file_results, line_result );

		  wait for 100 ns;

		  for i in 0 to 6 loop
			 readline ( file_vectors, line_vector );
			 Hread( line_vector, var_addr_bus );
			 addr_bus <= var_addr_bus;

			 wait for 50 ns;

			 var_opcode := std_logic_vector( output( 24 downto 20 ) );
			 var_19_16 := std_logic_vector( output( 19 downto 16 ) );
			 var_15_12 := std_logic_vector( output( 15 downto 12 ) );
			 var_11_08 := std_logic_vector( output( 11 downto 8 ) );
			 var_07_04 := std_logic_vector( output( 7 downto 4 ) );
			 var_03_00 := std_logic_vector( output( 3 downto 0 ) );

			 hwrite( line_result, var_addr_bus, right, 10 );
			 write( line_result, var_opcode, right, 10 );
			 write( line_result, var_19_16, right, 10 );
			 write( line_result, var_15_12, right, 10 );
			 write( line_result, var_11_08, right, 10 );
			 write( line_result, var_07_04, right, 10 );
			 write( line_result, var_03_00, right, 10 );

			 writeline ( file_results, line_result );
		  end loop;

		  file_close ( file_vectors );
		  file_close ( file_results );

		  wait;
		end process;
end;
