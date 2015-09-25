#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct abonent	
{ 
	int year;
	char name[30];
	char operational_system[30];
	char manufactur_country[50];
};

FILE * f_abon;
char file_name[25];
	
void file()
{
	setlocale(LC_ALL,"");
	
	cout<<"Введiть назву файлу для опрацювання (*.bin) (якщо такого файлу нема буде створено новий):";
	cin>>file_name;
	if ((f_abon=fopen(file_name,"rb+"))==NULL)
 	{
 	if ((f_abon=fopen(file_name,"wb+"))==NULL)
 	{
 		cout<<"Помилка!"<<endl;
	}
		cout<<"Створено файл з введеним ім’ям!"<<endl;
 	}
}

void input()
{
	setlocale(LC_ALL,"");
	fseek(f_abon,0,SEEK_END);
	struct abonent a;
	cout<<"Введiть данi:"<<endl;
	cout<<"Рiк випуску        -";
	cin>>a.year;getchar();
	cout<<"Операцiйна система -"; 
	gets(a.operational_system);
	cout<<"Назва телефону     -"; 
	gets(a.name);
	cout<<"Країна - виробник  -"; 
	gets(a.manufactur_country); 
	fwrite(&a,sizeof(a),1,f_abon);
	
	cout<<endl;
}


void print(struct abonent a)
{
	setlocale(LC_ALL,"");
	cout<<"Рiк випуску        -"<<a.year<<endl;
	cout<<"Операційна система -"<<a.operational_system<<endl; 
	cout<<"Назва телефону     -"<<a.name<<endl; 
	cout<<"Країна - виробник  -"<<a.manufactur_country<<endl; 
	cout<<endl;
}

void show()
{
	setlocale(LC_ALL,"");
 struct abonent a;
 int p,r;
 	p=0;
	fseek(f_abon,0,0);
	while (!feof(f_abon))
	{
		
		r=fread(&a,sizeof(a),1,f_abon);
		if (r<1) break;
		print(a);
		p++;
	}
	cout<<endl<<"Знайдено "<<p<<" телефон(iв)"<<endl<<endl;
}
 void search()
{
 setlocale(LC_ALL,"");
 int year_buf;
 struct abonent a;
 int p,r;
 	p=0;
	cout<<"Рiк виробництва - ";
	cin>>year_buf;
	cout<<endl;
	fseek(f_abon,0,0);
	while (!feof(f_abon))
	{
		r=fread(&a,sizeof(a),1,f_abon);
		if (r<1) break;
		if (year_buf==a.year)
		{
			print(a);
			p++;
		}
	}
	if (p==0) cout<<"Такоих телефонів не знайдено"<<endl;
	else cout<<endl<<"Знайдено "<<p<<" телефон(iв)"<<endl<<endl;
}

void search_m()
{
	setlocale(LC_ALL,"");
 char manufactur_country_buf[30];
 struct abonent a;
 int p,r,year;
 	p=0;
	cout<<"Рiк випуску     - ";
	cin>>year;getchar();
	cout<<"Країна-виробник - ";
	gets(manufactur_country_buf);
	
	cout<<endl;
	fseek(f_abon,0,0);
	while (!feof(f_abon))
	{
		r=fread(&a,sizeof(a),1,f_abon);
		if (r<1) break;
		if ((strcmp(a.manufactur_country, manufactur_country_buf)== 0)&&(year==a.year))
		{
			print(a);
			p++;
		}
	}
	if (p==0) cout<<"Такоих телефонів не знайдено"<<endl;
	else cout<<endl<<"Знайдено "<<p<<" телефон(iв)"<<endl<<endl;
}
 
void clear()
{
	setlocale(LC_ALL,"");
	fclose(f_abon);
	if ((f_abon=fopen(file_name,"wb+"))==NULL)
 	{
 		cout<<"Помилка!"<<endl;
	}
}

void red()
{
	abonent a;
	int x,z,year;
	char ye[30], os[30], mf[30],name_buf[30];
		show();
	cout << "Введiть назву телефона для редагування : ";
	gets(name_buf);
	fseek(f_abon,0,SEEK_SET);
	while (!feof(f_abon))
	{
		if (strcmp(a.name,name_buf)==0)
		        {
			    x:
			    	
			    	
			    cout << "Що ви хочете замiнити?\n\n1 - Рiк випуску\n2 - Операцiйну систему\n3 - Назву телефону\n4 - Країну-виробника\n5 - Знищити записанi данi\n6 - Вихiд\n";
				cin >> z;
				switch (z){
				case 1: cout << "Рiк                    - "; cin>>x; a.year=x; break;
				case 2: cout << "Операцiйна система     - "; cin>>os; strcpy(a.name, os);break;				
				case 3: cout << "Назва телефону        - "; cin>>ye; strcpy(a.operational_system, ye); break;
				case 4: cout << "Країна-виробник    - "; cin>>mf; strcpy(a.manufactur_country, mf); break;
				case 5: cout << "Данi знищено!"; strcpy(a.operational_system,"........");strcpy(a.name,"........");strcpy(a.manufactur_country,"........"); break;
				case 6: goto p;
				}
                goto x;
                p:z = ftell(f_abon);
                fseek(f_abon, z - sizeof(abonent), 0);
                fwrite(&a, sizeof(abonent), 1, f_abon);
                fseek(f_abon, sizeof(abonent), SEEK_CUR);
		        }	
		fread(&a, sizeof(abonent), 1, f_abon);
	}
	}
	

