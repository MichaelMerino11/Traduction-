#include "edit.h"
#include "ui_edit.h"
#include <QTranslator>

editpersona::editpersona(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editpersona)
{
    ui->setupUi(this);
}

editpersona::~editpersona()
{
    delete ui;
}

Persona *editpersona::persona() const
{
    return m_persona;
}

void editpersona::on_buttonBox_accepted()
{
    QString nombre = ui->nombre->text();
    QString apellido = ui->apellido->text();
    QString telefono = ui->telefono->text();
    QString email = ui->email->text();
    bool valid=false;

    QMessageBox adv;
    adv.setIcon(QMessageBox::Warning);
    adv.setWindowTitle("Registro de informacion");

    if(nombre.isEmpty()&&apellido.isEmpty()&&telefono.isEmpty()&&email.isEmpty())
    {
        adv.setText("No existen registros de datos"); adv.exec();
        return;
    }

    if(nombre.isEmpty() || apellido.isEmpty() || telefono.isEmpty() || email.isEmpty())
    {
        adv.setText("No existen registros de datos"); adv.exec();
        return;
    }

    for(int i=0; i<nombre.length(); i++)
    {
        if(nombre[i].isDigit())
        {
            adv.setText("Se ha producido un error. Registre nuevamente el Nombre"); adv.exec();
            return;
        }
    }

    for(int i=0; i<apellido.length(); i++)
    {
        if(apellido[i].isDigit())
        {
            adv.setText("Se ha producido un error. Registre nuevamente el Apellido"); adv.exec();
            return;
        }
    }

    for(int i=0; i<telefono.length(); i++)
    {
        if(!telefono[i].isDigit())
        {
            adv.setText("Se ha producido un error. Registre nuevamente el Telefono"); adv.exec();
            return;
        }
    }

    for(int i=0; i<email.length(); i++)
    {
        if(email[i]=="@")
        {
            for(int j=i; j<email.length(); j++)
            {
                if(email[j] == ".")
                    valid = true;
            }
        }
    }

    if(!valid)
    {
        adv.setText("Se ha producido un error. Registre nuevamente el Correo"); adv.exec();
        return;
    }

    this->m_persona = new Persona(nombre, apellido, telefono, email);

    accept();
}


void editpersona::on_buttonBox_rejected()
{
    reject();
}

