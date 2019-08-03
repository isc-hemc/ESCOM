library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity ROM is port (
	selector : out std_logic_vector ( 2 downto 0 );
	output : out std_logic_vector ( 6 downto 0 );
	input : in std_logic_vector ( 2 downto 0 );
	clock, clear : in std_logic
);

attribute PIN_NUMBERS of ROM : entity is (
"clear:13 clock:1 input(2):6 input(1):7 input(0):8 "& 
"output(6):20 output(5):19 output(4):18 output(3):17 output(2):16 output(1):15 output(0):21 "& 
"selector(2):14 selector(1):23 selector(0):22 "
);

end entity;

architecture arcROM of ROM is

-- Display selectors.
constant Q0 : std_logic_vector ( 2 downto 0 ) := "110";
constant Q1 : std_logic_vector ( 2 downto 0 ) := "101";
constant Q2 : std_logic_vector ( 2 downto 0 ) := "011";
-- Letters.
constant Lnone : std_logic_vector ( 6 downto 0 ) := "1111111";
constant LE : std_logic_vector ( 6 downto 0 ) := "0110000";
constant LS : std_logic_vector ( 6 downto 0 ) := "0100100";
constant LC : std_logic_vector ( 6 downto 0 ) := "0110001";
constant LO : std_logic_vector ( 6 downto 0 ) := "0000001";
constant LN : std_logic_vector ( 6 downto 0 ) := "0001001";
-- Ring counter signal.
signal Ring : std_logic_vector ( 2 downto 0 );
-- ROM memory.
type ROM is array ( 0 to 9 ) of std_logic_vector ( 6 downto 0 );
-- Memory data.
constant display : ROM := ( Lnone, Lnone, LE, LS, LC, LO, LN, LN, Lnone, Lnone );
-- Converter output.
signal cout : std_logic_vector ( 2 downto 0 );
-- Adder output ( Memory location ).
signal carry : std_logic_vector ( 2 downto 0 ); 
signal dir : std_logic_vector ( 3 downto 0 ); 

begin

	RingCounter : process ( clear, clock ) 
	begin
		if ( clear = '1' ) then
			Ring <= Q0;
		elsif ( clock'event and clock = '1' ) then
			case Ring is
				when Q0 => Ring <= Q1;
				when Q1 => Ring <= Q2;
				when Q2 => Ring <= Q0;
				when others => Ring <= ( others => '-' );
			end case;
		end if;
	end process;

	Decoder : process ( Ring )
	begin
		case Ring is
			when Q0 => cout <= "010";
			when Q1 => cout <= "001";
			when Q2 => cout <= "000";
			when others => cout <= ( others => '-' );
		end case;
	end process;

	Adder : process ( cout, input )
	begin
		carry(0) <= input(0) and cout(0);
		carry(1) <= ( input(1) and cout(1) ) or ( ( input(1) xor cout(1) ) and carry(0) );
		carry(2) <= ( input(2) and cout(2) ) or ( ( input(2) xor cout(2) ) and carry(1) );
		dir(0) <= input(0) xor cout(0);
		dir(1) <= input(1) xor cout(1) xor carry(0);
		dir(2) <= input(2) xor cout(2) xor carry(1);
		dir(3) <= carry(2);
	end process;

	output <= display ( conv_integer ( dir ) );
	selector <= Ring;

end architecture;
