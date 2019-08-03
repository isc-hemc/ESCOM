library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity ROM is port (
	selector : out std_logic_vector ( 2 downto 0 );
	display : out std_logic_vector ( 6 downto 0 );
	dir : in std_logic_vector ( 2 downto 0 ); 
	clock, clear : in std_logic
);

attribute PIN_NUMBERS of ROM : entity is (
"clear:13 clock:1 dir(2):6 dir(1):7 dir(0):8 "& 
"display(6):20 display(5):19 display(4):18 display(3):17 display(2):16 display(1):15 display(0):21 "& 
"selector(2):14 selector(1):23 selector(0):22 "
);

end entity;

architecture arcROM of ROM is

-- Display Selectors.
constant Q0 : std_logic_vector ( 2 downto 0 ) := "011";
constant Q1 : std_logic_vector ( 2 downto 0 ) := "101";
constant Q2 : std_logic_vector ( 2 downto 0 ) := "110";
-- Letters.
constant Lnone : std_logic_vector ( 6 downto 0 ) := "1111111";
constant LD : std_logic_vector ( 6 downto 0 ) := "0000001";
constant LE : std_logic_vector ( 6 downto 0 ) := "0110000";
constant LS : std_logic_vector ( 6 downto 0 ) := "0100100";
constant LI : std_logic_vector ( 6 downto 0 ) := "1001111";
constant LG : std_logic_vector ( 6 downto 0 ) := "0100000";
constant LN : std_logic_vector ( 6 downto 0 ) := "0001001";
-- RingCounter signal.
signal Ring : std_logic_vector ( 2 downto 0 );
-- ROM memory.
type ROM is array ( 0 to 7 ) of std_logic_vector ( 6 downto 0 );
-- Memory data.
constant LDisplay : ROM := ( Lnone, Lnone, LD, LE, LS, LI, LG, LN ); -- Left display.
constant CDisplay : ROM := ( Lnone, LD, LE, LS, LI, LG, LN, Lnone ); -- Center display.
constant Rdisplay : ROM := ( LD, LE, LS, LI, LG, LN, Lnone, Lnone ); -- Right display.
-- Display signals.
signal LData : std_logic_vector ( 6 downto 0 ); -- Left display data.
signal CData : std_logic_vector ( 6 downto 0 ); -- Center display data.
signal RData : std_logic_vector ( 6 downto 0 ); -- Right display data.

begin
	
	RingCounter : process ( clock, clear )
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

	ROMemory : process ( dir )
	begin 
		LData <= LDisplay ( conv_integer ( dir ) );
		CData <= CDisplay ( conv_integer ( dir ) );
		RData <= RDisplay ( conv_integer ( dir ) );
	end process;

	Multiplexer : process ( Ring )
	begin
		if ( Ring = "011" ) then
			display <= LData;
		elsif ( Ring = "101" ) then
			display <= CData;
		elsif ( Ring = "110" ) then
			display <= RData;
		end if;
	end process;

	selector <= Ring;

end architecture;
