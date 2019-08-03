library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity ROM is port (
	selector : out std_logic_vector ( 2 downto 0 );
	display : out std_logic_vector ( 6 downto 0 );
	dir : in std_logic_vector ( 3 downto 0 );
	clock, clear : in std_logic
);
end entity;

architecture arcROM of ROM is 

-- Display selectors.
constant Q0 : std_logic_vector ( 2 downto 0 ) := "011";
constant Q1 : std_logic_vector ( 2 downto 0 ) := "101";
constant Q2 : std_logic_vector ( 2 downto 0 ) := "110";
-- Letters.
constant Lnone : std_logic_vector ( 3 downto 0 ) := "0000";
constant LD : std_logic_vector ( 3 downto 0 ) := "0001";
constant LE : std_logic_vector ( 3 downto 0 ) := "0011";
constant LS : std_logic_vector ( 3 downto 0 ) := "0010";
constant LI : std_logic_vector ( 3 downto 0 ) := "0110";
constant LG : std_logic_vector ( 3 downto 0 ) := "0111";
constant LN : std_logic_vector ( 3 downto 0 ) := "0101";
constant LT : std_logic_vector ( 3 downto 0 ) := "0100";
constant LA : std_logic_vector ( 3 downto 0 ) := "1100"; 
constant LL : std_logic_vector ( 3 downto 0 ) := "1101";
constant X : std_logic_vector ( 3 downto 0 ) := "1110";
-- Ring counter signal.
signal Ring : std_logic_vector ( 2 downto 0 );
-- ROM memory.
type ROM is array ( 0 to 15 ) of std_logic_vector ( 3 downto 0 );
--Memory data.
constant LDisplay : ROM := ( Lnone, Lnone, LD, LI, LG, LI, LT, LA, LL, Lnone, LD, LE, LS, LI, LG, LN );
constant CDisplay : ROM := ( Lnone, LD, LI, LG, LI, LT, LA, LL, Lnone, LD, LE, LS, LI, LG, LN, Lnone );
constant RDisplay : ROM := ( LD, LI, LG, LI, LT, LA, LL, Lnone, LD, LE, LS, LI, LG, LN, Lnone, Lnone );
-- Display signals.
signal LData : std_logic_vector ( 3 downto 0 );
signal CData : std_logic_vector ( 3 downto 0 );
signal RData : std_logic_vector ( 3 downto 0 );
-- BCD signal.
--signal BCD : std_logic_vector ( 3 downto 0 );

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

	ROMemory : process ( dir )
	begin
		LData <= LDisplay ( conv_integer ( dir ) );
		CData <= CDisplay ( conv_integer ( dir ) );
		RData <= RDisplay ( conv_integer ( dir ) );
	end process;

	Multiplexer : process ( Ring, LData, CData, RData ) 
	begin
		if ( Ring = "011" ) then
			case LData is
				when "0000" => display <= "1111111"; -- none.
				when "0001" => display <= "0000001"; -- LD.
				when "0011" => display <= "0110000"; -- LE
				when "0010" => display <= "0100100"; -- LS
				when "0110" => display <= "1001111"; -- LI
				when "0111" => display <= "0100000"; -- LG
				when "0101" => display <= "0001001"; -- LN
				when "0100" => display <= "0100000"; -- LG
				when "1100" => display <= "1110000"; -- LT
				when "1101" => display <= "0001000"; -- LA
				when "1111" => display <= "1110001"; -- LL
				when others => display <= ( others => '-' );
			end case;
		elsif ( Ring = "101" ) then
			case CData is
				when "0000" => display <= "1111111"; -- none.
				when "0001" => display <= "0000001"; -- LD.
				when "0011" => display <= "0110000"; -- LE
				when "0010" => display <= "0100100"; -- LS
				when "0110" => display <= "1001111"; -- LI
				when "0111" => display <= "0100000"; -- LG
				when "0101" => display <= "0001001"; -- LN
				when "0100" => display <= "0100000"; -- LG
				when "1100" => display <= "1110000"; -- LT
				when "1101" => display <= "0001000"; -- LA
				when "1111" => display <= "1110001"; -- LL
				when others => display <= ( others => '-' );
			end case;
		elsif ( Ring = "110" ) then
			case RData is
				when "0000" => display <= "1111111"; -- none.
				when "0001" => display <= "0000001"; -- LD.
				when "0011" => display <= "0110000"; -- LE
				when "0010" => display <= "0100100"; -- LS
				when "0110" => display <= "1001111"; -- LI
				when "0111" => display <= "0100000"; -- LG
				when "0101" => display <= "0001001"; -- LN
				when "0100" => display <= "0100000"; -- LG
				when "1100" => display <= "1110000"; -- LT
				when "1101" => display <= "0001000"; -- LA
				when "1111" => display <= "1110001"; -- LL
				when others => display <= ( others => '-' );
			end case;
		end if;
	end process;

	selector <= Ring;

end architecture;
