#ifndef _JIEMIAN_H_
#define _JIEMIAN_H_

#include"conio.h"
#include"juBen.h"
using namespace std;

//�����������ȶ����ʼλ�ã�������λ�ƿ���ͨ����ͼ�ļ����Կ� 

void zhuangtai(string gongneng, string name, string zhuangtai) {//��״̬�ϣ���������ﵥ������һ�����У����ַ�������ʽ���ڴ洢��Ȼ����ú�����������ʱ���ֱ�ָ��������ܡ� ����״̬�������������ѡ���Ƿ���ţ� 
	if (gongneng == "���") {
		if (name == "��") {
			for (int i = 0; i < _renwu[0].zhuangtai.size(); i++) {
				cout << _renwu[0].zhuangtai[i] << " ";
			}
		}
		if (name == "˾��") {
			for (int i = 0; i < siJi.zhuangtai.size(); i++) {
				cout << siJi.zhuangtai[i] << " ";
			}
		}
	}
	else if (gongneng == "����") {//��Ϊû�뵽���õ��ж�����������ÿ��Ҫ����һ�������״̬���飨ע����ÿ�Σ����κ���״̬�йص�ָ��ǰ������ �ж�ǰ��Ϊ�������Ƿ����ֳ���Сλ�ã�,������һ�䣬��״̬�������д��״̬�й�ϵ�Ĵ��룬������������˳·��NPCλ�Ƹ�д��
		//����������˵�״̬�����е����ݣ�Ȼ����ݲ�ͬ�Ĳ����ֱ��ÿ���˼���״̬����
		for (int i = 0; i < _renwu.size(); i++) {
			_renwu[i].zhuangtai.clear(); 
		}
		for (int i = 0; i < _renwu.size(); i++) {//���ˣ����Ƿֲ�ͬ�����������ú��ˣ��Դ�λ��Ϊ��Ԫ��
			if (_renwu[i].daweizhi == _renwu[0].daweizhi) {
				if (_renwu[i].name == "��") {
					if (_renwu[0].baoShiDu_D <= 50 && _renwu[0].baoShiDu_D > 20) {
						_renwu[0].zhuangtai.push_back("<�Զ�>");
					}
					if (_renwu[0].baoShiDu_D <= 20 && _renwu[0].baoShiDu_D > 0) {
						_renwu[0].zhuangtai.push_back("<����>");
					}
					if (_renwu[0].baoShiDu_D == 0) {
						_renwu[0].zhuangtai.push_back("<������>");
					}
					if (_renwu[0].jingLi_D >= (0.8 * _renwu[0].jingLi_G) && _renwu[0].tiLi_D >= (0.8 * _renwu[0].tiLi_G)) {
						_renwu[0].zhuangtai.push_back("<������>");
					}
					if (_renwu[0].jingLi_D < (0.1 * _renwu[0].jingLi_G)) {
						_renwu[0].zhuangtai.push_back("<����>");
					}
					if (_renwu[0].tiLi_D < (0.5 * _renwu[0].tiLi_G) && _renwu[0].tiLi_D >= (0.2 * _renwu[0].tiLi_G)) {
						_renwu[0].zhuangtai.push_back("<����>");
					}
					if (_renwu[0].wenDu >= 75 && _renwu[0].wenDu < 100) {
						_renwu[0].zhuangtai.push_back("<����>");
					}
					if (_renwu[0].wenDu == 100) {
						_renwu[0].zhuangtai.push_back("<����>");
					}
					if (_renwu[0].wenDu == 0) {
						_renwu[0].zhuangtai.push_back("<����>");
					}
					if (_renwu[0].wenDu > 0 && _renwu[0].wenDu <= 25) {
						_renwu[0].zhuangtai.push_back("<����>");
					}
					sort(_renwu[0].zhuangtai.begin(), _renwu[0].zhuangtai.end());
					for (i = 1; i < _renwu[0].zhuangtai.size(); i++) {
						if (_renwu[0].zhuangtai[i] == _renwu[0].zhuangtai[i - 1]) {
							_renwu[0].zhuangtai.erase(_renwu[0].zhuangtai.begin() + i);
						}
					}
					_renwu[0].zhuangtai_num = _renwu[0].zhuangtai.size();
				}
				if (_renwu[i].name == "˾��") {
					if (_renwu[1].baoShiDu_D <= 50 && _renwu[1].baoShiDu_D > 20) {
						_renwu[1].zhuangtai.push_back("<�Զ�>");
					}
					if (_renwu[1].baoShiDu_D <= 20 && _renwu[1].baoShiDu_D > 0) {
						_renwu[1].zhuangtai.push_back("<����>");
					}
					if (_renwu[1].baoShiDu_D == 0) {
						_renwu[1].zhuangtai.push_back("<������>");
					}
					if (_renwu[1].jingLi_D >= (0.8 * _renwu[1].jingLi_G) && _renwu[1].tiLi_D >= (0.8 * _renwu[1].tiLi_G)) {
						_renwu[1].zhuangtai.push_back("<������>");
					}
					if (_renwu[1].jingLi_D < (0.1 * _renwu[1].jingLi_D)) {
						_renwu[1].zhuangtai.push_back("<����>");
					}
					if (_renwu[1].tiLi_D < (0.5 * _renwu[1].tiLi_G) && _renwu[1].tiLi_D >= (0.2 * _renwu[1].tiLi_G)) {
						_renwu[1].zhuangtai.push_back("<����>");
					}
					if (_renwu[1].wenDu >= 75 && _renwu[1].wenDu < 100) {
						_renwu[1].zhuangtai.push_back("<����>");
					}
					if (_renwu[1].wenDu == 100) {
						_renwu[1].zhuangtai.push_back("<����>");
					}
					if (_renwu[1].wenDu == 0) {
						_renwu[1].zhuangtai.push_back("<����>");
					}
					if (_renwu[1].wenDu > 0 && _renwu[1].wenDu <= 25) {
						_renwu[1].zhuangtai.push_back("<����>");
					}
					sort(_renwu[1].zhuangtai.begin(), _renwu[1].zhuangtai.end());
					for (i = 1; i < _renwu[1].zhuangtai.size(); i++) {
						if (_renwu[1].zhuangtai[i] == _renwu[1].zhuangtai[i - 1]) {
							_renwu[1].zhuangtai.erase(_renwu[1].zhuangtai.begin() + i);
						}
					}
					_renwu[1].zhuangtai_num = _renwu[1].zhuangtai.size();
				}
			}
		}
	}
	else if (gongneng == "����") {
	}
}

