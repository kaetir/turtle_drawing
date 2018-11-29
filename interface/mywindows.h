#ifndef MYWINDOWS_H
#define MYWINDOWS_H

#include <QtWidgets>
#include <fstream>
#include <iostream>
#include "svgview.h"
#include "turtle.h"


class MyWindows : public QWidget
{
Q_OBJECT
private:
    QGridLayout      *m_main_layout  = new QGridLayout(this);
    QFormLayout      *m_save_layout  = new QFormLayout(this);
    QLineEdit        *m_filename     = new QLineEdit(this);
    QTextEdit        *m_code         = new QTextEdit(this);
    QPushButton      *m_save         = new QPushButton("save", this);
    QPushButton      *m_run          = new QPushButton("run", this);
    SvgView          *m_SVG          ;
    // QSvgWidget       *m_SVG          = new QSvgWidget(QString("test.svg"), this);
    Turtle           *m_turtle       = new Turtle();



public slots:
    void savetofile();
    void renderSvg();

public:
    MyWindows();
    ~MyWindows();

};

#endif // MYWINDOWS_H
