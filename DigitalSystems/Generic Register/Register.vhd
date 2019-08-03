library ieee;
use ieee.std_logic_1164.all;

entity digitalRegister is generic ( N : Integer := 7 ); port (
	D : in std_logic_vector ( ( N-1 ) downto 0 );
	selector : in std_logic_vector ( 1 downto 0 );
	clock, clear, Sinput : in std_logic;
	Q : inout std_logic_vector ( ( N-1 ) downto 0 )
);

attribute PIN_NUMBERS of digitalRegister : entity is (
"clock:1 Sinput:2 D(6):3 D(5):4 D(4):5 D(3):6 D(2):7 D(1):8 D(0):9 "& 
"selector(0):10 selector(1):11 "& 
"clear:13 "& 
"Q(6):20 Q(5):19 Q(4):18 Q(3):17 Q(2):16 Q(1):15 Q(0):14" 
);

end digitalRegister;

architecture a_Register of digitalRegister is

signal MUX : std_logic_vector ( ( N-1 ) downto 0 );

begin 
	process ( clock, clear )
	begin 
		if ( clear = '1' ) then
			Q <= ( others => '0' );
		elsif ( clock'event and clock = '1' ) then
			Q <= MUX;
		end if;
	end process;

	process ( D, selector, Q, Sinput ) -- Secuential input => Sinput.
	begin
		case selector is 
		when "00" => -- Block.
			for i in 0 to ( N-1 ) loop
				MUX ( i ) <= Q ( i );
			end loop;
		when "01" => -- Load.
			for i in 0 to ( N-1 ) loop
				MUX ( i ) <= D ( i );
			end loop;
		when "10" => -- Shift left.
			for i in 1 to ( N-1 ) loop
				MUX ( i ) <= Q ( i-1 );
			end loop;
				MUX ( 0 ) <= Sinput;
 	    when "11" => -- Shift right.
			for i in 0 to ( N-2 ) loop
				MUX ( i ) <= Q ( i+1 );
			end loop;
				MUX ( N-1 ) <= Sinput;
		when others =>
			MUX <= ( others => '0' );
		end case;
   end process;

end architecture;

		
