#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define PARA_ELIMINAR -1
using namespace std;

struct Servicio {
	int codigo;
	char nombre[50];
	int duracion;
	double precio;
	char especialidad[50];
};
struct Usuario {
	int DNI;
	char nombre[25];
	char apellidoP[25];
	char apellidoM[25];
	int telefono;
	char gmail[25];
	char centroDeEstudio[30];
	char tipo[20];
	int sueldo;
	char password[50];
};

struct Fecha{
	int dia;
	int mes;
	int anio;
	int hora;
	int minutos;
};

struct Historial{
	int codigo;
	char Apellido_Paterno[15];
	char Apellido_Materno[15];
	char Nombres[25];
	char Estado_Civil[11];
	char Genero[9];
	Fecha Fecha_Nac;
	int DNI;
	int edad;
	int telefono;
	char Seguro[10];
	char Problemas_Medicos[200];
	char Hospitalizaciones[200];
	char Alergias[200];
	char Medicamentos[200];
};


struct Cita {
	int DNI;
	int codigo;
	int codigoCit;
	Fecha fechaCita;
};

void opcion_crear_archivo(FILE *archivoCita,char nombreArchivo[20]);

//Menu Principal
void menu_principal();

//Menu Usuario
void menu_usuario();
void menu_usuario_opciones();

//Menu Especialidad
void menu_especialidad();


//Menu Servicios
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
bool eliminar_servicio(int codigo);
bool eliminar_servicio_fisico();


//Menu Citas
void menu_cita();
void menu_cita_opciones(void);

void opcion_crear_cita();
bool insertar_cita_archivo(Cita cit);
bool existe_cita(int codigoCit, Cita *cit);

void opcion_mostrar_cita();
Cita *obtener_st_cita(int *n);

void opcion_actualizar_cita();
bool modificar_archivo_cita(Cita cit);

void opcion_eliminar_cita();
bool eliminar_cita(int);
bool eliminar_cita_fisico();


//Menu Historial
void menu_historial();
void menu_historial_opciones(void);

void opcion_crear_historial();
bool insertar_historial_archivo(Historial hist);
bool existe_historial(int codigo_historial,Historial *hist);

void opcion_mostrar_historial();
Historial *obtener_his_archivo(int *n);

int obtener_edad(Fecha fEdad);

//Menu Reportes
void menu_reportes();


//Funciones y Procedimientos de validación
void limpiar_pantalla();
void pausar_pantalla();
void titulo_principal();
int obtener_entero();
int obtener_entero(int, int);
bool es_entero_valido(string);
double obtener_flotante();
bool es_flotante_valido(string);
bool fecha_valida(Fecha fCita);
bool fecha_rango_valido(Fecha fCita);


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
				menu_usuario();
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
	cout << "\n\t\t[1]. Usuarios\n";
	cout << "\t\t[2]. Especialidades\n";
	cout << "\t\t[3]. Servicios\n";
	cout << "\t\t[4]. Cita\n";
	cout << "\t\t[5]. Historial Medico\n";
	cout << "\t\t[6]. Reportes\n";
	cout << "\t\t[7]. Salir\n";
	cout << "\n\t\tIngrese una opcion: ";
}


