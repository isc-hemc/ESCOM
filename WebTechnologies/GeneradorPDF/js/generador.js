
let idProfesor = null;
let botonGenerar = null;
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
  } 
async function generaArchivo() {
    if (isNaN(idprofesor.value) || idProfesor.value == "")
    {
        swal("Error", "Ingresa un ID valido");
       
       // return;
    }
    await sleep(3000);
    idProfesor.value = "";
}

function main() {
    idProfesor =document.getElementById("idprofesor");
    botonGenerar =document.getElementById("generar");
    botonGenerar.addEventListener("click", generaArchivo, true);
}

window.onload = main;