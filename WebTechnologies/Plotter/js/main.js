$(document).ready(function() {
    $('select').formSelect();
});

var slider = document.getElementById('test-slider');
  noUiSlider.create(slider, {
   start: [-5, 5],
   connect: true,
   step: 1,
   orientation: 'horizontal', // 'horizontal' or 'vertical'
   range: {
     'min': -50,
     'max': 50
   }
  });

window.onload = plot();

function plot() {
    var func_sel = document.getElementById("func_sel");
    var func = func_sel.options[func_sel.selectedIndex].value;
    var arg = document.getElementById("argument").value;
    if(arg == "")
        arg = "x";
    var fullExpr = "Math." + func + "(" + arg + ")";
    if (func == "f")
        fullExpr = arg;
    var data_var = [];
    var range = slider.noUiSlider.get();
    for (let index = 0; index < range.length; index++)
        range[index] = parseInt(range[index]);
    for (let x = range[0]; x <= range[1]; x += 0.001) {
        data_var.push({x: x, y: eval(fullExpr)});
    }
    var chart = new CanvasJS.Chart("chartContainer", {
        animationEnabled: true,
        theme: "light2",
        axisX: {
            title: "x"
        },
        axisY: {
            title: "f(x)"
        },
        data: [{
            type: "line",
            color: "#00C2AD",
            dataPoints: data_var
        }]
    });
    chart.render();
}