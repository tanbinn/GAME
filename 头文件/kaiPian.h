#ifndef _KAIPIAN_H_
#define _KAIPIAN_H_
#include"jieMian.h"
using namespace std;

int jiaojiedian_shanjiao2 = 0; int jiaojiedian_shanjiao3 = 0; int jiaojiedian_shanjiao4 = 0; int jiaojiedian_shanjiao6 = 0; int jiaojiedian_shanjiao7 = 0; int jiaojiedian_shanjiao5 = 0;
int jiaojiedian_shanjiao_ruko4 = 0;//���صص���ж���


//1000-->С�͵�ͼ�� 2000-->���͵�ͼ�� 3000-->���͵�ͼ�� 4000-->�����ͼ��
void map(int point){//�������룬���ƶ������У�ͨ�����벻ͬ���������л���ͬ�ĵ�ͼ���棬����������������ֵ����10.20.30�����ģ���Ҫ���λ���������ͻ
	ChongZhi();
	if (point == 2000) {
		if (zhuRenGong.daweizhi == "���ӵ�") {
			if(zhuRenGong.zhongweizhi == "ɽ��"){
				string w2 = "2��С·1��  "; 
				string w5 = "           ";
				string w3 = "               ";
				string w6 = "               ";
				string w4 = "          "; 
				string w7 = "         ";
				if(jiaojiedian_shanjiao2 >= 1){
					w2 = "2��С·1������"; 
					w3 = "3���Ծ��Ĵ�����";
					w4 = "4��С·2��";
				}
				if(jiaojiedian_shanjiao3 >= 1){
					w6 = "6�������ķ��ݡ�";
					w3 = "3���Ծ��Ĵ����� ����";
				}
				if(jiaojiedian_shanjiao4 >= 1){
					w4 = "4��С·2����������������"; 
					w7 = "7��ɽ·��" ;
				}
				if(jiaojiedian_shanjiao7 >= 1){
					w6 = "6�������ķ��ݡ��������� ";
					if(jiaojiedian_shanjiao3 == 0){
						w3 = "3���Ծ��Ĵ����� ����" ; 
					}
				}
				if(jiaojiedian_shanjiao6 >= 1){
					w6 = "6�������ķ��ݡ���������";
					w7 = "7��ɽ·��"; 
					w4 = "4��С·2����������������"; 
				}
				if (jiaojiedian_shanjiao2 > 0) {
					if ((jiaojiedian_shanjiao6 >= 1) or (jiaojiedian_shanjiao7 >= 1)) {
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "                                                                                                                        " << endl;
						cout << "                " << w3 << w6 << "                                                             " << endl;
						cout << "                        |                                   |                                                             " << endl;
						cout << "    1����ڡ�����" << w2 << w4 << w7 << "                                                      " << endl;
						if (jiaojiedian_shanjiao_ruko4 == 0) {
							cout << "                                                                                                                        " << endl;
							cout << "                                                                                                                        " << endl;
						}
						else {
							cout << "         |                                                                                                              " << endl;
							cout << "    5����ʯ�顿                                                                                                         " << endl;
						}
						cout << "                                                                                                                        " << endl;
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						return;
					}
					else {
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "                                                                                                                        " << endl;
						cout << "                " << w3 << w6 << "                                                             " << endl;
						cout << "                        |                                                                                                " << endl;
						cout << "    1����ڡ�����" << w2 << w4 << w7 << "                                                      " << endl;
						if (jiaojiedian_shanjiao_ruko4 == 0) {
							cout << "                                                                                                                        " << endl;
							cout << "                                                                                                                        " << endl;
						}
						else {
							cout << "         |                                                                                                              " << endl;
							cout << "    5����ʯ�顿                                                                                                         " << endl;
						}
						cout << "                                                                                                                        " << endl;
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						return;
					}
				}
				else {
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "                                                                                                                        " << endl;
					cout << "                " << w3 << w6 << "                                                             " << endl;
					cout << "                                                                                                                         " << endl;
					cout << "    1����ڡ�����" << w2 << w4 << w7 << "                                                      " << endl;
					if (jiaojiedian_shanjiao_ruko4 == 0) {
						cout << "                                                                                                                        " << endl;
						cout << "                                                                                                                        " << endl;
					}
					else {
						cout << "         |                                                                                                              " << endl;
						cout << "    5����ʯ�顿                                                                                                         " << endl;
					}
					cout << "                                                                                                                        " << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					return;
				}
			  //cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			  //cout << "                                                                                                                        " << endl;
			  //cout << "                3���Ծ��Ĵ����� ����6�������ķ��ݡ���������                                                             " << endl;
			  //cout << "                      |                                  |                                                              " << endl;
			  //cout << "    1����ڡ�����2��С·1������4��С·2������������������7��ɽ·��                                                        " << endl;
			  //cout << "         |                                                                                                              " << endl;
			  //cout << "    5����ʯ�顿                                                                                                         " << endl;
			  //cout << "                                                                                                                        " << endl;
			}
		}
		
	}
	else if (point == 1000) {
		//��δ֪������Ӱ�죬�Ժ����ַ����д�\��ʱ�ǵ�ÿ���ַ�д���飨����Ҫ���һ����\������Ҫ��������\������������ʹ��ĸ���
		if (zhuRenGong.daweizhi == "���ӵ�") {
			if (zhuRenGong.zhongweizhi == "ɽ��") {
				if (zhuRenGong.xiaoweizhi == "���") {
					if (jiaojiedian_shanjiao_ruko4 > 0) {
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "        ///////////////////////////////////////////////////////////////////////////////////////                         " << endl;
						cout << "       ////////////////////////////////////////////////////// ________ ////////////////////                             " << endl;
						cout << "       ///////////////////////////////////////////////////// |******  | ////////////////                                " << endl;
						cout << "     /////////////////////////////////////////////////////// |________|///////////////                                  " << endl;
						cout << "        _________________________________________________________||____________                                         " << endl;
						cout << "       |                                                                                                                " << endl;
						cout << "       |                                 [2]���              [3]ľ��          [5]С�� ��������>{С·1}                      " << endl;
						cout << "       |                                                                                                                " << endl;
						cout << "       |        _____________________    ((''''))  ____________________________                                         " << endl;
						cout << "       |        |                   |  ( '''''''' )|                                                                    " << endl;
						cout << "       |        |                   |( '*'''*''''''')                                                                   " << endl;
						cout << "       |        |    //////////    ( ''''''*'''''*''' )   //////////////////////                                        " << endl;
						cout << "       |        |     /////////    ( '''*''''*''''''' )   ////'/////////////////                                        " << endl;
						cout << "       |        | //////////////    |(''''''*''*''' )     //////////////////////                                        " << endl;
						cout << "       |        |    ////////       |  ( ''''''' ) |      /////'//////'/////////                                        " << endl;
						cout << "       |        |    ////////       |    (||||||)  |      /////////'////////////                                        " << endl;
						cout << "     //|        |\\   ///////////    |     ||||||   |     //////////////////////                                         " << endl;
						cout << "    ///|1[���] |\\\\  //////////     |     ||||||   |     //////////////////////                                         " << endl;
						cout << "   ////|        |\\\\\\//////////      |4[��]||||||   |     //////////////////////                                         " << endl;
						cout << "  /////|        |\\\\\\\\               |    //||||\\\\  |                                                                    " << endl;
						cout << "                                    |              |                                                                    " << endl;
						cout << "                                    |              |                                                                    " << endl;
						cout << "                                    | 6[С��]      |                                                                    " << endl;
						cout << "                                          |                                                                             " << endl;
						cout << "                                          |                                                                             " << endl;
						cout << "                                          V                                                                             " << endl;
						cout << "                                      {��ʯ��}                                                            welcome^_^    " << endl;
					}
					else if (jiaojiedian_shanjiao_ruko4 == 0) {
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "        ///////////////////////////////////////////////////////////////////////////////////////                         " << endl;
						cout << "       ////////////////////////////////////////////////////// ________ ////////////////////                             " << endl;
						cout << "       ///////////////////////////////////////////////////// |******  | ////////////////                                " << endl;
						cout << "     /////////////////////////////////////////////////////// |________|///////////////                                  " << endl;
						cout << "        _________________________________________________________||____________                                         " << endl;
						cout << "       |                                                                                                                " << endl;
						cout << "       |                                 [2]���              [3]ľ��          [5]С· ��������>{С·1}                      " << endl;
						cout << "       |                                                                                                                " << endl;
						cout << "       |        _____________________    ((''''))  ____________________________                                         " << endl;
						cout << "       |        |                   |  ( '''''''' )|                                                                    " << endl;
						cout << "       |        |                   |( '*'''*''''''')                                                                   " << endl;
						cout << "       |        |    //////////    ( ''''''*'''''*''' )   //////////////////////                                        " << endl;
						cout << "       |        |     /////////    ( '''*''''*''''''' )   ////'/////////////////                                        " << endl;
						cout << "       |        | //////////////    |(''''''*''*''' )     //////////////////////                                        " << endl;
						cout << "       |        |    ////////       |  ( ''''''' ) |      /////'//////'/////////                                        " << endl;
						cout << "       |        |    ////////       |    (||||||)  |      /////////'////////////                                        " << endl;
						cout << "     //|        |\\   ///////////    |     ||||||   |     //////////////////////                                         " << endl;
						cout << "    ///|1[���] |\\\\  //////////     |     ||||||   |     //////////////////////                                         " << endl;
						cout << "   ////|        |\\\\\\//////////      |4[��]||||||   |     //////////////////////                                         " << endl;
						cout << "  /////|        |\\\\\\\\               |    //||||\\\\  |                                                                    " << endl;
						cout << "                                                                                                          welcome^_^    " << endl;
					}
					


					/*cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "        ///////////////////////////////////////////////////////////////////////////////////////                         " << endl;
					cout << "       ////////////////////////////////////////////////////// ________ ////////////////////                             " << endl;
					cout << "       ///////////////////////////////////////////////////// |******  | ////////////////                                " << endl;
					cout << "     /////////////////////////////////////////////////////// |________|///////////////                                  " << endl;
					cout << "        _________________________________________________________||____________                                         " << endl;
					cout << "       |                                                                                                                " << endl;
					cout << "       |                                 [2]                  [3]              [5]----->                                " << endl;
					cout << "       |                                                                                                                " << endl;
					cout << "       |        _____________________    ((''''))  ____________________________                                         " << endl;
					cout << "       |        |                   |  ( '''''''' )|                                                                    " << endl;
					cout << "       |        |                   |( '*'''*''''''')                                                                   " << endl;
					cout << "       |        |    //////////    ( ''''''*'''''*''' )   //////////////////////                                        " << endl;
					cout << "       |        |     /////////    ( '''*''''*''''''' )   ////'/////////////////                                        " << endl;
					cout << "       |        | //////////////    |(''''''*''*''' )     //////////////////////                                        " << endl;
					cout << "       |        |    ////////       |  ( ''''''' ) |      /////'//////'/////////                                        " << endl;
					cout << "       |        |    ////////       |    (||||||)  |      /////////'////////////                                        " << endl;
					cout << "     //|        |\   ///////////    |     ||||||   |     //////////////////////                                         " << endl;
					cout << "    ///|  [1]   |\\  //////////     |     ||||||   |     //////////////////////                                         " << endl;
					cout << "   ////|        |\\\//////////      |  [4]||||||   |     //////////////////////                                         " << endl;
					cout << "  /////|        |\\\\               |    //||||\\  |                                                                    " << endl;
					cout << "                                                                                                          welcome^_^    "*/
	
				}
			}
		}
		
	}
}

