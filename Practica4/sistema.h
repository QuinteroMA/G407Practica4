#ifndef SISTEMA_H
#define SISTEMA_H

#include usuario.h
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class sistema {
private:
string user;
string pass;		
public:
	sistema();
	sistema(string name, string pass);
	void setUser(string);
	void setPass(string);
	
	void guardarDatos();
	void modificarDatos();
	void introducirDatos();
	void confirmarDatos();
};

#endif
