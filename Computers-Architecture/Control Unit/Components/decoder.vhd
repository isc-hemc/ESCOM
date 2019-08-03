library ieee;
use ieee.std_logic_1164.all;

entity decoder is 
	port (
		cp_code : in std_logic_vector( 4 downto 0 );
		R_TYPE : out std_logic;
		BEQ : out std_logic;
		BNEQ : out std_logic;
		BLT : out std_logic;
		BLE : out std_logic;
		BGT : out std_logic;
		BGET : out std_logic
	);
end decoder;

architecture ar_decoder of decoder is

	begin
	
		process( cp_code )
		begin
			if( cp_code = "00000" ) then
				R_TYPE <= '1';
				BEQ <= '0';
				BNEQ <= '0';
				BLT <= '0';
				BLE <= '0';
				BGT <= '0';
				BGET <= '0';
			elsif( cp_code = "01101" ) then
				R_TYPE <= '0';
				BEQ <= '1';
				BNEQ <= '0';
				BLT <= '0';
				BLE <= '0';
				BGT <= '0';
				BGET <= '0';
			elsif( cp_code = "01110" ) then
				R_TYPE <= '0';
				BEQ <= '0';
				BNEQ <= '1';
				BLT <= '0';
				BLE <= '0';
				BGT <= '0';
				BGET <= '0';
			elsif( cp_code = "01111" ) then
				R_TYPE <= '0';
				BEQ <= '0';
				BNEQ <= '0';
				BLT <= '1';
				BLE <= '0';
				BGT <= '0';
				BGET <= '0';
			elsif( cp_code = "10000" ) then
				R_TYPE <= '0';
				BEQ <= '0';
				BNEQ <= '0';
				BLT <= '0';
				BLE <= '1';
				BGT <= '0';
				BGET <= '0';
			elsif( cp_code = "10001" ) then
				R_TYPE <= '0';
				BEQ <= '0';
				BNEQ <= '0';
				BLT <= '0';
				BLE <= '0';
				BGT <= '1';
				BGET <= '0';
			elsif( cp_code = "10000" ) then
				R_TYPE <= '0';
				BEQ <= '0';
				BNEQ <= '0';
				BLT <= '0';
				BLE <= '0';
				BGT <= '0';
				BGET <= '1';
			else
				R_TYPE <= '0';
				BEQ <= '0';
				BNEQ <= '0';
				BLT <= '0';
				BLE <= '0';
				BGT <= '0';
				BGET <= '0';
			end if;
		end process;
		
end architecture;