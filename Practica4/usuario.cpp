#include "usuario.h"
#include "maquina.h"

usuario::usuario(){
	
}

void usuario::crearReserva(){

}

void usuario::modReserva(){

}

void usuario::eliminarReserva(){

}

void usuario::consultarReserva(){
	
	//iftream fich(idUsuario_+".dat");
	fich.open(idUsuario_+"_reservas.txt", ios::in);

  if (!fich.is_open())
  {
    cout << "Error al abrir el fichero de reservas\n";
    exit(EXIT_FAILURE);
  }

    char idmaquina[255],tInicio[255],tFinal[255],recursos[255];
    cout<<"Máquina:	Fecha de inicio:	Fecha final:	Recursos:"<<endl;                          
    while(f.getline(idmaquina, 255, ',')){ 
        fiche.getline(tInicio, 255, ',');
        fiche.getline(tFinal, 255, ',');
        fiche.getline(recursos, 255, '\n');
        cout<<idmaquina<<"\t"<<tInicio<<"\t"<<tFinal<<"\t"<<recursos<<endl;
    }
    f.close();
}

void usuario::consultarMaquina(){
}