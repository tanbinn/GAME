#include<iostream>
#include<Windows.h>
using namespace std;

void color(short x)	//�Զ��庯���ݲ����ı���ɫ 
{
	if (x >= 0 && x <= 256)//������0-15�ķ�Χ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ������ 
	else//Ĭ�ϵ���ɫ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int main() {
	cout << "�����ǹ�����ɫ�Ĳ��ԣ�Դ����Ҳ�ᱣ������" << endl;
	for (int i = 0; i < 256; i++) {
		cout << i << ": ";
		color(i);
		cout << i << "   ";
		color(7);
	}
	return 0;
}

//���ۣ���ɫ������16*16�֣�16Ϊ�ַ�����ɫ����һ��16Ϊ��������ɫ
//�Ժ�ʹ��ʱֱ�Ӳ鿴��ɫ����