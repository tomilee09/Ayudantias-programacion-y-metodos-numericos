codigo = main.cpp
ejecutable = main

all: $(ejecutable)

$(ejecutable): $(codigo)
	g++ -o $(ejecutable) $(codigo)

clean:
	rm -f $(ejecutable)

run: $(ejecutable)
	./$(ejecutable)