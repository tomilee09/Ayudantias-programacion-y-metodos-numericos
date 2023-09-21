all: main

main: main.cpp
	g++ -o main main.cpp

run: 
	./main

clean: 
	rm -f main posicion.txt posicion.png velocidad_promedio.txt velocidad_promedio.png

plot: 
	gnuplot mi_plot.gp