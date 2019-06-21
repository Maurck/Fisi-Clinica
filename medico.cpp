#include <iostream>
#include <cstring>
#include <cstdlib>
#define PARA_ELIMINAR -1
using namespace std;

struct Servicio {
	int codigo;
	char nombre[30];
	int duracion;
	double precio;
	char especialidad[50];
};
struct Medico {
	int DNI;
	char nombre[25];
	char apellidoP[25];
	char apellidoM[25];
	int telefono;
	char gmail[25];
	char centroDeEstudio[30];
	char especialidad[25];
	int  sueldo;
	char password[50];
};

void menu_principal();

void menu_medico();
void menu_medico_opciones();
void opcion_crear_medico();
bool insertar_medico_archivo(Medico user);
bool existe_medico(int codigo,Medico *user);
void opcion_mostrar_medico();
Medico *obtener_stu_archivo(int *n);
void opcion_actualizar_medico();
bool modificar_archivo_medico(Medico user);



void menu_especialidad();

void menu_servicios();
void menu_servicios_opciones();
void opcion_crear_servicio();
bool insertar_servicio_archivo(Servicio serv);
bool existe_servicio(int codigo_servicio, Servicio *serv);
void opcion_mostrar_servicio();
Servicio *obtener_st_archivo(int *n);
void opcion_actualizar_servicio();
bool modificar_archivo_servicio(Servicio serv);
void opcion_eliminar_servicio();
bool eliminar_servicio(int);
bool eliminar_servicio_fisico();


void menu_cita();

void menu_historial();

void menu_reportes();

void limpiar_pantalla();
void pausar_pantalla();
void titulo_principal();
int obtener_entero();
int obtener_entero(int, int);
bool es_entero_valido(string);
double obtener_flotante();
bool es_flotante_valido(string);


int main(void) {
	menu_principal();
	return 0;
}

void titulo_principal(void) {
	cout << "\n     ======================================================================\n";
	cout << "\t\t\t\t CLINICA FISI\n";
	cout << "     ======================================================================\n";
}
void menu_principal() {
	void menu_principal_opciones();
	bool se_repite = true;
	int opcion;

	do {
		menu_principal_opciones();
		opcion = obtener_entero();

		switch (opcion) {
			case 1:
				menu_medico();
				break;
			case 2:
				menu_especialidad();
				break;
			case 3:
				menu_servicios();
				break;
			case 4:
				menu_cita();
				break;
			case 5:
				menu_historial();
				break;
			case 6:
				menu_reportes();
				break;
			case 7:
				se_repite = false;
				break;
		}
	} while (se_repite);
}
void menu_principal_opciones(void) {
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU PRINCIPAL\n";
	cout << "\n\t\t[1]. Medicos\n";
	cout << "\t\t[2]. Especialidades\n";
	cout << "\t\t[3]. Servicios\n";
	cout << "\t\t[4]. Cita\n";
	cout << "\t\t[5]. Historial Medico\n";
	cout << "\t\t[6]. Reportes\n";
	cout << "\t\t[7]. Salir\n";
	cout << "\n\t\tIngrese una opcion: ";
}


