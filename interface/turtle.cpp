#include "turtle.h"

#include <QSvgGenerator>

Turtle::Turtle() : m_filename(new std::string("$tmp.turtle"))
{

}

Turtle::~Turtle()
{
    delete m_filename;
}


// fonction qui transforme le .turtle en .svg
int Turtle::render()
{
    // Run C++ to generate SVG
    system("./turtle tmp.turtle");

    return 0;
}


