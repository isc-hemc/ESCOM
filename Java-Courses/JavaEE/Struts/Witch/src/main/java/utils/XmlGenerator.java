package utils;

import java.nio.file.FileSystems;
import java.io.FileOutputStream;
import java.beans.XMLEncoder;
import java.io.File;

public class XmlGenerator {

	public XmlGenerator() {
		super();
	}
	
	public String generate(ExamXmlHelper exam) {
		String path = FileSystems.getDefault().getPath(".").toAbsolutePath().toString(); 
		String fname = exam.getId() + "_" + exam.getName() + ".xml";
		String storePath = path + "/../" + fname;
		try {
			FileOutputStream fos = new FileOutputStream(new File(storePath));
			XMLEncoder encoder = new XMLEncoder(fos);
			encoder.writeObject(exam);
			encoder.close();
			fos.close();
			return storePath;
		}catch(Exception e){
			return null;
		}
	}
}
