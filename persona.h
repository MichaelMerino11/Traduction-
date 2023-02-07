#ifndef PERSONA_H
#define PERSONA_H
#include <QTranslator>
#include <QObject>

class Persona : public QObject
{
    Q_OBJECT
public:
    explicit Persona(QObject *parent = nullptr);
    Persona(const QString &nombre, const QString &apellido, const QString &telefono, const QString &email);

    const QString &nombre() const;
    void setNombre(const QString &newNombre);

    const QString &apellido() const;
    void setApellido(const QString &newApellido);

    const QString &telefono() const;
    void setTelefono(const QString &newTelefono);

    const QString &email() const;
    void setEmail(const QString &newEmail);

private:
    QString m_nombre;
    QString m_apellido;
    QString m_telefono;
    QString m_email;

signals:

};

#endif // PERSONA_H
