#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"

class administrador : public usuario
{

    private:

    public:
        administrador();
        ~administrador();

    void crearUsuario();

	int seleccionarUsuario();
};

#endif // ADMINISTRADOR_H
