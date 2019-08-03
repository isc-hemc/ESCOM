<?php
  /* Ya no hay necesidad de base de datos */
  $dispositivos = file_get_contents("./../dispositivos.json");
  echo $dispositivos;
?>
