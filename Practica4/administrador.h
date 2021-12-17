#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"

class administrador : public usuario
{

    private:
    list<usuario>usuarios_;

    public:
        administrador(usuario x);
        ~administrador();

    bool validarUser();
    bool crearUsuario(usuario x);
	string seleccionarUsuario();
};

#endif // ADMINISTRADOR_H
