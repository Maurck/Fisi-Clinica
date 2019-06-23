#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define PARA_ELIMINAR -1
using namespace std;

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
	char Genero;
	Fecha Fecha_Nac;
	int DNI;
	int Edad;
	int telefono;
	char Seguro[10];
	char Problemas_Medicos[200];
	char Hospitalizaciones[200];
	char Alergias[200];
	char Medicamentos[200];
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

struct Cita {
	int codigoCit;
	int DNI;
	char Especialidad[30];
	Fecha fechaCita;
};

void menu_principal();

void menu_cita();//PRINCIPAL
void menu_cita_opciones();

void opcion_crear_archivo(FILE *archivoCita,char nombreArchivo[20]);
void opcion_agregar_cita();
bool insertar_cita_archivo(Cita cit);
bool existe_cita(int codigoCit, Cita *cit);
bool doctor_libre(char Especialidad[30],Fecha fCita);

bool existe_historial(int DNI,Historial *hist);

void opcion_mostrar_cita();
Cita *obtener_array_cita(int *n);

void menu_historial();//PRINCIPALL
void menu_historial_opciones(void);

void opcion_crear_historial();
bool insertar_historial_archivo(Historial hist);
bool existe_historial(int codigo_historial,Historial *hist);

void opcion_mostrar_historial();
Historial *obtener_his_archivo(int *n);

int obtener_edad(Fecha fEdad);

void menu_medico();//PRINCIPAL
void menu_medico_opciones();
void opcion_crear_medico();
bool insertar_medico_archivo(Medico user);
bool existe_medico(int codigo,Medico *user);
void opcion_mostrar_medico();
Medico *obtener_stu_archivo(int *n);
void opcion_actualizar_medico();
bool modificar_archivo_medico(Medico user);


void menu_reportes();///LEONIDAS ACA ENTRAS
void menu_reportes_opciones();

void opcion_especialidad_masolicitada();
void opcion_promedio_edad();
void opcion_promedio_edad_x_especialidad();
void opcion_ganancia_servicio();///LEONIDAS ACA TERMINA


int obtener_entero();
int obtener_entero(int inf, int sup);
bool es_entero_valido(string str);
double obtener_flotante();
bool es_flotante_valido(string str);
bool fecha_rango_valido(Fecha fCita);
bool hora_rango_valido(Fecha fCita);
bool fecha_valida(Fecha fCita);


void pausar_pantalla();
void titulo_principal(void);


