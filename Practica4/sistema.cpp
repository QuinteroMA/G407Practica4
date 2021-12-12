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

	int sistema::identificarse()
	{
		ifstream fich("logininfo.txt");
		if (!fich)
		{cout<<"Error al abrir el fichero logininfo\n";}
		else
		{
			bool res = false;
			vector<login> info;
			login aux;
			int i =0;
			while (!fich.eof())
			{
				fich>>aux.username;
				fich>>aux.passw;
				fich>>aux.id;
				fich>>aux.rol;
				info.push_back(aux);
				i++;
			}
			
			for(int j=0;j<i;j++)
			{
				if (info[j].username==user && info[j].passw == pass)
				{
					res==true;
					return info[j].rol;	
				}
			}
			if (res == false)
			{
				return 0;
			}
			
			fich.close();
		}
	}
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

