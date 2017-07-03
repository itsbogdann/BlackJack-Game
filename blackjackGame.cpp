#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <windows.h>
using namespace std;


int dealplayer(int player);
int dealdealer(int dealer);
int gameplayer(int player);
int gamedealer(int dealer);

char nume[15];
int money=100;

void despre()
{
	printf("Blackjack este un joc de noroc, \n");
	printf(" in care playerul joaca impotriva \n");
	printf(" dealer-ului, avand optiunile de a \n");
	printf(" cere sa primeasca o carte pe rand, \n");
	printf(" sau sa astepte, regula fiind ca \n");
	printf(" suma cartilor sale sa fie <=21!\n");
	printf(" Cine are suma cea mai mare castiga mana!\n");
	printf(" \nProiect realizat de Bogdan Catrinoiu\n");
}

int dealplayer(int player)
{
int cards[2], choice;
cards[0] =2 + rand() / (RAND_MAX / 9 + 1);
cards[1] = 2 + rand() / (RAND_MAX / 9 + 1);
player = cards[0] + cards[1];
printf("\n%s, cartile tale: %d, %d", nume, cards[0], cards[1]);
if(cards[0] == 11 && cards[1] == 11)
player = player - 10;
 	if(cards[0] == 11 || cards[1] == 11)
	{
	do
	{
	printf("\nAs-ul devine 1 sau 11?: ");
	scanf("%d", &choice);
		if(choice == 1)
		{ 
		player = player - 10;
		}
	}
	while(choice == 1 || choice == 11);
	}
//
return player;
}
int dealdealer(int dealer)
{
int cards[2];
cards[0] = 2 + rand() / (RAND_MAX / 9 + 1);
cards[1] = 2 + rand() / (RAND_MAX / 9 + 1);
dealer = cards[0] + cards[1];
printf("\nCartile dealer-ului : %d, %d\n", cards[0], cards[1]);
 
	if((cards[0] == 11) || (cards[1] == 11))
	{
		if(dealer > 21)
	dealer = dealer - 10;	
	}
		
//
return dealer;
}
int gameplayer(int player)
{
int card;
char choice;
do 
{
printf("\nAlege optiune: \n");
printf("H - Hit(Primesti carte noua)\n");
printf("S - Stay(Ramai cu cartile tale)\n");
choice=getch(); // in caz de eroare: scanf("\n%c", &choice);
				//printf("%c",choice);
choice = toupper(choice);
switch(choice)
{
case 'H': card = 2 + rand() / (RAND_MAX / 9 + 1);
while (card == 1 || card == 11)
{
if(card == 11)
{
printf("\nAs-ul devine 1 sau 11?: ");
//
scanf("%d",&choice);
}
}
player = player + card;
printf("\n%s, ai mai primit o carte!\n",nume);
printf("Suma cartilor tale: %d\n", player);
	if(player > 21)
	{
	printf("Ai pierdut mana,%s!\n",nume); 
choice = 'z';
// system("cls");
break;
}
break;
case 'S':system("cls");
break;
}
}
while(choice == 'H');
return player;
}
int gamedealer(int dealer)
{
int card;
while (dealer < 17)
{
card = 2 + rand() / (RAND_MAX / 9 + 1);
dealer = dealer + card;
if (card == 11 && dealer > 21)
card = card -10;
	if (dealer > 21)
	printf("\nAi castigat mana!\n");
//	system("cls"); 
}
return dealer;
}


int main()
{
srand(time(NULL));
char again, sp;
int dealertotal, playertotal, pariu=0,i;
char s2[16]={'B','o','g','d','a','n',' ','C','a','t','r','i','n','o','i','u'};
printf("                     Bun venit la ");
char s[10]={'B','l','a','c','k','J','a','c','k'};
	for (i=0;i<9;i++)
{
        printf("%c",s[i]);
   Sleep(200);
     } 

printf("\n");
printf("Optiuni:\n");
printf("1 - Despre\n");
printf("2 - Joaca\n");
sp=getch();
if (sp=='1') despre();
//scanf("%d",&i);
printf("\nNumele tau este: ");
gets(nume);
system("cls");
		

nume[0]=toupper(nume[0]);
do
{
  printf("%s, sa inceapa jocul de BlackJack:\n",nume);
  printf("Cati bani ($) vrei sa pariezi?: ");
  printf("\nSuma de pe masa: %d$", money);
  printf("\nPe masa pui: $");
  //
  scanf("%d", &pariu);
  playertotal = dealplayer(playertotal);
  dealertotal = dealdealer(dealertotal);
  playertotal = gameplayer(playertotal);
  if(dealertotal < 17 && playertotal < 21)
  dealertotal = gamedealer(dealertotal);
  printf("\n%s, suma cartilor tale a fost: %d\n",nume, playertotal);
  printf("Suma cartilor dealer-ului a fost: %d\n",dealertotal);
  if(playertotal == dealertotal)
  {
  printf("\nRemiza!\n");
  pariu = 0;
  }
	if((playertotal > dealertotal) && ((playertotal <= 21) || (dealertotal >= 21)))
	{
	printf("\n%s, ai castigat!\n",nume);
	money = money + pariu;
	pariu = 0;
	}
		
	if(playertotal > 21)
	{
		printf("\nDealerul castiga!\n");
		money = money - pariu;
		pariu = 0;
	}
			
	if((dealertotal > playertotal) && (dealertotal <= 21))
	{
			printf("\nDealerul castiga!\n");
			money = money - pariu;
			pariu = 0;
	}
  printf("Ai jucat excelent! Suma ramasa: %d$\n", money);
  printf("Jocul continua? (d/n): \n");
  again=getch();//scanf("\n%c", &again);
  again = toupper(again);
  srand(time(NULL));
 system("cls");
} while(again == 'D');

printf("\n%s, ti-au ramas %d$\n", nume, money);
if (money<100) printf("Poate data viitoare!");
else if (money==100) printf("Nu ai iesit pe pierdere, binisor!");
else printf("Ai reusit sa scoti profit, felicitari!");
printf("\nProiect realizat de ");
for (i=0;i<16;i++)
{

printf("%c",s2[i]);
   Sleep(150);
}

return 0;

}