void menu_medico() {
	bool se_repite = true;
	int opcion;
	titulo_principal();
	do{
		menu_medico_opciones();
		opcion=obtener_entero(1,4);
		switch(opcion){
			case 1:
				opcion_crear_medico();
				break;
			case 2: 
				opcion_mostrar_medico();
				break;
			case 3:
				opcion_actualizar_medico();
				break;
			case 4:
				se_repite = false;
				break;
		}
	}while(se_repite);
	
	cout << "\n\t\t\t\tMENU MEDICO\n";
	menu_medico_opciones();
	pausar_pantalla();
	
}
void menu_medico_opciones(){
	
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU MEDICOS\n";
	cout << "\n\n\t\t[1]. Crear Medico";
	cout << "\n\t\t[2]. Mostrar Medico";
	cout << "\n\t\t[3]. Actualizar Medico";
	cout << "\n\t\t[4]. Volver al menu principal\n";
	cout << "\n\t\tIngrese una opcion: ";
	
}
void opcion_crear_medico(){
	bool se_repite=true;
	Medico user;
	int tipo,DNI,Telefono,Sueldo;
	string nombre,aPaterno,aMaterno,correo,centro,tipoEspecialidad,contra,opc;
	do{
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\tingresar NUEVO MEDICO\n";
		cout << "\n\tIngresa el DNI del medico: ";
		DNI=obtener_entero();
		if(!existe_medico(DNI,&user)){
		user.DNI=DNI;
		cout << "\tIngresa el Nombre del medico: ";
		getline(cin,nombre);
		strcpy(user.nombre,nombre.c_str());
		cout << "\tIngresa el Apellido Paterno del medico: ";
		getline(cin,aPaterno);
		strcpy(user.apellidoP,aPaterno.c_str());
		cout << "\tIngresa el Apellido Materno del medico: ";
		getline(cin,aMaterno);
		strcpy(user.apellidoM,aMaterno.c_str());
		cout << "\tIngresa el NumeroTelefonico del medico: ";
		Telefono=obtener_entero();
		user.telefono=Telefono;
		cout << "\tIngresa el Correo Electronico del medico: ";
		getline(cin,correo);
		strcpy(user.gmail,correo.c_str());
		cout << "\tIngresa el Centro de estudios del medico: ";
		getline(cin,centro);
		strcpy(user.centroDeEstudio,centro.c_str());
		cout << "\t\t\t\tIngresa la especialidad del Medico: \n";
		cout << "\t\tMedicina General.....[1]\n";
		cout << "\t\tGinecologia............[2]\n";
		cout << "\t\tPedriatria.........[3]\n";
		tipo=obtener_entero(1,3);
		switch(tipo){
			case 1:
				tipoEspecialidad="Medicina General";
				strcpy(user.especialidad,tipoEspecialidad.c_str());
				break;
			case 2:
				tipoEspecialidad="Ginecologia";
				strcpy(user.especialidad,tipoEspecialidad.c_str());
				break;
			case 3:
				tipoEspecialidad="Pedriatria";
				strcpy(user.especialidad,tipoEspecialidad.c_str());
				break;
		}
		cout << "\tIngresa el sueldo del usuario en dolares : ";
		Sueldo=obtener_entero();
		user.sueldo=Sueldo;
		cout << "\tIngresa el pasword del Medico: ";
		getline(cin,contra);
		strcpy(user.password,contra.c_str());
	
		if(insertar_medico_archivo(user)){
			cout << "\n\t\t\t\t\tEl Medico fue creado con exito";
		}else{
			cout << "\n\tOcurrio un error al intentar crear el Medico" << endl;
			cout << "\tIntentelo nuevamente" << endl;
		}
	}else{
		cout << "\n\tEl Medico con DNI " << DNI << " ya existe.\n";
		cout << "\t  No puede ingresar dos Medicos con el mismo DNI" << endl;
	}
		cout <<" ";
		cout << "\n\t\t\t\tDesea seguir ingresando Medicos? [S/n]: ";
		fflush(stdin);
		getline(cin,opc);
		if(!(opc.compare("S")==0 || opc.compare("s")==0)){
			se_repite=false;
		}

	}while(se_repite);
	
}
bool insertar_medico_archivo(Medico user){
	FILE *datosMedico;
	bool agregado;
	datosMedico = fopen("datosDeMedico.dat","ab");
	if(datosMedico==NULL){
		agregado=false;	
	}else{
		fwrite(&user,sizeof(user),1,datosMedico);
		agregado=true;
		fclose(datosMedico);
	}
	return agregado;
}
bool existe_medico(int DNI,Medico *user){
	FILE* datosMedico;
	bool existe=false;
	
	datosMedico=fopen("datosDeMedico.dat","rb");
	if(!(datosMedico==NULL)){
		fread(&(*user),sizeof(*user),1,datosMedico);
		while(!feof(datosMedico)){
			if((*user).DNI==DNI){
				existe=true;
				break;
			}
			fread(&(*user),sizeof(*user),1,datosMedico);
		}
		fclose(datosMedico);
	}
	return existe;
}
void opcion_mostrar_medico(){
	Medico *medicos;
	int nro_medicos;

	limpiar_pantalla();
	titulo_principal();
	medicos = obtener_stu_archivo(&nro_medicos);

	if (nro_medicos == 0) {
		cout << "\n\tEl archivo esta vacio" << endl;
		pausar_pantalla();
	} else {

		cout << "\n\t\t\t\tUSUARIOS REGISTRADOS\n";
		cout << "\n\t   ------------------------------------------------------------\n";
		for (int i = 0; i < nro_medicos; i++) {
			if (medicos[i].DNI != PARA_ELIMINAR) {
				cout << "\t\tDNI: " << medicos[i].DNI << endl;
				cout << "\t\tNombre: " << medicos[i].nombre << endl;
				cout << "\t\tApellido Paterno: " << medicos[i].apellidoP << endl;
				cout << "\t\tApellido Materno: " << medicos[i].apellidoM << endl;
				cout << "\t\tNumero Telefonico: " << medicos[i].telefono << endl;
				cout << "\t\tCorreoElectronico: " << medicos[i].gmail << endl;
				cout << "\t\tCentro de estudio: " << medicos[i].centroDeEstudio << endl;
				cout << "\t\tTipo de usuario: " << medicos[i].especialidad << endl;
				cout << "\t\tSueldo en dolares: " << medicos[i].sueldo << endl;
				cout << "\t\tPassword: " << "********" << endl;
			}
			cout << "\n\t   ------------------------------------------------------------\n";
		}
		pausar_pantalla();
	}
	
}
Medico *obtener_stu_archivo(int *n) {
	FILE *archivo;
	Medico medico;
	Medico *medicos;
	int i;

	archivo = fopen("datosDeMedico.dat", "rb");

	if (archivo == NULL) {
		*n = 0;
		medicos = NULL;
	} else {
		fseek(archivo, 0, SEEK_END);
		*n = ftell(archivo) / sizeof(Medico);
		medicos = (Medico *)malloc((*n) * sizeof(Medico));
		fseek(archivo, 0, SEEK_SET);
		fread(&medico, sizeof(medico), 1, archivo);
		i = 0;
		while (!feof(archivo)) {
			medicos[i] = medico;
			fread(&medico, sizeof(medico), 1, archivo);
			i++;
		}
		fclose(archivo);
	}
	return medicos;
}
void opcion_actualizar_medico() {
	Medico user;
	int DNI,Telefono,Sueldo;
	bool se_repite = true;
	string respuesta, nombre, Especialidad,Contra,Apellidopaterno,ApellidoMaterno,Gmail,CE;

		do {
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\t\t\tMODIFICAR MEDICO\n";

			cout << "\n\tDNI del medico: ";
			DNI = obtener_entero();
			if (existe_medico(DNI, &user)){
				cout << "\n\tNombre del medico: " << user.nombre << endl;
				cout << "\n\tapellidoP del medico: " << user.apellidoP << endl;
				cout << "\n\tapellidoM del medico: " << user.apellidoM << endl;
				cout << "\n\ttelefono del medico: " << user.telefono << endl;
				cout << "\n\tgmail del medico: " << user.gmail << endl;
				cout << "\n\tcentroDeEstudio del medico: " << user.centroDeEstudio << endl;
				cout << "\n\tespecialidad del medico: " << user.especialidad << endl;
				cout << "\n\tsueldo del medico: " << user.sueldo << endl;
				cout << "\n\tpassword del medico: " << user.password << endl;
			

				cout << "\n\tElija los datos a modificar\n" << endl;

				cout << "\n\tNombre actual del medico: " << user.nombre << endl;
				cout << "\tDeseas modificar el nombre? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				cout << "\tNuevo nombre: ";
					getline(cin, nombre);
					strcpy(user.nombre, nombre.c_str());
				}	
				cout << "\n\tApellido Paterno actual del medico: " << user.apellidoP << endl;
				cout << "\tDeseas modificar el Apellido Paterno? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				cout << "\tNuevo Apellido Apellido Paterno: ";
					getline(cin, Apellidopaterno);
					strcpy(user.apellidoP, Apellidopaterno.c_str());
				}
		cout << "\n\tApellido Materno actual del medico: " << user.apellidoM << endl;
				cout << "\tDeseas modificar el Apellido Materno? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				cout << "\tNuevo Apellido Materno: ";
					getline(cin, ApellidoMaterno);
					strcpy(user.apellidoM, ApellidoMaterno.c_str());
				}
		cout << "\n\tTelefono actual del medico: " << user.telefono << endl;
				cout << "\tDeseas modificar el Telefono? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				cout << "\tNuevo Telefono: ";
					Telefono=obtener_entero();
					user.telefono=Telefono;
				}
		cout << "\n\tGmail actual del medico: " << user.gmail << endl;
				cout << "\tDeseas modificar el Gmail? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				cout << "\tNuevo Gmail: ";
					getline(cin, Gmail);
					strcpy(user.gmail, Gmail.c_str());
				}
		cout << "\n\tcentroDeEstudio actual del medico: " << user.centroDeEstudio << endl;
				cout << "\tDeseas modificar el centroDeEstudio? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					cout << "\tNuevo centroDeEstudio: ";
					getline(cin, CE);
					strcpy(user.centroDeEstudio, CE.c_str());
				}
		cout << "\n\tespecialidad actual del medico: " << user.especialidad << endl;
				cout << "\tDeseas modificar el especialidad? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					cout << "\tNuevo especialidad: ";
					getline(cin, Especialidad);
					strcpy(user.especialidad, Especialidad.c_str());
				}
		cout << "\n\tsueldo actual del medico: " << user.sueldo << endl;
				cout << "\tDeseas modificar el sueldo? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					cout << "\tNuevo sueldo: ";
					Sueldo=obtener_entero();
					user.sueldo=Sueldo;
				}
		cout << "\n\tpassword actual del medico: " << user.password << endl;
				cout << "\tDeseas modificar el password? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					cout << "\tNuevo password: ";
					getline(cin, Contra);
					strcpy(user.password, Contra.c_str());
				}
				cout << "\nEsta seguro que desea modificar los datos del medico? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					if (modificar_archivo_medico(user)) {
						cout << "\n\tEl medico fue modificado correctamente\n";
					} else {
						cout << "\n\tOcurrio un error al intentar modificar datos del medico\n";
						cout << "\tIntentelo nuevamente\n";
					}
				}
			} else {
				cout << "\n\tEl medico de codigo " << DNI << " no existe.\n";
			}
	
			cout << "\n\tDeseas modificar otro medico? [S/N]: ";
			getline(cin, respuesta);
			if (!(respuesta.compare("S") == 0 || respuesta.compare("s") == 0)) {
				se_repite = false;
			} 

	}while (se_repite);
}
bool modificar_archivo_medico(Medico user) {
	FILE *archivo;
	bool modificado;
	Medico medico;

	archivo = fopen("datosDeMedico.dat", "rb+");

	if (!(archivo == NULL)) {
		modificado = false;
		fread(&medico, sizeof(medico), 1, archivo);
		while (!feof(archivo)) {
			if (medico.DNI == user.DNI) {
				fseek(archivo, ftell(archivo) - sizeof(user), SEEK_SET);
				fwrite(&user, sizeof(user), 1, archivo);
				modificado = true;
				break;
			}
			fread(&medico, sizeof(medico), 1, archivo);
		}
		fclose(archivo);
	}
	return modificado;
}

