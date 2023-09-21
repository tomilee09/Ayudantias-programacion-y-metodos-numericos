set terminal png size 1200,1200

set output "sin_interpolado.png"
set title "grafico de datos interpolados donde se aprecia un sin(t) respecto a t"
set xlabel "t"
set ylabel "sin(t)"
plot 'archivo_interpolacion.dat' using 1:2 w l, 'datos.dat' using 1:2 w l
    

set output "cilindro.png"
set title "grafico de cilindro formado por la interpolación de los datos de seno y coseno"
set xlabel "sin(t)"
set ylabel "cos(t)"
set zlabel "t"
splot 'archivo_interpolacion.dat' using 2:3:1 w l, 'datos.dat' using 2:3:1 w l