library ieee;
use ieee.std_logic_1164.all;

entity asm is
	port (
		R_TYPE, BEQ, BNEQ, BLT, BLE, BGT, BGET : in std_logic;
		EQ, NEQ, LT, LET, TG, GET : in std_logic;
		clock, clear, na : in std_logic;
		sdopc, sm : out std_logic
	);
end asm;

architecture ar_asm of asm is

	type states is ( A );
	signal current_state, next_state : states;
	
	begin
	
		transition : process( clear, clock )
		begin
			if( clear = '1' ) then
				current_state <= A;
			elsif( clock'event and clock = '1' ) then 
				current_state <= next_state;
			end if;
		end process;
		
		automaton : process( R_TYPE, BEQ, BNEQ, BLT, BLE, BGT, BGET, EQ, NEQ, LT, LET, TG, GET, na, current_state )
		begin
			sm <= '0';
			sdopc <= '0';
			case( current_state ) is
				when A => next_state <= A;
					if( R_TYPE = '0' ) then
						if( BEQ = '1' ) then 
							if( na = '1' ) then
								sm <= '1';
							else
								if( EQ = '1' ) then
									sm <= '1';
									sdopc <= '1';
								else
									sm <= '1';
								end if;
							end if;
						elsif( BNEQ = '1' ) then
							if( na = '1' ) then
								sm <= '1';
							else
								if( NEQ = '1' ) then
									sm <= '1';
									sdopc <= '1';
								else
									sm <= '1';
								end if;
							end if;
						elsif( BGT = '1' ) then
							if( na = '1' ) then
								sm <= '1';
							else
								if( TG = '1' ) then
									sm <= '1';
									sdopc <= '1';
								else
									sm <= '1';
								end if;
							end if;
						elsif( BGET = '1' ) then
							if( na = '1' ) then
								sm <= '1';
							else
								if( GET = '1' ) then
									sm <= '1';
									sdopc <= '1';
								else
									sm <= '1';
								end if;
							end if;
						elsif( BLT = '1' ) then
							if( na = '1' ) then
								sm <= '1';
							else
								if( LT = '1' ) then
									sm <= '1';
									sdopc <= '1';
								else
									sm <= '1';
								end if;
							end if;
						elsif( BLE = '1' ) then
							if( na = '1' ) then
								sm <= '1';
							else
								if( LET = '1' ) then
									sm <= '1';
									sdopc <= '1';
								else
									sm <= '1';
								end if;
							end if;
						else
							sm <= '1';
							sdopc <= '1';
						end if;
					end if;
				end case;
		end process;

end architecture;