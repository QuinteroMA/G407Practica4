#include "usuario.h"



int diasMes(int x){
	int dias=0;
	switch(x){
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		dias=31;
	break;

	case 2:
		dias=28;
	break;

	case 4: case 6: case 9: case 11:
		dias=30;
	break;
	default:
		dias=0;
	break;
	}
	return dias;
}



usuario::usuario(){
    setID("");
    setContrasena("");
    setCorreo("");
    setNombre("");
    setTiempo(0);
    setRecursos(0);
    setTelefono(0);
}

usuario::usuario(string id, string contrasena, string mail, string nombre,  int tiempo, int recursos, int telefono, int rol){
    setID(id);
    setContrasena(contrasena);
    setRol(rol);
    setCorreo(mail);
    setNombre(nombre);
    setTiempo(tiempo);
    setRecursos(recursos);
    setTelefono(telefono);
}



void usuario::crearReserva(){

}

bool usuario::modReserva(string x){
	list<reserva>::iterator it;


	bool valido=true;
	int di,mi,ai,tiempo, recursos;
	time_t now= time(0);
	tm * time = localtime(&now);

	int year= time->tm_year+1900;
	int month=time->tm_mon+1;
	int day=time->tm_mday;

	cout<<endl<<"Fecha"<<year<<"\t"<<month<<"\t"<<day<<endl;
	cout<<endl<<"Inserta fecha de inicio (dd mm aa):"<<endl;
	do{
		valido=true;
		cin>>di;
		cin>>mi;
		cin>>ai;


		if(ai==year){
			if(mi==month){
				if(di<day)
				valido=false;
			}
			else if(mi<month) valido=false;
		}
		else if(ai<year) valido=false;

		if(!valido) cout<<endl<<"La fecha de inicio de la reserva no es válida, insertela de nuevo."<<endl;
	}while(!valido);

	cout<<endl<<"Cuantos días vas a reservar?"<<endl;

	do{
		cin>>tiempo;
		if(tiempo<1 || tiempo>getTiempo())
			cout<<"El tiempo no es válido, inserte de nuevo."<<endl;
	}while(tiempo<1 || tiempo>getTiempo());

	for (it = reservas_.begin(); it != reservas_.end(); ++it){
		if (it->RID_==x && (it->RUsuario_==getID()||getRol()==1)){
			cout<<endl<<"Inserta cuantos recursos deseas reservar."<<endl;
			do{
				cin>>recursos;
				if(recursos>(it->RRecursos_+getRecursos()))
					cout<<endl<<"No puedes reservar tantos recursos."<<endl<<"Recursos disponibles: "<<it->RRecursos_+getRecursos()<<endl;
			}while(recursos>(it->RRecursos_+getRecursos()));

			it->RRecursos_ =recursos;
			it->iDia_ = di;
			it->iMes_ =mi;
			it->iAno_ =ai;
			di=di+tiempo;
			while(di>diasMes(mi)){
				di=di-diasMes(mi)-1;
				mi=mi+1;
				if(mi>12){
					mi=1;
					ai=ai+1;
				}
			}
			it->fDia_ =di;
			it->fMes_ =mi;
			it->fAno_ =ai;
			return true;
		}
	}
	return false;
}

bool usuario::eliminarReserva(string x){
	list<reserva>::iterator it;
	for (it = reservas_.begin(); it != reservas_.end(); ++it){
		if (it->RID_==x && (it->RUsuario_==getID()||getRol()==1)){
			reservas_.erase(it);
			return true;
		}
	}
	return false;
}

void usuario::cargarReserva(){

	reservas_.clear();
		ifstream fiche("reservas.txt");
		if (!fiche.is_open())
		  {
		    cout << "Error al abrir ejemplo.dat\n";
		    exit(EXIT_FAILURE);
		  }
		string user, id, Saux;
		int idi,im,ia,fi,fm,fa, recur;
		reserva aux;
		getline(fiche,user,',');
		while (!fiche.eof()){
			getline(fiche,id,',');
			getline(fiche,Saux,'/');
			idi=stoi(Saux);
			getline(fiche,Saux,'/');
			im=stoi(Saux);
			getline(fiche,Saux,',');
			ia=stoi(Saux);
			getline(fiche,Saux,'/');
			fi=stoi(Saux);
			getline(fiche,Saux,'/');
			fm=stoi(Saux);
			getline(fiche,Saux,',');
			fa=stoi(Saux);
			getline(fiche,Saux,'\n');
			recur=stoi(Saux);
			aux.RUsuario_=user;
			aux.RID_=id;
			aux.iDia_=idi;
			aux.iMes_=im;
			aux.iAno_=ia;
			aux.fDia_=fi;
			aux.fMes_=fm;
			aux.fAno_=fa;
			aux.RRecursos_=recur;
			reservas_.push_back(aux);	//Añadir la nueva reserva al final de la lista

			getline(fiche,user,',');
		}
	fiche.close();
}


