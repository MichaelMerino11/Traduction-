#ifndef EDIT_H
#define EDIT_H
#include <QTranslator>
#include <QDialog>
#include <QMessageBox>
#include "persona.h"
#include "personadialog.h"


namespace Ui {
class editpersona;
}

class editpersona : public QDialog
{
    Q_OBJECT

public:
    explicit editpersona(QWidget *parent = nullptr);
    Persona *persona() const;
    ~editpersona();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::editpersona *ui;
    Persona *m_persona;
};

#endif // EDIT_H
