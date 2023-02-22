derlebaglacalistir: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/AdminNode.cpp -o ./lib/AdminNode.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++  ./lib/Node.o ./lib/SatirListesi.o ./lib/AdminNode.o ./lib/YoneticiListesi.o ./lib/main.o -o ./bin/program.exe
calistir:
	./bin/program.exe