void usuario::consultarReserva(){
	list<reserva>::iterator it;
	cout<<"Id reserva \t Fecha de inicio \t Fecha de finalización \t Recursos reservados\n";
	for (it = reservas_.begin(); it != reservas_.end(); ++it){
		if(it->RUsuario_==getID()||getRol()==1){
			cout<<it->RID_<<"\t"<<it->iDia_<<"/"<<it->iMes_<<"/"<<it->iAno_<<"\t"
			<<it->fDia_<<"/"<<it->fMes_<<"/"<<it->fAno_<<"\t"<<it->RRecursos_<<endl;
		}
	}
}

void usuario::consultarMaquina(){

}

void usuario::modificarUsuario()
{
	int seleccion;
	string mod;
	int modn;
	string answ = "no";
	vector<usuario> u;
	int i = 0;
	usuario aux;
	ifstream fich("usuarios.txt");
		if (!fich)
		{cout<<"Error al abrir el fichero usuarios.txt\n";}
		else
		{
			while (!fich.eof())
			{
                string saux;
                int iaux;
                fich>>saux;
                aux.setID(saux);
                fich>>saux;
                aux.setContrasena(saux);
                fich>>saux;
                aux.setCorreo(saux);
                fich>>saux;
                aux.setNombre(saux);
                fich>>saux;
                iaux=stoi(saux);
                aux.setTiempo(iaux);
                fich>>saux;
                iaux=stoi(saux);
                aux.setRecursos(iaux);
                fich>>saux;
                iaux=stoi(saux);
                aux.setTelefono(iaux);
                fich>>saux;
                iaux=stoi(saux);
                aux.setRol(iaux);

			}

		cout << "Para contestar hagalo siempre de la siguiente forma: " << endl;
		cout << "Para respuesta afirmativa: si" << endl;
		cout << "Para respuesta negativa: no" << endl;

		cout<<"Quieres editar la contraseña del usuario "<<seleccion<<"? ";
		cin>>answ;

		if (answ == "si"){
			cout << "Introduce la nueva contraseña para el usuario " <<seleccion;
			cin>>mod;
			for (int j = 0;j<i;j++)
			{
				if (u[j].idUsuario_ == seleccion){
					u[j].contrasena_ = mod;
				}
			}
		}

		cout<<"Quieres editar el mail del usuario "<<seleccion<<"? ";
		cin>>answ;

		if (answ == "si"){
			cout << "Introduce el nuevo mail para el usuario " <<seleccion;
			cin>>mod;
			for (int j = 0;j<i;j++)
			{
				if (u[j].idUsuario_ == seleccion){
					u[j].mail_ = mod;
				}
			}
		}

		cout<<"Quieres editar el nombre completo del usuario "<<seleccion<<"? ";
		cin>>answ;

		if (answ == "si"){
			cout << "Introduce el nuevo nombre completo para el usuario " <<seleccion;
			cin>>mod;
			for (int j = 0;j<i;j++)
			{
				if (u[j].idUsuario_ == seleccion){
					u[j].nombreCompleto_ = mod;
				}
			}
		}

		cout<<"Quieres editar el tiempo del usuario "<<seleccion<<"? ";
		cin>>answ;

		if (answ == "si"){
			cout << "Introduce el nuevo tiempo para el usuario " <<seleccion;
			cin>>modn;
			for (int j = 0;j<i;j++)
			{
				if (u[j].idUsuario_ == seleccion){
					u[j].tiempo_ = modn;
				}
			}
		}

		cout<<"Quieres editar los recursos del usuario "<<seleccion<<"? ";
		cin>>answ;

		if (answ == "si"){
			cout << "Introduce los nuevos recursos para el usuario " <<seleccion;
			cin>>modn;
			for (int j = 0;j<i;j++)
			{
				if (u[j].idUsuario_ == seleccion){
					u[j].recursos_ = modn;
				}
			}
		}

		cout<<"Quieres editar el telefono del usuario "<<seleccion<<"? ";
		cin>>answ;

		if (answ == "si"){
			cout << "Introduce el nuevo telefono para el usuario " <<seleccion;
			cin>>modn;
			for (int j = 0;j<i;j++)
			{
				if (u[j].idUsuario_ == seleccion){
					u[j].telefono_ = modn;
				}
			}
		}

		fich.close();
}

void usuario::cargarUsuarios(){
    usuario aux;
	ifstream fich("usuarios.txt");
	while (!fich.eof())	{
		string saux;
        int iaux;
        fich>>saux;
        aux.setID(saux);
        fich>>saux;
        aux.setContrasena(saux);
        fich>>saux;
        aux.setCorreo(saux);
        fich>>saux;
        aux.setNombre(saux);
        fich>>saux;
        iaux=stoi(saux);
        aux.setTiempo(iaux);
        fich>>saux;
        iaux=stoi(saux);
        aux.setRecursos(iaux);
        fich>>saux;
        iaux=stoi(saux);
        aux.setTelefono(iaux);
        fich>>saux;
        iaux=stoi(saux);
        aux.setRol(iaux);
		usuario_.push_back(aux);
	}
	fich.close();
}

usuario usuario::identificarse(string username, string passw) {

    list<usuario>::iterator it;
	bool res=false;
	usuario aux;
	for(it = usuario_.begin(); it != usuario_.end(); ++it){
		if (it->getID()==username && it->getContrasena() == passw)
			aux = *it;
	}
    return aux;
}
