HEADERS = -I Headers/Armas/ -I Headers/Personajes/ -I Headers/Efectos/ -I Utilities/
SOURCES = Sources/Armas/*.cpp Sources/Personajes/*.cpp Sources/Efectos/*.cpp Utilities/*.cpp

make:
	g++ -std=c++14 -Wall -Wextra $(HEADERS) -g $(SOURCES) main.cpp -o main
	./main
	rm main
	rm -rf main.dSYM/