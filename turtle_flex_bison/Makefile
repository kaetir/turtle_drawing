all:
	rm  turtle projet.flex.cpp projet.bison.cpp projet.bison.hpp
	flex -o projet.flex.cpp turtle.flex
	bison -d turtle.bison -o projet.bison.cpp
	g++ -o turtle projet.flex.cpp projet.bison.cpp -w
	./turtle exemple.turtle
	

