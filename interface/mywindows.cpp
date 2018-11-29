#include "mywindows.h"

void MyWindows::savetofile()
{
    std::ofstream file (this->m_filename->text().toStdString() + ".turlte", std::ofstream::out);
    file << this->m_code->toPlainText().toStdString();

    std::cout << "Save to " << this->m_filename->text().toStdString() << ".turtle" << std::endl;

}

void MyWindows::renderSvg()
{
    this->savetofile();
    this->m_turtle->render(this->m_filename->text().toStdString());
    this->m_SVG->openFile(QFile(QString(this->m_filename->text() + ".svg" )));
}

MyWindows::MyWindows(): m_SVG(new SvgView)
{

    // Création du layout
    this->m_main_layout->addWidget(this->m_code         , 0, 0, 4, 1);
    this->m_main_layout->addLayout(this->m_save_layout  , 0, 1, 4, 1);
    this->m_main_layout->addWidget(this->m_run          , 2, 1, 1, 1);
    this->m_main_layout->addWidget(this->m_SVG          , 0, 2, 4, 2);

    // Sauvegarde du fichier
    this->m_save_layout->addRow("code file",this->m_filename);
    this->m_save_layout->addRow(" ",this->m_save);

    // Affiche un fichier dans la zone SVG
    this->m_SVG->openFile(QFile(QString("test.svg")));
    this->m_SVG->setViewOutline(false);

    // Connexion entre les boutons et les fonctions
    QObject::connect(this->m_run , SIGNAL(clicked())  , this , SLOT(renderSvg())         );
    QObject::connect(this->m_save, SIGNAL(clicked())  , this , SLOT(savetofile())   );

}

MyWindows::~MyWindows(){
    delete m_save;
    delete m_run;
    delete m_SVG;
    delete m_code;
    delete m_filename;
    delete m_save_layout;
    delete m_main_layout;

}














