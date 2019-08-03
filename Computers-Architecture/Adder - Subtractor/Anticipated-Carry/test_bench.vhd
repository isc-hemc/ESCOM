library ieee;
use ieee.std_logic_1164.all;
 
entity anticipated_carry_simulation is
end anticipated_carry_simulation;
 
architecture behavior of anticipated_carry_simulation is
 
 
    component anticipated_carry port (
         a : in  std_logic_vector ( 3 downto 0 );
         b : in  std_logic_vector ( 3 downto 0 );
         s : out  std_logic_vector ( 3 downto 0 );
         cin : in  std_logic;
         cout : out  std_logic
        );
    end component;
    

   --Inputs
   signal a : std_logic_vector ( 3 downto 0 ) := ( others => '0' );
   signal b : std_logic_vector ( 3 downto 0 ) := ( others => '0' );
   signal cin : std_logic := '0';

 	--Outputs
   signal s : std_logic_vector ( 3 downto 0 );
   signal cout : std_logic;

begin
 
	-- Instantiate the Unit Under Test (UUT)
   uut: anticipated_carry port map (
          a => a,
          b => b,
          s => s,
          cin => cin,
          cout => cout
        );

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns. 
		a <= "0101";
		b <= "0101";
		cin <= '0';
      wait for 100 ns;
		a <= "1100";
		b <= "0111";
		cin <= '0';
      wait for 100 ns;
		a <= "1001";
		b <= "0101";
		cin <= '0';
      wait for 100 ns;
		a <= "1110";
		b <= "1001";
		cin <= '1';
      wait for 100 ns;
		a <= "0100";
		b <= "0010";
		cin <= '0';
      wait for 100 ns;
		a <= "0111";
		b <= "0111";
		cin <= '1';
      wait for 100 ns;
		a <= "1111";
		b <= "0101";
		cin <= '1';
      wait for 100 ns;
		a <= "1011";
		b <= "1000";
		cin <= '1';
      wait for 100 ns;
		a <= "0001";
		b <= "0100";
		cin <= '1';
      wait for 100 ns;
   end process;

end;