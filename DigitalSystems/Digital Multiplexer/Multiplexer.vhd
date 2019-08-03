library ieee;
use ieee.std_logic_1164.all;

entity PracticeZero is 
	port ( A, B, reference : in std_logic_vector ( 2 downto 0 );
	selector : in std_logic;
   	display : out std_logic_vector ( 6 downto 0 )
);

attribute PIN_NUMBERS of PracticeZero : entity is (
"a(0):4 a(1):3 a(2):2 "& 
"b(0):7 b(1):6 b(2):5 "& 
"reference(0):10 reference(1):9 reference(2):8 "&
"display(0):15 display(1):16 display(2):17 display(3):18 display(4):19 display(5):20 display(6):21 "
);

end PracticeZero;

architecture ar_PracticeZero of PracticeZero is

signal MUX : std_logic_vector ( 2 downto 0 );
signal COMP : std_logic_vector ( 2 downto 0 );

begin

	-- Multiplexor.
	one : process ( A, B, selector )
	begin
		if ( selector = '0' ) then 
			MUX <= A;
		else 
			MUX <= B;
		end if;
	end process;
   	
	-- Comparator.
	two : process ( MUX, reference ) 
	begin 
		if ( MUX < reference ) then 
			COMP <= "010";
		elsif ( MUX > reference ) then 
			COMP <= "110";
		else 
			COMP <= "011";
		end if;
	end process;

	display <= "0110001" when ( COMP = "010" ) else
		   "0000111" when ( COMP = "110" ) else
		   "0110111";
			
end architecture;
