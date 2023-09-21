all: main

main: main.cpp
	g++ -o main main.cpp

run: 
	./main

clean: 
	rm -f main spline splines_cubicos.dat *.png create_data archivo_interpolacion.dat

plot: 
	gnuplot grafico.gp