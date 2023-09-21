# podemos crear variables dentro de makefile
# es conveniente si no se quiere cambiar todo el texto de abajo
codigo = main.cpp
ejecutable = main

all: $(ejecutable)

$(ejecutable): $(codigo)
	g++ -o $(ejecutable) $(codigo)

clean:
	rm -f $(ejecutable)

run: $(ejecutable)
	./$(ejecutable)