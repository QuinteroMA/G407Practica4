#ifndef USUARIO_H
#define USUARIO_H

#include<string.h>
#include<iostream>
#include<fstream>
#include<list>

using namespace std;

struct reserva{
	string RUsuario_;
	string RInicio_, RFin_, RRecursos_;
};

class usuario {
private:
	string idUsuario_;
	string contrasena_;
	string mail_;
	string nombreCompleto_;
	int tiempo_, recursos_, telefono_;
	list <reserva> reservas_;


public:
	usuario();
	~usuario();

	inline void setID(string x){idUsuario_=x;};
	inline string getID(){return idUsuario_;};

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


	void crearReserva();
	void modReserva();
	void eliminarReserva();
	void cargarReserva();
	void consultarReserva();
	void consultarMaquina();
};

#endif