void menu_usuario() {
	bool se_repite = true;
	int opcion;
	do{
		menu_usuario_opciones();
		opcion=obtener_entero();
		switch(opcion){
			case 1:
				
				break;
			case 2:
			
				break;
			case 3:
				
			case 4:
				
			case 5:
				
				se_repite = false;
				break;
		}
	}while(se_repite);
	
	menu_usuario_opciones();
	
}
void menu_usuario_opciones(){
	
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU USUARIOS\n";
	cout << "\n\n\t\t[1]. Crear Usuario";
	cout << "\n\t\t[2]. Mostrar Usuario";
	cout << "\n\t\t[3]. Actualizar Usuario";
	cout << "\n\t\t[4]. Eliminar Usuario";
	cout << "\n\t\t[5]. Volver al menu principal\n";
	cout << "\n\t\tIngrese una opcion: ";
	
}
 /*void opcion_crear_usuario(){
	bool se_repite=true;
	Usuario user;
	int tipo,DNI;
	string nombre,aPaterno,aMaterno,correo,centro,tipoUsuario,contra,opc;
	do{
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\tCREAR NUEVO USUARIO\n";
		cout << "\n\tIngresa el DNI del usuario: ";
		DNI=obtener_entero();
		if(!existe_usuario(DNI,&user)){
		user.DNI=DNI;
		cout << "\tIngresa el Nombre del usuario: ";
		getline(cin,nombre);
		strcpy(user.nombre,nombre.c_str());
		cout << "\tIngresa el Apellido Paterno del usuario: ";
		getline(cin,aPaterno);
		strcpy(user.apellidoP,aPaterno.c_str());
		cout << "\tIngresa el Apellido Materno del usuario: ";
		getline(cin,aMaterno);
		strcpy(user.apellidoM,aMaterno.c_str());
		cout << "\tIngresa el NumeroTelefonico del usuario: ";
		user.telefono=obtener_entero();
		cout << "\tIngresa el Correo Electronico del usuario: ";
		getline(cin,correo);
		strcpy(user.gmail,correo.c_str());
		cout << "\tIngresa el Centro de estudios del usuario: ";
		getline(cin,centro);
		strcpy(user.centroDeEstudio,centro.c_str());
		cout << "\t\t\t\tIngresa el Tipo de usuario: \n";
		cout << "\t\tAdministrador.....[1]\n";
		cout << "\t\tDoctor............[2]\n";
		cout << "\t\tEnfermera.........[3]\n";
		cout << "\t\tCajero............[4]"<<endl;
		tipo=obtener_entero(1,4);
		switch(tipo){
			case 1:
				tipoUsuario="Administrador";
				strcpy(user.tipo,tipoUsuario.c_str());
				break;
			case 2:
				tipoUsuario="Doctor";
				strcpy(user.tipo,tipoUsuario.c_str());
				break;
			case 3:
				tipoUsuario="Enfermera";
				strcpy(user.tipo,tipoUsuario.c_str());
				break;
			case 4:
				tipoUsuario="Cajero";
				strcpy(user.tipo,tipoUsuario.c_str());
				break;
		}
		cout << "\tIngresa el pasword del usuario: ";
		getline(cin,contra);
		strcpy(user.password,contra.c_str());
	
		if(insertar_usuario_archivo(user)){
			cout << "\n\t\t\t\t\tEl usuario fue creado con exito";
		}else{
			cout << "\n\tOcurrio un error al intentar crear el usuario" << endl;
			cout << "\tIntentelo nuevamente" << endl;
		}
	}else{
		cout << "\n\tEl Usuario con DNI " << DNI << " ya existe.\n";
		cout << "\t  No puede ingresar dos Usuarios con el mismo DNI" << endl;
	}
		cout <<" ";
		cout << "\n\t\t\t\tDesea seguir ingresando Usuarios? [S/n]: ";
		fflush(stdin);
		getline(cin,opc);
		if(!(opc.compare("S")==0 || opc.compare("s")==0)){
			se_repite=false;
		}

	}while(se_repite);
	
}

void opcion_mostrar_usuario()
{
	Usuario *users;
	int nro_usuarios;

	limpiar_pantalla();
	titulo_principal();
	users = obtener_st_usuario(&nro_usuarios);

	if (nro_usuarios == 0) {
		cout << "\n\tEl archivo esta vacio" << endl;
		pausar_pantalla();
	} else {

		cout << "\n\t\t\t\tUSUARIOS REGISTRADOS\n";
		cout << "\n\t   ------------------------------------------------------------\n";
		for (int i = 0; i < nro_usuarios; i++) {
			if (users[i].DNI != PARA_ELIMINAR) {
				cout << "\t\tNombre: " << users[i].nombre <<" "<<users[i].apellidoP<<" "<<users[i].apellidoM<<endl;
				cout << "\t\tDNI: " << users[i].DNI << endl;
				cout << "\t\tTelefono: " << users[i].telefono << endl;
				cout << "\t\tGmail: " << users[i].gmail << endl;
				cout << "\t\tCentro de estudio: " << users[i].centroDeEstudio << endl;
				cout << "\t\tTipo: " << users[i].tipo << endl;
			}
			cout << "\n\t   ------------------------------------------------------------\n";
		}
		pausar_pantalla();
	}
}

*/
bool existe_historial(int codigo_historial, Historial *hist) {
	FILE *archivo;
	bool existe = false;

	archivo = fopen("historial.dat", "rb");

	if (!(archivo == NULL)) {
		fread(&(*hist), sizeof(*hist), 1, archivo);
		while (!feof(archivo)) {
			if ((*hist).codigo == codigo_historial) {
				existe = true;
				break;
			}
			fread(&(*hist), sizeof(*hist), 1, archivo);
		}
		fclose(archivo);
	}
	return existe;
}

