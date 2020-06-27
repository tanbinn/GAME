#ifndef _JUBEN_H_
#define _JUBEN_H_
#include<stdio.h>
#include<iostream>
#include"conio.h" 
#include<string>
#include<fstream>
#include<vector> 
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<Windows.h>
#include<direct.h>
#include<sstream>
using namespace std;

string setw_quanjiao(string cnt,short length) {
	string res;
	length *= 2;
	res = cnt;
	if (cnt.size() < length) {
		for (int i = 0; i < (length - cnt.size()) / 2;i++) {
			res = res + "  ";
		}
	}
	return res;
}

std::string banjiao_quanjiao(int num)//�����������������ת����ȫ�ǵ��ַ�����ʽ
{
	stringstream ss;
	ss << num;
	string str;
	ss >> str;
	std::string result = "";
	unsigned char tmp; unsigned char tmp1;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		tmp = str[i];
		tmp1 = str[i + 1];
		//cout << "uchar:" << (int) tmp << endl;   
		if (tmp > 32 && tmp < 128)
		{//�ǰ���ַ�
			result += 163;//��һ���ֽ�����Ϊ163
			result += (unsigned char)str[i] + 128;//�ڶ����ֽ�+128;   
		}
		else if (tmp >= 163)
		{//��ȫ���ַ�   
			result += str.substr(i, 2);
			i++;
			continue;
		}
		else if (tmp == 32)
		{//�����ǿո�   
			result += 161;
			result += 161;
		}
		else
		{
			result += str.substr(i, 2);
			i++;
		}
	}
	return result;
}

