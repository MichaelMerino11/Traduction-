#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{
    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();

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

void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}