bool insertar_historial_archivo(Historial hist) {
	FILE *archivo;
	bool insercion;

	archivo = fopen("historial.dat", "ab");

	if (archivo == NULL) {
		insercion = false;
	} else {
		fwrite(&hist, sizeof(hist), 1, archivo);
		insercion = true;
		fclose(archivo);
	}
	return insercion;
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
void menu_historial_opciones(void) {
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU HISTORIAL MEDICO\n";
	cout << "\n\t\t[1]. Crear archivo historial\n";
	cout << "\t\t[2]. Agregar Historial\n";
	cout << "\t\t[3]. Mostrar historial medico\n";
	cout << "\t\t[4]. Volver al menu principal\n";
	cout << "\n\t\tIngrese una opcion: ";
}

void menu_cita_opciones(void) {
	limpiar_pantalla();
	titulo_principal();
	cout << "\n\t\t\t\tMENU CITAS\n";
	cout << "\n\t\t[1]. Crear cita\n";
	cout << "\t\t[2]. Mostrar citas\n";
	cout << "\t\t[3]. Actualizar cita\n";
	cout << "\t\t[4]. Eliminar cita\n";
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

	archivo = fopen("servicios.dat", "ab");

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
void opcion_actualizar_servicio(void) {
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

			cout << "\tEspecialidad actual del servicio: " << serv.especialidad << endl;
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
Historial *obtener_his_archivo(int *n) {
	FILE *archivo;
	Historial historial;
	Historial *historiales;
	int i;

	archivo = fopen("historial.dat", "rb");

	if (archivo == NULL) {
		*n = 0;
		historiales = NULL;
	} else {
		fseek(archivo, 0, SEEK_END);
		*n = ftell(archivo) / sizeof(Historial);
		historiales = (Historial *)malloc((*n) * sizeof(Historial));
		fseek(archivo, 0, SEEK_SET);
		fread(&historial, sizeof(historial), 1, archivo);
		i = 0;
		while (!feof(archivo)) {
			historiales[i] = historial;
			fread(&historial, sizeof(historial), 1, archivo);
			i++;
		}
		fclose(archivo);
	}
	return historiales;
}

void menu_cita() {
	bool se_repite = true;
	int opcion;

	do {
		menu_cita_opciones();
		opcion = obtener_entero();

		switch (opcion) {
			case 1:
				opcion_crear_cita();
				break;
			case 2:
				opcion_mostrar_cita();
				break;
			case 3:
				opcion_actualizar_cita();
				break;
			case 4:
				opcion_eliminar_cita();
				break;
			case 5:
				se_repite = false;
				break;
		}
	} while (se_repite);
}

void opcion_crear_cita(){
	Cita cit;
	Servicio serv;
	Historial hist;
	bool se_repite = true;
	int DNI,codigo,codigoCit;
	Fecha fCita;
	string respuesta;
	
	
	do {
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\tCREAR NUEVA CITA\n";
		
		cout << "\tIngresa el Codigo de la cita: ";
		codigoCit = obtener_entero();
		
		if(existe_cita(codigoCit,&cit))
		{
			cout<<"\n\tEsta cita ya existe"<<endl;
		}else{
			
			cout << "\tIngresa el Codigo de servicio: ";
			codigo = obtener_entero();
			cout << "\tIngresa el DNI del usuario: ";
			DNI = obtener_entero();
		
			if (existe_servicio(codigo, &serv) && existe_historial(DNI,&hist)) {
		
			cit.codigoCit = codigoCit;
			cit.codigo = codigo;
			cit.DNI = DNI;
			
			cout << "\tDigite la fecha de la cita: ";
			
			cout<<"\n\tDia: ";
			fCita.dia = obtener_entero();
			cout<<"\tMes: ";
			fCita.mes = obtener_entero();
			cout<<"\tAño: ";
			fCita.anio = obtener_entero();
			
			cout<< "\n\tDigite la hora de la cita: ";
			
			cout<<"\n\tHora: ";
			fCita.hora = obtener_entero();
			cout<<"\tMinutos: ";
			fCita.minutos = obtener_entero();
			
			cit.fechaCita.minutos = fCita.minutos;
			cit.fechaCita.hora = fCita.hora;
			cit.fechaCita.dia = fCita.dia;
			cit.fechaCita.mes = fCita.mes;
			cit.fechaCita.anio = fCita.anio;
			fflush(stdin);
			
			if(!fecha_valida(fCita) || !fecha_rango_valido(fCita))
			{
				cout << "\n\tLa fecha de la cita es incorrecta." << endl;	
			}else if (insertar_cita_archivo(cit)) {
				cout << "\n\tLa cita fue creada satisfactoriamente" << endl;
			} else {
				cout<< "\n\tLa cita no se pudo crear correctamente, intentelo mas tarde " << endl;
			}	
		} else {
			cout << "\n\tEl servicio o el usuario no existe(n)" << endl;
				cout << "\tIntentelo nuevamente" << endl;
		}
		}
		cout << "\n\tDesea seguir creando citas? [S/n]: ";
		getline(cin, respuesta);
		if (!(respuesta.compare("s") == 0 || respuesta.compare("S") == 0)) {
			se_repite = false;
		}
	} while (se_repite);	
}

int obtener_edad(Fecha fEdad)
{
	Fecha fActual;
	int edad;
	time_t fechaActual = time(0);
	tm *Fecha = localtime(&fechaActual);
	
	fActual.anio = 1900 + Fecha->tm_year;
	fActual.mes = 1 + Fecha->tm_mon;
	fActual.dia = Fecha->tm_mday;
	fActual.hora = Fecha->tm_hour;
	fActual.minutos = Fecha->tm_min;
	
	edad = fActual.anio - fEdad.anio - 1;
	
	if(fActual.mes>=fEdad.anio && fActual.dia >= fEdad.dia)
		edad++;
		
	return edad;
}

bool fecha_valida(Fecha fCita)
{
	Fecha fActual;
	bool fValida = true;
	time_t fechaActual = time(0);
	tm *Fecha = localtime(&fechaActual);
	
	fActual.anio = 1900 + Fecha->tm_year;
	fActual.mes = 1 + Fecha->tm_mon;
	fActual.dia = Fecha->tm_mday;
	fActual.hora = Fecha->tm_hour;
	fActual.minutos = Fecha->tm_min;
	
	if(fCita.anio < fActual.anio)
		fValida = false;
	else if(fCita.anio == fActual.anio)
	{
		if(fCita.mes < fActual.mes)
			fValida = false;
		else if(fCita.mes == fActual.mes)
		{
			if(fCita.dia < fActual.dia)
				fValida = false;
			else if(fCita.dia == fActual.dia)
			{
				if(fCita.hora < fActual.hora)
					fValida = false;
				else if(fCita.hora == fActual.hora)
				{
					if(fCita.minutos < fActual.minutos)
						fValida = false;
				}
			}
		}
	}
	
	return fValida;
}

bool fecha_rango_valido(Fecha fCita)
{
	bool rango_valido = true;
	bool bisiesto;
	
	if((fCita.anio%4==0 && fCita.anio%100!=0) || (fCita.anio%4==0 && fCita.anio%100==0 && fCita.anio%400==0))
        bisiesto=true;
    else
        bisiesto=false;
        
    if(fCita.mes>0 && fCita.mes<=12)
    {
        if(fCita.mes==1 || fCita.mes==3 || fCita.mes==5 || fCita.mes==7 || fCita.mes==10 || fCita.mes==12)
        {
            if(fCita.dia<=0 || fCita.dia>31)
                rango_valido = false;
        }
    	
		if(fCita.mes==2)
		{
        	if(bisiesto)
            {
            	if(fCita.dia<=0 || fCita.dia>29)
                	rango_valido = false;
            }	
            
            if(!bisiesto)
            {
        		if(fCita.dia<=0 || fCita.dia>28)
                	rango_valido = false;
            }
    	}
    	
		if(fCita.mes==4 || fCita.mes==6 || fCita.mes==8 || fCita.mes==9 || fCita.mes==11)
    	{
        	if(fCita.dia<=0 || fCita.dia>30)
                rango_valido = false;
		}
    }else
        rango_valido = false;
        
	return rango_valido;
}

bool existe_cita(int codigoCit, Cita *cit) {
	FILE *archivo;
	bool existe = false;

	archivo = fopen("citas.dat", "rb");

	if (!(archivo == NULL)) {
		fread(&(*cit), sizeof(*cit), 1, archivo);
		while (!feof(archivo)) {
			if ((*cit).codigoCit == codigoCit) {
				existe = true;
				break;
			}
			fread(&(*cit), sizeof(*cit), 1, archivo);
		}
		fclose(archivo);
	}
	return existe;
}

bool insertar_cita_archivo(Cita cit) {
	FILE *archivo;
	bool insercion;

	archivo = fopen("citas.dat", "ab");

	if (archivo == NULL) {
		insercion = false;
	} else {
		fwrite(&cit, sizeof(cit), 1, archivo);
		insercion = true;
		fclose(archivo);
	}

	return insercion;
}

void opcion_mostrar_cita() {
	Cita *citas;
	int nro_citas;

	limpiar_pantalla();
	titulo_principal();
	citas = obtener_st_cita(&nro_citas);

	if (nro_citas == 0) {
		cout << "\n\tEl archivo esta vacio" << endl;
		pausar_pantalla();
	} else {

		cout << "\n\t\t\t\tCITAS REGISTRADAS\n";
		cout << "\n\t   ------------------------------------------------------------\n";
		for (int i = 0; i < nro_citas; i++) {
			if (citas[i].codigoCit != PARA_ELIMINAR) {
				cout << "\t\tCodigo de la cita: " << citas[i].codigoCit << endl;
				cout << "\t\tDNI del paciente: " << citas[i].DNI << endl;
				cout << "\t\tCodigo del servicio: " << citas[i].codigo << endl;
				cout << "\t\tFecha de la cita: " << citas[i].fechaCita.dia << "/"<< citas[i].fechaCita.mes << "/" << citas[i].fechaCita.anio << endl;
				cout << "\t\tHora de la cita: "<<citas[i].fechaCita.hora << ":" << citas[i].fechaCita.minutos << endl;
			}
			cout << "\n\t   ------------------------------------------------------------\n";
		}
		pausar_pantalla();
	}
}

void opcion_actualizar_cita(void) {
	Cita cit;
	Fecha fCita;
	int codigoCit;
	bool se_repite = true;
	string respuesta;

	do {
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\t\t\tMODIFICAR CITA\n";

		cout << "\n\tCodigo de la cita: ";
		codigoCit = obtener_entero();
		if (existe_cita(codigoCit, &cit)) {
			cout << "\n\tCodigo del servicio: " << cit.codigo << endl;
			cout << "\tDNI del paciente: " << cit.DNI<< endl;
			cout << "\tFecha de la cita " << cit.fechaCita.dia << "/" << cit.fechaCita.mes << "/" << cit.fechaCita.anio << endl;
			cout << "\tHora de la cita: "<<cit.fechaCita.hora << ":" << cit.fechaCita.minutos << endl;

			cout << "\n\tElija los datos a modificar\n" << endl;

			cout << "\n\tCodigo actual del servicio: " << cit.codigo << endl;
			cout << "\tDeseas modificar el codigo del servicio? [S/N]: ";
			getline(cin, respuesta);
			if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				cout << "\tNuevo codigo del servicio: ";
				cit.codigo = obtener_entero();
			}

			cout << "\tDNI actual del paciente: " << cit.DNI << endl;
			cout << "\tDeseas modificar el DNI del paciente? [S/N]: ";
			getline(cin, respuesta);
			if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				cout << "\tNuevo DNI: ";
				cit.DNI = obtener_entero();
			}

			cout << "\tFecha actual de la cita: " << cit.fechaCita.dia << "/" << cit.fechaCita.mes << "/" << cit.fechaCita.anio << endl;
			cout << "\tDeseas modificar la fecha de la cita? [S/N]: ";
			getline(cin, respuesta);
			if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				
				cout << "\tNuevo dia: ";
				fCita.dia = obtener_entero();
				cit.fechaCita.dia = fCita.dia;
				cout << "\tNuevo mes: ";
				fCita.mes = obtener_entero();
				cit.fechaCita.mes = fCita.mes;
				cout << "\tNuevo anio: ";
				fCita.anio = obtener_entero();
				cit.fechaCita.anio = fCita.anio;
			}
			
			cout << "\t\tHora actual de la cita: "<<cit.fechaCita.hora << ":" << cit.fechaCita.minutos << endl;
			cout << "\tDeseas modificar la hora de la cita? [S/N]: ";
			getline(cin, respuesta);
			if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				
				cout << "\tNuevo Minuto: ";
				fCita.minutos = obtener_entero();
				cit.fechaCita.minutos = fCita.minutos;
				cout << "\tNueva hora: ";
				fCita.hora = obtener_entero();
				cit.fechaCita.hora = fCita.hora;				

			}
			
			if(!fecha_valida(fCita) || !fecha_rango_valido(fCita))
				cout<<"\n\tLa fecha es incorrecta. "<<endl;
			else
			{
			
			cout << "\n\tEsta seguro que desea modificar los datos del producto? [S/N]: ";
			getline(cin, respuesta);
			if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				if (modificar_archivo_cita(cit)) {
					cout << "\n\tLa cita fue modificada correctamente\n";
				} else {
					cout << "\n\tOcurrio un error al intentar modificar la cita\n";
					cout << "\tIntentelo nuevamente\n";
				}
			}
		}
		} else {
			cout << "\n\tLa cita de codigo " << codigoCit << " no existe.\n";
		}

		cout << "\n\tDeseas modificar otro servicio? [S/N]: ";
		getline(cin, respuesta);
		if (!(respuesta.compare("S") == 0 || respuesta.compare("s") == 0)) {
			se_repite = false;
		}
	} while (se_repite);
}

