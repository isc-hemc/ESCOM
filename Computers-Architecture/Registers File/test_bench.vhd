library ieee;
library std;

use ieee.std_logic_unsigned.all;
use ieee.std_logic_textio.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;
use std.textio.all;

entity test_bench is
end test_bench;
 
architecture behavior of test_bench is
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    component register_file
    port (
         write_reg : in  std_logic_vector ( 3 downto 0 );
         read_reg_1 : in  std_logic_vector ( 3 downto 0 );
         read_reg_2 : in  std_logic_vector ( 3 downto 0 );
         shamt : in  std_logic_vector ( 3 downto 0 );
         read_data_1 : out  std_logic_vector (15 downto 0 );
         read_data_2 : out  std_logic_vector (15 downto 0 );
         write_data : in  std_logic_vector ( 15 downto 0 );
         clear : in  std_logic;
         clock : in  std_logic;
         wr : in  std_logic;
         she : in  std_logic;
         dir : in  std_logic
        );
    end component;
    

   --Inputs
   signal write_reg : std_logic_vector ( 3 downto 0 ) := ( others => '0' );
   signal read_reg_1 : std_logic_vector ( 3 downto 0 ) := ( others => '0' );
   signal read_reg_2 : std_logic_vector ( 3 downto 0 ) := ( others => '0' );
   signal shamt : std_logic_vector ( 3 downto 0 ) := ( others => '0' );
   signal write_data : std_logic_vector ( 15 downto 0 ) := ( others => '0' );
   signal clear : std_logic := '0';
   signal clock : std_logic := '0';
   signal wr : std_logic := '0';
   signal she : std_logic := '0';
   signal dir : std_logic := '0';

 	--Outputs
   signal read_data_1 : std_logic_vector ( 15 downto 0 );
   signal read_data_2 : std_logic_vector ( 15 downto 0 );

   -- Clock period definitions
   constant clock_period : time := 10 ns;
 
begin
 
	-- Instantiate the Unit Under Test (UUT)
   uut: register_file port map (
          write_reg => write_reg,
          read_reg_1 => read_reg_1,
          read_reg_2 => read_reg_2,
          shamt => shamt,
          read_data_1 => read_data_1,
          read_data_2 => read_data_2,
          write_data => write_data,
          clear => clear,
          clock => clock,
          wr => wr,
          she => she,
          dir => dir
        );

   -- Clock process definitions
   clock_process : process
   begin
		clock <= '0';
		wait for clock_period/2;
		clock <= '1';
		wait for clock_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
		file file_vectors : text;
		variable line_vector : line;
		variable var_rr1 : std_logic_vector ( 3 downto 0 ); -- Read Register 1.
		variable var_rr2 : std_logic_vector ( 3 downto 0 ); -- Read Register 2.
		variable var_shamt : std_logic_vector ( 3 downto 0 ); -- Shamt.
		variable var_wreg : std_logic_vector ( 3 downto 0 ); -- Write Register.
		variable var_wd : std_logic_vector ( 15 downto 0 ); -- Write data.
		variable var_wr : std_logic;
		variable var_she : std_logic;
		variable var_dir : std_logic;
		variable var_clear: std_logic;
	
		file file_results : text;
		variable line_result : line;
		variable var_rd1 : std_logic_vector ( 15 downto 0 );
		variable var_rd2 : std_logic_vector ( 15 downto 0 );
		variable str : string ( 1 to 7 );
		
		begin 
			file_open ( file_vectors, "Vectors.txt", read_mode );
			file_open ( file_results, "Results.txt", write_mode );
			
			str := "    RR1";
			write ( line_result, str, right, str'length + 1 );
			str := "    RR2";
			write ( line_result, str, right, str'length + 1 );
			str := "  SHAMT";
			write ( line_result, str, right, str'length + 1 );
			str := "   WREG";
			write ( line_result, str, right, str'length + 1 );
			str := "  WDATA";
			write ( line_result, str, right, str'length + 1 );
			str := "     WR";
			write ( line_result, str, right, str'length + 1 );
			str := "    SHE";
			write ( line_result, str, right, str'length + 1 );
			str := "    DIR";
			write ( line_result, str, right, str'length + 1 );
			str := "    RD1";
			write ( line_result, str, right, str'length + 1 );
			str := "    RD2";
			write ( line_result, str, right, str'length + 1 );
			writeline ( file_results, line_result );
			
			wait for 100 ns;
			
			for i in 0 to 8 loop
				readline ( file_vectors, line_vector );
				Hread ( line_vector, var_rr1 );
				read_reg_1 <= var_rr1;
				Hread ( line_vector, var_rr2 );
				read_reg_2 <= var_rr2;
				Hread ( line_vector, var_shamt );
				shamt <= var_shamt;
				Hread ( line_vector, var_wreg );
				write_reg <= var_wreg;
				Hread ( line_vector, var_wd );
				write_data <= var_wd;
				read ( line_vector, var_wr );
				wr <= var_wr;
				read ( line_vector, var_she );
				she <= var_she;
				read ( line_vector, var_dir );
				dir <= var_dir;
				read ( line_vector, var_clear );
				clear <= var_clear;
				
				wait until rising_edge ( clock );

				var_rd1 := read_data_1;
				var_rd2 := read_data_2;
				Hwrite ( line_result, var_rr1, right, 8 );
				Hwrite ( line_result, var_rr2, right, 8 );
				Hwrite ( line_result, var_shamt, right, 8 );
				Hwrite ( line_result, var_wreg, right, 8 );
				Hwrite ( line_result, var_wd, right, 8 );
				write ( line_result, var_wr, right, 8 );
				write ( line_result, var_she, right, 8 );
				write ( line_result, var_dir, right, 8 );
				Hwrite ( line_result, var_rd1, right, 8 );
				Hwrite ( line_result, var_rd2, right, 8 );
				
				writeline ( file_results, line_result );
			end loop;
			
			file_close ( file_vectors );
			file_close ( file_results );
			
			wait;
   end process;

END;
