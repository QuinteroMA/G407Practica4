#include "usuario.h"
#include "maquina.h"
#include "administrador.h"

using namespace std;


int main()
{
    usuario user;
    user.cargarUsuarios();
	int elec;
	int login=0;
	string idUser;
	string pass;
	do{
		cout<<"Introduce tu nombre de usuario: ";
		cin>>idUser;
		cout<<"Introduce tu contrase�a: ";
		cin>>pass;

        user=user.identificarse(idUser,pass);
        login=user.getRol();

    }while(login==0);

        administrador admin(user);


	if (login == 1)
	{
		do{

		cout<<"Bienvenido Administrador de usuarios: "<<endl;
		cout<<"1. Crear usuario"<<endl;
		cout<<"2. Eliminar usuario"<<endl;
		cout<<"3. Modificar usuario"<<endl;
		cout<<"4. Crear reserva"<<endl;
		cout<<"5. Eliminar reserva"<<endl;
		cout<<"6. Modificar reserva"<<endl;
		cout<<"7. Ver reservas"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Introduce la funcion que quieres realizar: ";
		cin>>elec;

		switch(elec)
		{
			case 1:
			{
                string idUsuario;
                string contrasena;
                string mail;
                string nombreCompleto;
                int tiempo, recursos, telefono,rol;
                cout<<"Introduce ID de usuario"<<endl;
                cin>>idUsuario;
                cout<<"Introduce contraseña"<<endl;
                cin>>contrasena;
                cout<<"Introduce correo de usuario"<<endl;
                cin>>mail;
                cout<<"Introduce nombre de usuario"<<endl;
                cin>>nombreCompleto;
                cout<<"Introduce tiempo máximo de reserva (en días)"<<endl;
                cin>>tiempo;
                cout<<"Introduce recursos máquimos de reserva"<<endl;
                cin>>recursos;
                cout<<"Introduce telefono de usuario"<<endl;
                cin>>telefono;
                cout<<"Introduce rol de usuario (usuario/adminUsuarios/adminMaquinas)"<<endl;
                cin>>rol;

                usuario aux(idUsuario,contrasena,mail,nombreCompleto,tiempo,recursos,telefono,rol);
                if (admin.crearUsuario(aux))
                    cout<<"Usuario anadido con exito"<<endl;
                else cout<<"No se pudo anadir el usuario"<<endl;
            }
				break;

			case 2:
			{

			}
				break;
			case 3:
            {
                string idaux;
                idaux=admin.seleccionarUsuario();

            }
				break;
            case 4:
            {

            }
				break;
            case 5:
            {
                string idreserva;
                admin.consultarReserva();
                cin>>idreserva;
                if(admin.eliminarReserva(idreserva))
                cout<<"Reserva eliminada correctamente";
            }
				break;
            case 6:
            {
                string idreserva;
                admin.consultarReserva();
                cin>>idreserva;
                if(admin.modReserva(idreserva))
                cout<<"Reserva modificada correctamente";
            }
				break;
            case 7:
            {
                admin.consultarReserva();
                cout<<"\n\n";
            }
                break;
            case 0:
                break;
			default: cout<<"Introduce una opcion valida\n";
		}
		}while(elec!=0);
	}

	else if (login == 2)
	{
		do{

		cout<<"Bienvenido Administrador de maquinas: "<<endl;
		cout<<"1. Crear Maquina"<<endl;
		cout<<"2. Eliminar Maquina"<<endl;
		cout<<"3. Modificar Maquina"<<endl;
		cout<<"4. Crear reserva"<<endl;
		cout<<"5. Eliminar reserva"<<endl;
		cout<<"6. Modificar reserva"<<endl;
		cout<<"0. Salir"<<endl;
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
			default: cout<<"Introduce una opcion valida\n";
		}
		}while(elec!=0);
	}
	else{
		do{
		cout<<"Bienvenido: "<<endl;
		cout<<"1. Crear reserva"<<endl;
		cout<<"2. Eliminar reserva"<<endl;
		cout<<"3. Modificar reserva"<<endl;
		cout<<"4. Modificar datos"<<endl;
		cout<<"5. Ver reservas"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Introduce la funcion que quieres realizar: ";
		cin>>elec;

		switch(elec)
		{
			case 1:
				break;
			case 2:
			{
                string idreserva;
                user.consultarReserva();
                cin>>idreserva;
                if(user.eliminarReserva(idreserva))
                cout<<"Reserva eliminada correctamente"<<endl<<endl;
			}
				break;
			case 3:
			{
                string idreserva;
                user.consultarReserva();
                cin>>idreserva;
                if(user.modReserva(idreserva))
                cout<<"Reserva modificada correctamente"<<endl<<endl;
			}
				break;

            case 4:
            {
            }
                break;

            case 5:
            {
                user.consultarReserva();
                cout<<"\n\n";
            }
                break;
			default: cout<<"Introduce una opcion valida\n";
		}
		}while(elec!=0);
	}

	return 0;
}
