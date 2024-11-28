hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c
	gcc -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c
	gcc -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c
	gcc -I ./include/ -o ./lib/bagliListe.o -c ./src/bagliListe.c
	gcc -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.c
	gcc -I ./include/ -o ./bin/Test ./lib/Bocek.o ./lib/Canli.o ./lib/Bitki.o ./lib/Sinek.o ./lib/Pire.o ./lib/Habitat.o ./lib/bagliListe.o ./lib/Dugum.o ./src/Test.c

calistir:
	./bin/Test
