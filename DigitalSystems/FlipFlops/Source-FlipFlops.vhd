library ieee;
use ieee.std_logic_1164.all;

entity FlipFlop is port (

	--FlipFlops inputs.
	D, T, S, R, J, K, clock, clear : in std_logic; 
	--Multiplexor selectors.
	selector : in std_logic_vector ( 1 downto 0 );
	--Output.
   	display : out std_logic_vector ( 5 downto 0 ) 

);

attribute PIN_NUMBERS of FlipFlop : entity is (
"clock:1 J:2 K:3 T:4 S:5 R:6 D:7 selector(0):8 selector(1):9 clear:13 "& 
"display(5):21 display(4):20 display(3):19 display(2):18 display(1):17 display(0):16"
); 

end FlipFlop;

architecture a_FlipFlop of FlipFlop is

signal qD, qT, qSR, qJK : std_logic;
signal MUX : std_logic;

begin

	--FlipFlop D.
	process ( clock, clear )
	begin
		if ( clear = '1' ) then
			qD <= '0';
		--Wait for a raising edge ( clock ).
		elsif ( clock'event and clock = '1' ) then 
			qD <= D;
		end if;
	end process;

	--FlipFlop T.
	process ( clock, clear ) 
	begin
		if ( clear = '1' ) then
			qT <= '0';
		elsif ( clock'event and clock = '1' ) then
			qT <= T xor qT;
		end if;
	end process;

	--FlipFlop SR.
	process ( clock, clear )
	begin
		if ( clear = '1' ) then
			qSR <= '0';
		elsif ( clock'event and clock = '1' ) then 
			qSR <= ( ( not R ) and qSR ) or S;
		end if;
	end process;

	--FlipFlop JK.
	process ( clock, clear )
	begin 
		if ( clear = '1' ) then 
			qJK <= '0';
		elsif ( clock'event and clock = '1' ) then
			qJK <= ( J and ( not qJK ) ) or ( ( not K ) and qJK );
		end if;
	end process;

	--Multiplexor.
	process ( selector, qD, qT, qSR, qJK )
	begin 
		if ( selector = "00" ) then
			MUX <= qJK;
		elsif ( selector = "01" ) then
			MUX <= qT;
		elsif ( selector = "10" ) then
			MUX <= qD;
		else
			MUX <= qSR;
		end if;
	end process;

	display <= "000000" when ( MUX = '0' ) else
			"100111";

end architecture;
