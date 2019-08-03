library ieee;

use ieee.std_logic_1164.all;
 
entity level is 
	port (
		clock, clear : in std_logic;
		na : out std_logic
	);
end entity;

architecture ar_level of level is

	signal pclock : std_logic;
	signal nclock : std_logic;
	
	begin
	
		process( clock, clear )
		begin
			if( clear = '1' ) then
				pclock <= '0';
				nclock <= '0';
			elsif( rising_edge( clock ) ) then
				pclock <= not pclock;
			elsif( falling_edge( clock ) ) then
				nclock <= not nclock;
			end if;
		end process;
		
		na <= ( pclock xor nclock );
		
end architecture;