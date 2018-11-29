#include "turtle.h"

#include <QSvgGenerator>
std::string *Turtle::filename() const
{
    return m_filename;
}

void Turtle::setFilename(std::string *filename)
{
    m_filename = filename;
}

Turtle::Turtle()
{

}

Turtle::~Turtle()
{
    delete m_filename;
}

Turtle::Turtle(const std::string &filename)
{
    setFilename(new std::string(filename));
}

// fonction qui transforme le .turtle en .svg
int Turtle::render()
{

    // check if the code is corect in file filename.turtle


    // transform it to C++ code




    // Run C++ to generate SVG


    return 0;
}



int Turtle::render(const std::string &filename)
{
    setFilename(new std::string(filename));
    render();
    return 0;
}
