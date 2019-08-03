library ieee;

use ieee.std_logic_1164.all;

entity digital_clear is
	port(
		clear_output : out std_logic;
		clear, clock : in std_logic
	);
end digital_clear;

architecture ar_digital_clear of digital_clear is

signal not_clock : std_logic;

begin

	process( clear, clock, not_clock )
	begin
		if( falling_edge( clock ) ) then
			clear_output <= clear;
		end if;
	end process;
	
end ar_digital_clear;