void menu_especialidad() {

	int prueba;
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU USUARIOS\n";
	pausar_pantalla();
}

void menu_servicios() {
	bool se_repite = true;
	int opcion;

	do {
		menu_servicios_opciones();
		opcion = obtener_entero();

		switch (opcion) {
			case 1:
				opcion_crear_servicio();
				break;
			case 2:
				opcion_mostrar_servicio();
				break;
			case 3:
				opcion_actualizar_servicio();
				break;
			case 4:
				opcion_eliminar_servicio();
				break;
			case 5:
				se_repite = false;
				break;
		}
	} while (se_repite);
}
void menu_servicios_opciones(void) {
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU SERVICIOS\n";
	cout << "\n\t\t[1]. Crear servicio\n";
	cout << "\t\t[2]. Mostrar servicios\n";
	cout << "\t\t[3]. Actualizar servicios\n";
	cout << "\t\t[4]. Eliminar servicio\n";
	cout << "\t\t[5]. Volver al menu principal\n";
	cout << "\n\t\tIngrese una opcion: ";
}
void opcion_crear_servicio(void) {
	Servicio serv;
	bool se_repite = true;
	string respuesta;
	int codigo;
	string nombre, especialidad;

	do {
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\tCREAR NUEVO SERVICIO\n";

		cout << "\tIngresa el Codigo de servicio: ";
		codigo = obtener_entero();
		if (!existe_servicio(codigo, &serv)) {
			serv.codigo = codigo;

			cout << "\tNombre del servicio: ";
			getline(cin, nombre);
			strcpy(serv.nombre, nombre.c_str());

			cout << "\tDuracion del servicio (min): ";
			serv.duracion = obtener_entero();
			cout << "\tPrecio (s/.): ";
			serv.precio = obtener_flotante();
			especialidad = "pendiente";
			strcpy(serv.especialidad, especialidad.c_str());

			if (insertar_servicio_archivo(serv)) {
				cout << "\n\tEl servicio fue creado satisfactoriamente" << endl;
			} else {
				cout << "\n\tOcurrio un error al intentar crear el servicio" << endl;
				cout << "\tIntentelo nuevamente" << endl;
			}	
		} else {
			cout << "\n\tEl servicio de codigo " << codigo << " ya existe.\n";
			cout << "\t  No puede ingresar dos servicios con el mismo codigo" << endl;
		}
		cout << "\n\tDesea seguir ingresando servicios? [S/n]: ";
		getline(cin, respuesta);
		if (!(respuesta.compare("s") == 0 || respuesta.compare("S") == 0)) {
			se_repite = false;
		}
	} while (se_repite);
}
bool existe_servicio(int codigo_servicio, Servicio *serv) {
	FILE *archivo;
	bool existe = false;

	archivo = fopen("servicios.dat", "rb");

	if (!(archivo == NULL)) {
		fread(&(*serv), sizeof(*serv), 1, archivo);
		while (!feof(archivo)) {
			if ((*serv).codigo == codigo_servicio) {
				existe = true;
				break;
			}
			fread(&(*serv), sizeof(*serv), 1, archivo);
		}
		fclose(archivo);
	}
	return existe;
}
bool insertar_servicio_archivo(Servicio serv) {
	FILE *archivo;
	bool insercion;

	archivo = fopen("servicios.dat", "wb");

	if (archivo == NULL) {
		insercion = false;
	} else {
		fwrite(&serv, sizeof(serv), 1, archivo);
		insercion = true;
		fclose(archivo);
	}

	return insercion;
}
void opcion_mostrar_servicio() {
	Servicio *servicios;
	int nro_servicios;

	limpiar_pantalla();
	titulo_principal();
	servicios = obtener_st_archivo(&nro_servicios);

	if (nro_servicios == 0) {
		cout << "\n\tEl archivo esta vacio" << endl;
		pausar_pantalla();
	} else {

		cout << "\n\t\t\t\tSERVICIOS REGISTRADOS\n";
		cout << "\n\t   ------------------------------------------------------------\n";
		for (int i = 0; i < nro_servicios; i++) {
			if (servicios[i].codigo != PARA_ELIMINAR) {
				cout << "\t\tCodigo: " << servicios[i].codigo << endl;
				cout << "\t\tNombre: " << servicios[i].nombre << endl;
				cout << "\t\tDuracion: " << servicios[i].duracion << endl;
				cout << "\t\tPrecio: " << servicios[i].precio << endl;
				cout << "\t\tEspecialidad: " << servicios[i].especialidad << endl;
			}
			cout << "\n\t   ------------------------------------------------------------\n";
		}
		pausar_pantalla();
	}
}
void opcion_actualizar_servicio(void){
		Servicio serv;
		int codigo;
		bool se_repite = true;
		string respuesta, nombre, especialidad;

		do {
			limpiar_pantalla();
			titulo_principal();
			cout << "\n\t\t\t\tMODIFICAR SERVICIO\n";
	
			cout << "\n\tCodigo del servicio: ";
			codigo = obtener_entero();
			if (existe_servicio(codigo, &serv)) {
				cout << "\n\tNombre del servicio: " << serv.nombre << endl;
				cout << "\tDuracion del servicio (min): " << serv.duracion << endl;
				cout << "\tPrecio del servicio (s/.): " << serv.precio << endl;
				cout << "\tEspecialidad del servicio: " << serv.especialidad << endl;
	
				cout << "\n\tElija los datos a modificar\n" << endl;
	
				cout << "\n\tNombre actual del servicio: " << serv.nombre << endl;
				cout << "\tDeseas modificar el nombre? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					cout << "\tNuevo nombre: ";
					getline(cin, nombre);
					strcpy(serv.nombre, nombre.c_str());
				}
	
				cout << "\tDuracion actual del servicio (min): " << serv.duracion << endl;
				cout << "\tDeseas modificar la duracion del servicio? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					cout << "\tNueva duracion: ";
					serv.duracion = obtener_entero();
				}
	
				cout << "\tPrecio actual del servicio (S/.): " << serv.precio << endl;
				cout << "\tDeseas modificar el precio del servicio? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					cout << "\tNuevo precio: ";
					serv.precio = obtener_flotante();
				}
	
				cout << "\tEspecialidad acutal del servicio: " << serv.especialidad << endl;
				cout << "\tDeseas modificar la especialidad del servicio? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					cout << "\tNueva especialidad: ";
					getline(cin, especialidad);
					strcpy(serv.especialidad, especialidad.c_str());
				}
	
				cout << "\nEsta seguro que desea modificar los datos del producto? [S/N]: ";
				getline(cin, respuesta);
				if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
					if (modificar_archivo_servicio(serv)) {
						cout << "\n\tEl servicio fue modificado correctamente\n";
			} else {
						cout << "\n\tOcurrio un error al intentar modificar el servicio\n";
						cout << "\tIntentelo nuevamente\n";
					}
				}
			} else {
				cout << "\n\tEl servicio de codigo " << codigo << " no existe.\n";
			}
	
			cout << "\n\tDeseas modificar otro servicio? [S/N]: ";
			getline(cin, respuesta);
			if (!(respuesta.compare("S") == 0 || respuesta.compare("s") == 0)) {
				se_repite = false;
			}
		} while (se_repite);
}
bool modificar_archivo_servicio(Servicio serv) {
	FILE *archivo;
	bool modificado;
	Servicio servicio;

	archivo = fopen("servicios.dat", "rb+");

	if (!(archivo == NULL)) {
		modificado = false;
		fread(&servicio, sizeof(servicio), 1, archivo);
		while (!feof(archivo)) {
			if (servicio.codigo == serv.codigo) {
				fseek(archivo, ftell(archivo) - sizeof(serv), SEEK_SET);
				fwrite(&serv, sizeof(serv), 1, archivo);
				modificado = true;
				break;
			}
			fread(&servicio, sizeof(servicio), 1, archivo);
		}
		fclose(archivo);
	}
	return modificado;
}
void opcion_eliminar_servicio(void) {
	Servicio serv;
	int codigo;
	bool se_repite = true;
	string respuesta;

	do {
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\t\t\tELIMINAR SERVICIO\n";

		cout << "\n\tCodigo de servicio: ";
		codigo = obtener_entero();

		if (existe_servicio(codigo, &serv)) {
			cout << "\n\tCodigo del servicio: " << serv.codigo << endl;
			cout << "\tNombre del servicio: " << serv.nombre << endl;
			cout << "\tDuracion del servicio (min): " << serv.duracion << endl;
			cout << "\tPrecio del servicio: " << serv.precio << endl;
			cout << "\tEspecialidad: " << serv.especialidad << endl;

			cout << "\n\tDesea eliminar el producto? [S/N]: ";
			getline(cin, respuesta);

			if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				if (eliminar_servicio(codigo)) {
					if (eliminar_servicio_fisico()) {
						cout << "\n\tSe elimino exitosamente del archivo\n";
					} else {
						cout << "\n\tEl servicio no pudo ser eliminado del archivo\n";
						cout << "\tIntentelo mas tarde\n";
					}
				} else {
					cout << "\n\tEl servicio no pudo ser eliminado\n";
				}
			}
		} else {
			cout << "\n\tEl servicio de codigo " << codigo << " no existe.\n";
		}

		cout << "\n\tDeseas eliminar otro servicio? [S/N]: ";
		getline(cin, respuesta);

		if (!(respuesta.compare("S") == 0 || respuesta.compare("s") == 0)) {
			se_repite = false;
		}
	} while (se_repite);
}
bool eliminar_servicio(int codigo) {
	FILE *archivo;
	FILE *auxiliar;
	Servicio serv;
	bool se_elimina = false;

	archivo = fopen("servicios.dat", "r+b");

	if (archivo == NULL) {
		se_elimina = false;
	} else {
		se_elimina = false;
		fread(&serv, sizeof(serv), 1, archivo);
		while (!feof(archivo)) {
			if (serv.codigo == codigo) {
				fseek(archivo, ftell(archivo) - sizeof(serv), SEEK_SET);
				serv.codigo = PARA_ELIMINAR;
				fwrite(&serv, sizeof(serv), 1, archivo);
				se_elimina = true;
				break;
			}
			fread(&serv, sizeof(serv), 1, archivo);
		}
		fclose(archivo);
	}
	return se_elimina;
}
bool eliminar_servicio_fisico() {
	FILE *archivo;
	FILE *auxiliar;
	Servicio serv;
	bool se_elimina = false;

	archivo = fopen("servicios.dat", "rb");
	auxiliar = fopen("auxiliar.dat", "wb");

	if (archivo == NULL || auxiliar == NULL) {
		se_elimina = false;
	} else {
		fread(&serv, sizeof(serv), 1, archivo);
		while (!feof(archivo)) {
			if (serv.codigo != PARA_ELIMINAR) {
				fwrite(&serv, sizeof(serv), 1, auxiliar);
			}
			fread(&serv, sizeof(serv), 1, archivo);
		}
		fclose(archivo);
		fclose(auxiliar);

		remove("servicios.dat");
		rename("auxiliar.dat", "servicios.dat");

		se_elimina = true;
	}
	return se_elimina;
}
Servicio *obtener_st_archivo(int *n) {
	FILE *archivo;
	Servicio servicio;
	Servicio *servicios;
	int i;

	archivo = fopen("servicios.dat", "rb");

	if (archivo == NULL) {
		*n = 0;
		servicios = NULL;
	} else {
		fseek(archivo, 0, SEEK_END);
		*n = ftell(archivo) / sizeof(Servicio);
		servicios = (Servicio *)malloc((*n) * sizeof(Servicio));
		fseek(archivo, 0, SEEK_SET);
		fread(&servicio, sizeof(servicio), 1, archivo);
		i = 0;
		while (!feof(archivo)) {
			servicios[i] = servicio;
			fread(&servicio, sizeof(servicio), 1, archivo);
			i++;
		}
		fclose(archivo);
	}
	return servicios;
}

