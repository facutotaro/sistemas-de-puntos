.PHONY: all
all: tp1 codificarParticipantes

tp1: tp1.o partido.o winPercentage.o colleyMatrix.o ratingIndex.o
	g++ -Wall $^ -o $@

tp1.o: tp1.cpp winPercentage.h colleyMatrix.h ratingIndex.h
	g++ -c -Wall $< -o $@

partido.o: partido.cpp
	g++ -c -Wall $< -o $@

winPercentage.o: winPercentage.cpp winPercentage.h partido.cpp
	g++ -c -Wall $< -o $@

colleyMatrix.o: colleyMatrix.cpp colleyMatrix.h partido.cpp
	g++ -c -Wall $< -o $@

ratingIndex.o: ratingIndex.cpp ratingIndex.h partido.cpp
	g++ -c -Wall $< -o $@

codificarParticipantes: codificarParticipantes.o partido.o
	g++ -Wall $^ -o $@

codificarParticipantes.o: codificarParticipantes.notcpp
	# Para evitar que el python de tests salvaje compile esto
	cp codificarParticipantes.notcpp codificarParticipantes.cpp
	g++ -c -Wall codificarParticipantes.cpp -o $@
	rm -f codificarParticipantes.cpp

.PHONY: clean
clean:
	rm -f *.o
	rm -f tp1
	rm -f codificarParticipantes
