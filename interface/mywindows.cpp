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

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        in >> code.;
        if (contacts.isEmpty()) {
            QMessageBox::information(this, tr("No contacts in file"),
                                     tr("The file you are attempting to open contains no contacts."));
        } else {
            QMap<QString, QString>::iterator i = contacts.begin();
            nameLine->setText(i.key());
            addressText->setText(i.value());
        }
    }

    updateInterface(NavigationMode);
}

void MyWindows::renderSvg()
{
    this->savetofile();
    //this->m_turtle->render(this->m_filename->text().toStdString());
    //this->m_SVG->openFile(QFile(QString(this->m_filename->text() + ".svg" )));
}



MyWindows::MyWindows(): m_SVG(new SvgView)
{

    // Création du layout
    this->m_main_layout->addWidget(this->m_code         , 0, 0, 4, 1);
    this->m_main_layout->addLayout(this->m_save_layout  , 0, 1, 4, 1);
    this->m_main_layout->addWidget(this->m_run          , 2, 1, 1, 1);
    this->m_main_layout->addWidget(this->m_SVG          , 0, 2, 4, 2);

    // Sauvegarde du fichier
    // this->m_save_layout->addRow("code file",this->m_filename);
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
    //delete m_filename;
    delete m_save_layout;
    delete m_main_layout;

}














