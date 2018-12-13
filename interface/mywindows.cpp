#include "mywindows.h"

void MyWindows::savetofile()
{

    QString filter = "Turtle Files (*.turtle)";
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save turtle file"), "",
                                                    filter, &filter);
    if (!fileName.endsWith(".turtle"))
        fileName += ".turtle";

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        QTextStream stream( &file );
        stream <<  this->m_code->toPlainText() ;
        std::cout << "Save to " << fileName.toStdString() << std::endl;

    }

    {
    QString fileName("tmp.turtle");
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    QTextStream stream( &file );
    stream <<  this->m_code->toPlainText() ;
    }


}

void MyWindows::loadFromFile()
{

    QString filter = "Turtle Files (*.turtle)";
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open turtle file"), "",
                                                    filter, &filter);
    if (!fileName.endsWith(".turtle"))
        fileName += ".turtle";

    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QTextStream in(&file);
        m_code->setText(in.readAll());

    }
}


void MyWindows::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    m_code->setFont(font);

    highlighter = new Highlighter(m_code->document());

    QFile file("exemple.turtle");
    if (file.open(QFile::ReadOnly | QFile::Text))
        m_code->setPlainText(file.readAll());
}

void MyWindows::renderSvg()
{

    this->m_turtle->render();
    this->m_SVG->openFile(QFile(QString("turtle.svg" )));
}



MyWindows::MyWindows(): m_SVG(new SvgView)
{
    // Création du layout
    this->m_main_layout->addWidget(this->m_code , 0, 0, 4, 1);
    this->m_main_layout->addWidget(this->m_SVG  , 0, 2, 4, 2);

    // Sauvegarde du fichier
    this->m_main_layout->addWidget(this->m_save ,  0, 1, 1, 1);
    // Chargement du fichier
    this->m_main_layout->addWidget(this->m_load ,  1, 1, 1, 1);
    // lancement de la turtle
    this->m_main_layout->addWidget(this->m_run  ,  2, 1, 1, 1);

    // Affiche un fichier dans la zone SVG
    this->m_SVG->openFile(QFile(QString("test.svg")));
    this->m_SVG->setViewOutline(false);
    setupEditor();

    // Connexion entre les boutons et les fonctions
    QObject::connect(this->m_run , SIGNAL(clicked())  , this , SLOT(renderSvg())         );
    QObject::connect(this->m_save, SIGNAL(clicked())  , this , SLOT(savetofile())        );
    QObject::connect(this->m_load, SIGNAL(clicked())  , this , SLOT(loadFromFile())      );

}

MyWindows::~MyWindows(){
    delete m_save;
    delete m_load;
    delete m_run;
    delete m_SVG;
    delete m_code;
    delete m_main_layout;

}














