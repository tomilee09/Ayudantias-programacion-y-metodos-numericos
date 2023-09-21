set terminal png size 700,700
set output "posicion.png"
plot 'posicion.txt' using 1:2

set terminal png size 700,700
set output "posicion_promedio.png"
plot 'posicion_promedio.txt'

set terminal png size 700,700
set output "velocidad_promedio.png"
plot 'velocidad_promedio.txt'