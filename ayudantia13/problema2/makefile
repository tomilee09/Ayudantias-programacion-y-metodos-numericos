all: main

main: main.cpp
	g++ -o main main.cpp

run: 
	./main

clean: 
	rm -f main *.dat *.txt

dev:
	make clean
	make
	make run
	python3 graficar.py

plot: 
	gnuplot graficar.gp