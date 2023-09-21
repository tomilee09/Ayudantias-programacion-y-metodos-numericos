set terminal png size 1200,1200

set output "cilindro.png"
set title "grafico de cilindro formado por la interpolación de los datos de seno y coseno"
set xlabel "sin(t)"
set ylabel "cos(t)"
set zlabel "t"
splot 'rk4.dat' using 2:3:1 w l