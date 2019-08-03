library ieee;
use ieee.std_logic_1164.all;

entity condition is generic ( n : integer := 4 ); port (
		flags : in std_logic_vector( n - 1 downto 0 );
		EQ, NEQ, LT, LET, TG, GET : out std_logic
	);
end condition;

architecture ar_condition of condition is

	signal flag_z, flag_c, flag_n, flag_ov : std_logic;
	
	begin
	
		-- Initialize flags.
		flag_c <= flags( 0 );
		flag_z <= flags( 1 );
		flag_n <= flags( 2 );
		flag_ov <= flags( 3 );
		
		-- Assing conditions.
		EQ <= flag_z;
		NEQ <= not( flag_z );
		TG <= ( not flag_z ) and flag_c;
		GET <= flag_c;
		LT <= not( flag_c );
		LET <= flag_z or not( flag_c );
	
end architecture;