bool modificar_archivo_cita(Cita cit) {
	FILE *archivo;
	bool modificado;
	Cita cita;

	archivo = fopen("citas.dat", "rb+");

	if (!(archivo == NULL)) {
		modificado = false;
		fread(&cita, sizeof(cita), 1, archivo);
		while (!feof(archivo)) {
			if (cita.codigo == cit.codigo) {
				fseek(archivo, ftell(archivo) - sizeof(cit), SEEK_SET);
				fwrite(&cit, sizeof(cit), 1, archivo);
				modificado = true;
				break;
			}
			fread(&cita, sizeof(cita), 1, archivo);
		}
		fclose(archivo);
	}
	return modificado;
}

void opcion_eliminar_cita(void) {
	Cita cit;
	int codigo;
	bool se_repite = true;
	string respuesta;

	do {
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\t\t\tELIMINAR CITA\n";

		cout << "\n\tCodigo de cita: ";
		codigo = obtener_entero();

		if (existe_cita(codigo, &cit)) {
			cout << "\n\tCodigo de la cita: " << cit.codigoCit << endl;
			cout << "\tCodigo del servicio: " << cit.codigo << endl;
			cout << "\tDNI del paciente: " << cit.DNI << endl;
			cout << "\tFecha de la cita: " << cit.fechaCita.dia <<"/"<<cit.fechaCita.mes<<"/"<<cit.fechaCita.anio<<endl;
			cout << "\tHora de la cita: "<<cit.fechaCita.hora << ":" << cit.fechaCita.minutos << endl;

			cout << "\n\tDesea eliminar el producto? [S/N]: ";
			getline(cin, respuesta);

			if (respuesta.compare("S") == 0 || respuesta.compare("s") == 0) {
				if (eliminar_cita(codigo)) {
					if (eliminar_cita_fisico()) {
						cout << "\n\tSe elimino exitosamente del archivo\n";
					} else {
						cout << "\n\tLa cita no pudo ser eliminada del archivo\n";
						cout << "\tIntentelo mas tarde\n";
					}
				} else {
					cout << "\n\tLa cita no pudo ser eliminada\n";
				}
			}
		} else {
			cout << "\n\tLa cita con codigo numero " << codigo << " no existe.\n";
		}

		cout << "\n\tDeseas eliminar otra cita? [S/N]: ";
		getline(cin, respuesta);

		if (!(respuesta.compare("S") == 0 || respuesta.compare("s") == 0)) {
			se_repite = false;
		}
	} while (se_repite);
}

