#include "sistema.h"
#include <vector>

	sistema::sistema(string name, string pass){
		setUser(name);
		setPass(pass);
	}
	
	void sistema::setUser(string name)
	{
		user=name;
	}
	
	void sistema::setPass(string password)
	{
		pass = password;
	}

/*	string sistema::identificarse()
	{
		ifstream fich("usuarios.txt");
		if (!fich)
		{cout<<"Error al abrir el fichero usuarios \n";}
		else
		{
			bool res = false;
			vector<usuario> info;
			usuario aux;
			int i =0;
			while (!fich.eof())
			{
				fich>>aux.idUsuario_;
				fich>>aux.contrasena_;
				fich>>aux.mail_;
				fich>>aux.nombreCompleto_;
				fich>>aux.tiempo_;
				fich>>aux.recursos_;
				fich>>aux.telefono_;
				fich>>aux.rol_;
				info.push_back(aux);
				i++;
			}
			
			for(int j=0;j<i;j++)
			{
				if (info[j].idUsuario_==user && info[j].contrasena_ == pass)
				{
					res==true;
					return info[j].getID();	
				}
			}
			if (res == false)
			{
				return "";
			}
			
			fich.close();
		}
	}*/
	
	void sistema::guardarDatos()
	{
		
	}
	void sistema::modificarDatos()
	{
		
	}
	void sistema::introducirDatos()
	{
		
	}
	void sistema::confirmarDatos()
	{
		
	}

