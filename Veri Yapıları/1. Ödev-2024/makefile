all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -c -I "./include" ./src/UstDugum.cpp -o ./lib/UstDugum.o
	g++ -c -I "./include" ./src/UstBagliListe.cpp -o ./lib/UstBagliListe.o
	
bagla:
	g++ ./lib/BagliListe.o ./lib/Dugum.o ./lib/UstBagliListe.o ./lib/UstDugum.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program