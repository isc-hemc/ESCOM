library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity register_file is generic ( n : integer := 15 ); port (
	write_reg, read_reg_1, read_reg_2, shamt : in std_logic_vector ( 3 downto 0 );
	read_data_1, read_data_2 : out std_logic_vector ( n downto 0 );
	write_data : in std_logic_vector ( n downto 0 );
	clear, clock, wr, she, dir : in std_logic
	);
end register_file;

architecture ar_register_file of register_file is

	type registers is array ( 0 to n ) of std_logic_vector ( n downto 0 );
	signal reg_file : registers;

	begin

		process ( clear, clock )
		begin
			if ( clear = '1' ) then
				for i in 0 to n loop
					reg_file(i) <= ( others => '0' );
				end loop;
			elsif ( clock'event and clock = '1' ) then
				if ( wr = '1' and she = '0' ) then
					reg_file(to_integer(unsigned(write_reg))) <= write_data;
				end if;
				if ( wr = '1' and she = '1' and dir = '0' ) then -- Right shift.
					reg_file(to_integer(unsigned(write_reg))) <= std_logic_vector ( unsigned(reg_file(to_integer(unsigned(read_reg_1)))) srl to_integer(unsigned(shamt)) );
				end if;
				if ( wr = '1' and she = '1' and dir = '1' ) then -- Left shift.
					reg_file(to_integer(unsigned(write_reg))) <= std_logic_vector ( unsigned(reg_file(to_integer(unsigned(read_reg_1)))) sll to_integer(unsigned(shamt)) );
				end if;
			end if;
		end process;

		read_data_1 <= reg_file(to_integer(unsigned(read_reg_1)));
		read_data_2 <= reg_file(to_integer(unsigned(read_reg_2)));

end architecture;
