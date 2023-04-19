build: compile
	g++ ./obj/*.o -o ./release/chap4 -L "D:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
compile:
	cd ./obj && g++ -c ../src/*.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/MenuState.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/Application.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/GUI_Button.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/TitleState.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/GUI_Container.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/Stack.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/GUI_Label.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/GUI_InputButton.cpp -I "D:\SFML-2.5.1\include"
#	cd ./obj && g++ -c ../src/GUI_Component.cpp -I "D:\SFML-2.5.1\include"

# application
# StateStack
# State	
# GameState
# LoadingState
# Menu
#
#
#
#
#