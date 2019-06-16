#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

struct Historial{
	int codigo;
	char Apellido_Paterno[15];
	char Apellido_Materno[15];
	char Nombres[25];
	char Estado_Civil[11];
	char Genero;
	char Fecha_Nacim[8];
	char Dia_cita[8];
	int Edad;
	int DNI;
	char seguro[2];
	char Problemas_Medicos[200];
	char Alergias[200];
	char Medicamentos[200];
};

struct Fecha{
	int dia;
	int mes;
	int anio;
	int hora;
	int minutos;
};

struct Cita {
	int codigoCit;
	int DNI;
	char Especialidad[30];
	Fecha fechaCita;
};

void menu_principal();

void menu_cita();
void menu_cita_opciones();

void opcion_crear_archivo(FILE *archivoCita,char nombreArchivo[20]);
void opcion_agregar_cita();
bool insertar_cita_archivo(Cita cit);
bool existe_cita(int codigoCit, Cita *cit);
bool doctor_libre(char Especialidad[30],Fecha fCita);

bool existe_historial(int DNI,Historial *hist);

void opcion_mostrar_cita();
Cita *obtener_array_cita(int *n);

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

void pruebaHistorial(int dni,int edad,char genero){
	FILE *archivo;
	Historial hist;
	
	hist.DNI = dni;
	hist.Edad = edad;
	hist.Genero = genero;
	archivo = fopen("historial.dat","wb");
	fclose(archivo);
	archivo = fopen("historial.dat","ab");
	fwrite(&hist,sizeof(hist),1,archivo);
	fclose(archivo);
}


int main()
{	
	pruebaHistorial(76536666,10,'F'); //Parametros: DNI,EDAD,GENERO DE 1 PACIENTE EN HISTORIAL PARA PRUEBAS
	menu_cita();	
	return 0;
}

void menu_principal()
{
	
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
