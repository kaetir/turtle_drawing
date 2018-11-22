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
    int render(const std::string  &filename);

    std::string *filename() const;
    void setFilename(std::string *filename);

};

#endif // TURTLE_H
