library ieee;
library std;

use ieee.std_logic_textio.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;
use std.textio.all;

entity test_bench is
end test_bench;
 
architecture behavior of test_bench is 
	
	component stack
	port(
		pc_output : out  std_logic_vector( 15 downto 0 );
		clear : in  std_logic;
		clock : in  std_logic;
		wpc : in  std_logic;
		up : in  std_logic;
		down : in  std_logic;
		data : in  std_logic_vector( 15 downto 0 );
		sp_output : out  std_logic_vector( 0 to 2 )
	);
	end component;
    
	
   --Inputs
   signal clear : std_logic := '0';
   signal clock : std_logic := '0';
   signal wpc : std_logic := '0';
   signal up : std_logic := '0';
   signal down : std_logic := '0';
   signal data : std_logic_vector( 15 downto 0 ) := ( others => '0' );

 	--Outputs
   signal pc_output : std_logic_vector( 15 downto 0 );
   signal sp_output : std_logic_vector( 0 to 2 );

   -- Clock period definitions
   constant clock_period : time := 10 ns;
 
begin
 
	-- Instantiate the Unit Under Test (UUT)
   uut: stack port map (
          pc_output => pc_output,
          clear => clear,
          clock => clock,
          wpc => wpc,
          up => up,
          down => down,
          data => data,
          sp_output => sp_output
        );

   -- Clock process definitions
   clock_process :process
   begin
		clock <= '0';
		wait for clock_period/2;
		clock <= '1';
		wait for clock_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
		file file_vectors : text;
		variable line_vectors : line;
		variable var_data : std_logic_vector( 15 downto 0 );
		variable var_clear : std_logic;
		variable var_down : std_logic;
		variable var_wpc : std_logic;
		variable var_up : std_logic;
		
		file file_results : text;
		variable line_results : line;
		variable var_pc_output : std_logic_vector( 15 downto 0 );
		variable var_sp_output : std_logic_vector( 2 downto 0 );
		variable str : string( 1 to 10 );
		
		begin
			file_open( file_vectors, "Vectors.txt", read_mode );
			file_open( file_results, "Results.txt", write_mode );
			
			str := "     CLEAR";
			write( line_results, str, right, str'length + 1 );
			str := "        UP";
			write( line_results, str, right, str'length + 1 );
			str := "      DOWN";
			write( line_results, str, right, str'length + 1 );
			str := "       WPC";
			write( line_results, str, right, str'length + 1 );
			str := "      DATA";
			write( line_results, str, right, str'length + 1 );
			str := " SP OUTPUT";
			write( line_results, str, right, str'length + 1 );
			str := " PC OUTPUT";
			write( line_results, str, right, str'length + 1 );
			writeline( file_results, line_results );
			
			wait for 100 ns;
			
			for i in 0 to 22 loop
				readline( file_vectors, line_vectors );
				read( line_vectors, var_clear );
				clear <= var_clear;
				read( line_vectors, var_up );
				up <= var_up;
				read( line_vectors, var_down );
				down <= var_down;
				read( line_vectors, var_wpc );
				wpc <= var_wpc;
				hread( line_vectors, var_data );
				data <= var_data;
				
				wait until rising_edge( clock );
				
				var_pc_output := pc_output;
				var_sp_output := sp_output;
				write( line_results, var_clear, right, 11 );
				write( line_results, var_up, right, 11 );
				write( line_results, var_down, right, 11 );
				write( line_results, var_wpc, right, 11 );
				hwrite( line_results, var_data, right, 11 );
				write( line_results, var_sp_output, right, 11 );
				hwrite( line_results, var_pc_output, right, 11 );
				
				writeline( file_results, line_results );
			end loop;
			file_close( file_results );
			file_close( file_vectors );
      wait;
   end process;

END;