Cita *obtener_st_cita(int *n) {
	FILE *archivo;
	Cita cita;
	Cita *citas;
	int i;

	archivo = fopen("citas.dat", "rb");

	if (archivo == NULL) {
		*n = 0;
		citas = NULL;
	} else {
		fseek(archivo, 0, SEEK_END);
		*n = ftell(archivo) / sizeof(Cita);
		citas = (Cita *)malloc((*n) * sizeof(Cita));
		fseek(archivo, 0, SEEK_SET);
		fread(&cita, sizeof(cita), 1, archivo);
		i = 0;
		while (!feof(archivo)) {
			citas[i] = cita;
			fread(&cita, sizeof(cita), 1, archivo);
			i++;
		}
		fclose(archivo);
	}
	return citas;
}

bool eliminar_cita(int codigo) {
	FILE *archivo;
	Cita cit;
	bool se_elimina = false;

	archivo = fopen("citas.dat", "r+b");

	if (archivo == NULL) {
		se_elimina = false;
	} else {
		se_elimina = false;
		fread(&cit, sizeof(cit), 1, archivo);
		while (!feof(archivo)) {
			if (cit.codigoCit == codigo) {
				fseek(archivo, ftell(archivo) - sizeof(cit), SEEK_SET);
				cit.codigoCit = PARA_ELIMINAR;
				fwrite(&cit, sizeof(cit), 1, archivo);
				se_elimina = true;
				break;
			}
			fread(&cit, sizeof(cit), 1, archivo);
		}
		fclose(archivo);
	}
	return se_elimina;
}

