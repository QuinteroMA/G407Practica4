#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

struct login{
	string username;
	string passw;
	int id;
	int rol;
};

class sistema {
private:
string user;
string pass;		
public:
	sistema();
	sistema(string name, string pass);
	void setUser(string);
	void setPass(string);
	
	int identificarse();
	void guardarDatos();
	void modificarDatos();
	void introducirDatos();
	void confirmarDatos();
};

#endif
