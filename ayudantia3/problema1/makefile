# all es el código que se ejecutará predefinidamente (escribiendo "make en la terminal")
all: main

# main es el nombre de la funcion que se ejecutará
# la funcion llama a main.cpp
# el código de abajo es lo que se ejecutará en la terminal
# dado que está llamada dentro del main se puede ejecutar de 2 formas:
# poniendo en terminal: "make" o "make main"
main: main.cpp
	g++ -o main main.cpp

# se corre poniendo "make run"
run: 
	./main

# se corre poniendo "make clean"
clean:
	rm -f main