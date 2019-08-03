library ieee;
use ieee.std_logic_1164.all;

entity alu is generic ( n : integer := 4 ); 
	port (
		cout, flag_z, flag_c, flag_n, flag_ov : out std_logic;
		output : inout std_logic_vector ( n - 1 downto 0 );
		operation : in std_logic_vector ( 1 downto 0 );
		a, b : in std_logic_vector ( n - 1 downto 0 );
		sel_a, sel_b : in std_logic
	);
end alu;

architecture arq_alu of alu is

signal mux_a, mux_b : std_logic_vector ( n - 1 downto 0 );
signal carry : std_logic_vector ( n downto 0 );

begin

	process ( a, b, sel_a, sel_b, mux_a, mux_b, carry, output, operation )
	begin
	carry <= ( others => '0' );
	carry(0) <= sel_b;
	for i in 0 to n - 1 loop
		mux_a(i) <= a(i) xor sel_a;
		mux_b(i) <= b(i) xor sel_b;
		case operation is
			when "00" => -- AND/NOR/NOT logical operation.
				output(i) <= mux_a(i) and mux_b(i);
			when "01" => -- OR/NAND/NOT logical operation.
				output(i) <= mux_a(i) or mux_b(i);
			when "10" => -- XOR/XNOR logical operation.
				output(i) <= mux_a(i) xor mux_b(i);
			when others => -- Arithmetic operations.
				output(i) <= mux_a(i) xor carry(i) xor mux_b(i);
				carry(i+1) <= ( mux_a(i) and carry(i) ) or ( mux_b(i) and carry(i) ) or ( mux_a(i) and mux_b(i) );
		end case;
	end loop;
	flag_z <= not ( output(0) or output(1) or output(2) or output(3) );
	flag_ov <= carry(n) xor carry(n-1);
	flag_n <= output(n-1);
	flag_c <= carry(n);
	cout <= carry(n);
	end process;

end architecture;
