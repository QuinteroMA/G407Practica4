#ifndef USUARIO_H
#define USUARIO_H

#include<string.h>

using namespace std;

class usuario {
private:
	string idUsuario_;
	string contraseña_;
	string mail_;
	string nombreCompleto_;
	int tiempo_, recursos_, telefono_;

public:
	inline void setID(string x){idUsuario_=x;};
	inline string getID(){return idUsuario_;};

	inline void setContraseña(string x){contraseña_=x;};
	inline string getContraseña(){return contraseña_;};

	inline void setCorreo(string x){mail_=x;};
	inline string getCorreo(){return mail_;};

	inline void setNombre(string x){nombreCompleto_=x;};
	inline string getNombre(){return nombreCompleto_;};

	inline void setTiempo(int x){tiempo_=x;};
	inline int getTiempo(){return tiempo_;};

	inline void setRecursos(int x){recursos_=x;};
	inline int getRecursos(){return recursos_;};

	inline void setTelefono(int x){telefono_=x;};
	inline int getTelefono(){return telefono_;};


	void crearReserva();
	void modReserva();
	void eliminarReserva();
	void consultarReserva();
	void consultarMaquina();
};

#endif