void color(short x)	//�Զ��庯���ݲ����ı���ɫ 
{
	if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ 
	else//Ĭ�ϵ���ɫ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

struct zhandou_gongji {//���Թ��ܣ���Ҫ�������ýṹ������ÿ�ֵ�Ļ���屶�ʺ�������
	//���ݿ��Դ�ͷд�𣬱�����������������ֵ�Ļ��ʽ������������ÿ�ֵ�Ļ��ʽдһ����������Ȼ��ͨ����Ļ���ͽṹ�����ָ����ʽ�ĵ���
	string toubiao;//ͷ��
	string name_global;//����ʽ����
	string name;//����
	short leixing;//��Ļ����
	short yangshi;//��Ļ��ʽ		//ʵ��Ҫ���õ�ֻ����ʽ��һ�㣬�����嵯Ļ���ͺ�ͷ���Ƿ��������������д�������ֲ����ж���£�
	short shuxing;//��Ļ����
	short xiaohao_power;//��λ��Ļ�����powerֵ
	short xiaohao_xingdongzhi;//��λ��Ļ����Ҫ���ж�ֵ
	short shanghai_beilv;//���������﹥��ֵ�ģ��˺�����
	int shanghai_shuzhi;//(���ܱ����Դ���)�����˺�
	short sudu;//��������
	short level;//�ȼ�����ֱ�Ӵ�����㣬������ǣ�
	string jiaobiao;//�ű�
	vector <string> beizhu;
};

//��ΪҪ���ļ����������ݴ洢�͵��ã�������Ҫ��ÿ�����ܶ���һ��ͷ��ͽű꣬��ʽ�����������ݵĶ��뷽ʽ
zhandou_gongji NULL_gongji = { "�հ�","","",0,0,0,0,0,0,0,0,0,"" };//A-1
zhandou_gongji suijidan_daodan_level1 = { "����","�����","����",2,0,0,5,0,10,10,0,1,"A0l1" };//A0l1
zhandou_gongji suijidan_xiaoyu_level1 = { "����","�����","С��",2,6,0,4,0,10,8,0,1,"A1l1" };//A1l1

struct zhandou_yidong {
	string toubiao;//ͷ��
	string name;//����
	short xiaohao_power;//�����powerֵ
	short xiaohao_xingdongzhi;//������ж�ֵ
	short sudu;//�ƶ�ǿ��
	short level;//�ȼ�
	zhandou_gongji* danmu;//�������ƶ���ʽ���Ա����ܱ߽��е�Ļ������������б��޻�(��Ȼ��ָ����ʽ���ܻ������ʱ��ע��һ��)
	string jiaobiao;//�ű�
};
//��ס�����ܵĶ����൱�ڳ������壬��Ҫ����ڵ���ʱ���иĶ�����Ϊ�ײ���ָ�룬ԭ����������ݵĸ��Ƿ�����һ���ģ�
zhandou_yidong NULL_yidong = { "�հ�","",0,0,0,0,NULL,"" };//B-1
zhandou_yidong weiyi_level1 = { "�ƶ�","΢��",0,3,2,1,NULL,"B0l1"};//B0l1
zhandou_yidong zhongfuyidong_level1 = { "�ƶ�","�з��ƶ�",0,5,4,1,NULL,"B1l1"};//B1	l1
zhandou_yidong gaosuchuanxing_level1 = { "�ƶ�","���ٴ���",0,7,6,1,NULL,"B2l1"};//B2l1
zhandou_yidong ceshi_yidongsheji = { "�ƶ�","���ԡ����ƶ����",5,5,3,1,&suijidan_daodan_level1,"B1000" };//B1000	�ǵõ�ʱ������ָ��ɾ������ֻ��Ϊ�˵���һ���ƶ�ʱ���䵯Ļ�Ĺ��ܣ�

struct quanju_jineng_dingyi {
	vector <zhandou_yidong> yidong;//����һ�����ڴ洢ȫ�ֵĵ�Ļ�������͵Ķ�̬���飬����������Ҫ��parsein�����н��У���Ӧ���ƶ�����Ҳ�ǣ�
	vector <zhandou_gongji> gongji;//����ȫ�ִ洢�ƶ�������Ϣ������
};
quanju_jineng_dingyi quanju_jineng;//�������ü��޸ģ���߿ɲ���ָ��

struct zhanoushuju_save_beifen {
	zhandou_gongji* gongji = NULL;
	zhandou_yidong* yidong = NULL;
};

struct zhandoushuju_save {
	string toubiao;
	string name;
	vector <string> S;
	vector <int> danmu[3][8][6];
	short left;
	zhanoushuju_save_beifen save;
};

struct _renwushuju {//���ڶ����������ݵĽṹ��
//��������
	string name;
	bool panduan_duiwu;
	int tiLi_D;
	int tiLi_G;
	int jingLi_D;
	int jingLi_G;
	int jingYan;
	int liLiang_D;
	int liLiang_G;//��Ϸ��������һ�������ء����һ��������Ӧһ�㸺��
	int fangYu_D;
	int fangYu_G;
	int suDu_D;
	int suDu_G;
	int faShu_D;
	int faShu_G;
	int moKang_D;
	int moKang_G;
	int zhiLi_D;
	int zhiLi_G;
	int baoShiDu_D;
	int baoShiDu_G;
	int wenDu;
	int xinQing;
	int haoGan;
	string daweizhi;
	string zhongweizhi;
	string xiaoweizhi;
	string weizhi;
	int zhuangtai_num;
	vector <string> zhuangtai;
	int xingdongcao_num;
	vector <zhandoushuju_save> xingdongcao;

	//����������������������������������������������������������������������������
	//���߻��Ƿ��⼸�ְɣ�Ǯ�ң���ָ���ڽ��׵Ļ��ң����زĺ͵��ߣ�����û�����Խ綨�����߱���Ҳ���Գ�Ϊ�زģ���Ҫ�ǰѻ����ز����ֳ��������������䷽
	int huobi_money;//Ǯ
	//����ͷ�����ں�������������ʱ���и������ֵģ�
	//�زı�ͷΪ0
	int sucai_shuzhi;//0 1 ��֦ 0.2
	int sucai_muchai;//0 2 ľ�� 0.5
	int sucai_gancao;//0 3 �ɲ� 0.1
	int sucai_shitou;//0 4 ʯͷ 0.5
	int sucai_mogu;//0 5 Ģ�� 0.1
	int sucai_yecai;//0 6 Ұ�� 0.2
	int sucai_yegu;//0 7 Ұ�� 0.1

	//���߱�ͷΪ1
	int daoju_pingguo;//1 1 ƻ�� 0.5
	int daoju_li;//1 2 �� 0.5
	int daoju_suishi;//1 3 ��ʯ 0.5
	int daoju_shui;//1 4 ˮ 0.5
	int daoju_yinghuo;//1 5  Ӫ�� 2

	//������ͷΪ2
	int fuka_kongbai;//2 1 �հ׷��� 1
	int fuka_qiluruo_weiding;//2 2 ����׼������ʽ��1

	//�䷽��ͷΪ3
	int peifang_yinghuo;//3 1 Ӫ���䷽��


	quanju_jineng_dingyi jineng;
};

string zhangJie;
string nandu;

int year_quanju = 0; int hour_quanju = 8; int min_quanju = 30; int day_quanju = 20; int month_quanju = 11;//����Ϊʱ���ȫ�ֱ��� 
int year_tianqi = 0; int hour_tianqi = 9; int min_tianqi = 30; int day_tianqi = 20; int month_tianqi = 11; bool panduan_tianqi = false;//���������������ж�ʱ���� 

string tianqi_jiaojiedian;

string kongBai_shuju[30];
string kongbai_daoju[16];
string kongbai_jineng[7];
vector <_renwushuju> _renwu;
vector <_renwushuju> _team;
_renwushuju siJi;_renwushuju zhuRenGong;
string _NAME = "��";


void shiJianJieMian(int jiaFen, string gongneng) {//ע�⣺ʱ�亯������ֲ
	if (gongneng == "ȫ��") {
		int kaiFen = hour_quanju * 60 + min_quanju;
		int houFen = kaiFen + jiaFen;
		while (houFen > 1440) {
			day_quanju++;
			houFen = houFen - 1440;
		}
		bool panduan = true;
		while (panduan) {
			if (((month_quanju == 1) || (month_quanju == 3) || (month_quanju == 5) || (month_quanju == 7) || (month_quanju == 8) || (month_quanju == 10) || (month_quanju == 12)) and (day_quanju > 31)) {
				day_quanju = day_quanju - 31;
				if (month_quanju == 12) {
					month_quanju = 1;
					year_quanju++;
				}
				else {
					month_quanju++;
				}
				if (day_quanju > 28) {
					continue;
				}
				//cout << "31days" << endl;
			}
			else if ((month_quanju == 2) and (day_quanju > 28)) {
				day_quanju = day_quanju - 28;
				month_quanju++;
				if (day_quanju > 28) {
					continue;
				}
				//cout << "28days" << endl;
			}
			else if (((month_quanju == 4) or (month_quanju == 6) or (month_quanju == 9) or (month_quanju == 11)) and (day_quanju > 30)) {
				day_quanju = day_quanju - 30;
				month_quanju++;
				if (day_quanju > 28) {
					continue;
				}
				//cout << "30days"<< endl;
			}
			else {
				panduan = false;
			}
		}
		hour_quanju = houFen / 60;
		min_quanju = houFen % 60;
	}
	if (gongneng == "��������") {
		int kaiFen = hour_quanju * 60 + min_quanju;//ע�⣬�����ҽ���ʼʱ�任��ȫ��ʱ�� 
		int houFen = kaiFen + jiaFen;
		while (houFen > 1440) {
			day_tianqi++;
			houFen = houFen - 1440;
			year_tianqi++;
		}
		bool panduan = true;
		while (panduan) {
			if (((month_tianqi == 1) || (month_tianqi == 3) || (month_tianqi == 5) || (month_tianqi == 7) || (month_tianqi == 8) || (month_tianqi == 10) || (month_tianqi == 12)) and (day_tianqi > 31)) {
				day_tianqi = day_tianqi - 31;
				if (month_tianqi == 12) {
					month_tianqi = 1;
				}
				else {
					month_tianqi++;
				}
				if (day_tianqi > 28) {
					continue;
				}
				//cout << "31days" << endl;
			}
			else if ((month_tianqi == 2) and (day_tianqi > 28)) {
				day_tianqi = day_tianqi - 28;
				month_tianqi++;
				if (day_tianqi > 28) {
					continue;
				}
				//cout << "28days" << endl;
			}
			else if (((month_tianqi == 4) or (month_tianqi == 6) or (month_tianqi == 9) or (month_tianqi == 11)) and (day_tianqi > 30)) {
				day_tianqi = day_tianqi - 30;
				month_tianqi++;
				if (day_tianqi > 28) {
					continue;
				}
				//cout << "30days"<< endl;
			}
			else {
				panduan = false;
			}
		}
		hour_tianqi = houFen / 60;
		min_tianqi = houFen % 60;
	}
}


void JuBen(string gongneng, int bianhao) {
	if (gongneng == "����") {
		if (zhangJie == "��ƪ") {
			if (bianhao == 1) {
				cout << "��������������" << endl;
				cin >> _NAME;
				cout << _NAME << "�����Ǻã����ǿ�ʼ�ɣ�" << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "..." << endl << ".." << endl << "." << endl;
				_getch();
				cout << "�������İ���������," << _NAME << "����ش��˸���Ƿ:�����ǵģ�����ݼ�û��ã���Ҫ����ȥ�������ˡ���" << endl;
				_getch();
				cout << "��˵�������ϴ���������ʲôʱ�����ţ��ƺ���ʮ����ǰ�����ˡ�" << endl;
				_getch();
				cout << "�Դ���λ���˴����¿Ƽ����������綼������������ֻ��һ���ϱ�ȫ�淭�£�û�˽ֵ���û�˵��ߣ����µ�ֻ��һ������ΰ�ĸ�¥���ã����������ʴ����ߡ����������￪�⣬���ʴ������������ű����գ�ۼ�����" << endl;
				_getch();
				cout << "����������ȫ�淭�£�������ԭ�ϻ�����Դ����������ã���ȾҲ�Ǳ�������΢����΢��˵����Դ������ɿصĺ˾۱似������������еĴ�ͳ���糧.ͨ�����������ֻ��Ҫһˮ���ˮ����ɹ���ȫ��һ��������ܺġ�" << endl;
				_getch();
				cout << "ӵ���˽�����֮��������Դ������֮��ʧȥ�������ı�Ҫ������λ���˵�Ȱ˵�£��ܶ���ҷ��¹�ȥ�Ķ�Թ�����Է�չ�ѺõĹ�ϵ����Ȼż��Ҳ������������Ҳ�����ڴ��˵ĵ�����ƽϢ�ˡ�" << endl;
				_getch();
				cout << "��������һ�꣬��ȥ��Ӱ�ӱ���ʧ����Ӱ���٣��е�ֻ���¿Ƽ��Ĳ���ֹ��˼��꣬�����ʧȥ�����������壬�����еĹ��Ҵ�ͷ�������е�������" << endl;
				_getch();
				cout << "û��а��û�����ˣ����µ�ֻ�к�ƽ��" << endl;
				_getch();
				cout << "���ҵ���Ҳ�������˰ɡ�����" << endl;
				_getch();
				cout << "���ȷʵ����ô��������ܿ죬�����뷨ȷ�������ˡ�" << endl;
				_getch();
				cout << "����ǰ�������磬��������ǵ��ھ�������󱯲ҵ�ԭʼ����������Է���̸��κ����Ƿǵ������飬�������Ҹ��˳���������Ҫ�Ͼ������ǵ���ϵ����" << endl;
				_getch();
				cout << "�����Ǵ�ɲ�������ȥ����ƨ�ɣ�����֪���������ĸ�λ�϶������Ŀ������ǵ��ھӽ�����Ϊ�˻������������ʱ�޿�ð������Σ�ա�������Ȼ�����ǲ���ð������Ҳֻ����Ϊ���ǵ�˼������ظ�����" << endl;
				_getch();
				cout << "������ǣ����ǵð����Ǵ���Ԩ�����ȳ�������ʹ���������಻���ľ�������һ�е��������һ���ᶮ�����ǵ��������ģ�������һ����������������ͬ����������������" << endl;
				_getch();
				cout << "��λ������ô˵�˺󣬵õ��˸�����֧�֡���һҹ֮�䣬���������ʽ���������˳���������Ӫ�󣬶�����ָ����ȫ��е���ĸ������ӱ�ӿ�����У��·������ѹһ�С�" << endl;
				_getch();
				cout << "��ֵ��ǣ������������û�ܹ��¶Է������Ҷ���ķ���Խ��Խ�ι��ˡ�" << endl;
				_getch();
				cout << "��������ʹ��ħ�������ֺ������ݺ��߼����ԵĶ�����������䴫������������ٵ�����һֱ���������гɹ�������ǣ����ǵ�˼���Ѿ��ظ����޿ɾ�ҩ�ˣ����ǵ������Ѿ��޷�Ϊ����������ˡ�";
				cout << "Ϊ�˶����˵�δ�������ǲ��ò����������˵����棬�����ǰ��µ����Ѷ�ɱ��ҡ����ɣ���" << endl;
				_getch();
				cout << "���Ǻ���ȫ������ǿ�ǰ���Ž���һ��Ϊ���ػ��Լ��ļ�԰��ս��" << endl;
				_getch();
				cout << "������" << _NAME << "����ô���������ģ���ʵ�ϣ����Լ�Ҳ������ˡ������ڱ���������ʱ���ֶϲ㣬���µı��ǲ��ϵ�ѵ�����������ָʾȥ�����������ļ����ˡ�" << endl;
				_getch();
				cout << "������" << _NAME << "��Ҫȥ�ĵط��������������Ŷ��޷����ã�ֻ�ܿ���ͳ�������ִ" << endl;
				cout << "�����ĵؼ�����һȦ��" << _NAME << "��������䳵���ҵ�����һ����϶��" << endl << "�ܿ�ϧ�������ܷ�����ͷһ����������С�������������ȣ�Ψһ���ܵ��Ĺ���ֻ�������ĺ������ˡ�" << endl;
				_getch();
				cout << "�������Ѿ��ٽ��ƻ������׶Σ��óô��˴򿪵Ŀռ��ѷ챻���ǲ��ǰ�����Ǹ��ط�����Ȼ�Ļ�������ǰ��������һ�ж�����ͽ�͡�������" << _NAME << "�ı�Թ��˾�������������ӳ�ǰ���˹�����" << endl;
				_getch();
				cout << "��������Ϊ������" << _NAME << "�Ż���ò�����......��" << _NAME << "��������ǰ��˫�˺����۵����ƣ�̾���������������֡����������ˣ���������ͨ�˶��������ص������������������ṩ����Ϣ���˷�����˼���ο��ҽ�Ҫ���������һ�С�����" << endl;
				_getch();
				cout << "����Ϊֹ���ұ�Ӧ���������ٻ����أ���ʶ�����ļ�����������������ʤ����ͬ��������һ�ؿ������׶༪�ٰɡ����뵽�⣬" << _NAME << "�̲�ס���������˫����." << endl;
				_getch();
				cout << "��ĬƬ�̺�˾�����ε�����͸�˹�������û�취��Ϊ�˱�֤�����ԣ��ռ��ѷ�ֻ������һ���˽�ȥ���������Ҳֻ��ȥ���һ������ȡ�����ܶ���鱨���С���ס���ڴ��ͻ��ǰ�����ȡ��ÿһ���鱨����Ӱ�������˵���������" << endl;
				_getch();
				cout << "��ʵ�����ľ�����û�취�ء�" << endl;
				_getch();
				cout << "�����Ž�ʱ��������" << _NAME << "��֪����˯���ˡ�" << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
				_getch();
				cout << "..." << endl << ".." << endl << "." << endl;
				_getch();
				cout << "�����ˣ��������ɣ������ű����ˡ�" << _NAME << "������˫�ۣ����Ź�Ƿ���˳���" << endl;
				_getch();
				cout << "��ǰ����λŮ�ӣ�����һͷ��ɫ�ĳ������������·����ҫ�۵Ĺ�ԡ����µ������ϣ�һ˫�����˫����Ƕ��ѩ�׵ļ����У�ɢ�������˵ĺ�ɫ����ı�ͦ��������װ��һ�����Ͽ����ĺ���������ΪӢ�������������ǹ���������ͺţ������Ǻ��ټ�������װ����" << endl;
				_getch();
				cout << "��Ȼ���������Ȳ��͵�LED�ƣ���һ�������棬" << _NAME << "���Ǳ��������������ʶ�������ۡ�" << endl;
				_getch();
				cout << "���ף����ǡ�����" << _NAME << "��΢��Ӧһ�������ӳ�������ģ���ǰ��һ�����������ƣ�ȴ���ѱ�������¥����" << endl;
				_getch();
				cout << "û��������û�����⣬������ɫ�ʶ�û�У����Ʋ����ĳ����ƺ��ѿ�����Ⱦ�������������Ļ�ɫ��ֻ�е����ķ�����һ����֤�����ǵĴ��ڡ�" << endl;
				_getch();
				cout << "��ת��ʧ�ܶ��������ĳ�����" << _NAME << "�����°ͣ�ϸϸ�������ţ���������ֵط��Ѿ�������ˡ�����λ���˵ĸ����������еĵط���������ִ������졣��ô˵�����˴���������ԭ���ǡ�����" << endl;
				_getch();
				cout << "��û��������Ϊ�Ǹ��ط�����ͣ����һ�£�˾������˵�������⸽���Ŀռ��߷ǳ�Ť�����޷������¿Ƽ��Ŀռ似����������н���ת�͡���ϧ��ѽ����ô�õ���λ�ͻ�����������˵��Դ���˵㣬������������Ƶĸ��죬�ۺ�ָ��϶���������Щ�����ѽ������" << endl;
				_getch();
				cout << "������ô˵�������������������ȫû��������ϧ����˼��" << endl;
				_getch();
				cout << "���ܲ������Ϊʲô����ô˵�ɣ����������" << _NAME << "�����ߣ�˾��˵�������Ǿ���ת����ɡ���" << endl;
				_getch();
				cout << "ת��" << _NAME << "��Ȼ��Щ���⣬�����ǻ����ڴ�������ת�˹�ȥ����" << endl;
				_getch();
				cout << "����Ծ��ǵ����Ļ�ɫ������ת�����ȵļӴ�һĨ��Ŀ����ɫ�������۽ǣ���" << _NAME << "���ɵþ�����һ����" << endl;
				_getch();
				cout << "��ת����һ�㣬���԰�������ɫ��ͿĨ����Ұ�Ϸ������·������˴���ĵ���ɫ��һ�������ĺۼ���Զ���������֣��·����ӵ���ߡ�" << endl;
				_getch();
				cout << "���һ�㡣ε��������Ͼ��ĵص�׺�ż������͸�Ƶ��ƶ䡣һ����ɽ����������ɫ�����£����ص����Ǳ��о�����ء�һƬƽԭ�����������������½����ӳ����ľ�Ͳݴ���΢��Ĵ�����ͬ����Ȼһͬ������һ��С�ӣ���һ����ɫ�Ķд�������������������������޵���������" << endl;
				_getch();
				cout << "ӭ��������߲�ɫ��̫�����Σ���������͵����," << _NAME << "��������������ǰ������������һʱ֮���Ȼ�𾪵�˵��������" << endl;
				_getch();
				cout << "����������Ȼ��⣬û���κ������ĺۼ���" << endl;
				_getch();
				cout << "���ܿ�ϧ��������" << _NAME << "Ц��˵�������Ҳ�����ѧ����ȫû���������������Ķ���������" << endl;
				_getch();
				cout << "�·������鶼����ϴ��һ����" << endl;
				_getch();
				cout << "�·��ǻ���һ��ĵط���" << endl;
				_getch();
				cout << "��������һ���ɣ���˾����ο��˵�������ҵ����ܶඥ����԰��Ҳ�����������Ȼ�����������ҵ�һ��������Ƭ����ʱ���ұ����ף���ط��Ѿ���Ȼ�ý�������Ȼ�ˡ���" << endl;
				_getch();
				cout << "����ô˵���ҽ�Ҫǰ���ĵط����������" << _NAME << "˵�������ٴ���ǰ�ľ����������ǵط�ȷʵ��ͦԭʼ��" << endl;
				_getch();
				cout << "��˵����һ�룬����������Ŀ�ĵػ�Զ�ţ�����ֻ�Ǹ���ڶ��ѡ��߰ɣ����ǻ������������ء���˾����ǰ�ߴ�ͷ������������ɽ���˹�ȥ��" << endl;
				_getch();
				cout << "����֮ǰ��" << _NAME << "�ֻ�����һȦ����Ƭ�������Ǳ����⻮�ֳ����ģ������Ǹ�һ������������������Ȼ��ͬ�����硣";
				cout << "����Զ����ȥ����Ƭ�������Χͬ���Ǳ���ɫ�Ľ���Ⱥ����������" << endl;
				_getch();
				cout << "��Զһ��Ϳ������ˡ�" << endl;
				_getch();
				cout << "����������" << _NAME << "�첽������ȥ��" << endl;
				_getch();
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "..." << endl;
				_getch();
				cout << ".." << endl;
				_getch();
				cout << "." << endl;
				_getch();
				cout << "�����Զ����ȥ����������һƬԭʼ���򡣵���ʵ�ϣ��߽�֮����ܷ��֣��������ط��Ѿ�������̽�����ˣ����ϵ�С·�ͱ�ʶ��ľ�ƿ���֤����һ�㡣" << endl;
				_getch();
				cout << "���ںܾ���ǰ�����ﱾ����һƬ��ģ��С�Ĵ�ׯ���������ʱ����չ���ܶ��˶������Ǩ�ߣ������ǶԴ˵�����ѵ���Ҳ�ᵽ�����ĳ���ʹ�ô˵���û���ˡ���";
				cout << "˾��һ����ǰ���·��һ���������µ�˵������������ط����±�������עʱ���˵����ѻع���Ȼ��ɫ�ˡ�������̽����ط���������֣�����Ƭ���򲻽��ò���ָ���롢GPS���������������㶼ģ������ȫ�޷����ϡ���" << endl << endl;
				_getch();
				cout << "�����������д�˵�㲻��˼�鰡����" << endl;
				_getch();
				cout << "���٣��ǿɲ������⻹��������µġ�ƽԭ���򻹺�˵��������ǣ�ң��һ�½���Ⱥ���ô�����ȷ�������򣬵�һ����������ɽ���Ǻǡ�����˾������ͣ��������������Ϊ�������Ⱦ����һ�㣬��ɽ�ķ����Ǳߴ���һ���������죬���ơ�ѹ�֣��ֲ�̫����ʲô�����������" << endl;
				_getch();
				cout << "����紵��ɽ�ȵ������ɡ�������Ȼ�����еף���" << _NAME << "���Ǳ��ŵö�����һ�£��Դ���Թ����ʧ�����˵�������㻹���ʺ�ȥ���ֲ����°�����֮���أ�ɽ����ʲô��ֵĶ����𣿡�" << endl;
				_getch();
				cout << "��������лл������ͣ���˾��ˬ�ʵ�Ц�˼�����ͻȻ���������������ص�����˵������ɽ�е�Ȼû����ֵĶ��������Ͼ�ǰȥ̽������һ����û�л�����˭�ֻ�֪���أ���" << endl;
				_getch();
				cout << "�����ƺ��е�����Ϊʲô�⸽���ĳ��б������ˡ�" << endl;
				_getch();
				cout << "������Ȼû���ţ����Ͼ���̽���ӣ�����ÿ��һ�ξ���������һ�ڴ��濨���ӽ���Χ���յ��Ĵ��濨������������Ȼû����ʲôΣ�գ�����һ���ⶼ����������·���������ǻ�������ǿ���Լ�������ʲôĪ���Ķ����������ǻ�û�������ʧ����Ӱ�����ˡ���" << endl;
				_getch();
				cout << "��ԭ����ˡ������ǵ��Ĺ��𣿡�" << _NAME << "�����ⷬ���󣬲��ɵ���Щ���������ǣ�������һȺ������ʶ����һ�е��ؾ����ء���" << endl << endl;
				_getch();
				cout << "����ô����¶���δ��Ҳ̫�ż��ˣ��Ͼ������������������¼������١��������ڿ����Ǹ��ط�ǰ������ô��ġ���" << _NAME << "������������˾�������еĲ����ˡ�" << endl;
				_getch();
				cout << "��������Ҳ�Ǻ���������ˣ���˾�����������������������ڵ�ʱ����֪���ŵ�����Ψ�ֱ�֮�������׷׳�������ɽ��һ��εĵط�������Ҳ�ͳ�Ϊ����ո��������ĸ�֡��������͵�ʱ����Ⱦ����ˮƽ��������ط��ķ羰�����ϡ���ѵ�";
				cout << "�����ǣ��ȷ�ͷһ�����ܶ��˹��������ܱߵ��׷����������Ϊȫ���������ĸ߶�סլ��֮һ����Ȼ�����۷��۱����ö�ߣ�Ҳû���ĸ������̸���������һ���ġ����Ҳ������ո����������龰������Ҳ���¿Ƽ��ռ�����Щ��ĳɹ����ˡ���" << endl << endl;
				_getch();
				cout << "ͦ����˼����" << endl;
				_getch();
				cout << _NAME << "���ͷ������ʵ�������ط�������Ҵ������ˡ�����˵�����ǽ�����Ҫ��ɽ����" << endl;
				_getch();
				cout << "˾�����ͷ������������ǵ�Ȼ�����ң��ǽ���ɽ����������㲻�ص��ģ���Ƭ���򲻾�ǰ����ר��̽����������ֱ��˳������·����ȥ�����ˡ���" << endl;
				_getch();
				cout << "��������������" << _NAME << "̧ͷ����һ��ɽͷ����ŵĹ���һ�¾����̾����������������һ�β�С�ľ��밡������" << endl;
				_getch();
				cout << "���ú���ϧһ�������������ʱ��ɣ���˾����Ȥ������ָ��������������Ļ���Ŷ~��" << endl << endl;
				_getch();
				cout << "���ȣ����������Ц������Ȼûָ���ܻ��Ż�������Ҳ��ϣ����Ľ������Ƕ��ˡ���" << _NAME << "���������˵����ͻȻ����˾���������췢Ц��" << endl;
				_getch();
				cout << "��ι������һ����" << _NAME << "���ߵ�˾����ǰ������������֮���ߣ����������ز�����" << _NAME << "��������֣���������ͷ��Ǹ������������˼��,������ô�ɰ����ұ��̲�ס��Ҫ׽Ū��һ�£�û�뵽����������л�Ҫû�����ء���" << endl;
				_getch();
				cout << "����һ���Ǹ����˼��û�С���" << _NAME << "���ε�ҡҡͷ��˵��������������û�취����" << endl;
				_getch();
				cout << "�����˺��ˣ���˵����ˡ��㿴�������Ѿ���������ˡ���";
			}
		}

	}
	else if (gongneng == "����") {

	}
	else if (gongneng == "����") {

	}
}

void ZhangJie0() {
	//	JuBen("����",1);
}

#endif


//����������ϣ���������ģ������缴���˹����ڵ����磬���а������ڵĻ����磬 �����������˹���Ҫ��ռ���ǹ�ȥ�Ļ����硣
//�ڶ����ϣ����Ⱥ�Ļ���¶��������ˣ����Ǵ�������տ��Ŀ��ƣ����������ó��ִ��Ŀռ似���жϺտ���������򡢵�������ϵ��
//����͵����ѱ����ƣ���ǰ������������Ҫͨ����������롣�ܿ�ϧ����ʵ�Ļ�����ԭס����ǿ�ֿ������˸����򲻽�ȥ��
//������֮�����ÿռ似�����ڳ�Ұ��ǿ�д�һ��ʱ���ѷ죬ͨ����ȥ�Ļ����硣�����ȥ�Ļ��������ֱ�� Ӱ�����ڵĻ����磬����Ҫ���˹����б�Ҫ����졣
//��ͷ���˹����˽⵽����Ϣֻ����Ҫ����͸���з�������֪���Լ�������һ��ʱ�����У������ص㡣 


