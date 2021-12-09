#include "usuario.h"

usuario::usuario(){
	idUsuario_ = contrasena_ = mail_ = nombreCompleto_ = "";
	tiempo_ = recursos_ = telefono_ =0;
	reservas_.clear();
}

usuario::~usuario(){}

void usuario::crearReserva(){

}

void usuario::modReserva(){

}

void usuario::eliminarReserva(){

}

void usuario::cargarReserva(){
	
	reservas_.clear();
		ifstream fiche("reservas.txt");		//Abre fichero en modo lectura

		string user, init, fin, recur;	
		
		getline(fiche,user,',');		        //Leer fichero hasta la primera cola almacenandolo en un string

		while (!fiche.eof()){
			
			getline(fiche,init,',');
			getline(fiche,fin,',');
			getline(fiche,recur,'\n');
			
			if (user==getID()){
			reserva aux;
			aux.RUsuario_=user;
			aux.RInicio_=init;
			aux.RFin_=fin;
			aux.RRecursos_=recur;

			reservas_.push_back(aux);	//Añadir la nueva reserva al final de la lista
			}

			getline(fiche,user,',');		//Si en la ultima vuelta no hace esto no llega 
											//al final y vuelve a recorer el while lo que proboca error
		}
	fiche.close();
}

void usuario::consultarReserva(){
	cargarReserva();
	list<reserva>::iterator it;
	cout<<"Fecha de inicio \t Fecha de finalización \t Recursos reservados\n";
	for (it = reservas_.begin(); it != reservas_.end(); ++it){
			cout<<it->RInicio_<<"\t"<<it->RFin_<<"\t"<<it->RRecursos_<<endl;
		}
}

void usuario::consultarMaquina(){
}
