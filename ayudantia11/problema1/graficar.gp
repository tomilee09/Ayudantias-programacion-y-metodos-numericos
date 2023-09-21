set terminal pngcairo enhanced size 800, 600  
set output 'grafico_barra_mitad_caliente.png'  
set view 120, 30, 1, 1
set xlabel 'posicion'
set ylabel 'tiempo'
set zlabel 'amplitud'
set title 'Barra mitad caliente'

splot 'datos.txt' palette pointtype 7
