#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std; 

short contador=0;

#define MAX 4

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


class Estructura
{
  private:

    short Numero[MAX];
    short Estado;


  public:

  	void Ingreso()
  	{
  		system("cls");

  		gotoxy(15,3);
		cout<<" ######";
		gotoxy(15,4);
		cout<<" #     #  #    #   ####   #    #";
		gotoxy(15,5);
		cout<<" #     #  #    #  #       #    #";
		gotoxy(15,6);
		cout<<" ######   #    #   ####   ######";
		gotoxy(15,7);
		cout<<" #        #    #       #  #    #";
		gotoxy(15,8);
		cout<<" #        #    #  #    #  #    #";
		gotoxy(15,9);
		cout<<" #         ####    ####   #    #";
  		
  		if(contador == MAX )
  		{
  			gotoxy(30,15);
  			cout<<"PILA LLENA ";
  			
  			gotoxy(30,17);
  			cout<<"* OVERFLOW *";
  			
  			Estado = 1;
  		
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}
		
		if(contador < MAX )
		{
			gotoxy(30,15);
  			cout<<"Ingresa un nuevo Numero : ";
  			cin>>Numero[contador];
  		
  			contador++;
  			
  			Estado = 3;

         if(contador == MAX)
  			{
  				Estado = 1;
			}
  		
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}
  	
	}
	
	void Borrar()
	{
		short repetido;
  		system("cls");
  		
  		gotoxy(15,3);
		cout<<" ######";
		gotoxy(15,4);
		cout<<" #     #   ####   #####";
		gotoxy(15,5);
		cout<<" #     #  #    #  #    #";
		gotoxy(15,6);
		cout<<" ######   #    #  #    #";
		gotoxy(15,7);
		cout<<" #        #    #  #####";
		gotoxy(15,8);
		cout<<" #        #    #  #";
		gotoxy(15,9);
		cout<<" #         ####   #";
  		
 		if(contador == 0 )
  		{
  			gotoxy(30,15);
  			cout<<"PILA SIN ELEMENTOS ";
  			
  			gotoxy(30,17);
  			cout<<"* Underflow *";
  			
  			Estado = 2;
  		
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}
		
		if(contador > 0 )
		{
			
			if(Numero[contador-1] == Numero[contador - 2])
			{
				repetido = Numero[contador -2];
				
				contador = contador - 2;
				
				for(short i = contador-1  ; i > 0 ; i--)
				{
					if(Numero[i] == repetido)
					{
						contador = contador - 1;
						
					}
				}
				
				
				gotoxy(30,15);
  				cout<<"Repetidos sucecivos Eliminados";
			
				
				
				Estado = 3;

  				if(contador == 0)
  				{
  					Estado = 2;
				}
			}
			
			else
		    {
		    	gotoxy(30,15);
  				cout<<"Ultimo Numero Eliminado con Exito";

  				contador--;

  				Estado = 3;

  				if(contador == 0)
  				{
  					Estado = 2;
				}
			}
			


  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}	
		
		
	}
	
	void Mostrar()
	{
		short y = 15;
		
  		system("cls");
  		
  		gotoxy(15,3);
		cout<<"  #####";
		gotoxy(15,4);
		cout<<" #     #  #    #   ####   #    #       ####   #####    ##     ####   #    #";
		gotoxy(15,5);
		cout<<" #        #    #  #    #  #    #      #         #     #  #   #    #  #   #";
		gotoxy(15,6);
		cout<<"  #####   ######  #    #  #    #       ####     #    #    #  #       ####";
		gotoxy(15,7);
		cout<<"       #  #    #  #    #  # ## #           #    #    ######  #       #  #";
		gotoxy(15,8);
		cout<<" #     #  #    #  #    #  ##  ##      #    #    #    #    #  #    #  #   #";
		gotoxy(15,9);
		cout<<"  #####   #    #   ####   #    #       ####     #    #    #   ####   #    #";



		gotoxy(75,13);
		switch(Estado)
		{
			case 1 :
			cout<<"ESTADO DE LA PILA : LLENA ";
			break;

			case 2 :
			cout<<"ESTADO DE LA PILA : VACIA ";
			break;

			case 3 :
			cout<<"ESTADO DE LA PILA : NEUTRAL";
			break;
		}


		gotoxy(15,13);
		cout<<"Posicion";
		gotoxy(25,13);
		cout<<"Contenido";

		for(short i = contador-1 ; i >= 0 ; i--)
		{
			gotoxy(17,y);
			cout<<(i+1);
			gotoxy(27,y);
			cout<<Numero[i];

			gotoxy(16,y+1);
			cout<<"---------------------";

			y++;
			y++;
		}

  		y = 15;


		gotoxy(90,26);
		cout<<"Press Enter to continue";
		getch();
	}
	
	
	
/*	
	void Borrar_Repetidos()   //CODIGO MAL , HABIA HECHO OTRA FUNCION PARA BORRAR REPETIDOS
	{
		
  		system("cls");
  		
  		gotoxy(15,3);
		cout<<"######                                              ######                 ";
		gotoxy(15,4);
		cout<<"#     #  ######  #       ######  #####  ######      #     #  ######  #####";
		gotoxy(15,5);
		cout<<"#     #  #       #       #         #    #           #     #  #       #    #";
		gotoxy(15,6);
		cout<<"#     #  #####   #       #####     #    #####       ######   #####   #    #";
		gotoxy(15,7);
		cout<<"#     #  #       #       #         #    #           #   #    #       #####";
		gotoxy(15,8);
		cout<<"#     #  #       #       #         #    #           #    #   #       #";
		gotoxy(15,9);
		cout<<"######   ######  ######  ######    #    ######      #     #  ######  #";
		
		if(contador == 0 )
  		{
  			gotoxy(30,15);
  			cout<<"PILA SIN ELEMENTOS ";
  			
  			gotoxy(30,17);
  			cout<<"* Underflow *";
  			
  			Estado = 2;
  		
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}

		else
		{
			for(short h = 0 ; h < contador ; h++)
			{

				for(short j = h+1 ; j < contador ; j++ )
				{
			
					if(Numero[h] == Numero [j])
					{
						for(short k = j ; k < contador ; k++ )
						{
			    			Numero[k] = Numero[k+1];
							j = h;					
						}

						contador--;
					
					
				
					}
					
				}
				
			
	  		}
	  		 
	  		 
	  		 
	  		if(contador == 0)
			{
				Estado = 2;
			}
		
			else
			{
				Estado = 3;
			}
			
			
			gotoxy(30,15);
  			cout<<"REPETIDOS ELIMINADOS ";
			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		
	   
		}
    		
		
		
 		
		
	}

*/

}Pila;







void Menu()
{
	short option;

  do
  {

	system("cls");

	gotoxy(5,1);
	cout<<"Elementos en Pila : "<<contador;

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
	cout<<"1.-PUSH";
	gotoxy(50,17);
	cout<<"2.-POP";
	gotoxy(50,19);
	cout<<"3.-SHOW STACK";
	gotoxy(50,21);
	cout<<"4.-EXIT";
	gotoxy(50,23);
	//cout<<"5.-EXIT";

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
		case 1 : Pila.Ingreso(); break;
		case 2 : Pila.Borrar(); break;
		case 3 : Pila.Mostrar(); break;
		case 4 :  break;
	}
  
  
  } while(option != 4);
  
}





int main()
{
   Menu();

   system("cls");
   gotoxy(50,15);
   cout<<("PROGRAMA TERMINADO");

   getch();
   
  return 0;


}
