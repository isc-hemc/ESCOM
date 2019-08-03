library ieee;

use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity function_memory is generic( k : integer := 32; m : integer := 20 ); 
	port (
		output : out std_logic_vector ( m - 1 downto 0 );
		addr_bus : in std_logic_vector ( 3 downto 0 )
	);
end function_memory;

architecture ar_functmemory of function_memory is
	-- Microcode flags order: SDMP UP DW WPC SR2 SWD SEXT SHE DIR WR SOP1 SOP2 ALUOP SDMD WD SR LF.
	constant verification_microcode : std_logic_vector ( m - 1 downto 0 ) := "00001000000001110001";
	-- Load and store microcodes.
	constant LI : std_logic_vector ( m - 1 downto 0 )    :=   "00000000010000000000";
	constant LWI : std_logic_vector ( m - 1 downto 0 )   :=   "00000100010000001000";
	constant LW : std_logic_vector ( m - 1 downto 0 )    :=   "00000110010100110001";
	constant SWI : std_logic_vector ( m - 1 downto 0 )   :=   "00001000000000001100";
	constant SW : std_logic_vector ( m - 1 downto 0 )    :=   "00001010000100110101";
	-- Arithmetic microcodes.
	constant R_ADD : std_logic_vector ( m - 1 downto 0 ) :=   "00000100010000110011";
	constant R_SUB : std_logic_vector ( m - 1 downto 0 ) :=   "00000100010001110011";
	constant ADDI : std_logic_vector ( m - 1 downto 0 )  :=   "00000100010100110011";
	constant SUBI : std_logic_vector ( m - 1 downto 0 )  :=   "00000100010101110011";
	-- Logical microcodes.
	constant R_AND : std_logic_vector ( m - 1 downto 0 ) :=   "00000100010000000011";
	constant R_OR : std_logic_vector ( m - 1 downto 0 )  :=   "00000100010000010011";
	constant R_XOR : std_logic_vector ( m - 1 downto 0 ) :=   "00000100010000100011";
	constant R_NAND : std_logic_vector ( m - 1 downto 0 ):=   "00000100010011010011";
	constant R_NOR : std_logic_vector ( m - 1 downto 0 ) :=   "00000100010011000011";
	constant R_XNOR : std_logic_vector ( m - 1 downto 0 ):=   "00000100010010100011";
	constant R_NOT : std_logic_vector ( m - 1 downto 0 ) :=   "00000100010011010011";
	constant ANDI : std_logic_vector ( m - 1 downto 0 )  :=   "00000100010100000011";
	constant ORI : std_logic_vector ( m - 1 downto 0 )   :=   "00000100010100010011";
	constant XORI : std_logic_vector ( m - 1 downto 0 )  :=   "00000100010100100011";
	constant NANDI : std_logic_vector ( m - 1 downto 0 ) :=   "00000100010111010011";
	constant NORI : std_logic_vector ( m - 1 downto 0 )  :=   "00000100010111000011";
	constant XNORI : std_logic_vector ( m - 1 downto 0 ) :=   "00000100010110100011";
	-- Shift microcodes.
	constant R_SLL : std_logic_vector ( m - 1 downto 0 ) :=   "00000001110000000000";
	constant R_SRL : std_logic_vector ( m - 1 downto 0 ) :=   "00000001010000000000";
	-- Conditional and unconditional jumps microcodes.
	constant BEQI : std_logic_vector ( m - 1 downto 0 )  :=   "10010000001100110011";
	constant BNEI : std_logic_vector ( m - 1 downto 0 )  :=   "10010000001100110011";
	constant BLTI : std_logic_vector ( m - 1 downto 0 )  :=   "10010000001100110011";
	constant BLETI : std_logic_vector ( m - 1 downto 0 ) :=   "10010000001100110011";
	constant BGTI : std_logic_vector ( m - 1 downto 0 )  :=   "10010000001100110011";
	constant BGETI : std_logic_vector ( m - 1 downto 0 ) :=   "10010000001100110011";
	constant B : std_logic_vector ( m - 1 downto 0 )     :=   "00010000000000000000";
	-- Subroutine microcodes.
	constant CALL : std_logic_vector ( m - 1 downto 0 )  :=   "01010000000000000000";
	constant RET : std_logic_vector ( m - 1 downto 0 )   :=   "00100000000000000000";
	-- Other instructions.
	constant NOP : std_logic_vector ( m - 1 downto 0 )   :=   "00000000000000000000";
	-- Defining the microcode operation memory.
	type memory is array( 0 to k - 1 ) of std_logic_vector( m - 1 downto 0 );
	constant funct_memory : memory := (
		R_ADD,
		R_SUB,
		R_AND,
		R_OR,
		R_XOR,
		R_NAND,
		R_NOR,
		R_XNOR,
		R_NOT,
		R_SLL,
		R_SRL,
		others => ( others => '0' )
	);
	
	begin

		output <= funct_memory( conv_integer( addr_bus ) );
		
end ar_functmemory;