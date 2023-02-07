#include "persona.h"
#include <QTranslator>

Persona::Persona(QObject *parent)
    : QObject{parent}
{

}

Persona::Persona(const QString &nombre, const QString &apellido, const QString &telefono, const QString &email) :
    m_nombre(nombre),
    m_apellido(apellido),
    m_telefono(telefono),
    m_email(email)
{}

const QString &Persona::nombre() const
{
    return m_nombre;
}

void Persona::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
}

const QString &Persona::apellido() const
{
    return m_apellido;
}

void Persona::setApellido(const QString &newApellido)
{
    m_apellido = newApellido;
}

const QString &Persona::telefono() const
{
    return m_telefono;
}

void Persona::setTelefono(const QString &newTelefono)
{
    m_telefono = newTelefono;
}

const QString &Persona::email() const
{
    return m_email;
}

void Persona::setEmail(const QString &newEmail)
{
    m_email = newEmail;
}
