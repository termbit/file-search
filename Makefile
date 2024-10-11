default:
	g++ -o main main.cpp
clean:
	rm -rf main
fltk:
	fltk-config --compile main.cpp