#include<stdio.h>

#define max 10

int alt_tab[max][max];
char ust_tab[max+1][max+2];

void olustur_alt(int alt_tab[max][max], int boyut);
void olustur_ust(char ust_tab[max+1][max+2], int boyut);
void yazdir_ust(char ust_tab[max+1][max+2], int boyut);


int main()
{
	int byt=0;
	int x=0, y=0;
	printf("------AMIRAL BATTI------\n");
	printf("**oyun tum gemiler batana kadar surer**\n");
	
	do
	{
		printf("harita boyutu girin(5-10 arasi): ");
		scanf("%d", &byt);
		
	}while(byt<5 || byt>10);
	
	olustur_alt(alt_tab, byt);
	olustur_ust(ust_tab, byt);
	yazdir_ust(ust_tab, byt);
	
	int count=0;
	int  ctrl=1;
	do
	{
		int i,j;	
		scanf("%d %d", &x, &y);
		system("cls");		
		printf("------AMIRAL BATTI------\n");
			
	    	if(x<0 || x>byt-1 || y<0 || y>byt-1)
	    	{
	    		printf("uygun bir koordinat girin!\n");
			}
			else if(alt_tab[x][y]==0)
			{
				ust_tab[x+1][y]='.';
				alt_tab[x][y]=7;
			}
			else if(alt_tab[x][y]==1)
			{
				ust_tab[x+1][y]='1';
				alt_tab[x][y]=6;
				count++;
			}
			else if(alt_tab[x][y]==2)
			{
				ust_tab[x+1][y]='2';
				alt_tab[x][y]=6;
				count++;
			}
			else if(alt_tab[x][y]==3)
			{
				ust_tab[x+1][y]='3';
				alt_tab[x][y]=6;
				count++;
			}
			else if(alt_tab[x][y]==4)
			{
				ust_tab[x+1][y]='M';
				alt_tab[x][y]=5;
				ctrl=0;
			}
			else if(alt_tab[x][y]==6 || alt_tab[x][y]==7)
			{
				printf("bu koordinat zaten girilmis!\n");
			}
		   
		   if(count==10)
		   {
		   		ctrl=2;
		   }
		
		   yazdir_ust(ust_tab, byt);
			
	}while(ctrl==1);
	
	if(ctrl==0)
	{
		printf("MAYINI PATLATTINIZ, OYUN BITTI!\n");
	}
	if(ctrl==2)
	{
		printf("OYUNU KAZANDINIZ!\n");
	}
	
	return 0;	
}

void olustur_alt(int alt_tab[max][max], int boyut)
{
	int i,j;
	srand(time(NULL));

	for(i=0; i<boyut; i++)
	{
		for(j=0; j<boyut; j++)
		{
			alt_tab[i][j]=0;
		}
	}	
	
	int a=0, b=0, ran=0, ran1=0, ran2=0, c=0, d=0, ran3=0, ran4=0;
	ran=rand()%2;
	ran1=rand()%(boyut-2);
	ran2=rand()%(boyut-2); 
	if(ran==1)
	{
		a=1;
		b=3;
	}
	else
	{
		a=3;
		b=1;
	}
	
	for(i=ran1; i<a+ran1; i++) 
	{
		for(j=ran2; j<b+ran2; j++) 
		{
			alt_tab[i][j]=3; 
		}
	}

	if(ran==1)
	{
		c=1;
		d=2;
	}
	else
	{
		c=2;
		d=1;
	}	
		
	int k;

	for(k=0; k<2; k++)
	{
		do
		{
			ran3=rand()%(boyut-1);
			ran4=rand()%(boyut-1);			
			
		}while(alt_tab[ran3][ran4]!=0 || alt_tab[ran3+1][ran4]!=0 || alt_tab[ran3][ran4]!=0 || alt_tab[ran3][ran4+1]!=0); 
		
		for(i=ran3; i<c+ran3; i++)
			{
				for(j=ran4; j<d+ran4; j++)
				{
					alt_tab[i][j]=2;
				}
			}
		
	}
		
	// 3 luk ve 2 likleri yerlestirdikten sonra birlikler ve mayinlar bu sekilde konulabilir;
	for(i=0; i<3; i++)
	{
		// 1 karelik gemileri yerlestirme
		int x=0, y=0;
		
		do
		{
			x=rand()%boyut;
			y=rand()%boyut;
			
		}while(alt_tab[x][y]!=0);
		
		alt_tab[x][y]=1;
	}
	
	for(i=0; i<2; i++)
	{
		// mayýnlarý yerlestirme
		
		int x=0, y=0;
		
		do
		{
			x=rand()%boyut;
			y=rand()%boyut;
			
		}while(alt_tab[x][y]!=0);
		
		alt_tab[x][y]=4;
	}
	
}

void olustur_ust(char ust_tab[max+1][max+2], int boyut)
{
	int i,j;
	for(i=0; i<boyut; i++)
	{
		ust_tab[0][i]=48+i;
	}
	for(i=1; i<boyut+1; i++)
	{
		ust_tab[i][boyut]=('-');
		ust_tab[i][boyut+1]=48+i-1;
	}
	
	for(i=1; i<boyut+1; i++)
	{
		for(j=0; j<boyut; j++)
		{
			ust_tab[i][j]='#';
		}
	}
}

void yazdir_ust(char ust_tab[max+1][max+2], int boyut)
{
	int i, j;
	for(i=0; i<boyut+1; i++)
	{
		for(j=0; j<boyut+2; j++)
		{
			printf("%2c",ust_tab[i][j]);
		}
		printf("\n");
	}
	printf("bir koordinat girin(ornek: 3 4)\n");
}





















