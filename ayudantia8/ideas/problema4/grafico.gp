set terminal png size 1200,1200

set output "rk4.png"
set title "holaaaaa"
set xlabel "tiempo [s]"
set ylabel "posición [x]"
plot 'rk4.dat' using 4:3 w l

set output "rk4_error.png"
set title "holaaaaa"
set xlabel "tiempo [s]"
set ylabel "posición [x]"
plot 'rk4_error.dat' using 4:3 w l

set output "todos.png"
set title "gráfico de todos los métodos"
set xlabel "tiempo [s]"
set ylabel "posición [x]"
plot 'rk4.dat' using 1:4 w l, \
'rk4_error.dat' using 1:4 w l \