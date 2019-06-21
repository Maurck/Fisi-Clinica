#include <iostream>
using namespace std;

struct Persona
{
	char nombre[20];
	char apellido[20];
	int edad;
};

int main()
{
	char temp[2];
	Persona p1[2][2];
	char arreglo[3];		
	
	for (int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<"Ingrese el nombre: ";
			gets(p1[i][j].nombre);
		}
	}
	
	for (int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<p1[i][j].nombre<<endl;
		}
	}
	
	
}
