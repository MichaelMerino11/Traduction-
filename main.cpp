#include "principal.h"
#include <QTranslator>
#include <QInputDialog>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    QTranslator T;
    QStringList langs;
    langs << "Español" << "Portugues" << "English";
    const QString lang = QInputDialog::getItem(NULL,
                         "Language",
                         "Select a language",
                         langs);
    if(lang=="Portugues"){
        T.load(":/portugues.qm");
    }else if(lang=="English"){
        T.load(":/ingles.qm");
    }
    if(lang!="Español"){
        a.installTranslator(&T);
    }
    Principal w;
    w.show();
    return a.exec();
}
