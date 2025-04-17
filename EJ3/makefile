HEADERS = -I ../EJ1/Headers/Armas/ -I ../EJ1/Headers/Personajes/ -I ../EJ1/Headers/Efectos/ -I ../EJ1/Utilities/
SOURCES = ../EJ1/Sources/Armas/*.cpp ../EJ1/Sources/Personajes/*.cpp ../EJ1/Sources/Efectos/*.cpp ../EJ1/Utilities/utilities.cpp ../EJ2/PersonajeFactory.cpp

make:
	g++ -std=c++14 -Wall -Wextra $(HEADERS) -g main.cpp $(SOURCES) -o main
	./main
	rm main
	rm -rf main.dSYM/