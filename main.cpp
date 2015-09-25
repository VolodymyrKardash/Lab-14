#include <iostream>
#include <__mobiletel.h>
#include <stdlib.h>
using namespace std;



int main() 
{ 
	setlocale(LC_ALL,"");
	char x;
	file();
	
 	do
 	{
 		cout<<"1 - Ввiд"<<endl;
 		cout<<"2 - Показати все"<<endl;
		cout<<"3 - Пошук за роком випуску"<<endl;
		cout<<"4 - Пошук за роком випуску та країною-виробником"<<endl;
		cout<<"5 - Очистити базу"<<endl;
		cout<<"6 - Редагувати базу"<<endl;
 		cout<<"7 - Пiдключення iншого файлу"<<endl;
		cout<<"8 - Вихiд"<<endl<<endl;
 		x=getch();
 		switch(x)
 		{
		case '8': fclose(f_abon); return 0;
 		case '1': input();break;
		case '2': show(); break;
      	case '3': search(); break;
      	case '4': search_m();break;
      	case '5': clear(); break;
		case '6': red();break;
      	case '7': file(); break;
 	 	}
 	} while (1);	
}

