library ieee;
use ieee.std_logic_1164.all;

entity test_bench is
end test_bench;

architecture behavior of test_bench is

    -- Component Declaration for the Unit Under Test (UUT)

    component alu
    port(
         cout : out  std_logic;
         flag_z : out  std_logic;
         flag_c : out  std_logic;
         flag_n : out  std_logic;
         flag_ov : out  std_logic;
         output : inout  std_logic_vector ( 3 downto 0 );
         operation : in  std_logic_vector ( 1 downto 0 );
         a : in  std_logic_vector ( 3 downto 0 );
         b : in  std_logic_vector ( 3 downto 0 );
         sel_a : in  std_logic;
         sel_b : in  std_logic
        );
    end component;


   --Inputs
   signal operation : std_logic_vector ( 1 downto 0 ) := ( others => '0' );
   signal a : std_logic_vector ( 3 downto 0 ) := ( others => '0' );
   signal b : std_logic_vector ( 3 downto 0 ) := ( others => '0' );
   signal sel_a : std_logic := '0';
   signal sel_b : std_logic := '0';

	--BiDirs
   signal output : std_logic_vector ( 3 downto 0 );

 	--Outputs
   signal cout : std_logic;
   signal flag_z : std_logic;
   signal flag_c : std_logic;
   signal flag_n : std_logic;
   signal flag_ov : std_logic;
   -- No clocks detected in port list. Replace <clock> below with
   -- appropriate port name


begin

	-- Instantiate the Unit Under Test (UUT)
   uut: alu port map (
          cout => cout,
          flag_z => flag_z,
          flag_c => flag_c,
          flag_n => flag_n,
          flag_ov => flag_ov,
          output => output,
          operation => operation,
          a => a,
          b => b,
          sel_a => sel_a,
          sel_b => sel_b
        );

   -- Stimulus process
   stim_proc: process
   begin
      -- hold reset state for 100 ns.
      wait for 100 ns;
		-- operation: a+b.
		operation <= "11";
		sel_a <= '0';
		sel_b <= '0';
		a <= "0101";
		b <= "1110";
		wait for 100 ns;
		-- operation: a-b.
		operation <= "11";
		sel_a <= '0';
		sel_b <= '1';
		a <= "0101";
		b <= "1110";
		wait for 100 ns;
		-- operation: a and b.
		operation <= "00";
		sel_a <= '0';
		sel_b <= '0';
		a <= "0101";
		b <= "1110";
		wait for 100 ns;
		-- operation: a nand b.
		operation <= "01";
		sel_a <= '1';
		sel_b <= '1';
		a <= "0101";
		b <= "1110";
		wait for 100 ns;
		-- operation: a or b.
		operation <= "01";
		sel_a <= '0';
		sel_b <= '0';
		a <= "0101";
		b <= "1110";
		wait for 100 ns;
		-- operation: a nor b.
		operation <= "00";
		sel_a <= '1';
		sel_b <= '1';
		a <= "0101";
		b <= "1110";
		wait for 100 ns;
		-- operation: a xor b.
		operation <= "10";
		sel_a <= '0';
		sel_b <= '0';
		a <= "0101";
		b <= "1110";
		wait for 100 ns;
		-- operation: a xnor b.
		operation <= "10";
		sel_a <= '1';
		sel_b <= '0';
		a <= "0101";
		b <= "1110";

		wait for 100 ns;
		-- operation: a + b.
		operation <= "11";
		sel_a <= '0';
		sel_b <= '0';
		a <= "0101";
		b <= "0111";

		wait for 50 ns;
		-- operation: a - b.
		operation <= "11";
		sel_a <= '0';
		sel_b <= '1';
		a <= "0101";
		b <= "0101";
		wait for 50 ns;
		-- operation: a not b.
		operation <= "01";
		sel_a <= '1';
		sel_b <= '1';
		a <= "0101";
		b <= "0101";
		wait;
   end process;

end;
