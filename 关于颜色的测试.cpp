#include<iostream>
#include<Windows.h>
using namespace std;

void color(short x)	//自定义函根据参数改变颜色 
{
	if (x >= 0 && x <= 256)//参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数 
	else//默认的颜色白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int main() {
	cout << "这里是关于颜色的测试，源码我也会保存下来" << endl;
	for (int i = 0; i < 256; i++) {
		cout << i << ": ";
		color(i);
		cout << i << "   ";
		color(7);
	}
	return 0;
}

//结论，颜色分类有16*16种，16为字符的颜色，另一个16为背景的颜色
//以后使用时直接查看颜色表即可