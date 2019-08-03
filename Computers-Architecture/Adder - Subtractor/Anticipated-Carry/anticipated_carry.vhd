library ieee;
use ieee.std_logic_1164.all;

entity anticipated_carry is generic ( n : integer := 4 ); Port (
	a, b : in std_logic_vector ( n - 1 downto 0 );
	s : out std_logic_vector ( n - 1 downto 0 );
	cin : in  std_logic;
	cout : out std_logic
	);
end anticipated_carry ;

architecture arq_anticipated_carry  of anticipated_carry is
begin

	process ( a, b, cin )
	variable Eb, p, g : std_logic_vector ( n - 1 downto 0 );
	variable c : std_logic_vector ( n downto 0 );
	variable aux1, aux2, aux3 : std_logic;
	begin
		c(0) := cin;
		for i in 0 to n - 1 loop
			aux1 := '1';
			Eb(i) := b(i) xor cin;
			p(i) := a(i) xor Eb(i);
			g(i) := a(i) and Eb(i);
			s(i) <= a(i) xor Eb(i) xor c(i);
			for l in 0 to i loop
				aux1 := aux1 and p(l);
			end loop;
			aux2 := '0';
			for j in 0 to i - 1 loop
				aux3 := '1';
				for k in j + 1 to i loop
					aux3 := aux3 and p(k);
				end loop;
				aux2 := aux2 or ( g(j) and aux3 );
			end loop;
			c(i+1) := g(i) or aux2 or ( c(0) and aux1 );
		end loop;
		cout <= c(n);
	end process;

end architecture;