//1000-->С�͵�ͼ�� 2000-->���͵�ͼ�� 3000-->���͵�ͼ�� 4000-->�����ͼ
void yidong(int point){
	ChongZhi();
	int zhongji = 0;
	if (point == 2000) {
		cout << endl << endl << endl << "��λ:" << zhuRenGong.zhongweizhi << "   �ص㣺" << zhuRenGong.xiaoweizhi << "   ������(���ڿ�����)   ʱ�䣺" << month_quanju << "��" << day_quanju << "�� " << hour_quanju << ":" << min_quanju << endl;
		map(2000);
		cout << "1000[С��ͼ] 3000[���ͼ] 4000[ȫ�ֵ�ͼ] 0[����]" << endl;
		cout << "��Ŀǰ���޷�ֱ���ƶ���˴�Χ" << endl;
		cin >> zhongji;
		if(zhuRenGong.daweizhi == "���ӵ�"){
			if(zhuRenGong.zhongweizhi == "ɽ��") {
				if (zhongji == 1000 or zhongji == 3000 or zhongji == 4000) {
					return yidong(zhongji);
				}
				if (zhongji == 0) {
					return;
				}
				string kongbai;
				if (kongbai == "�����ȿ��ţ�������������ϵͳ����С����С����ܵ��ж�") {
					if(zhongji == 5 && jiaojiedian_shanjiao5 > 0){
						zhuRenGong.xiaoweizhi = "��ʯ��";
					}
					else if(zhongji == 2){
							zhuRenGong.xiaoweizhi = "С·1";
							jiaojiedian_shanjiao2 = jiaojiedian_shanjiao2 + 1;
					}
					else if(zhongji == 3 && jiaojiedian_shanjiao2 >= 1){
							zhuRenGong.xiaoweizhi = "�Ծ��Ĵ���";
							jiaojiedian_shanjiao3 = jiaojiedian_shanjiao3 + 1;
					}
					else if(zhongji == 6 && ((jiaojiedian_shanjiao3 >= 1) or (jiaojiedian_shanjiao7 >= 1))){
							zhuRenGong.xiaoweizhi = "�����ķ���";
							jiaojiedian_shanjiao6 ++;
					}
					else if(zhongji == 4 && jiaojiedian_shanjiao2 >= 1){
							zhuRenGong.xiaoweizhi = "С·2";
							jiaojiedian_shanjiao4 ++;
					}
					else if(zhongji == 7 && ((jiaojiedian_shanjiao4 >= 1) or (jiaojiedian_shanjiao6 >= 1))){
							zhuRenGong.xiaoweizhi = "ɽ·";
							jiaojiedian_shanjiao7 ++; 
					}
					else {//���else�Ѿ�����Ч��ѡ����˵��ˣ����Կ��Է��ı༭���������
						cout << "��������Чѡ���Ӧ�����֡�" << endl;
						_getch();
						return yidong(2000);
					}
					if (zhuRenGong.zhongweizhi == _renwu[0].zhongweizhi && zhuRenGong.xiaoweizhi == _renwu[0].xiaoweizhi) {
						cout << "����ԭ��̤��Ŷ" << endl;
						_getch();
						return yidong(2000);
					}
					else {
						cout << "�ƶ�����" << zhuRenGong.xiaoweizhi << "  " << zhuRenGong.weizhi;
						shiJianJieMian(20, "ȫ��");
						return yidong(2000);
					}
				}
				else {
					return yidong(2000);
				}
			}
		}
	}
	else if (point == 1000) {
		cout << endl << endl << endl << "�ص�:" << zhuRenGong.xiaoweizhi << "   λ�ã�" << zhuRenGong.weizhi << "   ������(���ڿ�����)   ʱ�䣺" << month_quanju << "��" << day_quanju << "�� " << hour_quanju << ":" << min_quanju << endl;
		map(1000);
		cout << "2000[�е�ͼ] 3000[���ͼ] 4000[ȫ�ֵ�ͼ] 0[����]" << endl;
		cout << "��������Ҫǰȥ�ĵط�" << endl;
		cin >> zhongji;
		if (zhuRenGong.daweizhi == "���ӵ�") {
			if (zhuRenGong.zhongweizhi == "ɽ��") {
				if (zhuRenGong.xiaoweizhi == "���") {
					if (zhongji == 2000 or zhongji == 3000 or zhongji == 4000) {
						return yidong(zhongji);
					}
					else if (zhongji == 0) {
						return;
					}
					else if (zhongji == 1) {
						zhuRenGong.weizhi = "���";
					}
					else if (zhongji == 2) {
						zhuRenGong.weizhi = "���";
					}
					else if (zhongji == 3) {
						zhuRenGong.weizhi = "ľ��";
					}
					else if (zhongji == 5) {
						zhuRenGong.weizhi = "С��";
						zhuRenGong.zhongweizhi = "С·1";
					}
					else if (zhongji == 4) {
						zhuRenGong.weizhi = "��";
						jiaojiedian_shanjiao_ruko4 ++;
					}
					else if (zhongji == 6 && jiaojiedian_shanjiao_ruko4 > 0) {
						zhuRenGong.weizhi = "С��";
						zhuRenGong.xiaoweizhi = "��ʯ��";
						jiaojiedian_shanjiao5 ++;
					}
					else {
						cout << "��������Чѡ���Ӧ�����֡�" << endl;
						_getch();
						return yidong(1000);
					}
					if (zhuRenGong.xiaoweizhi == _renwu[0].xiaoweizhi && zhuRenGong.weizhi == _renwu[0].weizhi) {
						cout << "����ԭ��̤��Ŷ" << endl;
						_getch();
						return yidong(1000);
					}
					else {
						cout << "�ƶ�����" << zhuRenGong.weizhi;
						_getch();
						shiJianJieMian(2, "ȫ��");
						return yidong(1000);
					}
				}
			}
		}
	}
}

#endif

//���������ƶ�ʱ��Ļ�����û������ƶ��������ǣ�С��ͼ��Χ���ƶ����Լ��з�Χ�ʹ�Χ���Բ�ͬʱ��Ϊһ���������� 

