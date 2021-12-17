#include "administrador.h"

administrador::administrador(usuario x)
{
    setID(x.getID());
    setContrasena(x.getContrasena());
    setCorreo(x.getCorreo());
    setNombre(x.getNombre());
    setTiempo(x.getTiempo());
    setRecursos(x.getRecursos());
    setTelefono(x.getTelefono());
    setRol(x.getRol());
    list<usuario>usuarios_=x.getListaUser();
}

administrador::~administrador()
{
    //dtor
}

bool administrador::validarUser(){
    list<usuario>::iterator it;
    bool encontrado=false;

    for (it = usuarios_.begin(); it != usuarios_.end(); ++it){
		if(it->getID()==getID()||it->getCorreo()==getCorreo()||it->getNombre()==getNombre()||it->getTelefono()==getTelefono())
            encontrado=true;
	}
	return encontrado;
}

bool administrador::crearUsuario(usuario x)
{
	if(!validarUser()){
        ofstream fich("usuarios.txt",ios::app);//ios::app agrega al final
        if (!fich){
        cout<<"Error al abrir el fichero usuarios.txt\n";
        return false;
        }
        else {
            fich<<getID()<<" "<<getContrasena()<<" "<<getCorreo()<<" "<<getNombre()<<" "<<getTiempo()<<" "<<getRecursos()<<" "<<getTelefono()<<" "<<getRol()<<endl;
            cout<<"Usuario guardado con exito"<<endl;
            fich.close();
            return true;
            }
    }
    else cout<<"No puede haber dos usuarios con el mismo id/correo/nombre/telefono"<<endl;
    return false;
}


string administrador::seleccionarUsuario(){

	list<usuario>::iterator it;
	usuario aux;
	bool baux;
    string id;
	cout<<"Usuarios:"<<endl;

	for (it =usuarios_.begin(); it!=usuarios_.end();it++ )
		cout<<it->getID()<<"\t";
	cout<<endl;

	cout<<"Introduce el id del usuario que quiere modificar o eliminar: ";
	do{
	cin>>id;
	baux=validarUser();
	if (!baux)
	cout<<"Usuario no encontrado, inserte el id de nuevo"<<endl;
	}while(baux);
	return id;
}
