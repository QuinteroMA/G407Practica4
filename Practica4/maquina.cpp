
#include "maquina.h"
	
maquina::maquina(){
setId(0);
setRecursos(0);
}

maquina::maquina(int i,int resources){
setId(i);
setRecursos(resources);
}

void maquina::crearMaquina()
{
	ofstream fich("maquinas.txt",ios::app);//ios::app agrega al final
		if (!fich)
		{cout<<"Error al abrir el fichero maquinas.txt\n";}
		else
		{
			fich<<id<<" "<<recursos<<endl;
			cout<<"M�quina guardada"<<endl;
			fich.close();
		}
		
}

void maquina::modificarMaquina()
{
	int seleccion = selecMaquina();
	int mod;
	int i = 0;
	vector<maquina> m;
	maquina aux;
	ifstream fich("maquinas.txt");
		if (!fich)
		{cout<<"Error al abrir el fichero logininfo\n";}
		else
		{
			while (!fich.eof())
			{
				fich>>aux.id;
				fich>>aux.recursos;
				m.push_back(aux);
				i++;
			}
		
		cout<<"Cuantos recursos tiene la maquina con Id: "<<seleccion<<"? ";
		cin>>mod;
		
		for (int j = 0;j<i;j++)
		{
			if (m[j].id == seleccion)
			{
				m[j].recursos = mod;
			}
		}
		fich.close();
	    ofstream fich2("maquinas.txt",ios::out);
		if (!fich2)
		{cout<<"Error al abrir el fichero maquinas.txt\n";}
		else
		{
			for (int j = 0;j<i;j++)
			{
				fich2<<m[j].id<<" "<<m[j].recursos<<endl;
				cout<<"M�quina actualizada"<<endl;
				fich2.close();
			}
		}
		
		}
}

int maquina::selecMaquina(){
	int c = 0;
	vector<maquina> m;
	maquina aux;
	ifstream fich("maquinas.txt");
	if (!fich)
	{cout<<"Error al abrir el fichero maquinas.txt\n";}
	else
	{
		while (!fich.eof())
			{
				fich>>aux.id;
				fich>>aux.recursos;
				m.push_back(aux);
				c++;
			}
		for (int j = 0;j<(c-1);j++)
		{
			cout<<"Id de maquina: "<<m[j].id<<" -> Recursos de la maquina: "<<m[j].recursos<<endl;
		}
		cout<<"Introduce el id de la maquina que quiere modificar o eliminar: ";
		cin>>c;
	}
	fich.close();
	return c;
}

bool maquina::comprobarMaquina()
{
	int c = 0;
	int i = 0;
	vector<maquina> m;
	maquina aux;
	ifstream fich("maquinas.txt");
	if (!fich)
	{cout<<"Error al abrir el fichero maquinas.txt\n";}
	else
	{
		while (!fich.eof())
			{
				fich>>aux.id;
				fich>>aux.recursos;
				m.push_back(aux);
				c++;
			}
		
		for (int j = 0; j<c;j++)
		{
			if (m[j].id==id)
			{
				i++;
			}
		}
		if (i==0){return true;}
		else
		{return false;}
	}
}

void maquina::selecFecha(){

}

void maquina::confirmarReserva(){

}

void maquina::consultarFecha(){

}