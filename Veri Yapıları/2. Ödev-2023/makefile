all: derle bagla calistir

derle:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -I "./include" -c ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ -I "./include" -c ./src/Yigin.cpp -o ./lib/Yigin.o

bagla:
	g++ ./lib/Dugum.o ./lib/AVLAgaci.o ./lib/main.o ./lib/Yigin.o -o ./bin/program

calistir:
	./bin/program