int main()
{	
	menu_principal();	
	return 0;
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
			//	menu_especialidad();
				break;
			case 3:
			//	menu_servicios();
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
	system("cls");
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

void menu_cita() {
	bool se_repite = true;
	int opcion;
	FILE *aCita;
	char nombreArchivo[] = "citas.dat";

	do {
		menu_cita_opciones();
		opcion = obtener_entero(1,4);

		switch (opcion) {
			case 1:
				opcion_crear_archivo(aCita,nombreArchivo);
				break;
			case 2:
				opcion_agregar_cita();
				break;
			case 3:
				opcion_mostrar_cita();
				break;
			case 4:
				se_repite = false;
				break;
		}
	} while (se_repite);
}

void menu_cita_opciones() {
	system("cls");
	titulo_principal();
	cout << "\n\t\t\t\tMENU CITAS\n";
	cout << "\n\t\t[1]. Crear archivo citas\n";
	cout << "\t\t[2]. Agregar cita\n";
	cout << "\t\t[3]. Mostrar citas\n";
	cout << "\t\t[4]. Volver al menu principal\n";
	cout << "\n\t\tIngrese una opcion: ";
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

void opcion_agregar_cita(){
	Cita cit;
	Historial hist;
	int DNI,tipoSer,codigoCit,opcionTipoEsp;
	Fecha fCita;
	string respuesta;
	bool ninio = true,mujer = true,se_repite = true;
	char med[30] = "Medicina General",ped[30] = "Pediatria",gin[30] = "Ginecologia";
	
	
	do {
		system("cls");
		titulo_principal();
		cout << "\n\t\tCREAR NUEVA CITA\n";
		
		cout << "\tIngresa el Codigo de la cita: ";
		codigoCit = obtener_entero();
		
		if(existe_cita(codigoCit,&cit))
		{
			cout<<"\n\tEsta cita ya existe"<<endl;
		}else{
			
			cout << "\tIngresa el DNI del usuario: ";
			DNI = obtener_entero();
		
			if (existe_historial(DNI,&hist)) {
		
			cit.codigoCit = codigoCit;
			cit.DNI = DNI;
			
			do {
				ninio = true,mujer = true;
				system("cls");
				titulo_principal();
				cout << "\n\t\tCREAR NUEVA CITA\n";
				cout << "\tIngresa el Codigo de la cita: "<<codigoCit<<endl;
				cout << "\tIngresa el DNI del usuario: "<<DNI<<endl;
					
				cout<<"\n\tSeleccione la Especialidad: "<<endl;
			
				cout<<"\n\t1.- Medicina General."<<endl;
				cout<<"\t2.- Pediatria."<<endl;
				cout<<"\t3.- Ginecologia."<<endl;
				cout<<"\tDigite la opcion: ";
			
				opcionTipoEsp = obtener_entero(1,3);
			
				switch(opcionTipoEsp)
				{
					case 1:
						strcpy(cit.Especialidad,med);
						break;
					case 2:
						strcpy(cit.Especialidad,ped);
						break;
					case 3:
						strcpy(cit.Especialidad,gin);
						break;
				}
			
				if(opcionTipoEsp == 2)
				{
					if(hist.Edad > 12)
					{
						cout<<"\n\tSolo los niños pueden acceder a Pediatria. "<<endl;
						cout<<"\n\t";
						system("pause");
						ninio = false;	
					}	
				}else if(opcionTipoEsp == 3)
				{
					if(hist.Genero != 'F')
					{
						cout<<"\n\tSolo las mujeres pueden acceder a Ginecologia. "<<endl;
						cout<<"\n\t";
						system("pause");
						mujer = false;
					}	
				} 
			}while(!ninio || !mujer);
			
			cout << "\n\tDigite la fecha de la cita: ";
			
			cout<<"\n\tDia: ";
			fCita.dia = obtener_entero();
			cout<<"\tMes: ";
			fCita.mes = obtener_entero();
			cout<<"\tAño: ";
			fCita.anio = obtener_entero();
			
			do{
				system("cls");
				titulo_principal();
				cout << "\n\t\tCREAR NUEVA CITA\n";
				cout << "\tIngresa el Codigo de la cita: "<<codigoCit<<endl;
				cout << "\tIngresa el DNI del usuario: "<<DNI<<endl;
					
				cout<<"\n\tSeleccione la Especialidad: "<<endl;
			
				cout<<"\n\t1.- Medicina General."<<endl;
				cout<<"\t2.- Pediatria."<<endl;
				cout<<"\t3.- Ginecologia."<<endl;
				cout<<"\tDigite la opcion: "<<opcionTipoEsp<<endl;
				
				cout << "\n\tDigite la fecha de la cita: ";
				cout<<"\n\tDia: "<<fCita.dia;
				cout<<"\n\tMes: "<<fCita.mes;
				cout<<"\n\tAño: "<<fCita.anio;
				
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
				
				if(!doctor_libre(cit.Especialidad,fCita))
				{	
					cout<<"\n\tEl doctor no esta disponible a esa hora, digite otra ";
					cout<<"\n\t";
					system("pause");
				}
			
			}while(!doctor_libre(cit.Especialidad,fCita));
			
			if(!fecha_valida(fCita) || !fecha_rango_valido(fCita) || !hora_rango_valido(fCita))
			{
				cout << "\n\tLa fecha de la cita es incorrecta." << endl;	
			}else if (insertar_cita_archivo(cit)) {
				cout << "\n\tLa cita fue creada satisfactoriamente" << endl;
			} else {
				cout<< "\n\tLa cita no se pudo crear correctamente, intentelo mas tarde " << endl;
			}	
		} else {
			cout << "\n\tEl paciente no existe" << endl;
				cout << "\tIntentelo nuevamente" << endl;
		}
		}
		
		cout << "\n\tDesea continuar? [S/n]: ";
		getline(cin, respuesta);
		
		if (!(respuesta.compare("s") == 0 || respuesta.compare("S") == 0))
			se_repite = false;
		else
			menu_principal();
		
	} while (se_repite);	
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

Cita *obtener_array_cita(int *n) {
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

bool hora_rango_valido(Fecha fCita)
{
	bool rango_valido = true;
	
	if(fCita.hora > 24 || fCita.hora < 0 || fCita.minutos > 60 || fCita.minutos < 0)
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

bool existe_historial(int DNI,Historial *hist){
	FILE* datosHistorial;
	bool existe=false;
	
	datosHistorial=fopen("Historial.dat","rb");
	if(!(datosHistorial==NULL)){
		fread(&(*hist),sizeof(*hist),1,datosHistorial);
		while(!feof(datosHistorial)){
			if((*hist).DNI==DNI){
				existe=true;
				break;
			}
			fread(&(*hist),sizeof(*hist),1,datosHistorial);
		}
		fclose(datosHistorial);
	}
	return existe;
}

bool doctor_libre(char Especialidad[30],Fecha fCita)
{
	bool doctorLibre = true;
	int minsCit,minsCitas,n;
	minsCit = fCita.hora*60 + fCita.minutos;
	Cita *citas;
	
	citas = obtener_array_cita(&n);
	
	for(int i=0;i<n;i++)
	{
		minsCitas = citas[i].fechaCita.hora * 60 + citas[i].fechaCita.minutos;
		if(strcmp(citas[i].Especialidad,Especialidad) == 0)
		{
			if(citas[i].fechaCita.anio == fCita.anio && citas[i].fechaCita.mes == fCita.mes && citas[i].fechaCita.dia == fCita.dia)
			{	
				if(minsCit >= minsCitas && minsCit <= minsCitas + 60)
					doctorLibre = false;
			}
		}
	}
	return doctorLibre;
}

void opcion_mostrar_cita() {
	Cita *citas;
	int nro_citas;

	system("cls");
	titulo_principal();
	citas = obtener_array_cita(&nro_citas);

	if (nro_citas == 0) {
		cout << "\n\tEl archivo esta vacio" << endl;
		pausar_pantalla();
	} else {

		cout << "\n\t\t\t\tCITAS REGISTRADAS\n";
		cout << "\n\t   ------------------------------------------------------------\n";
		for (int i = 0; i < nro_citas; i++) {
			//if (citas[i].codigoCit != PARA_ELIMINAR) {
				cout << "\t\tCodigo de la cita: " << citas[i].codigoCit << endl;
				cout << "\t\tDNI del paciente: " << citas[i].DNI << endl;
				cout << "\t\tEspecialidad: " << citas[i].Especialidad << endl;
				cout << "\t\tFecha de la cita: " << citas[i].fechaCita.dia << "/"<< citas[i].fechaCita.mes << "/" << citas[i].fechaCita.anio << endl;
				cout << "\t\tHora de la cita: "<<citas[i].fechaCita.hora << ":" << citas[i].fechaCita.minutos << endl;
			//}
			cout << "\n\t   ------------------------------------------------------------\n";
		}
		pausar_pantalla();
	}
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
	system("cls");
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
		system("cls");
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

	system("cls");
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
		system("cls");
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

void opcion_crear_historial(void){
	Historial hist;
	string rspta,apelli1,apelli2,nombres,nacim,cita,problem;
	string hosp,aler,medi,estad1,segur1,gmail;
	bool repetir=true;
	int edad,dni,genero,estado,seguro,codigoHist,telef;
	string respuesta;
	Fecha fNac;
	do {
		system("cls");
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
        		hist.Genero = 'F';
        		break;
        	case 2:
        		hist.Genero = 'M';
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
		
		hist.Edad = obtener_edad(fNac);
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

	system("cls");
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
				cout << "\t\tEdad: "<< historiales[i].Edad<< endl;
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

void menu_historial_opciones(void) {
	system("cls");
	titulo_principal();
	cout << "\n\t\t\t\tMENU HISTORIAL MEDICO\n";
	cout << "\n\t\t[1]. Crear archivo historial\n";
	cout << "\t\t[2]. Agregar Historial\n";
	cout << "\t\t[3]. Mostrar historial medico\n";
	cout << "\t\t[4]. Volver al menu principal\n";
	cout << "\n\t\tIngrese una opcion: ";
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

void menu_reportes() { //LEONIDAS ACA EMPIENZA
	void menu_principal_opciones();
	bool se_repite = true;
	int opcion;

	do {
		menu_reportes_opciones();
		opcion = obtener_entero();

		switch (opcion) {
			case 1:
				opcion_especialidad_masolicitada();
				break;
			case 2:
				opcion_promedio_edad();
				break;
			case 3:
				opcion_promedio_edad_x_especialidad();
				break;
			case 4:
				opcion_ganancia_servicio();
				break;
			case 5:
				se_repite = false;
				break;
		}
	} while (se_repite);
}

void menu_reportes_opciones(void) {
	system("cls");
	titulo_principal();
	cout << "\n\t\t\t\tMENU SERVICIOS\n";
	cout << "\n\t\t[1]. Especialidad mas solicitada\n";
	cout << "\t\t[2]. Edad promedio\n";
	cout << "\t\t[3]. Edad promedio por especialidad\n";
	cout << "\t\t[4]. Gancancia por cada servicio\n";
	cout << "\t\t[5]. Volver al menu principal\n";
	cout << "\n\t\tIngrese una opcion: ";
}

void opcion_especialidad_masolicitada(){
	int prueba;
	titulo_principal();
	cout << "\n\t\t\t\tMENU CITA\n";
	pausar_pantalla();
}

void opcion_promedio_edad(){
Historial *historiales;
int num_histo;
float sumaEdad=0;
float promedio;

	system("cls");
	titulo_principal();
	historiales = obtener_his_archivo(&num_histo);

		cout << "\n\t\t\t EDAD PROMEDIO\n";
		cout << "\n\t   ------------------------------------------------------------\n";
		for (int i = 0; i < num_histo; i++) {
				sumaEdad=sumaEdad+historiales[i].Edad;
			}
			promedio=(sumaEdad)/num_histo;
			cout<<"\n\tLa edad promedio registrado de todos los pacientes es: "<<promedio;
			cout<<endl; 
			cout << "\n\t   ------------------------------------------------------------\n";
			
	pausar_pantalla();
}
	


void opcion_promedio_edad_x_especialidad(){
	system("cls");
	pausar_pantalla();
}

void opcion_ganancia_servicio(){
	int prueba;
	titulo_principal();
	cout << "\n\t\t\t\tMENU CITA\n";
	pausar_pantalla();
}

void titulo_principal(void) {
	cout << "\n     ======================================================================\n";
	cout << "\t\t\t\t CLINICA FISI\n";
	cout << "     ======================================================================\n";
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
	int i=0;
	bool valido = true;
	if (str.length() == 0) {
		valido = false;
	}
	
	while (valido && i < int(str.length())) {
		if (!isdigit(str.at(i))) {
			valido = false;
		}
		i++;
	}

	return valido;
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