bool eliminar_cita_fisico() {
	FILE *archivo;
	FILE *auxiliar;
	Cita cit;
	bool se_elimina = false;

	archivo = fopen("citas.dat", "rb");
	auxiliar = fopen("auxiliar.dat", "wb");

	if (archivo == NULL || auxiliar == NULL) {
		se_elimina = false;
	} else {
		fread(&cit, sizeof(cit), 1, archivo);
		while (!feof(archivo)) {
			if (cit.codigoCit != PARA_ELIMINAR) {
				fwrite(&cit, sizeof(cit), 1, auxiliar);
			}
			fread(&cit, sizeof(cit), 1, archivo);
		}
		fclose(archivo);
		fclose(auxiliar);

		remove("citas.dat");
		rename("auxiliar.dat", "citas.dat");

		se_elimina = true;
	}
	return se_elimina;
}
void opcion_crear_historial(void){
	Historial hist;
	string rspta,apelli1,apelli2,nombres,nacim,cita,problem;
	string hosp,aler,medi,gener1,estad1,segur1,gmail;
	bool repetir=true;
	int edad,dni,genero,estado,seguro,codigoHist,telef;
	string respuesta;
	Fecha fNac;
	do {
		limpiar_pantalla();
		titulo_principal();
		cout << "\n\t\tCREAR NUEVO HISTORIAL MEDICO\n";
		cout<< "\tIngrese codigo del historial: ";
		codigoHist=obtener_entero();
			if (existe_historial(codigoHist, &hist)) {
			cout <<"\n\tEste historial ya existe"<<endl;
		}else{	
		cout << "\tApellido Paterno: ";
		getline(cin,apelli1);
		strcpy(hist.Apellido_Paterno,apelli1.c_str());
		cout << "\tApellido Materno: ";
		getline(cin,apelli2);
		strcpy(hist.Apellido_Materno,apelli2.c_str());
		cout<< "\tNombres: ";
		getline(cin,nombres);
		strcpy(hist.Nombres,nombres.c_str());
        cout<< "\tEstado Civil: ";
        cout<< "\n\t\tSoltero.....[1]";
        cout<< "\n\t\tCasado......[2]";
        cout<< "\n\t\tViudo.......[3]";
        cout<< "\n\t\tDivorciado..[4]";
        cout<< "\n\t\t";
        estado=obtener_entero(1,4);
        switch(estado){
        	case 1:
        		estad1="Soltero";
        		strcpy(hist.Estado_Civil,estad1.c_str());
        		break;
        	case 2:
        		estad1="Casado";
        		strcpy(hist.Estado_Civil,estad1.c_str());
        		break;
        	case 3:
        		estad1="Viudo";
        		strcpy(hist.Estado_Civil,estad1.c_str());
        		break;
        	case 4:
        		estad1="Divorciado";
        		strcpy(hist.Estado_Civil,estad1.c_str());
        		break;
		}
        cout<< "\tGenero: ";
        cout<< "\n\t\tFemenino.....[1]";
        cout<< "\n\t\tMasculino....[2]";
        cout<< "\n\t\t";
        genero=obtener_entero(1,2);
        switch(genero){
        	case 1: 
        		gener1="F";
        		strcpy(hist.Genero,gener1.c_str());
        		break;
        	case 2:
        		gener1="M";
        		strcpy(hist.Genero,gener1.c_str());
        		break;
		}
        cout<< "\tFecha de Nacimiento: ";
       	cout<<"\n\tDia: ";
       	cin>>fNac.dia;
       	hist.Fecha_Nac.dia = fNac.dia;
       	cout<<"\tMes: ";
       	cin>>fNac.mes;
		hist.Fecha_Nac.mes = fNac.mes;
       	cout<<"\tAnio: ";
       	cin>>fNac.anio;
		hist.Fecha_Nac.anio = fNac.anio;
		
		hist.edad = obtener_edad(fNac);
        cout<< "\tDNI: ";
        fflush(stdin);
		dni=obtener_entero();
        hist.DNI=dni;
        cout<< "\tTelefono: ";
        telef=obtener_entero();
        hist.telefono=telef;
        cout<< "\tSeguro: ";
        cout<< "\n\t\tCuenta con Seguro......[1]";
        cout<< "\n\t\tNo cuenta con Seguro...[2]";
        cout<< "\n\t\t";
        
		seguro=obtener_entero(1,2);
        
		switch(seguro){
        	case 1:
        		segur1="Si";
        		strcpy(hist.Seguro,segur1.c_str());
        		break;
        	case 2:
        		segur1="No";
        		strcpy(hist.Seguro,segur1.c_str());
        		break;
		}
		fflush(stdin);
        cout<< "\tProblemas Medicos: ";
        getline(cin,problem);
        strcpy(hist.Problemas_Medicos,problem.c_str());
        fflush(stdin);
        cout<< "\tHospitalizaciones: ";
        getline(cin,hosp);
        fflush(stdin);
		strcpy(hist.Hospitalizaciones,hosp.c_str());
        cout<< "\tAlergias: ";
        getline(cin,aler);
        strcpy(hist.Alergias,aler.c_str());
        cout<< "\tMedicamentos: ";
        getline(cin,medi);
        strcpy(hist.Medicamentos,medi.c_str());   
        if (insertar_historial_archivo(hist)) {
				cout << "\n\tEl Historial fue creado satisfactoriamente" << endl;
			} else {
				cout << "\n\tExiste un error al intentar crear el historial." << endl;
				cout << "\n\tIntentelo nuevamente." << endl;
			}	
		}
		cout << "\n\tDesea seguir ingresando historiales? [S/n]: ";
		getline(cin, respuesta);
		if (!(respuesta.compare("s") == 0 || respuesta.compare("S") == 0)) {
			repetir = false;
		}
	} while (repetir);    
}
void opcion_mostrar_historial() {
	Historial *historiales;
	int num_histo;

	limpiar_pantalla();
	titulo_principal();
	historiales = obtener_his_archivo(&num_histo);

	if (num_histo == 0) {
		cout << "\n\tEl archivo esta vacio" << endl;
		pausar_pantalla();
	} else {

		cout << "\n\t\t\t\tHISTORIALES REGISTRADOS\n";
		cout << "\n\t   ------------------------------------------------------------\n";
		for (int i = 0; i < num_histo; i++) {
			if (historiales[i].codigo != PARA_ELIMINAR) {
				cout << "\t\tCodigo: " << historiales[i].codigo << endl;
				cout << "\t\tApellido Paterno: " << historiales[i].Apellido_Paterno << endl;
				cout << "\t\tApellido Materno: " << historiales[i].Apellido_Materno << endl;
				cout << "\t\tNombres: " << historiales[i].Nombres << endl;
				cout << "\t\tEstado Civil: " << historiales[i].Estado_Civil<< endl;
				cout << "\t\tGenero: " << historiales[i].Genero << endl;
				cout << "\t\tFecha de Nacimiento: ";
				cout << "\n\t\tDia: "<<historiales[i].Fecha_Nac.dia<<endl;
				cout << "\t\tMes: "<<historiales[i].Fecha_Nac.mes<<endl;
				cout << "\t\tAnio: "<<historiales[i].Fecha_Nac.anio<<endl;
				cout << "\t\tEdad: "<< historiales[i].edad<< endl;
				cout << "\t\tDNI: "<< historiales[i].DNI<< endl;
				cout << "\t\tTelefono: "<< historiales[i].telefono<<endl;
				cout << "\t\tSeguro: "<< historiales[i].Seguro<<endl;
				cout << "\t\tProblemas Medicos: "<< historiales[i].Problemas_Medicos<<endl;
				cout << "\t\tHospitalizaciones: "<< historiales[i].Hospitalizaciones<<endl;
				cout << "\t\tAlergias: "<< historiales[i].Alergias<<endl;
				cout << "\t\tMedicamentos: "<< historiales[i].Medicamentos<<endl;	
			}
			cout << "\n\t   ------------------------------------------------------------\n";
		}
		pausar_pantalla();
	}
}
void menu_historial() {
	bool repetir = true;
	FILE* archivo;
	char historial[20]="historial.dat";
	int opcion;

	do {
		menu_historial_opciones();
		opcion = obtener_entero();
		switch (opcion) {
			case 1:
				opcion_crear_archivo(archivo,historial);
				break;					
			case 2:
				opcion_crear_historial();
				break;
			case 3:
				opcion_mostrar_historial();
				break;
			/*case 3:
				opcion_actualizar_historial();
				break;*/
			case 4:
				repetir = false;
				break;
		}
	} while (repetir);
}

void opcion_crear_archivo(FILE *archivoCita,char nombreArchivo[20])
{
	archivoCita = fopen(nombreArchivo,"wb");
	
	if(archivoCita == NULL)
	{
		system("cls");
		titulo_principal();
		cout<<"\n\tEl archivo no se pudo crear."<<endl;
		pausar_pantalla();
	}
	else
	{
		system("cls");
		titulo_principal();
		cout<<"\n\tEl archivo se creo correctamente. "<<endl;
		pausar_pantalla();
	}
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
