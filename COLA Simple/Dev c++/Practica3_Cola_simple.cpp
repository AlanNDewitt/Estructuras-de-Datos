#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


#define MAX 8



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



class Estructura_Cola
{
  private:
  	
  	short Numero[MAX];
  	short Frente=0;
  	short Final=0;
  	short Estado;
  	bool  first_push = false;
  	
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
  		
  		if(Final == MAX - 1 )
  		{
  			gotoxy(30,15);
  			cout<<"COLA SIN ESPACIOS ";
  			
  			gotoxy(30,17);
  			cout<<"* OVERFLOW *";
  			
  			Estado = 1;
  		
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}
		
		if(Final < MAX - 1 )
		{

  			if(first_push == true)
  			{
  				Final++;
				gotoxy(30,15);
  				cout<<"Ingresa un nuevo Numero : ";
  				cin>>Numero[Final];  		
			}			
			
			if(first_push == false)
			{
				gotoxy(30,15);
  				cout<<"Ingresa un nuevo Numero : ";
  				cin>>Numero[0];	
				  
				first_push = true;			
			}

  			
  			Estado = 3;


            if(Final == MAX - 1)
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
  		
  		
 		if( (Final == 0 && Numero[0] != 0)  || (Final == Frente && Final != 0) )
  		{
  			gotoxy(30,15);
  			cout<<"NO PUEDES BORRAR EL UNICO NUMERO O DEJA DE SER UNA COLA ";
  			
  			gotoxy(30,17);
  			cout<<"* Underflow *";
  			
  			Estado = 2;
  		
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}  		
  		
  		
  		
 		if(Final == 0 && Numero[0] == 0)
  		{
  			gotoxy(30,15);
  			cout<<"COLA SIN ELEMENTOS ";
  			
  			gotoxy(30,17);
  			cout<<"* Underflow *";
  			
  			Estado = 2;
  		
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}
		
		if(Final > 0  && Final != Frente)
		{
			Frente++;
			
  			if(Frente == MAX - 1)
  			{
  				Estado = 1;
			}
			
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
		}
		
 		
		if(Frente > MAX-1 && Final >= MAX - 1)
  		{
  			gotoxy(30,15);
  			cout<<"COLA SIN ELEMENTOS Y SIN ESPACIOS ";
  			
  			gotoxy(30,17);
  			cout<<"* Underflow *";
  			
  			Estado = 2;
  		
  			gotoxy(30,20);
  			cout<<"Press Enter to continue";
  			getch();
	    }
		
	}
	
	void Mostrar()
	{
		short y = 14;
		
  		system("cls");
  		
  		gotoxy(15,3);
		cout<<"  #####                                #####";
		gotoxy(15,4);
		cout<<" #     #  #    #   ####   #    #      #     #   ####   #         ##";
		gotoxy(15,5);
		cout<<" #        #    #  #    #  #    #      #        #    #  #        #  #";
		gotoxy(15,6);
		cout<<"  #####   ######  #    #  #    #      #        #    #  #       #    #";
		gotoxy(15,7);
		cout<<"       #  #    #  #    #  # ## #      #        #    #  #       ######";
		gotoxy(15,8);
		cout<<" #     #  #    #  #    #  ##  ##      #     #  #    #  #       #    #";
		gotoxy(15,9);
		cout<<"  #####   #    #   ####   #    #       #####    ####   ######  #    #";



		gotoxy(75,13);
		switch(Estado)
		{
			case 1 :
			cout<<"ESTADO DE LA COLA : LLENA ";
			break;

			case 2 :
			cout<<"ESTADO DE LA COLA : VACIA ";
			break;

			case 3 :
			cout<<"ESTADO DE LA COLA : NEUTRAL";
			break;
		}
		
		
		gotoxy(15,12);
		cout<<"Posicion";
		gotoxy(25,12);
		cout<<"Contenido";

		for(short i = 0 ; i < MAX; i++)
		{
			gotoxy(17,y);
			cout<<(i+1);
			
			if(Frente == i )
			{
				gotoxy(39,y);
				cout<<("Frente");				
			}
			
			if(Final == i )
			{
				gotoxy(39,y);
				cout<<("Final");				
			}
			
			if(Frente == i && Final ==i)
			{
				gotoxy(39,y);
				cout<<("Frente y Final");
			}
			
			
					
			gotoxy(27,y);
			if(i >= Frente )
			{
				if(Numero[i] == 0)
				{
					cout<<"          ";
				} 
				
				else
				{
					cout<<Numero[i];
				}
				
			}
			
			

			gotoxy(16,y+1);
			cout<<"---------------------";

			y++;
			y++;
		}

  		y = 14;


		gotoxy(90,26);
		cout<<"Press Enter to continue";
		getch();
	}
	
  	

}Cola;





void Menu()
{
	short option;

  do
  {

	system("cls");

	gotoxy(5,1);
	//cout<<"Elementos en Pila : "<<contador;

   gotoxy(80,1);
   cout<<"* Practica 3  *";

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
	cout<<"3.-SHOW COLA";
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
		case 1 : Cola.Ingreso(); break;
		case 2 : Cola.Borrar(); break;
		case 3 : Cola.Mostrar(); break;
		case 4 :  break;
	}
  
  
  } while(option != 4);
  
}






int main()
{
   Beep(500,3000);
	
   Menu();

   system("cls");
   
   gotoxy(50,15);
   cout<<("PROGRAMA TERMINADO");
   
   Beep(1000,3000);
   
   gotoxy(80,25);
   cout<<("-> Suarez Vega Edgar Alan <-");  

   
  return 0;


}
