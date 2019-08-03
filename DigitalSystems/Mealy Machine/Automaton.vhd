library ieee;
use ieee.std_logic_1164.all;

entity Automaton is port (
	clock, clear, x : in std_logic;
	y : out std_logic_vector ( 6 downto 0 )
);

attribute PIN_NUMBERS of Automaton : entity is (
"clock:1 x:2 clear:13 "& 
"y(0):14 y(1):15 y(2):16 y(3):17 y(4):18 y(5):19 y(6):20"
);

end Automaton;

architecture a_Automaton of Automaton is

signal Qa, Qb : std_logic;

begin
	
	process ( clock, clear )
	begin 
		if ( clear = '1' ) then
			Qa <= '0';
			Qb <= '0';
		elsif ( clock'event and clock = '1' ) then
			Qa <= ( Qa and ( not Qb ) ) or ( ( not Qa ) and Qb and x );
			Qb <= ( not Qb ) and ( Qa xor x );
		end if;
	end process;

	y <= "1110111" when ( ( Qa and Qb and x ) = '1' ) else
		 "1001111";	

end architecture;
