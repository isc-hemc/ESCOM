library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity rom is generic( n : integer := 16 );
	port (
		addr_bus : in std_logic_vector ( n - 1 downto 0 );
		output : out std_logic_vector ( 24 downto 0 )
	);
end rom;

architecture ar_rom of rom is
	-- Instructions type R opcode always will be '0'.
	constant OPCODE_TYPE_R : std_logic_vector( 4 downto 0 ) := "00000";
	-- Instructions type R (Register):
	constant FUNCTION_CODE_ADD : std_logic_vector( 3 downto 0 ) := "0000"; -- Function code 00.
	constant FUNCTION_CODE_SUB : std_logic_vector( 3 downto 0 ) := "0001"; -- Function code 01.
	constant FUNCTION_CODE_AND : std_logic_vector( 3 downto 0 ) := "0010"; -- Function code 02.
	constant FUNCTION_CODE_OR : std_logic_vector( 3 downto 0 ) := "0011"; -- Function code 03.
	constant FUNCTION_CODE_XOR : std_logic_vector( 3 downto 0 ) := "0100"; -- Function code 04.
	constant FUNCTION_CODE_NAND : std_logic_vector( 3 downto 0 ) := "0101"; -- Function code 05.
	constant FUNCTION_CODE_NOR : std_logic_vector( 3 downto 0 ) := "0110"; -- Function code 06.
	constant FUNCTION_CODE_XNOR : std_logic_vector( 3 downto 0 ) := "0111"; -- Function code 07.
	constant FUNCTION_CODE_NOT : std_logic_vector( 3 downto 0 ) := "1000"; -- Function code 08.
	constant FUNCTION_CODE_SLL : std_logic_vector( 3 downto 0 ) := "1001"; -- Function code 09.
	constant FUNCTION_CODE_SRL : std_logic_vector( 3 downto 0 ) := "1010"; -- Function code 10.
	-- Instructions type I (Immediate):
	constant OPCODE_LI : std_logic_vector( 4 downto 0 ) := "00001"; -- Opcode 01.
	constant OPCODE_LWI : std_logic_vector( 4 downto 0 ) := "00010"; -- Opcode 02.
	constant OPCODE_LW : std_logic_vector( 4 downto 0 ) := "10111"; -- Opcode 23.
	constant OPCODE_SWI : std_logic_vector( 4 downto 0 ) := "00011"; -- Opcode 03.
	constant OPCODE_SW : std_logic_vector( 4 downto 0 ) := "00100"; -- Opcode 04.
	constant OPCODE_ADDI : std_logic_vector( 4 downto 0 ) := "00101"; -- Opcode 05.
	constant OPCODE_SUBI : std_logic_vector( 4 downto 0 ) := "00110"; -- Opcode 06.
	constant OPCODE_ANDI : std_logic_vector( 4 downto 0 ) := "00111"; -- Opcode 07.
	constant OPCODE_ORI : std_logic_vector( 4 downto 0 ) := "01000"; -- Opcode 08.
	constant OPCODE_XORI : std_logic_vector( 4 downto 0 ) := "01001"; -- Opcode 09.
	constant OPCODE_NANDI : std_logic_vector( 4 downto 0 ) := "01010"; -- Opcode 10.
	constant OPCODE_NORI : std_logic_vector( 4 downto 0 ) := "01011"; -- Opcode 11.
	constant OPCODE_XNORI : std_logic_vector( 4 downto 0 ) := "01100"; -- Opcode 12.
	constant OPCODE_BEQI : std_logic_vector( 4 downto 0 ) := "01101"; -- Opcode 13.
	constant OPCODE_BNEI : std_logic_vector( 4 downto 0 ) := "01110"; -- Opcode 14.
	constant OPCODE_BLTI : std_logic_vector( 4 downto 0 ) := "01111"; -- Opcode 15.
	constant OPCODE_BLETI : std_logic_vector( 4 downto 0 ) := "10000"; -- Opcode 16.
	constant OPCODE_BGTI : std_logic_vector( 4 downto 0 ) := "10001"; -- Opcode 17.
	constant OPCODE_BGETI : std_logic_vector( 4 downto 0 ) := "10010"; -- Opcode 18.
	-- Operations type J (Jump):
	constant OPCODE_B : std_logic_vector( 4 downto 0 ) := "10011"; -- Opcode 19.
	constant OPCODE_CALL : std_logic_vector( 4 downto 0 ) := "10100"; -- Opcode 20.
	-- Other operations:
	constant OPCODE_RET : std_logic_vector( 4 downto 0 ) := "10101"; -- Opcode 21.
	constant OPCODE_NOP : std_logic_vector( 4 downto 0 ) := "10110"; -- Opcode 22.
	-- S/U slots:
	constant SU : std_logic_vector( 3 downto 0 ) := "0000";
	-- Registers:
	constant R0 : std_logic_vector( 3 downto 0 ) := "0000";
	constant R1 : std_logic_vector( 3 downto 0 ) := "0001";
	constant R2 : std_logic_vector( 3 downto 0 ) := "0010";

	-- Defining ROM memory.
	type memory is array( 0 to 2**n ) of std_logic_vector( 24 downto 0 );
	constant rom_memory : memory := (
		OPCODE_LI & R0 & x"0001",
		OPCODE_LI & R1 & x"0007",
		OPCODE_TYPE_R & R1 & R1 & R0 & SU & FUNCTION_CODE_ADD,
		OPCODE_SWI & R1 & x"0005",
		OPCODE_B & SU & x"0002",
		others => ( others => '0' )
	);

	begin

		output <= rom_memory( conv_integer( addr_bus ) );

end ar_rom;
