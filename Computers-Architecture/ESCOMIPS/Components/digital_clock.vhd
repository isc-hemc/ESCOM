library ieee;

use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity digital_clock is generic( n : integer := 26 );
	port(
		clock_output : out std_logic;
		clock, clear : in std_logic
	);
end digital_clock;

architecture ar_digital_clock of digital_clock is

	signal aux : std_logic_vector( n downto 0 );

	begin

		process( clock, clear )
		begin
			if( clear = '1' ) then
				aux <= ( others => '0' );
			elsif( clock'event and clock = '1' ) then
				aux <= aux + 1;
			end if;
		end process;
	
	clock_output <= aux(n);

end ar_digital_clock;
