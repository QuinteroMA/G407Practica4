
#include "maquina.h"
#include "usuario.h"
using namespace std;


int main()
{
	usuario login;
	int elec;
	string user;
	string pass;
	do{
		cout<<"Introduce tu nombre de usuario: ";
		cin>>user;
		cout<<"Introduce tu contrase�a: ";
		cin>>pass;
		
		login = login.identificarse(user,pass);
		
	}while(login.getRol() ==0);
	
	if (login.getRol() ==1)
	{
		do{
		
		cout<<"Bienvenido Administrador de usuarios: "<<endl;
		cout<<"1. "<<endl;
		cout<<"2. "<<endl;
		cout<<"3. "<<endl;
		cout<<"Introduce la funcion que quieres realizar: ";
		cin>>elec;
		
		switch(elec)
		{
			case 1: 
				break;
			case 2:
				break;
			case 3: 
				break;
			default: cout<<"Introduce una opcion valida\n";
		}
		}while(elec!=5);
	}
	else if (login.getRol() ==2)
	{	
		do{
		
		cout<<"Bienvenido Administrador de maquinas: "<<endl;
		cout<<"1. "<<endl;
		cout<<"2. "<<endl;
		cout<<"3. Crear M�quina"<<endl;
		cout<<"4. Modificar M�quina"<<endl;
		cout<<"5. Eliminar M�quina"<<endl;
		cout<<"Introduce la funcion que quieres realizar: ";
		cin>>elec;
		
		switch(elec)
		{
			case 1:cout<<"Introduce una opcion valida\n";
				break;
			case 2:cout<<"Introduce una opcion valida\n";
				break;
			case 3: 
			{
				int id,recursos;
			cout<<"Introduce el Id de la nueva m�quina: ";
			cin>>id;
			cout<<"Intruce los recursos que posee la nueva maquina: ";
			cin>>recursos;
			
			maquina m(id,recursos);
			if (m.comprobarMaquina())
			{
				m.crearMaquina();
			}
			else
			{
				cout<<"No puede haber 2 m�quinas con el mismo id"<<endl;
			}
			
			}
				break;
				
			case 4: 
			{
				maquina m(0,0);
				m.modificarMaquina();
			}
				break;
			case 5: 
			{
				maquina m(0,0);
				m.eliminarMaquina();
			}
				break;
			default: cout<<"Introduce una opcion valida\n";
		}
		}while(elec!=6);
	}
	else{
		do{
		cout<<"Bienvenido: "<<endl;
		cout<<"1. "<<endl;
		cout<<"2. "<<endl;
		cout<<"3. "<<endl;
		cout<<"Introduce la funcion que quieres realizar: ";
		cin>>elec;
		
		switch(elec)
		{
			case 1:
				break;
			case 2:
				break;
			case 3: 
				break;
			default: cout<<"Introduce una opcion valida\n";
		}
		}while(elec!=5);
	}
	
	return 0;
}
