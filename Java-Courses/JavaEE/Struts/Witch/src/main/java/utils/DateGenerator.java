package utils;

import java.text.SimpleDateFormat;
import java.text.DateFormat;
import java.util.Date;

public class DateGenerator {

	private DateFormat df;
	
	public DateGenerator() {
		super();
		this.df = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
	}
	
	public String getCurrentDate() {
		Date date = new Date();
		return this.df.format(date);
	}
	
}
