library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity Counter is generic ( N : Integer := 9 ); port (
	output : out std_logic_vector ( N downto 0 );
	clock, clear, enable, UD : in std_logic
);

attribute PIN_NUMBERS of Counter : entity is (
"output(9):20 output(8):19 output(7):18 output(6):17 "& 
"clock:1 enable:2 UD:3 clear:13 "
);
end entity;

architecture arcCounter of Counter is
begin
	
	Counter : process ( clock, clear )
	begin
		if ( clear = '1' ) then
			output <= ( others => '0' );
		elsif ( clock'event and clock = '1' ) then
			if ( enable = '1' ) then
				if ( UD = '1' ) then 
					output <= output + 1; -- Increment.
				else
					output <= output - 1; -- Decrement.
				end if;
			else
				output <= output; -- Block.
			end if;
		end if;
	end process;

end architecture;
