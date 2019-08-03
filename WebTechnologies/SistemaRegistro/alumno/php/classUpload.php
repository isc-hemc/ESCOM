<?php
	 //if (substr_count($_SERVER['HTTP_ACCEPT_ENCODING'], 'gzip')) ob_start("ob_gzhandler"); else ob_start();
?>
<?php
// Uploader class, by Alex
// This class is meant to handle all kinds of file uploads for DJs Music
// Images, music... all here
// http://urbanoalvarez.es/blog/2009/08/07/easiest-php-file-upload/

/* *****
SE OMITIERON LOS echo  PARA EVITAR CONFLICTOS EN LAS RESPUESTAS DE LAS PETICONES REALIZADAS POR MEDIO DE AJAX
JAOR - 260515
***** */

class Uploader{
	var $maxSize;
	var $allowedExt;
	var $fileInfo = array();

	function config($maxSize,$allowedExt){
		$this->maxSize = $maxSize;
		$this->allowedExt = $allowedExt;
	}

	function generateRandStr($length){
		$randstr = "";
		for($i=0; $i< $length; $i++){
			$randnum = mt_rand(0,61);
			if($randnum < 10){
				$randstr .= chr($randnum+48);
			}else if($randnum < 36){
				$randstr .= chr($randnum+55);
			}else{
				$randstr .= chr($randnum+61);
			}
		}
		return $randstr;
	}

	function check($uploadName){
		if(isset($_FILES[$uploadName])){
			$this->fileInfo['ext'] = substr(strrchr($_FILES[$uploadName]["name"], '.'), 1);
			$this->fileInfo['name'] = basename($_FILES[$uploadName]["name"]);
			$this->fileInfo['size'] = $_FILES[$uploadName]["size"];
			$this->fileInfo['temp'] = $_FILES[$uploadName]["tmp_name"];
			if($this->fileInfo['size']< $this->maxSize){
				if(strlen($this->allowedExt)>0){
					$exts = explode(',',$this->allowedExt);
					if(in_array($this->fileInfo['ext'],$exts)){
						return true;
					}
					//echo "<p>Formato de archivo no permitido. Los tipos de archivos que se soportan son: ".$this->allowedExt."</p>";
					return false; //failed ext
				}
				//echo "<p>Oops! Tuvimos algunos problemas. Intentalo de nuevo por favor.</p>";
				return false; //All ext allowed
			}else{
				if($this->maxSize < 1000000){
					$rsi = round($this->maxSize/1000,2).' Kb';
				}else if($this->maxSize < 1000000000){
					$rsi = round($this->maxSize/1000000,2).' Mb';
				}else{
					$rsi = round($this->maxSize/1000000000,2).' Gb';
				}
				//echo "<p>Oops! El archivo es demasiado grande. El tamaño maximo permitido es de: ".$rsi."</p>";
				return false; //failed size
			}
		}
		//echo "<p>Oops! Se present&oacute; un error inesperado. Intentalo de nuevo por favor (File).</p>";
		return false; //Either form not submitted or file/s not found
	}

	function upload($name,$dir,$fname=false){
		if(!is_dir($dir)){
			//echo "<p>Oops! se present&oacute; un error inesperado. Intentalo de nuevo por favor (Dir).</p>";
			return false; //Directory doesn't exist!
		}
		if($this->check($name)){
			//Process upload. All info stored in array fileinfo:
			//Dir OK, keep going:
			//Get a new filename:
			if(!$fname){
				$this->fileInfo['fname'] = $this->generateRandStr(15).'.'.$this->fileInfo['ext'];
			}else{
				$this->fileInfo['fname'] = $fname.'.'.$this->fileInfo['ext'];
			}
			//Unique name gotten
			// Move file:
			if(@move_uploaded_file($this->fileInfo['temp'], $dir.$this->fileInfo['fname'])){
				//Done
				return true;
			}else{
				//echo "<p>Oops! No se pud&oacute; copiar el archivo. Intentalo de nuevo por favor.</p>";
				return false; //File not moved
			}
		}else{
		return false;
		}
	}
};

?>
