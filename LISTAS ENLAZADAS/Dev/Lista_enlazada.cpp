
#include <iostream>                                                                      //EDGAR ALAN SUAREZ VEGA
#include <conio.h>
#include <windows.h>


using namespace std;

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
    
    Nodo* siguiente;
    
    Nodo()
    {
        dato = 0;
        siguiente = NULL;
    }
    
    Nodo(short number) 
	{
			dato = number;
			siguiente = NULL;
    }
    
    short obtener_dato()
    {
    	return dato;
	}
	
	void asignar_dato(short numero)
	{
		dato = numero;
	}
};


Nodo* primer_nodo = NULL;   //el puntero del primer nodo al inicio es nulo ya que no apunta a nada todavia

Nodo* primer_nodo_sin_repetidos = NULL;





bool verificar_num_repetidos(short n)
{
	Nodo * node = primer_nodo;
	int i = 0;
	
	while(node != NULL)	
	{
				
		if(node->obtener_dato() == n) 
		{
			++i;
			
			if(i >= 2) 
			{
				return true;
			} 
		}
		
		node = node->siguiente;
		
	}
			
		return false;
			
}
	
  	void Ingreso()                //Funcion de Clase
  	{
  		
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
  		
  		
		Nodo* nuevo_nodo = new Nodo;
		
		Nodo* aux = new Nodo;  		
  		
  		if(primer_nodo == NULL)
  		{
  			gotoxy(20,15);
  			cout<<"Primer Ingreso";
  			
  			gotoxy(20,17);
  			cout<<"Ingresa el nuevo Numero : ";
			cin>>nuevo_nodo->dato;
			
			primer_nodo = nuevo_nodo;   			
		}
		
		else
		{
			aux = primer_nodo;
			
 			gotoxy(20,15);
  			cout<<"Ingreso";
  			
  			gotoxy(20,17);
  			cout<<"Ingresa el nuevo Numero : ";
			cin>>nuevo_nodo->dato;	
			
            while(aux->siguiente != NULL)
            {
            	aux = aux->siguiente;
			}
			
			aux->siguiente = nuevo_nodo;
				
		}
  		
 		
 	
  		
  		
		gotoxy(90,26);
		cout<<"Press Enter to continue";
		getch();  	
	}
	
	short x[99],i=0;
	
	void Borrar()               //Funcion de Clase
	{
		short opcion;
		short numero;
		short i = 0;
		
		Nodo* node ;	
		node = primer_nodo;
		
		Nodo* nodle ;
		
		
		Nodo* ok ;
		ok = primer_nodo;
		
		
		
		
  		system("cls");
  		
  		gotoxy(15,3);
		cout<<" ######";
		gotoxy(15,4);
		cout<<" #     #   ####   #####   #####     ##    #####";
		gotoxy(15,5);
		cout<<" #     #  #    #  #    #  #    #   #  #   #    #";
		gotoxy(15,6);
		cout<<" ######   #    #  #    #  #    #  #    #  #    #";
		gotoxy(15,7);
		cout<<" #     #  #    #  #####   #####   ######  #####";
		gotoxy(15,8);
		cout<<" #     #  #    #  #   #   #   #   #    #  #   #";
		gotoxy(15,9);
		cout<<" ######    ####   #    #  #    #  #    #  #    #";
  		
  		
  		if(primer_nodo == NULL)
  		{
  			gotoxy(20,15);
  			cout<<"Todavia no hay Numeros ingresados"; 			
		}
		
		else
		{
		

			i=0;
			
			short y = 15;
			
			
			gotoxy(48,13);
			cout<<"LISTA";
			
			while(node != NULL)
			{
				if(verificar_num_repetidos(node->obtener_dato()) == false )
				{
					//nodle = new Nodo(node->getNumber(), newNode);
					gotoxy(48,y);
					cout<<"| "<<node->obtener_dato()<<" |";
					y++;
				}
				
				node = node->siguiente;
			}
			
			//start = newNode;
		    


			
			gotoxy(20,17);
  			cout<<"Borrando Repetidos : ";
  			
		}
  	
 

 		
		gotoxy(90,26);
		cout<<"Press Enter to continue";
		getch();
		
	}
	
	
	
    void Mostrar()       //Funcion de Clase
	{
		Nodo* recorre = new Nodo;
		
		short y = 16;
		
		bool repetido = false;
		
  		system("cls");
  		
  		gotoxy(15,3);
		cout<<" #     #                      #     #";
		gotoxy(15,4);
		cout<<" #     #  ######  #####       ##    #  #    #  #    #  ######  #####    ####    ####";
		gotoxy(15,5);
		cout<<" #     #  #       #    #      # #   #  #    #  ##  ##  #       #    #  #    #  #";
		gotoxy(15,6);
		cout<<" #     #  #####   #    #      #  #  #  #    #  # ## #  #####   #    #  #    #   #### ";
		gotoxy(15,7);
		cout<<"  #   #   #       #####       #   # #  #    #  #    #  #       #####   #    #       #";
		gotoxy(15,8);
		cout<<"   # #    #       #   #       #    ##  #    #  #    #  #       #   #   #    #  #    #";
		gotoxy(15,9);
		cout<<"    #     ######  #    #      #     #   ####   #    #  ######  #    #   ####    ####";		

		
		if(primer_nodo == NULL)
		{
			gotoxy(20,15);
			cout<<"Todavia no hay numeros ingresados";
		}
		
		else
		{
			recorre = primer_nodo;
			
			gotoxy(30,14);
			cout<<" LISTA ";
			
			while(recorre != NULL)
			{
				
		
				gotoxy(30,y);
				cout<<"| "<<recorre->dato<<" |";
				y++;	
				
						
				recorre = recorre->siguiente;
				
			}
		}











		gotoxy(90,26);
		cout<<"Press Enter to continue";
		getch();
	}



void Menu()
{
	short option;

  do
  {

	system("cls");
	
	gotoxy(3,2);

    gotoxy(70,1);
    cout<<"* Practica 5 Lista Enlazada Simple (Nodos) *";

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
	cout<<"1.-Ingresar nuevo Dato";
	gotoxy(50,17);
	cout<<"2.-Mostrar Borrando Repetidos";
	gotoxy(50,19);
	cout<<"3.-Mostrar Todos los Datos";
	gotoxy(50,21);
	cout<<"4.-EXIT";
	gotoxy(50,23);

    gotoxy(50,25);
	cout<<"Option : ";
	cin>>option;
	
	while(option < 1 || option > 4 )
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
		case 1 : Ingreso(); break;
		case 2 : Borrar();  break;
		case 3 : Mostrar(); break;
		case 4 :            break;
	}
  
  
  } while(option != 4);
  
}


int main()
{

   //-----------------------------------------------



   //-------------------------------------------------

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

