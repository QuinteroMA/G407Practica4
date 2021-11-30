#ifndef MAQUINA_H
#define MAQUINA_H

using namespace std;

class maquina {
private:
	int id_, recursos_;
public:
	maquina();

	inline void setId(int x){id_=x;};
	inline int getId(){return id_;};

	inline void setRecursos(int x){recursos_=x;};
	inline int getRecursos(){return recursos_;};

	void selecMaquina();
	void selecFecha();
	void confirmarReserva();
	void consultarFecha();
};

#endif