void menu_cita() {
	int prueba;
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU CITA\n";
	pausar_pantalla();
}

void menu_historial() {
	int prueba;
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU HISTORIAL\n";
	pausar_pantalla();
}

void menu_reportes() {
	int prueba;
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU REPORTES\n";
	pausar_pantalla();
}

int obtener_entero() {
	bool no_es_entero = true;
	string valor;

	while (no_es_entero) {
		try {
			getline(cin, valor);
			if (!es_entero_valido(valor)) {
				throw valor;
			}
		} catch(string e) {
			cout << "\t\tPor favor, ingrese un entero valido: ";
			continue;
		} catch(...) {
			cout << " ";
		}
		no_es_entero = false;
	}
	return atoi(valor.c_str());
}
int obtener_entero(int inf, int sup) {
	bool no_aceptado = true;
	int numero;
	while (no_aceptado) {
		try {
			numero = obtener_entero();
			if (numero < inf || numero > sup) {
				throw numero;
			}
		}catch(int e) {
			cout << "\t\tPor favor, ingrese un numero entero entre " << inf << " y " << sup << ": ";
			continue;
		}
		no_aceptado = false;
	}
	return numero;
}
bool es_entero_valido(string str) {
	int inicio = 0;
	int i;
	bool valido = true;
	bool signo = false;

	if (int(str.length()) == 0) {
		valido = false;
	}

	if (str.at(0) == '-' || str.at(0) == '+') {
		signo = true;
		inicio = 1;
	}

	if (signo && int(str.length()) == 1) {
		valido = false;
	}

	i = inicio;
	while (valido && i < int(str.length())) {
		if (!isdigit(str.at(i))) {
			valido = false;
		}
		i++;
	}

	return valido;
}
void limpiar_pantalla(void) {
	system("cls");
}
double obtener_flotante(void) {
	bool no_es_flotante = true;
	string valor;

	while (no_es_flotante) {
		try {
			getline(cin, valor);
			if (!es_flotante_valido(valor)) {
				throw valor;
			}
		} catch(string e) {
			cout << "\t\tPor favor, ingrese un numero decimal valido: ";
			continue;
		}
		no_es_flotante = false;
	}
	return atof(valor.c_str());
}
bool es_flotante_valido(string str) {
	int inicio = 0;
	int i, n_puntos = 0;
	bool valido = true;
	bool signo = false;

	if (int(str.length()) == 0) {
		valido = false;
	}

	if (str.at(0) == '-' || str.at(0) == '+') {
		signo = true;
		inicio = 1;
	}

	if (str.at(1) == '.') {
		valido = false;
	}

	if (signo && int(str.length()) == 1) {
		valido = false;
	}

	i = inicio;
	while (valido && i < int(str.length())) {
		if (!isdigit(str.at(i))) {
			if (!(str.at(i) == '.')) {
				valido = false;
			}
		}

		if (str.at(i) == '.') {
			n_puntos++;
		}
		i++;
	}

	if (n_puntos > 1) {
		valido = false;
	}

	return valido;
}
void pausar_pantalla() {
	char caracter;
	cout << "\n\tPresiona 'Enter' para continuar...";
	while (caracter != '\n') {
		cin.get(caracter);
	}
}

