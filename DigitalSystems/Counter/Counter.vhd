library ieee;
use ieee.std_logic_1164.all;

entity Counter is generic ( N : Integer := 7 ); port ( 
	clock, clear, E : in std_logic;
	Q : inout std_logic_vector ( ( N - 1 ) downto 0 )
);

end entity;

architecture a_Counter of Counter is 
begin 

	process ( clock, clear ) 

	VARIABLE aux : std_logic;

	begin
		if ( clear = '1' ) then
			Q <= ( others => '0' );
		elsif ( clock'event and clock = '1' ) then
			for i in 0 to ( N - 1 ) loop
			aux := '1';
				for j in 0 to ( i - 1 ) loop
					aux := aux and Q(j);
				end loop;
				Q(i) <= Q(i) xor ( E and aux );
			end loop;
		end if;
	end process;

end architecture;
				

