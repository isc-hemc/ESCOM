library ieee;
use ieee.std_logic_1164.all;

entity state_register is generic ( n : integer := 4 );
	port (
		flags_out : out std_logic_vector( n - 1 downto 0 );
		flags_in : in std_logic_vector( n - 1 downto 0 );
		clock, clear, lf : in std_logic
	);
end state_register;

architecture ar_stregister of state_register is

	begin
	
		process( clock, clear ) 
		begin
			if( clear = '1' ) then
				flags_out <= ( others => '0' );
			elsif ( clock'event and clock = '0' ) then
				if ( lf = '1' ) then 
					flags_out <= flags_in;
				end if;
			end if;
		end process;	
		
end architecture;