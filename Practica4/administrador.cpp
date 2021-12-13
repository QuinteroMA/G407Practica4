#include "administrador.h"

administrador::administrador()
{
    //ctor
}

administrador::~administrador()
{
    //dtor
}

void administrador::crearUsuario()
{
	ofstream fich("usuarios.txt",ios::app);//ios::app agrega al final
		if (!fich)
		{cout<<"Error al abrir el fichero usuarios.txt\n";}
		else
		{
			fich<<getID()<<","<<getContrasena()<<","<<getNombre()<<","<<getRol()<<","<<getCorreo()<<","<<getTiempo()<<","<<getRecursos()<<","<<getTelefono()<<endl;
			cout<<"Usuario guardado con exito"<<endl;
			fich.close();
		}

}


int administrador::seleccionarUsuario(){
	int i = 0;
	list<usuario> u;
	usuario aux;
	ifstream fich("usuarios.txt");
	if (!fich)
	{cout<<"Error al abrir el fichero usuarios.txt\n";}
	else
	{
		while (!fich.eof())
			{
				/*fich>>aux.setID();
				fich>>aux.setContrasena();
				fich>>aux.setNombre();
				fich>>aux.setRol();
				fich>>aux.setCorreo();
				fich>>aux.setTiempo();
				fich>>aux.setRecursos();
				fich>>aux.setTelefono();
				u.push_back(aux);*/
				i++;
			}
		for (int j = 0;j<(i-1);j++)
		{
			/*cout <<"Id del Usuario: "<<u[j].idUsuario_<<endl;
			cout <<" -> Contraseña del usuario: "<<u[j].contrasena_<<endl;
			cout <<" -> Mail del usuario: "<<u[j].mail_<<endl;
			cout <<" -> Nombre completo del usuario: "<<u[j].nombreCompleto_<<endl;
			cout <<" -> Tiempo del usuario: "<<u[j].tiempo_<<endl;
			cout <<" -> Recursos del usuario: "<<u[j].recursos_<<endl;
			cout <<" -> telefono_ del usuario: "<<u[j].telefono_<<endl;*/
		}
		cout<<"Introduce el id del usuario que quiere modificar o eliminar: ";
		cin>>i;
	}
	fich.close();
	return i;
}
