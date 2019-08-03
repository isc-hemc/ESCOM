library ieee;

use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity ram is generic( n : integer := 16 );
	port (
		addr_w, addr_r : in std_logic_vector( n - 1 downto 0 );
		data_bus : in std_logic_vector( n - 1 downto 0 );
		output : out std_logic_vector( n - 1 downto 0 );
		clock, wd : in std_logic
	);
end ram;

architecture ar_ram of ram is

	type ram_memory is array( 0 to 2**n ) of std_logic_vector( n - 1 downto 0 );
	signal memory : ram_memory;

	begin

		process( clock )
		begin
			if ( clock'event and clock = '1' ) then
				if ( wd = '1' ) then
					memory( conv_integer( addr_w ) ) <= data_bus;
				end if;
			end if;
		end process;

		output <= memory( conv_integer( addr_r ) );

end architecture;
