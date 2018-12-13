all:
	rm -f turtle projet.flex.cpp projet.bison.cpp projet.bison.hpp
	flex -o projet.flex.cpp turtle.flex
	bison -d turtle.bison -o projet.bison.cpp
	g++ -o turtle projet.flex.cpp projet.bison.cpp  -Wall
	
	./turtle exemple.turtle
	
	cp turtle ../build-turtle_drawing-Desktop_Qt_5_11_2_GCC_64bit-Release
	cp  turtle.svg /srv/http/bite.html	
	#cp bite.html /srv/http	

