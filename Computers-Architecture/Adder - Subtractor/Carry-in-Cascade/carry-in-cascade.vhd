library ieee;
use ieee.std_logic_1164.all;

entity carry_in_cascade is generic ( n : integer := 4 ); port (
	a, b : in std_logic_vector ( n - 1 downto 0 );
	s : out std_logic_vector ( n - 1 downto 0 );
	cin : in std_logic;
	cout : out std_logic );
end carry_in_cascade;

architecture Behavioral of carry_in_cascade is

signal Eb : std_logic_vector ( n - 1 downto 0 );
signal c : std_logic_vector ( n downto 0 );

begin

	c(0) <= cin;
	statement : for i in 0 to n - 1 generate
		Eb(i) <= b(i) xor c(0);
		s(i) <= a(i) xor Eb(i) xor c(i);
		c(i+1) <= ( a(i) and c(i) ) or ( Eb(i) and c(i) ) or ( a(i) and Eb(i) );
	end generate;
	cout <= c(n);

end Behavioral;