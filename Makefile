build: compile
	g++ ./obj/*.o -o ./release/chap4 -L "D:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
compile:
	cd ./obj && g++ -c ../src/*.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/Game.cpp -I "D:\SFML-2.5.1\include"
#Player.cpp
#Command.cpp
#CommandQueue.cpp
#Entity.hpp
#Game.hpp
#
#
#
#
#
#