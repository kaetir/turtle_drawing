#ifndef TURTLE_H
#define TURTLE_H

#include <string>

class Turtle
{
   std::string *m_filename;

public:
    Turtle();
    ~Turtle();
    Turtle(const std::string  &filename);


    int render();
    std::string *filename() const;

};

#endif // TURTLE_H
