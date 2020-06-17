#include <iostream>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

	int ile_o_0poz=0, ile_x_0poz=0, ile_o_0pion=0, ile_x_0pion=0;
	int ile_o_1poz=0, ile_x_1poz=0, ile_o_1pion=0, ile_x_1pion=0;	
	int ile_o_2poz=0, ile_x_2poz=0, ile_o_2pion=0, ile_x_2pion=0;
	int i, j;
	int pustka=9;	
	int tfu_tfu;
	int strzal_X, strzal_Y;	
	int wygrana=0;
	int ukos1x=0, ukos2x=0, ukos1o=0, ukos2o=0;
	int wybor;
	
	//tworzenie tablicy
	char t[3][3];	

void wprowadzanie ()
{
	do{
		tfu_tfu=0;
		cout<<"\n	Wprowad\253 wsp\242\210rz\251dne dla O: \n"
			<<"(UWAGA! wsp\242\210rz\251dne od 0 do 2)\n";
		do{
			cout<<"Wsp\242\210rz\251dna X: ";
			cin>>strzal_X;
			if(strzal_X>2)
				cout<<"Nieprawid\210owa wsp\242\210rz\251dna.\n"
					<<"(UWAGA! wsp\242\210rz\251dne musz\245 mie\206 warto\230\206 od 0 do 2)\n";
		}while(strzal_X>2);
		do{
			cout<<"Wsp\242\210rz\251dna Y: ";
			cin>>strzal_Y;
			if(strzal_Y>2)
				cout<<"Nieprawid\210owa wsp\242\210rz\251dna.\n"
					<<"(UWAGA! wsp\242\210rz\251dne musz\245 mie\206 warto\230\206 od 0 do 2)\n";
		}while(strzal_Y>2);
	
		if(t[strzal_Y][strzal_X]==' ')
		{
			t[strzal_Y][strzal_X]='O';
			tfu_tfu++;
		}
		else
		{
			cout<<"Pole jest ju\276 zaj\251te.\n"
				<<"Musisz wybra\206 ponownie \n";
		}
	}while(tfu_tfu==0);
}

void wyswietlanie ()
{
	cout<<"\n\n"<<(char)196<<(char)197<<(char)196<<(char)197<<(char)196<<"\n";
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<t[i][j]<<(char)179;
		}
		cout<<"\n"<<(char)196<<(char)197<<(char)196<<(char)197<<(char)196<<"\n";
	}	
}

void losowanie ()
{
	srand(time(NULL));
	int kx, ky;
	do{
		kx=rand()%3;
		ky=rand()%3;
	}while(t[ky][kx]!=' ');
		
	t[ky][kx]='X';	
}

void sprawdzanie ()
{
	ile_o_0poz=0, ile_x_0poz=0, ile_o_0pion=0, ile_x_0pion=0;
	ile_o_1poz=0, ile_x_1poz=0, ile_o_1pion=0, ile_x_1pion=0;	
	ile_o_2poz=0, ile_x_2poz=0, ile_o_2pion=0, ile_x_2pion=0;	
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(t[i][j]=='O')
			{
				if(i==0)
				{
					if(j==0)
					{
						ile_o_0pion++;
						ile_o_0poz++;
					}
					if(j==1)
					{
						ile_o_1pion++;
						ile_o_0poz++;
					}
					if(j==2)
					{
						ile_o_2pion++;
						ile_o_0poz++;
					}
				}
				if(i==1)
				{
					if(j==0)
					{
						ile_o_0pion++;
						ile_o_1poz++;
					}
					if(j==1)
					{
						ile_o_1pion++;
						ile_o_1poz++;
					}
					if(j==2)
					{
						ile_o_2pion++;
						ile_o_1poz++;
					}
				}
				if(i==2)
				{
					if(j==0)
					{
						ile_o_0pion++;
						ile_o_2poz++;
					}
					if(j==1)
					{
						ile_o_1pion++;
						ile_o_2poz++;
					}
					if(j==2)
					{
						ile_o_2pion++;
						ile_o_2poz++;
					}
				}
			}
			if(t[i][j]=='X')
			{
				if(i==0)
				{
					if(j==0)
					{
						ile_x_0pion++;
						ile_x_0poz++;
					}
					if(j==1)
					{
						ile_x_1pion++;
						ile_x_0poz++;
					}
					if(j==2)
					{
						ile_x_2pion++;
						ile_x_0poz++;
					}
				}
				if(i==1)
				{
					if(j==0)
					{
						ile_x_0pion++;
						ile_x_1poz++;
					}
					if(j==1)
					{
						ile_x_1pion++;
						ile_x_1poz++;
					}
					if(j==2)
					{
						ile_x_2pion++;
						ile_x_1poz++;
					}
				}
				if(i==2)
				{
					if(j==0)
					{
						ile_x_0pion++;
						ile_x_2poz++;
					}
					if(j==1)
					{
						ile_x_1pion++;
						ile_x_2poz++;
					}
					if(j==2)
					{
						ile_x_2pion++;
						ile_x_2poz++;
					}
				}				
			}	
		}
	}	
}


