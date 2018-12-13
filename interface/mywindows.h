#ifndef MYWINDOWS_H
#define MYWINDOWS_H

#include <QtWidgets>
#include <fstream>
#include <iostream>
#include "svgview.h"
#include "turtle.h"
#include "highlighter.h"

class MyWindows : public QWidget
{
Q_OBJECT
private:
    QGridLayout      *m_main_layout  = new QGridLayout(this);
    QFileDialog      *file_save      = new QFileDialog(this, "Choose file to save");
    QTextEdit        *m_code         = new QTextEdit(this);
    QPushButton      *m_save         = new QPushButton("save", this);
    QPushButton      *m_load         = new QPushButton("load", this);
    QPushButton      *m_run          = new QPushButton("run" , this);

    // Custom
    Highlighter      *highlighter    ;
    SvgView          *m_SVG          ;
    Turtle           *m_turtle       = new Turtle();


    void setupEditor();


public slots:
    void savetofile();
    void loadFromFile();
    void renderSvg();


public:
    MyWindows();
    ~MyWindows();

};

#endif // MYWINDOWS_H
