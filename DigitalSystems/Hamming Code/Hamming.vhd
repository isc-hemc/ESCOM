library ieee;
use ieee.std_logic_1164.all;

entity Hamming is port ( 
	input : in std_logic_vector ( 3 downto 0 );
	output : out std_logic_vector ( 6 downto 0 )
);

attribute PIN_NUMBERS of Hamming : entity is (
"input(3):1 input(2):2 input(1):3 input(0):4 "& 
"output(6):20 output(5):19 output(4):18 output(3):17 output(2):16 output(1):15 output(0):14 "
);
end entity;

architecture a_Hamming of Hamming is
signal hamming : std_logic_vector ( 2 downto 0 );
begin

	process ( input ) 
	begin
		hamming(0) <= ( ( not input(3) ) and input(2) ) or ( input(2) and input(0) ) or ( ( not input(3) ) and input(0) );
		hamming(1) <= ( input(3) and input(2) and ( not input(1) ) ) or ( input(3) and input(1) and input(0) ) or ( ( not input(3) ) and ( not input(1) ) and input(0) ) or ( ( not input(3) ) and input(2) and input(1) );
  	    hamming(2) <= ( ( not input(1) ) and input(0) ) or ( input(2) and input(0) ) or ( input(2) and ( not input(1) ) );
	end process;

	output(6) <= hamming(0);
	output(5) <= hamming(1);
	output(4) <= input(3);
	output(3) <= hamming(2);
	output(2) <= input(2);
	output(1) <= input(1);
	output(0) <= input(0);

end architecture;

-- Given the BCD code -1, 4, -2 and 8. Desing a circuit generator of hamming code with even parity.

