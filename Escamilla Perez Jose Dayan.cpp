#include <iostream>
#include <conio.h>


using namespace std;

struct nodo
{
	string nombre;
	int edad;
	nodo *anterior;
	nodo * siguiente;
} *primero=NULL, *ultimo=NULL;

void insertar();
void ver_lista();
void jugar();
void eliminar_nodo(string);


int main(){
	nodo *ant, *sig;
	char res;
	int edad, opc;
	string nombre;

	do {
		system("cls");
		cout<< "\t" << '\n';
		cout<< "1) Ingresar nuevo jugador \n";
		cout<< "2) Mostrar jugadores ingresados \n";
		cout<< "3) Jugar ahora \n";
		cout<< "4) Salir \n";
		cout<< "Seleccione una Opcion \n";
		cin>> opc;
		switch (opc) {
			case 1:
				cout<< "Ingresar jugador \n";
				insertar();
				getch();
				break;
			case 2:
				cout<< "Mostrar Jugadores\n";
				ver_lista();
				getch();
				break;
			case 3:
				cout<< "Zapatito Blanco zapatito azul dime cuantos años tienes tu... \n";
				jugar();
				getch();
				break;
			case 4:
				cout<< "Enter para Salir \n";
				getch();
				break;
			default:
				cout<< "Error \n";
		}
	} while(opc != 4);

	return 0;
}

void insertar(){
	nodo *nuevo = new nodo();
	cout<< "\n Nombre del nino  " << " ";
	cin>> nuevo -> nombre;
	cout<< "Edad" << " ";
	cin>> nuevo -> edad;

	if (primero==NULL) {
		primero=nuevo;
		ultimo=nuevo;
		primero -> siguiente=primero;
		primero -> anterior=ultimo;
	}else{
		ultimo -> siguiente=nuevo;
		nuevo -> anterior=ultimo;
		nuevo -> siguiente=primero;
		ultimo=nuevo;
		ultimo -> siguiente = primero;
		primero -> anterior=ultimo;
	}
	cout<< "correctamente agregado \n";
};

void ver_lista() {
	nodo *actual = new nodo();
	actual = primero;
	if (primero!=NULL && primero!=0) {
		do {
			cout<< actual -> nombre << " " << actual -> edad << '\n';
			actual = actual -> siguiente;
		} while(actual!=primero);
	}else{
		cout<< "No hay nadie en la lista \n";
	}
}


void jugar() {
	nodo *otro = new nodo();
	otro = primero;
	nodo *actual = new nodo();
	actual = primero;
	nodo *sentido_reloj = new nodo();

	string nom_eliminar;
	bool bandera=false;
	int cont=0;
	int asignar_edad;
	int i=1, j=0, k=0;

	do {
		i;
		otro = otro -> siguiente;
		i = i + 1;
	} while(i != 14);

	cout<< "El inicia con: "<< otro -> nombre<<"  que tiene "<< otro -> edad<<" Anios \n";
	asignar_edad = otro -> edad;
	sentido_reloj = otro;

	if (primero!=NULL) {
		do {
			actual = actual -> siguiente;
			cont=cont+1;
		} while(actual!=primero);
	}

	if(cont==1){
		cout<< "El nino: " << actual -> nombre << "  Es el unico jugador \n";
	}else
	{

		j = cont;

		do {
			j;
			if (bandera==false && cont!=1 && cont>1) {
				do {
					k;
					sentido_reloj = sentido_reloj -> siguiente;
					k = k + 1;
				} while(k != asignar_edad);
				k=0;

				asignar_edad = 0;
				asignar_edad = sentido_reloj -> edad;
				cout<< "Sale el jugador: " << sentido_reloj -> nombre << '\n';
				
				nom_eliminar = sentido_reloj -> nombre;
				eliminar_nodo(nom_eliminar);
				bandera=true;
			}else if(bandera==true && cont != 1 ){
				
				
				do {
					k;
					sentido_reloj = sentido_reloj -> anterior;
					k = k + 1;
				} while(k != asignar_edad);
				k=0;
				asignar_edad = 0;
				asignar_edad = sentido_reloj -> edad;
				cout<< "Sale el Jugador: " << sentido_reloj -> nombre << '\n';
				
				
				nom_eliminar = sentido_reloj -> nombre;
				eliminar_nodo(nom_eliminar); 
				bandera=false;
			}

			j = j - 1;
			actual = primero;

			if (j==1) {
				do {
					cout<< "El jugador: " << actual -> nombre << " Gano el Juego \n";
					actual = actual -> siguiente;
				} while(actual!=primero);
				cout<< "\n el juego Termino ";
				}
				cont=j;
		} while(j != 1);
	}
	getch();
}


void eliminar_nodo(string nom_eliminar) {
	nodo *actual = new nodo();
	actual = primero;
	nodo *anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	string nodo_buscado;
	nodo_buscado = nom_eliminar;
	if (primero!=NULL) {
		do {
				if (actual -> nombre == nodo_buscado) {
						if (actual == primero) {
								primero = primero -> siguiente;
								primero -> anterior = ultimo;
								ultimo -> siguiente = primero;
								delete actual;
						}else if (actual == ultimo) {
								ultimo = anterior;
								ultimo -> siguiente = primero;
								primero -> anterior = ultimo;
								delete actual;
						}else{
								anterior -> siguiente = actual -> siguiente;
								actual -> siguiente -> anterior = anterior;
								delete actual;
						}
						encontrado = true;
				}
				anterior = actual;
				actual = actual -> siguiente;
		} while((actual != primero) && (encontrado != true));
		if (! encontrado) {
				cout<< "Nodo no encontrado \n";
		}
	}else{
	cout<< "Lista vacia \n";
	}	
}
