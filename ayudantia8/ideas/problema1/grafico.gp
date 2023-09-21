set terminal png size 1200,1200

set output "pefrl.png"
set title "gráfico de resolución de ode con método Euler"
set xlabel "tiempo [s]"
set ylabel "posición [x]"
plot 'pefrl.dat' using 1:4 w l

# set output "todos.png"
# set title "gráfico de todos los métodos"
# set xlabel "tiempo [s]"
# set ylabel "posición [x]"
# plot 'euler.dat' using 1:4 w l, 'euler_cromer.dat' using 1:4 w l, 'verlet.dat' using 1:4 w l, 'rk2.dat' using 1:4 w l