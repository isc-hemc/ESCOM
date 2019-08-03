<?php
    require("../php/DB_Manager.php");
    $res = get_report_data("AlumnosSexo");
?>
<html>
    <head>
        <script src="../js/jquery/jquery-3.3.1.min.js"></script>
        <script src="../js/canvasjs.min.js"></script>
        <script type="text/javascript">
            window.onload = function () {
                var chart = new CanvasJS.Chart("chartContainer", {
                    theme: "light2",
                    title: {
                        text: "Porcentaje de alumnos por sexo",
                        horizontalAlign: "left"
                    },
                    data: [
                    {
                        // Change type to "doughnut", "line", "splineArea", etc.
                        type: "doughnut",
                        startAngle: 60,
                        innerRadius: 300,
                        indexLabelFontSize: 36,
                        indexLabel: "{label}: {y} (#percent%)",
                        toolTipContent: "<b>{label}:</b> {y} (#percent%)",
                        dataPoints: [
                            <?php
                                while ($row = mysqli_fetch_array($res)) {
                                    echo "{ y: ".$row['Alumnos'].", label: '".$row['Sexo']."' },";
                                }
                            ?>
                        ]
                    }
                    ]
                });
                chart.render();
                var canvas = $("#chartContainer .canvasjs-chart-canvas").get(0);
                var dataURL = canvas.toDataURL('image/png');
                $.ajax({
                    method: "post",
                    url: "./chart_to_img.php",
                    data: {
                        img_url: dataURL,
                        file_name: 'alum_sexo.png'
                    },
                    success: function(resp) {
                        if (resp) {
                            location.href = 'report_pdf.php';
                        } else {
                            alert("Imagen no creada");
                        }
                    }
                });
            }
        </script>
        <style>
            #chartContainer {
                width: 1920px;
                height: 1080px;
            }
        </style>
    </head>
    <body>
        <div id="chartContainer"></div>
    </body>
</html>