void tianqi() {//�����������Գ���������һ�㡣�����䶯���Դ��ͼΪһ�����õ�λ����һ��������λ�����Ϊ���㵥λ������ʱ�����ṩ��ʱ�ַ����飬��������벻ͬ���͡��������������ƣ� 
			  //Ȼ�������������ȡ�����ַ������ṩ�±꣬�Ӷ����������������
			  //����ʱ����һ���������������Ļ���ϣ����120���ӵ�720����֮�䣬Ȼ�������һ������
			  //��Ȼ����ͬ�ļ��ڡ��ص㡢���＼�ܶ���Ӱ�쵽�����仯���������ص㷽���Ӱ��д��ú������ɣ����������ز�����Ӱ���ֱ���ں�����Ķ�������Ҫ������������ʱ�䣩 
	if (year_tianqi < year_quanju) {
		panduan_tianqi = true;
	}
	else if (year_tianqi = year_quanju) {
		if (month_tianqi < month_quanju) {
			panduan_tianqi = true;
		}
	}
	else if (year_tianqi = year_quanju) {
		if (month_tianqi = month_quanju) {
			if (day_tianqi < day_quanju) {
				panduan_tianqi = true;
			}
		}
	}
	else if (year_tianqi = year_quanju) {
		if (month_tianqi = month_quanju) {
			if (day_tianqi = day_quanju) {
				if (hour_tianqi < hour_quanju) {
					panduan_tianqi = true;
				}
			}
		}
	}
	else if (year_tianqi = year_quanju) {
		if (month_tianqi = month_quanju) {
			if (day_tianqi = day_quanju) {
				if (hour_tianqi < hour_quanju) {
					if (min_tianqi <= min_quanju)
						panduan_tianqi = true;
				}
			}
		}
	}
	else {
		panduan_tianqi = false;
	}

	if (panduan_tianqi == true) {
		srand(time(0));
		int suijinum = 0;
		if (_renwu[0].daweizhi == "���ӵ�") {
			string zhongji;
			shiJianJieMian(180, "��������");
			if (tianqi_jiaojiedian == "��") {
				string tianqi[5] = { "��","��","����","����","����" };
				tianqi_jiaojiedian = tianqi[rand() % 5];
				zhongji = tianqi_jiaojiedian;
				if (zhongji == "��") {
					return;
				}
				else if (zhongji == "����" && hour_quanju >= 6 && hour_quanju <= 16) {//���� 
					cout << "�ƶ�ۼ�����������΢��ס�˵�̫����" << endl;
					cout << "�е����Ǻ����ˡ�" << endl;
					return;
				}
				else if (zhongji == "����" && hour_quanju > 16 && hour_quanju <= 18) {//�ƻ� 
					if (rand() % 2 == 0) {
						cout << "Ϧ�����£��ۿ��Ź�â���ţ��ƶ��Ƿ·�е�ʮ�ֲ��ᣬ�׷״Ӷ���ԶԶ�ر�����ת�ۼ�����׳�۵Ľ�ɫ���ˣ�̰�ĵ���������������Ĺ�ԡ�" << endl;
						cout << "�����˵ľ�ɫ�ء�" << endl;
						return;
					}
					else if (rand() % 2 == 1) {
						cout << "���̫����û���£���������������Ӱ��ˡ��ƶ����˷ܵش�����˷����˳�������ӵ����������������ƶ���" << endl;
						cout << "������Ҫ���ƹ����ء�" << endl;
						return;
					}
				}
				else {//ҹ�� 
					cout << "�ƶ�ۼ������������������������һ���ᱡ����ɴ��" << endl;
					cout << "��˵�������У���������ø��Ӻڰ��ˡ�" << endl;
					return;
				}
			}
			else if (tianqi_jiaojiedian == "����") {
				string tianqi[3] = { "��","��","��" };
				tianqi_jiaojiedian = tianqi[rand() % 3];
				zhongji = tianqi_jiaojiedian;
				if (zhongji == "��" && hour_quanju >= 6 && hour_quanju <= 16) {
					//	if(rand() % 3 == 0)  ���Ǻ���Ҫ��һ���㷨��Ŀǰ���ڽ����ڣ���ʱ���ţ��Ժ����������������������ı�����Ҫ����ҹ���е�������ζ�� 
					cout << "̫���������ص��Ʋ㣬�ڸ߿�չʾ�������ˡ�" << endl;
					cout << "�����ů���ء�" << endl;
					return;
				}
				else if (zhongji == "��" && hour_quanju > 16 && hour_quanju <= 18) {
					cout << "��ɹ���̫���ؼҵ���ʽ�󣬽�ɫ��������ɢ�������һ���С�����Ž������ˡ�" << endl;
					return;
				}
				else if (zhongji == "��" && hour_quanju >= 6 && hour_quanju <= 16) {
					cout << "�ƶ���ѻ�����һ��������˺��ص��Ʋ㣬ֱѹ���Ͽգ����˴�����������" << endl;
					cout << "��������͸���������ѹ�ֵĺ�ɫ����������˵Ļ�ɫ�����»������ء�" << endl;
					return;
				}
				else if (zhongji == "��" && hour_quanju > 16 && hour_quanju <= 18) {
					cout << "������ƶ���뵽��ȡ��ɫ��Ե������У�ֱ�����������һ���϶��û�С���ʣ��һ���âҲ�����ɣ���ط·���ǰ������ҹ��" << endl;
					cout << "��ɲ���ѽ����" << endl;
					return;
				}
				else if (zhongji == "��" && hour_quanju > 18 && hour_quanju < 24 && hour_quanju >= 0 && hour_quanju < 6) {
					cout << "�ƶ�ɢ���ˣ��¹������������к�����������������ɫ����װ��" << endl;
					cout << "��Ȼ�����Ǻ���������ƾ�������Կ�����Χ�Ļ����ˡ�" << endl;
					return;
				}
				else if (zhongji == "��" && hour_quanju > 18 && hour_quanju < 24 && hour_quanju >= 0 && hour_quanju < 6)
				{
					cout << "�ƶ��һ���ۼ����ܿ���ռ����Ƭ��գ���һ��������һ˿��âҲ����ȡ�ˡ�" << endl;
					cout << "û��������Դ�Ļ������������ֲ�����ָ��" << endl;
					return;
				}
			}
			else if (tianqi_jiaojiedian == "��") {
				string tianqi[6] = { "����","��","��" };
				tianqi_jiaojiedian = tianqi[rand() % 3];
				zhongji = tianqi_jiaojiedian;
				if (zhongji == "����" && hour_quanju >= 6 && hour_quanju <= 16) {
					cout << "����ɢ����һ�㣬��΢���Ƽ�̫���ˡ�" << endl;
				}
				else if (zhongji == "��" && hour_quanju >= 6 && hour_quanju <= 16) {
					if (rand() % 2 == 0) {//�����ı�bug�����������ɽ�������еĻ�ǧ��Ҫ������ı�����ʱ��ǵ��������
						cout << "һ�����⻮����գ�ֱֱ�ش���Զ����һ�ô����ϣ�ֻһ˲�������������" << endl;
						_getch();
						cout << "����¡¡��������������" << endl;
						cout << "�������ģ��Ǽ������Ƶ�������" << endl;
						cout << "ͻȻ����Χ�����˿�磬���ݡ���ľ�Ա�ѹ�Ƶ�ֱ���������е����������𣬱�˺������Ƭ��ɢ��������" << endl;
						_getch();
						cout << "��ž��" << endl;
						cout << "������Ȼ��һ���������ڲ�Զ����һ�Ŵ����ϣ���β�ֻ�Ǳ���ն�����ڵ���֦�ϻ�Я���ſ��µĻ��棬�����ڲݵ��ϡ�" << endl;
						cout << "���µı��������˻������ӡ��ۿ��ž�Ҫ�չ����ˣ�һ˿�����д�" << _NAME << "��ͷ�ϴ��˹�������" << endl;
						_getch();
						cout << "����ˮ��" << endl;
						_getch();
						cout << "ֻ��һգ�۵Ĺ�����ˮ���㸲�����������������������������˿����������˿�㼯����������룬";
						cout << "�����˻��ݣ���ɢ����Ҷ����û�˻��档���뱩��һͬ�����ţ�ϯ���Ŵ���ϵ�һ�С�" << endl;
						cout << "�����ö�һ�¡�" << endl;
						return;
					}
					if (rand() % 2 == 1) {

						return;
					}
				}
			}
			else if (tianqi_jiaojiedian == "��") {
				string tianqi_jiaojiedian[6] = { "��","��" };
			}

		}
	}
}


