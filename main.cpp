//Jeszcze szybsze rozwiacanie wg Problemu Pleckowego gdzie pojemosc to suma wszystkich/2, pakowanie elementow suma/2 do 1

#include <iostream>

using namespace std;

short MIN=9999;
short max_value;
int licznik=0;

void program();
void WriteScore(short liczba);
void Absolute(short &liczba);
short Absolute2Vir(short liczba1);
void ProgDynamic(short minimum,short table[], short table_virable[],short survey,short counter);

int main()
{
	program();

return 0;
}

void program()
{
short tests,survey; //testy, pomiar
short max_total=0;
short table[5001];
short table_virable[5001];

	scanf("%hu",&tests);
	for(short k=0;k<tests;k++)
	{

		scanf("%hu",&survey);

		for(short i=1;i<=survey;i++)             //Wczytanie pomiarów
		{
			scanf("%hu",&table[i]);
			max_total+=table[i];
		}

		for(short i=2;i<=survey;i++)           //tablica wartosci wg kolejnosci pomiarów a ile zostlo jako sumy do konca
			if(i!=2)
				table_virable[i]=table_virable[i-1]-table[i-1];
			else
				table_virable[i]=max_total-table[i-1];

		if(survey == 1 || max_total == 0)
			cout<<max_total<<" "<<max_total<<"\n";
		else{
			ProgDynamic(table[1],table,table_virable,survey,2);
			cout<<MIN<<" "<<max_total<<"\n";
		}
		max_total=0;
		MIN = 9999;
	}
	cout<<"Liczba iteracji: "<<licznik<<"\n";

}

void ProgDynamic(short minimum,short table[], short table_virable[],short survey,short counter)   //wyznacza wartosc minimalna wg drzewa
{
short helpPLUS;
short helpMINUS;
    licznik+=1;
	helpMINUS = helpPLUS = minimum;

	if(counter < survey+1)															//Iteracje: ProgDynamic
	{
		helpMINUS-=table[counter];
		//if(Absolute2Vir(helpMINUS) < table_virable[counter])                       //445 255
		if(helpMINUS >=(-table[counter]) && helpMINUS < table_virable[counter])    //86 217 poprawne wyniki
		{
			if(counter != survey)
				ProgDynamic(helpMINUS,table,table_virable,survey,counter+1);
			else if(counter == survey)
				WriteScore(helpMINUS);
		}

		helpPLUS+=table[counter];
		if(helpPLUS < table_virable[counter])
			ProgDynamic(helpPLUS,table,table_virable,survey,counter+1);
	}
}

void WriteScore(short liczba)
{
//int help=liczba;
	Absolute(liczba);
	if(liczba<MIN)
		MIN=liczba;
}
void Absolute(short &liczba)        //modol
{
	if(liczba<0)
		liczba*=(-1);
}
short Absolute2Vir(short liczba)
{
	if(liczba<0)
		liczba*=(-1);
return liczba;
}
