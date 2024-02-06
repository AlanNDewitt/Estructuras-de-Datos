
#include <iostream>                                                                      //EDGAR ALAN SUAREZ VEGA
#include <conio.h>
#include <windows.h>

                                  

//-------------------------------------------------------------------------------------
void gotoxy(int x, int y)  // funcion de posicionamiento
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}
//--------------------------------------------------------------------------------------


class Nodo 
{
  public :
  
    short dato;
    
    Nodo* derecha;
    Nodo* izquierda;
    Nodo* padre;
    
    Nodo()
    {
        dato = 0;
        derecha = NULL;
   		izquierda = NULL;
    	padre = NULL;
    }
    
    Nodo(short number, Nodo* father) 
	{
		dato = number;
        derecha = NULL;
   		izquierda = NULL;
    	padre = father;
    }
    
    short obtener_dato()
    {
    	return dato;
	}
	
};


Nodo* primer_nodo = NULL;   //el puntero del primer nodo al inicio es nulo ya que no apunta a nada todavia





	short Ingresar_nodo_visual()
	{
		short n;
		
 		system("cls");

  		gotoxy(15,3);
		cout<<" ###";
		gotoxy(15,4);
		cout<<"  #   #    #   ####   #####   ######   ####     ##    #####       #####     ##    #####   ####";
		gotoxy(15,5);
		cout<<"  #   ##   #  #    #  #    #  #       #        #  #   #    #      #    #   #  #     #    #    #";
		gotoxy(15,6);
		cout<<"  #   ##   #  #    #  #    #  #       #        #  #   #    #      #    #   #  #     #    #    #";
		gotoxy(15,7);
		cout<<"  #   # #  #  #       #    #  #####    ####   #    #  #    #      #    #  #    #    #    #    #";
		gotoxy(15,8);
		cout<<"  #   #  # #  #  ###  #####   #            #  ######  #####       #    #  ######    #    #    #";
		gotoxy(15,9);
		cout<<"  #   #   ##  #    #  #   #   #       #    #  #    #  #   #       #    #  #    #    #    #    #";
		gotoxy(15,10);
		cout<<" ###  #    #   ####   #    #  ######   ####   #    #  #    #      #####   #    #    #     ####";
  		
  		
  		gotoxy(20,15);
  		cout<<"Ingreso";
  			
  		gotoxy(20,17);
  		cout<<"Ingresa el nuevo Numero : ";
  		cin>>n;
  		
  		return n;
		
	}
	
short nodos=0;
	
  	void Ingresar_nodo(Nodo *&arbol,short numero, Nodo *padre)                //Funcion publica hace la operacion de ingresar al arbol nuevos nodos
  	{	
  		
  		short valor_raiz;
  			
  		
  		if(arbol == NULL)
  		{
  			Nodo *nuevo_Nodo = new Nodo(numero, padre);
			arbol = nuevo_Nodo;
			
			nodos++;		
		}
		
		else
		{	
			valor_raiz = arbol->dato;
			
			if (numero < valor_raiz)
			{
				Ingresar_nodo(arbol->izquierda,numero, arbol);
			} 
			
			else
			{
				Ingresar_nodo(arbol->derecha,numero, arbol);	
			}
  		
 		}
 		
 		
 	 	
	}
	
	

	
    void Mostrar_arbol_R_D_I(Nodo* arbol, short contador)       //Funcion que hace la operacion de imprimir arbol horizontalmente
	{

		
		if(arbol == NULL)
		{

		}
		
		else
		{
			cout<<arbol->dato<<endl;
			
			Mostrar_arbol_R_D_I(arbol->derecha, contador+0);

			for(int i = 0; i < contador; ++i)
			{
				
				cout<<"   ";
			}
			
			
			Mostrar_arbol_R_D_I(arbol->izquierda, contador+0);
	
		}

	}
	
	void Mostrar_arbol_normal(Nodo* arbol, short contador)       //Funcion que hace la operacion de imprimir arbol horizontalmente
	{
		if(arbol == NULL)
		{

		}
		
		else
		{
			
			
			Mostrar_arbol_normal(arbol->derecha, contador+1);

			for(int i = 0; i < contador; ++i)
			{
				
				cout<<"   ";
			}
			
			cout<<arbol->dato<<endl;
			Mostrar_arbol_normal(arbol->izquierda, contador+1);
	
		}		

	}

	

void Menu()
{
	short option;
	short cont=0;
	short number;

  do
  {

	system("cls");

    gotoxy(70,1);
    cout<<"* Practica 6 Arbol BB  (Nodos) *";

	gotoxy(15,3);
	cout<<" #######";
	gotoxy(15,4);
	cout<<" #     #  #####   ######  #####     ##     ####   #   ####   #    #  ######   ####";
	gotoxy(15,5);
	cout<<" #     #  #    #  #       #    #   #  #   #    #  #  #    #  ##   #  #       #";
	gotoxy(15,6);
	cout<<" #     #  #    #  #####   #    #  #    #  #       #  #    #  # #  #  #####    ####";
	gotoxy(15,7);
	cout<<" #     #  #####   #       #####   ######  #       #  #    #  #  # #  #            #";
	gotoxy(15,8);
	cout<<" #     #  #       #       #   #   #    #  #    #  #  #    #  #   ##  #       #    #";
	gotoxy(15,9);
	cout<<" #######  #       ######  #    #  #    #   ####   #   ####   #    #  ######   ####";

	gotoxy(50,15);
	cout<<"1.-Ingresar nuevo Numero";
	gotoxy(50,17);
	cout<<"2.-Mostrar Arbol BB";
	gotoxy(50,19);
	cout<<"3.-EXIT";
	gotoxy(50,21);
	
    gotoxy(50,23);
	cout<<"Option : ";
	cin>>option;
	
	while(option < 1 || option > 3 )
	{
		gotoxy(50,26);
		cout<<"Ingresa una opcion correcta !";
		gotoxy(59,25);
		cout<<"                                  ";
		
		gotoxy(50,25);
		cout<<"Option : ";
		cin>>option;
			
	}
	
	switch(option)
	{
		case 1 : 
				 number = Ingresar_nodo_visual();
				 Ingresar_nodo(primer_nodo, number , NULL);
				 
				 gotoxy(90,26);
				 cout<<"Press Enter to continue";
				 getch();  	
				 
				 									break;
		
		case 2 :	
					system("cls");
					cout<<"\n\nRecorrido:  Raiz - Rama Derecha - Rama Izquierda\n\n";
					
					Mostrar_arbol_R_D_I(primer_nodo, cont);
					
					cout<<"\n\n ARBOL BB Graficamente (Horizontal)\n\n";
					
					Mostrar_arbol_normal(primer_nodo, cont);
					
					
					cout<<"\n\nArbol Binario de Busqueda con : "<<nodos<<" nodos "; 
					
					
					cout<<"\t\t\t\tPress Enter to continue";
					getch();
					
					cout<<"\n\n\n";
					
					break;
		
		case 3 :            break;
	}
  
  
  } while(option != 3);
  
}


int main()
{


   Beep(500,3000);
	
   Menu();                            //Funcion donde se almacena practicamente todas las instrucciones, usando anidacion de Funciones

   system("cls");
   
   gotoxy(50,15);
   cout<<("PROGRAMA TERMINADO");
   
   Beep(1000,3000);
   
   gotoxy(80,25);
   cout<<("-> Suarez Vega Edgar Alan <-");

   
  return 0;
                                                                                                                                           //EDGAR ALAN SUAREZ VEGA
}