void ChongZhi(string gongneng) {//�������ֲ�����һ��ȫ�֣����Ƿ�����������ר�����ڽ�duiwu�����е����ݸ��ǵ�renwu�����е�
	//��renwu����Ϊ�������ģ�����ֱ�ӵ��ú��޸ģ�Ҳ����ͨ��team�������޸ģ���team������Ը���renwu���飩
	if (gongneng == "���鸲��") {
		for (int i = 0; i < _team.size(); i++) {
			if (_team[i].name == "��") {
				_renwu[0] = _team[i];
			}
			else if (_team[i].name == "˾��") {
				_renwu[1] = _team[i];
			}
		}
		shiJianJieMian(0, "��������");
		zhuangtai("����", ".", ".");
	}
	else if (gongneng == "ȫ��") {
		for (int i = 0; i < _renwu.size(); i++) {
			if (_renwu[i].panduan_duiwu == true) {
				for (int o = 0; o < _team.size(); o++) {
					if (_team[o].name == _renwu[i].name) {
						_team[o] = _renwu[i];
					}
				}
			}
		}
		shiJianJieMian(0, "��������");
		zhuangtai("����", ".", ".");
	}
}

void daoju(string gongneng) {
	while (true) {
		ChongZhi("ȫ��");
		if (gongneng == "����") {
			double zongzhong_dongtai = 0;
			int zongzhong_guding = 0;
			zongzhong_dongtai = zongzhong_dongtai + _renwu[0].sucai_shuzhi * 0.2 + _renwu[0].sucai_muchai * 0.5 + _renwu[0].sucai_gancao * 0.1 + _renwu[0].sucai_shitou * 0.5 +
				_renwu[0].sucai_mogu * 0.1 + _renwu[0].sucai_yecai * 0.2 + _renwu[0].sucai_yegu * 0.1 + _renwu[0].daoju_pingguo * 0.5 +
				_renwu[0].daoju_li * 0.5 + _renwu[0].daoju_suishi * 0.5 + _renwu[0].daoju_shui * 0.5 + _renwu[0].fuka_kongbai * 1 + 
				_renwu[0].fuka_qiluruo_weiding * 1;
			for (int i = 0; i < _team.size(); i ++) {
				zongzhong_guding = zongzhong_guding + _team[i].liLiang_D;
			}
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "�����е���Ʒ:" << endl;
			cout << "�زģ�";
			int zhongji1 = 0;
			if (_renwu[0].sucai_shuzhi > 0) {
				cout << "   01[��֦]��" << _renwu[0].sucai_shuzhi;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].sucai_muchai > 0) {
				cout << "   02[ľ��]��" << _renwu[0].sucai_muchai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].sucai_gancao > 0) {
				cout << "   03[�ɲ�]��" << _renwu[0].sucai_gancao;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].sucai_shitou > 0) {
				cout << "   04[ʯͷ]��" << _renwu[0].sucai_shitou;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].sucai_mogu > 0) {
				cout << "   05[Ģ��]��" << _renwu[0].sucai_mogu;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].sucai_yecai > 0) {
				cout << "   06[Ұ��]��" << _renwu[0].sucai_yecai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].sucai_yegu > 0) {
				cout << "   07[Ұ��]��" << _renwu[0].sucai_yegu;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "����";
			if (_renwu[0].daoju_pingguo > 0) {
				cout << "   11[ƻ��]��" << _renwu[0].daoju_pingguo;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].daoju_li > 0) {
				cout << "   12[��]��" << _renwu[0].daoju_li;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].daoju_suishi > 0) {
				cout << "   13[��ʯ]��" << _renwu[0].daoju_suishi;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].daoju_shui > 0) {
				cout << "   14[ˮ]��" << _renwu[0].daoju_shui;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "����";
			if (_renwu[0].fuka_kongbai > 0) {
				cout << "   21[�հ׷���]��" << _renwu[0].fuka_kongbai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0].fuka_qiluruo_weiding > 0) {
				cout << "   22[(baka��)δ��ģ�����]��" << _renwu[0].fuka_qiluruo_weiding;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "�䷽";
			if (_renwu[0].peifang_yinghuo > 0) {
				cout << "   31[Ӫ��]";
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl;
			char zhongji2;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "1[ʹ��]   2[����]  3[�鿴]  0[����]" << endl;
			cin >> zhongji2;
			if (zhongji2 == '1') {
				int zhongji3 = 0;
				cout << endl;
				color(3);
				cout << "��������ѡ���ߵĶ�Ӧ���֡�" << endl;
				color(7);
				cin >> zhongji3;
				if (zhongji3 == 01) {//�������ж�����Ʒ�Ƿ����ʹ�ã�����֦���������ӻ𣬻��������ض������д������صȣ����������Ϊģ��
					while(true){
						string weiding;
						if (weiding == "���ﻹû�пɵ��õĺ�����������������ǣ���Ϊ��������˴���λ�ã���Ӫ��"){
							for (int i = 0; i < _team.size(); i++) {
								if (_team[i].name == "��") {
									if (_renwu[0].sucai_shuzhi > 0){//��������������ӻ���
								
									}
								}

							}
						}
						else {
							cout << "��������Чѡ���Ӧ�����֡�" << endl;
							_getch();
							continue;
						}
					}
				}
				else if (zhongji3 == 31 and _renwu[0].peifang_yinghuo > 0) {//Ӫ���䷽��
					while (true) {
						ChongZhi("ȫ��");
						char zhongji4;
						cout << endl;
						color(3);
						cout << "�����زģ���[10 * ��֦ + 1 * ��ʯ�������ģ� + 3 * ʯͷ]" << endl;
						cout << "         ��[3 * ľ�� + 1 * ��ʯ�������ģ�+ 3 * ʯͷ]" << endl;
						color(7);
						cout << "��ѡ����Ӧ���䷽��	0[����]" << endl;
						cin >> zhongji4;
						if (zhongji4 == '1') {
							int num_shuzhi = 0;
							int num_suishi = 0;
							int num_shitou = 0;
							int zhongji6 = 0;
							zhongji6 = _renwu[0].sucai_shuzhi;
							while (zhongji6 > 0) {
								zhongji6--;
								num_shuzhi++;
							}
							zhongji6 = _renwu[0].daoju_suishi;
							while (zhongji6 > 0) {
								zhongji6--;
								num_suishi++;
							}
							zhongji6 = _renwu[0].sucai_shitou;
							while (zhongji6 > 0) {
								zhongji6--;
								num_shitou++;
							}
							if (num_shuzhi < 10 or num_suishi < 1 or num_shitou < 3) {
								cout << "���ϲ���Ŷ��" << endl;
								if (num_shuzhi < 10) {
									cout << "��ȱ��֦��" << 10 - num_shuzhi;
								}
								if (num_suishi < 1) {
									cout << "  ��ȱ��ʯ:" << 1 - num_suishi;
								}
								if (num_suishi < 3) {
									cout << "  ��ȱʯͷ:" << 3 - num_shitou;
								}
								_getch();
								continue;
							}
							else if ((zongzhong_dongtai + 5) > zongzhong_guding ) {
								cout << "�����ռ䲻��" << endl;
								cout << "Ӫ������Ϊ5������" << (zongzhong_dongtai + 5) - zongzhong_guding;
								_getch();
							}
						
						}
						else if (zhongji4 == '2') {

						}
						else {
							cout << "��������Чѡ���Ӧ������" << endl;
							_getch();
							continue;
						}
					}
				}
				else {
					cout << "��������Чѡ���Ӧ������" << endl;
					_getch();
				}
			}
			else if (zhongji2 == '0') {
				return;
			}
			else {
				cout << "��������Чѡ���Ӧ������" << endl;
				_getch();
				cout << endl;
			}
		}
		else if (gongneng == "����") {

		}
		else if (gongneng == "�ɼ�") {

		}
		else if (gongneng == "����") {

		}
	}
}


#endif
