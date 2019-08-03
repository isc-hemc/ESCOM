LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
entity test_bench is
end test_bench;
 
architecture behavior of test_bench is
 
    component escomips_main
		port(
			escomips_output : out std_logic_vector( 15 downto 0 );
			clear : in std_logic;
			clock : in std_logic
		);
    end component;
    

   --Inputs
   signal clear : std_logic := '0';
   signal clock : std_logic := '0';

 	--Outputs
   signal escomips_output : std_logic_vector( 15 downto 0 );

   -- Clock period definitions
   constant clock_period : time := 2 ns;
 
begin
 
	-- Instantiate the Unit Under Test (UUT)
   uut: escomips_main
		port map(
			escomips_output => escomips_output,
			clear => clear,
			clock => clock
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
   stim_proc : process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
      clear <= '1';
		wait for 100 ns;
		clear <= '0';
      wait;
   end process;
	
end;