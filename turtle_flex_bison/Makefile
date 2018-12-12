all:
	rm -f turtle projet.flex.cpp projet.bison.cpp projet.bison.hpp
	flex -o projet.flex.cpp turtle.flex
	bison -d turtle.bison -o projet.bison.cpp
	g++ -o turtle projet.flex.cpp projet.bison.cpp -Wall
	./turtle exemple.turtle
	cp bite.html /srv/http	

