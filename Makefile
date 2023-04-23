build: compile
	g++ ./obj/*.o -o ./release/chap4 -L "D:\SFML-2.5.1\lib" -lcomdlg32 -lsfml-graphics -lsfml-window -lsfml-system

obj/%.o: src/%.cpp
	g++ -c $< -o $@ -I "D:\SFML-2.5.1\include"

CPP_FILES  = $(wildcard src/*.cpp)
OBJ_FILES = $(CPP_FILES:src/%.cpp=obj/%.o)

compile: $(OBJ_FILES)

clean:
	del obj\*.o

all: build