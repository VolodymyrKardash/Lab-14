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
 		cout<<"1 - ��i�"<<endl;
 		cout<<"2 - �������� ���"<<endl;
		cout<<"3 - ����� �� ����� �������"<<endl;
		cout<<"4 - ����� �� ����� ������� �� ������-����������"<<endl;
		cout<<"5 - �������� ����"<<endl;
		cout<<"6 - ���������� ����"<<endl;
 		cout<<"7 - �i��������� i����� �����"<<endl;
		cout<<"8 - ���i�"<<endl<<endl;
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