void remis ()
{
	pustka=9;
		for(i=0; i<3; i++)
		{
			for(j=0; j<3; j++)
			{
				if(t[i][j]=='O')
					pustka--;	
				if(t[i][j]=='X')
					pustka--;		
			}
		}	
}

void wygrana_ukos ()
{
	ukos1o=0;
	ukos2o=0;
	ukos1x=0;
	ukos2x=0;
	
	if(t[0][0]=='O'&&t[1][1]=='O'&&t[2][2]=='O')
		ukos1o++;
	if(t[0][2]=='O'&&t[1][1]=='O'&&t[2][0]=='O')
		ukos2o++;
	if(t[0][0]=='X'&&t[1][1]=='X'&&t[2][2]=='X')
		ukos1x++;
	if(t[0][2]=='X'&&t[1][1]=='X'&&t[2][0]=='X')
		ukos2x++;		
}




int main(int argc, char** argv) {
do{
	cout<<"		Witaj w s\210ynnej grze K\242\210ko i Krzy\253k. \n";
	
	//zerowanie
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			t[j][i]=' ';	
	
	do{
		
		wprowadzanie ();
		
		wyswietlanie ();
		
		sprawdzanie ();
		
		wygrana_ukos();
	
		remis ();
	
		cout<<"\n\nPoczekaj na ruch komputera...";
	
		if(pustka!=0)
		{
			_sleep(1300);
	
			losowanie ();
	
			wyswietlanie ();
		}
	
		sprawdzanie ();
		
		wygrana_ukos();
	
		remis ();
		
		if(ile_o_0pion==3||ile_o_1pion==3||ile_o_2pion==3||ile_o_0poz==3||ile_o_1poz==3||ile_o_2poz==3||ile_x_0pion==3||ile_x_1pion==3||ile_x_2pion==3||ile_x_0poz==3||ile_x_1poz==3||ile_x_2poz==3)
			wygrana++;
		
	}while(wygrana!=1&&pustka!=0&&ukos1o==0&&ukos2o==0&&ukos1x==0&&ukos2x==0);
	
	if(ile_o_0pion==3||ile_o_1pion==3||ile_o_2pion==3||ile_o_0poz==3||ile_o_1poz==3||ile_o_2poz==3||ukos1o==1||ukos2o==1)
	{
		cout<<"\n\n\nWygra\210e\230!!! \n"
			<<"BRAWO!!!\n\n";
	}
	else
	{
		if(ile_x_0pion==3||ile_x_1pion==3||ile_x_2pion==3||ile_x_0poz==3||ile_x_1poz==3||ile_x_2poz==3||ukos1x==1||ukos2x==1)
		{
			cout<<"\n\n\nWygra\210 komputer! \n"
				<<"Przegra\210e\230!!!\n\n";
		}
		else
		{
			if(pustka==0)
				cout<<"\n\n\nREMIS!!!\n\n";
		}
			
	}	
	
	cout<<"Dzi\251kuj\251 za wspania\210\245 gr\251!\n"
		<<"Mam ostatnie pytanie...\n\n"
		<<"Chcia\210by\230 zagra\206 ponownie?\n"
		<<"1. TAK\n"
		<<"0. NIE i zako\344cz\n\n";
		
	ile_o_0poz=0, ile_x_0poz=0, ile_o_0pion=0, ile_x_0pion=0;
	ile_o_1poz=0, ile_x_1poz=0, ile_o_1pion=0, ile_x_1pion=0;	
	ile_o_2poz=0, ile_x_2poz=0, ile_o_2pion=0, ile_x_2pion=0;
	pustka=9;
	wygrana=0;
	ukos1x=0, ukos2x=0, ukos1o=0, ukos2o=0;
	
	cin>>wybor;
	cout<<"\n\n";
	
}while(wybor==1);

exit(0);
	
	
	return 0;
}

