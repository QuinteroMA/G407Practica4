#ifndef MAQUINA_H
#define MAQUINA_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

class maquina {
private:
	int id, recursos;
public:
	maquina();
	maquina(int i,int resources);

	inline void setId(int x){id=x;};
	inline int getId(){return id;};

	inline void setRecursos(int x){recursos=x;};
	inline int getRecursos(){return recursos;};

	void crearMaquina();
	bool comprobarMaquina();
	void modificarMaquina();
	void eliminarMaquina();
	int selecMaquina();
	void selecFecha();
	void confirmarReserva();
	void consultarFecha();
};

#endif
