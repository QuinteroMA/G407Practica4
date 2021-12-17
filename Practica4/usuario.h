#ifndef USUARIO_H
#define USUARIO_H

#include<sstream>
#include<string.h>
#include<iostream>
#include<fstream>
#include<ctime>
#include<list>

using namespace std;

struct reserva{
	string RUsuario_, RID_;
	int RRecursos_;
	int iDia_, iMes_, iAno_, fDia_, fMes_, fAno_;

};

class usuario {
private:
	string idUsuario_;
	string contrasena_;
	string mail_;
	string nombreCompleto_;
	int tiempo_, recursos_, telefono_,rol_;
	list <reserva> reservas_;
	list<usuario> usuario_;


public:
	usuario();
	usuario(string id, string contrasena, string mail, string nombre,  int tiempo, int recursos, int telefono, int rol);

	inline void setID(string x){idUsuario_=x;};
	inline string getID(){return idUsuario_;};

	inline void setRol(int x){rol_=x;};
	inline int getRol(){return rol_;};

	inline void setContrasena(string x){contrasena_=x;};
	inline string getContrasena(){return contrasena_;};

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

    inline list<usuario> getListaUser(){return usuario_;};

	void crearReserva();
	bool modReserva(string x);
	bool eliminarReserva(string x);
	void cargarReserva();
	usuario identificarse(string username, string passw);
	void cargarUsuarios();
	void consultarReserva();
	void consultarMaquina();
    void modificarUsuario();
};

#endif
