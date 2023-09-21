set terminal png size 700,700
set output "posicion.png"
plot 'posicion.txt' using 1:2 with lines 