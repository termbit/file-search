CPP = main.cpp find_in_file.cpp

default:
	g++ -o main main.cpp
clean:
	rm -rf main
fltk:
	g++ $(CPP) -o main -lfltk