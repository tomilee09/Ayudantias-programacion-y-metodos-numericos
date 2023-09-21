set pm3d map
set palette defined (-1 "blue", 0 "white", 1 "red")
set xlabel "x"
set ylabel "y"
set zlabel "Amplitud"
set title "Ecuación de Onda en 2D"
set xrange [0:1]
set yrange [0:1]
set cbrange [-1e-06:-1e-05]
set terminal png
set output "onda.png"
splot "datos.txt" matrix with pm3d