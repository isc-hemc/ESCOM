library ieee;

use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity stack is generic( n : integer := 16; m : integer := 7 );
  port (
    pc_output : out std_logic_vector( n - 1 downto 0 );
    sp_output : out std_logic_vector( 2 downto 0 );
    data : in std_logic_vector( n - 1 downto 0 );
    clear, clock, wpc, up, down : in std_logic
  );
end entity;

architecture ar_stack of stack is

	type type_stack is array( 0 to m ) of std_logic_vector( n - 1 downto 0 );

	begin

		process( clear, clock )

		variable sp : integer range 0 to m; -- Stack pointer.
		variable pc : type_stack; -- Stack counters.

		begin
			if( clear = '1' ) then
				for i in 0 to m loop
					pc( i ) := ( others => '0' );
				end loop;
				sp := 0;
			elsif( clock'event and clock = '1' ) then
				if( wpc = '1' and up = '0' and down = '0' ) then -- Branch, conditional and unconditional jumps.
					pc( sp ) := data;
				end if;
				if( wpc = '1' and up = '1' and down = '0' ) then -- Call.
					sp := sp + 1;
					pc( sp ) := data;
				end if;
				if( wpc = '0' and up = '0' and down = '1' ) then -- RET.
					sp := sp - 1;
					pc( sp ) := pc( sp ) + 1;
				end if;
				if( wpc = '0' and up = '0' and down = '0' ) then -- pc( sp )++ and sp = sp.
					pc( sp ) := pc( sp ) + 1;
				end if;
			end if;
			sp_output <= std_logic_vector( to_unsigned( sp, sp_output'length ) );
			pc_output <= pc( sp );
		end process;

end architecture;
