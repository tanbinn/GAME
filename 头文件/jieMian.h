
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
					for (int o = 1; o < _renwu[0].zhuangtai.size(); o++) {
						if (_renwu[0].zhuangtai[o] == _renwu[0].zhuangtai[o - 1]) {
							_renwu[0].zhuangtai.erase(_renwu[0].zhuangtai.begin() + o);
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
					for (int o = 1; o < _renwu[1].zhuangtai.size(); o++) {
						if (_renwu[1].zhuangtai[o] == _renwu[1].zhuangtai[o - 1]) {
							_renwu[1].zhuangtai.erase(_renwu[1].zhuangtai.begin() + o);
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
			for (int i = 0; i < _team.size(); i++) {
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
					while (true) {
						string weiding;
						if (weiding == "���ﻹû�пɵ��õĺ�����������������ǣ���Ϊ��������˴���λ�ã���Ӫ��") {
							for (int i = 0; i < _team.size(); i++) {
								if (_team[i].name == "��") {
									if (_renwu[0].sucai_shuzhi > 0) {//��������������ӻ���

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
							else if ((zongzhong_dongtai + 5) > zongzhong_guding) {
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




void zhandoujiemian(string leixing,string diren) {
	if (nandu == "��ͨ") {
		if (leixing == "��Ļս") {

			vector <zhandoushuju> fightarrey;

			int totalblood_zheng = 0;
			int totalblood_fu = 0;
			int xingdongzhi_zheng_G = 0; int xingdongzhi_zheng_D = 0;
			int xingdongzhi_fu_G = 0; int xingdongzhi_fu_D = 0;
			int powerzhi_zheng_G = 0;int powerzhi_zheng_D = 0;
			int powerzhi_fu_G = 0;int powerzhi_fu_D = 0;

			if (diren == "������NPC") {

				int danmu[1][3][9][7];

				for (short q = 0; q < 1; q++) {
					for (short p = 0; p < 3; p++) {
						for (short i = 0; i < 8; i++) {
							for (short o = 0; o < 7; o++) {
								danmu[q][p][i][o] = 0;
							}
						}
					}
				}
				
				//����ϵ��ע��
				danmu[0][0][0][0] = 0;//danmu_zheng_zijiju_daodan_wushuxing
				danmu[0][0][0][1] = 0;//danmu_zheng_zijiju_daodan_huo
				danmu[0][0][0][2] = 0;//danmu_zheng_zijiju_daodan_shui
				danmu[0][0][0][3] = 0;//danmu_zheng_zijiju_daodan_jin
				danmu[0][0][0][4] = 0;//danmu_zheng_zijiju_dandao_mu
				danmu[0][0][0][5] = 0;//danmu_zheng_zijiju_daodan_tu
				danmu[0][0][0][6] = 0;//danmu_zheng_zijiju_daodan_ri
				danmu[0][0][0][7] = 0;//danmu_zheng_zijiju_daodan_yue
				
				//��Ļ��ʽע��
				danmu[0][0][0][1] = 0;//danmu_zheng_zijiju_daodan
				danmu[0][0][1][1] = 0;//danmu_zheng_zijiju_dayu
				danmu[0][0][2][1] = 0;//danmu_zheng_zijiju_diedan
				danmu[0][0][3][1] = 0;//danmu_zheng_zijiju_jiandan
				danmu[0][0][4][1] = 0;//danmu_zheng_zijiju_jiguangdan
				danmu[0][0][5][1] = 0;//danmu_zheng_zijiju_xiaomidan
				danmu[0][0][6][1] = 0;//danmu_zheng_zijiju_xiaoyu
				danmu[0][0][7][1] = 0;//danmu_zheng_zijiju_zhadan
				danmu[0][0][8][1] = 0;//danmu_zheng_zijiju_zhongyu
				danmu[0][0][9][1] = 0;//danmu_zheng_zijiju_lindan

				//��Ļ����ע��
				danmu[0][0][0][2] = 0;//danmu_zheng_zijiju
				danmu[0][1][0][2] = 0;//danmu_zheng_pianxiangju
				danmu[0][2][0][2] = 0;//danmu_zheng_suijidan
				danmu[0][3][0][2] = 0;//danmu_zheng_xianweidan

				//����ע��
				danmu[0][0][0][3] = 0;//danmu_zheng
				danmu[1][0][0][3] = 0;//danmu_fu

				for (int i = 0; i < _team.size(); i++) {
					totalblood_zheng = totalblood_zheng + _team[i].tiLi_D;
					powerzhi_zheng_G = powerzhi_zheng_G + _team[i].zhiLi_D;
					xingdongzhi_zheng_G = xingdongzhi_zheng_G + _team[i].suDu_D;
				}
				struct _renwushuju NPC_1 = {"NPC_1", 0,1000,1000,1000,1000,0,20,20,10,10,10,10,10,10,5,5,10,10,100,100,50,50,0,"���ӵ�","ɽ��","���","���",3};
				struct _renwushuju NPC_2 = {"NPC_2", 0,1000,1000,1000,1000,0,20,20,10,10,10,10,10,10,5,5,10,10,100,100,50,50,0,"���ӵ�","ɽ��","���","���",3};
				vector <_renwushuju> team_fu;
				team_fu.push_back(NPC_1);
				team_fu.push_back(NPC_2);
				for (int i = 0; i < team_fu.size(); i++) {
					totalblood_fu = totalblood_fu + team_fu[i].tiLi_D;
					powerzhi_fu_G = powerzhi_fu_G + team_fu[i].zhiLi_D;
					xingdongzhi_fu_G = xingdongzhi_fu_G + team_fu[i].suDu_D;
				}
				while (totalblood_zheng >= 0 or totalblood_fu >= 0) {
					ChongZhi("ȫ��");
					xingdongzhi_zheng_D = xingdongzhi_zheng_G;
					xingdongzhi_fu_D = xingdongzhi_fu_G;
					cout << "========================================================================================================================" << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					for (int i = 0; i < _team.size(); i++) {
						color(12);
						cout << _team[i].name << ":" << endl;
						color(7);
						cout << "��������" << _team[i].tiLi_D << "/" << _team[i].tiLi_G << "��";
						for (int o = 0; o < _team[i].zhuangtai.size(); o++) {
							cout << _team[i].zhuangtai[o] << " ";
						}
						cout << endl;
					}
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					for (int i = 0; i < team_fu.size(); i++) {//��ʱ��״̬���ú����а�����Ķ������ǵõ�ʱ�����޸��Ǹ�������ʱ��������Ҳ��һ�¡�
						team_fu[i].zhuangtai.clear();
					}
					for (int i = 0; i < team_fu.size(); i++) {//˵���˾�����������ָ�루��
						if (team_fu[i].baoShiDu_D <= 50 && team_fu[i].baoShiDu_D > 20) {
							team_fu[i].zhuangtai.push_back("<�Զ�>");
						}
						if (team_fu[i].baoShiDu_D <= 20 && team_fu[i].baoShiDu_D > 0) {
							team_fu[i].zhuangtai.push_back("<����>");
						}
						if (team_fu[i].baoShiDu_D == 0) {
							team_fu[i].zhuangtai.push_back("<������>");
						}
						if (team_fu[i].jingLi_D >= (0.8 * team_fu[i].jingLi_G) && team_fu[i].tiLi_D >= (0.8 * team_fu[i].tiLi_G)) {
							team_fu[i].zhuangtai.push_back("<������>");
						}
						if (team_fu[i].jingLi_D < (0.1 * team_fu[i].jingLi_G)) {
							team_fu[i].zhuangtai.push_back("<����>");
						}
						if (team_fu[i].tiLi_D < (0.5 * team_fu[i].tiLi_G) && team_fu[i].tiLi_D >= (0.2 * team_fu[i].tiLi_G)) {
							team_fu[i].zhuangtai.push_back("<����>");
						}
						if (team_fu[i].wenDu >= 75 && team_fu[i].wenDu < 100) {
							team_fu[i].zhuangtai.push_back("<����>");
						}
						if (team_fu[i].wenDu == 100) {
							team_fu[i].zhuangtai.push_back("<����>");
						}
						if (team_fu[i].wenDu == 0) {
							team_fu[i].zhuangtai.push_back("<����>");
						}
						if (team_fu[i].wenDu > 0 && team_fu[i].wenDu <= 25) {
							team_fu[i].zhuangtai.push_back("<����>");
						}
						sort(team_fu[i].zhuangtai.begin(), team_fu[i].zhuangtai.end());
						for (int o = 1; o < team_fu[i].zhuangtai.size(); o++) {
							if (team_fu[i].zhuangtai[o] == team_fu[i].zhuangtai[o - 1]) {
								team_fu[i].zhuangtai.erase(team_fu[i].zhuangtai.begin() + i);
							}
						}
						team_fu[i].zhuangtai_num = team_fu[i].zhuangtai.size();
					}
					for (int i = 0; i < team_fu.size(); i++) {
						color(12);
						cout << team_fu[i].name << ":" << endl;
						color(7);
						cout << "��������" << team_fu[i].tiLi_D << "/" << team_fu[i].tiLi_G << "��";
						for (int o = 0; o < team_fu[i].zhuangtai.size(); o++) {
							cout << team_fu[i].zhuangtai[o] << " ";
						}
						cout << endl;
					}
					for (short q = 0; q < 1; q++) {
						if (q == 0) {
							cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
							color(12); cout << "�ҷ�:" << endl; color(7);
						}
						else if (q == 1) {
							cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
							color(12); cout << "�Է�:" << endl; color(7);

						}
						for (short p = 0; p < 3; p++) {
							if (p == 0) {
								cout << "  �Ի��ѣ�";
							}
							else if (p == 1) {
								cout << "  ƫ��ѣ�";
							}
							else if (p == 2) {
								cout << "  �����:";
							}
							else if (p == 3) {
								cout << "  ��λ��:";
							}
							for (short i = 0; i < 8; i++) {
								for (short o = 0; o < 7; o++) {
									if (danmu[q][p][i][o] > 0 and i == 0) {
										cout << "  ����";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
									}
									if (danmu[q][p][i][o] > 0 and i == 1) {
										cout << "  ����";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
									}
									if (danmu[q][p][i][o] > 0 and i == 2) {
										cout << "  ����";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}


									}
									if (danmu[q][p][i][o] > 0 and i == 3) {
										cout << "  ����";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}

									}
									if (danmu[q][p][i][o] > 0 and i == 4) {
										cout << "  ���ⵯ";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}

									}
									if (danmu[q][p][i][o] > 0 and i == 5) {
										cout << "  С�׵�";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}

									}
									if (danmu[q][p][i][o] > 0 and i == 6) {
										cout << "  С��";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}

									}
									if (danmu[q][p][i][o] > 0 and i == 7) {
										cout << "  ����";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}

									}
									if (danmu[q][p][i][o] > 0 and i == 8) {
										cout << "  ����";
										if (o == 0) {
											cout << "��" << danmu[q][p][i][o];
										}
										else if (o == 1) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 2) {
											cout << "(ˮ����)��" << danmu[q][p][i][o];
										}
										else if (o == 3) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 4) {
											cout << "(ľ����)��" << danmu[q][p][i][o];
										}
										else if (o == 5) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 6) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
										else if (o == 7) {
											cout << "(������)��" << danmu[q][p][i][o];
										}
									}
								}
							}
							cout << endl;
						}
						cout << endl;
					}
					cout << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "����ѡ�����������������Ĺ���ѡ�" << endl;
					for (int i = 0; i < _team.size(); i++) {
						cout << i + 1 << "[" << _team[i].name << "]  ";
					}
					for (int i = 0; i < team_fu.size(); i++) {
						cout << _team.size() + i + 1 << "[" << team_fu[i].name << "]  ";
					}
					cout << _team.size() + team_fu.size() + 1 << "[����]��δ������";
					cout << endl << endl;
					short zhongji1_short; cin >> zhongji1_short;
					if (zhongji1_short > 0 and zhongji1_short <= _team.size()) {
						string zhongji2_string;
						while (true) {
							cout << "��ѡ�����" << _team[zhongji1_short - 1].name << endl;
							cout << "1[����]  2[�ƶ�]  3[�ڻ�]  4[����]  5[�鿴]  0[����]" << endl;
							cin >> zhongji2_string;
							if (_team[zhongji1_short - 1].name == "��") {
								if (zhongji2_string == "1") {//����
									bool danmuleixing_bool[4] = { 0,0,0,0 };
									for (int i = 0; i < _team[zhongji1_short - 1].jineng.gongji.size(); i++) {
										switch (_team[zhongji1_short - 1].jineng.gongji[i].leixing) {
										case 0:
											danmuleixing_bool[0] = true;
											break;
										case 1:
											danmuleixing_bool[1] = true;
											break;
										case 2:
											danmuleixing_bool[2] = true;
											break;
										case 3:
											danmuleixing_bool[3] = true;
											break;
										default:
											//�����ܵ�����~
											break;
										}
									}
									vector <short> danmuleixing_xuanze;
									for (int i = 0; i < 3; i++) {
										if (danmuleixing_bool[i] == true) {
											if (i == 0) {
												danmuleixing_xuanze.push_back(0);
											}
											else if (i == 1) {
												danmuleixing_xuanze.push_back(1);
											}
											else if (i == 2) {
												danmuleixing_xuanze.push_back(2);
											}
											else if (i == 3) {
												danmuleixing_xuanze.push_back(3);
											}
										}
									}
									int zhongji3_int;
									short zhongji4_short;
									while (true) {
										short a = 1;
										for (int i = 0; i < danmuleixing_xuanze.size(); i++) {
											switch(danmuleixing_xuanze[i]) {
												case 0:
													cout << a << "[�Ի���]  ";
													break;
												case 1:
													cout << a << "[ƫ���]  ";
													break;
												case 2:
													cout << a << "[�����]  ";
													break;
												case 3:
													cout << a << "[��λ��]  ";
													break;
											}
											a++;
										}
										cout << "1[�����]  2[�Ի���]  3[ƫ���]  0[����]" << endl;
										cin >> zhongji2_string;
										if (zhongji2_string == "0") {
											break;
										}
										else if (zhongji2_string == "1") {
											zhandoushuju zhongji0;
											zhongji0.leixing = "����";
											zhongji0.name = "�����";
											zhongji0.S.push_back(_team[zhongji1_short - 1].name);
											zhongji0.left = 1;
											cout << "��ѡ��Ļ��ʽ��" << endl;
											cout << "1[����]  2[С��]  3[����]" << endl;
											cin >> zhongji2_string;
											if (zhongji2_string == "1") {
												cout << "�����뵯Ļ����(ÿ5öһ��powerֵ����������ȥ�������ֵ)��		��ǰʣ��powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 5;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[2][0][0] = zhongji3_int * 5;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
											else if (zhongji2_string == "2") {
												cout << "�����뵯Ļ������ÿ4öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 4;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[2][6][0] = zhongji3_int * 4;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
											else if (zhongji2_string == "3") {
												cout << "�����뵯Ļ������ÿ3öһ��powerֵ����������ȥ�������ֵ����";
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 3;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[2][8][0] = zhongji3_int * 3;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
										}
										else if (zhongji2_string == "2") {
											zhandoushuju zhongji0;
											zhongji0.leixing = "����";
											zhongji0.name = "�Ի���";
											zhongji0.S.push_back(_team[zhongji1_short - 1].name);
											zhongji0.left = 1;
											if (team_fu.size() > 1) {
												cout << "��ѡ�������Ķ���";
												for (int i = 0; i < team_fu.size(); i++) {
													cout << "  " << i + 1 << "[" << team_fu[i].name << "]";
												}
												cout << "  0[����]" << endl;
												cin >> zhongji4_short;
												if (zhongji4_short <= team_fu.size() and zhongji4_short >= 1) {
													zhongji0.M.push_back(team_fu[zhongji4_short - 1].name);
												}
												else if (zhongji4_short == 0) {
													continue;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
											else {
												zhongji0.M.push_back(team_fu[0].name);
											}
											cout << "��ѡ��Ļ��ʽ��" << endl;
											cout << "1[����]  2[С��]  3[����]  4[���ⵯ]" << endl;
											cin >> zhongji2_string;
											if (zhongji2_string == "1") {
												cout << "�����뵯Ļ����(ÿ5öһ��powerֵ����������ȥ�������ֵ)��		��ǰʣ��powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 5;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[0][0][0] = zhongji3_int * 5;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
											else if (zhongji2_string == "2") {
												cout << "�����뵯Ļ������ÿ4öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 4;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[0][6][0] = zhongji3_int * 4;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
											else if (zhongji2_string == "3") {
												cout << "�����뵯Ļ������ÿ3öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 3;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[0][8][0] = zhongji3_int * 3;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
											else if (zhongji2_string == "4") {
												cout << "�����뵯Ļ������ÿ2öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 2;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[0][4][0] = zhongji3_int * 2;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
										}
										else if (zhongji2_string == "3") {
											zhandoushuju zhongji0;
											zhongji0.leixing = "����";
											zhongji0.name = "ƫ���";
											zhongji0.S.push_back(_team[zhongji1_short - 1].name);
											zhongji0.left = 1;
											if (team_fu.size() > 1) {
												cout << "��ѡ�������Ķ���";
												for (int i = 0; i < team_fu.size(); i++) {
													cout << "  " << i + 1 << "[" << team_fu[i].name << "]";
												}
												cout << "  0[����]" << endl;
												cin >> zhongji4_short;
												if (zhongji4_short <= team_fu.size() and zhongji4_short >= 1) {
													zhongji0.M.push_back(team_fu[zhongji4_short - 1].name);
												}
												else if (zhongji4_short == 0) {
													continue;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
											else {
												zhongji0.M.push_back(team_fu[0].name);
											}
											cout << "��ѡ��Ļ��ʽ��" << endl;
											cout << "1[����]  2[�۵�]  3[С�׵�]" << endl;
											cin >> zhongji2_string;
											if (zhongji2_string == "1") {
												cout << "�����뵯Ļ����(ÿ5öһ��powerֵ����������ȥ�������ֵ)��		��ǰʣ��powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 5;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[1][0][0] = zhongji3_int * 5;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}

											}
											else if (zhongji2_string == "2") {
												cout << "�����뵯Ļ������ÿ5öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 5;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[1][9][0] = zhongji3_int * 5;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}

											}
											else if (zhongji2_string == "3") {
												cout << "�����뵯Ļ������ÿ8öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 8;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[1][5][0] = zhongji3_int * 8;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}

											}
										}
									}
								}
								else if (zhongji2_string == "2") {//�ƶ�
									while (true) {
										cout << "��ѡ�����" << _team[zhongji1_short - 1].name << endl;
										cout << "1[΢��]  2[�з��ƶ�]  3[���ٴ���]  0[����]" << endl;
										cin >> zhongji2_string;
										if (zhongji2_string == "0") {
											break;
										}
										else if (zhongji2_string == "1") {
											zhandoushuju zhongji0;
											zhongji0.leixing = "�ƶ�";
											zhongji0.name = "΢��";
											zhongji0.left = 1;
											zhongji0.S.push_back(_team[zhongji1_short - 1].name);
											cout << "�������ƶ�ǿ�ȣ�3���ж�ֵΪһ�Σ���		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
											short zhongji3_short;
											cin >> zhongji3_short;
											if (zhongji3_short == 0) {
												break;
											}
											if (xingdongzhi_zheng_D >= zhongji3_short * 3 and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
												xingdongzhi_zheng_D = xingdongzhi_zheng_D - zhongji3_short * 3;
												zhongji0.danmu[0][0][0] = zhongji3_short;
												fightarrey.push_back(zhongji0);
												_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
												break;
											}
											else if (xingdongzhi_zheng_D < zhongji3_short * 3) {
												cout << "�ж�ֵ���㡣" << endl;
												_getch();
												continue;
											}
											else {
												cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
												for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
													cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
												}
												cout << "	0[����]" << endl;
												short zhongji4_short;
												cin >> zhongji4_short;
												if (zhongji4_short == 0) {
													break;
												}
												else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
													_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
													fightarrey.push_back(zhongji0);
													break;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
										}
										else if (zhongji2_string == "2") {
											zhandoushuju zhongji0;
											zhongji0.leixing = "����";
											zhongji0.name = "�з��ƶ�";
											zhongji0.left = 1;
											zhongji0.S.push_back(_team[zhongji1_short - 1].name);
											cout << "�������ƶ�ǿ�ȣ�5���ж�ֵΪһ�Σ���		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
											short zhongji3_short;
											cin >> zhongji3_short;
											if (zhongji3_short == 0) {
												break;
											}
											if (xingdongzhi_zheng_D >= zhongji3_short * 5 and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
												xingdongzhi_zheng_D = xingdongzhi_zheng_D - zhongji3_short * 5;
												zhongji0.danmu[0][0][0] = zhongji3_short;
												fightarrey.push_back(zhongji0);
												_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
												break;
											}
											else if (xingdongzhi_zheng_D < zhongji3_short * 5) {
												cout << "�ж�ֵ���㡣" << endl;
												_getch();
												continue;
											}
											else {
												cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
												for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
													cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
												}
												cout << "	0[����]" << endl;
												short zhongji4_short;
												cin >> zhongji4_short;
												if (zhongji4_short == 0) {
													break;
												}
												else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
													_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
													fightarrey.push_back(zhongji0);
													break;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
										}
										else if (zhongji2_string == "3") {
											zhandoushuju zhongji0;
											zhongji0.leixing = "����";
											zhongji0.name = "���ٴ���";
											zhongji0.left = 1;
											zhongji0.S.push_back(_team[zhongji1_short - 1].name);
											cout << "�������ƶ�ǿ�ȣ�7���ж�ֵΪһ�Σ���		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
											short zhongji3_short;
											cin >> zhongji3_short;
											if (zhongji3_short == 0) {
												break;
											}
											if (xingdongzhi_zheng_D >= zhongji3_short * 7 and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
												xingdongzhi_zheng_D = xingdongzhi_zheng_D - zhongji3_short * 7;
												zhongji0.danmu[0][0][0] = zhongji3_short;
												fightarrey.push_back(zhongji0);
												_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
												break;
											}
											else if (xingdongzhi_zheng_D < zhongji3_short * 7) {
												cout << "�ж�ֵ���㡣" << endl;
												_getch();
												continue;
											}
											else {
												cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
												for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
													cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
												}
												cout << "	0[����]" << endl;
												short zhongji4_short;
												cin >> zhongji4_short;
												if (zhongji4_short == 0) {
													break;
												}
												else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
													_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
													fightarrey.push_back(zhongji0);
													break;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
										}
									}
								}
								else if (zhongji2_string == "3") {
									while (true) {
										cout << "��ѡ�����" << _team[zhongji1_short - 1].name << endl;
										cout << "1[����]  2[��Ļ����]  3[��Ļ����]  4[��Ļ��λ]  0[����]" << endl;
										cin >> zhongji2_string;
										int zhongji3_int;
										if (zhongji2_string == "0") {
											break;
										}
										else if (zhongji2_string == "1") {
											zhandoushuju zhongji0;
											zhongji0.leixing = "�ڻ�";
											zhongji0.name = "����";
											zhongji0.left = 1;
											zhongji0.S.push_back(_team[zhongji1_short - 1].name);
											short zhongji4_short;
											if (_team.size() > 1) {
												cout << "��ѡ���ڻ��Ķ��󣺶Լ�����3���ж�ֵ����������5���ж�ֵ��		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
												for (int i = 0; i < _team.size(); i++) {
													cout << "  " << i + 1 << "[" << _team[i].name << "]";
												}
												cout << "  0[����]" << endl;
												cin >> zhongji4_short;
												if (zhongji4_short <= _team.size() and zhongji4_short >= 1) {
													zhongji0.M.push_back(_team[zhongji4_short - 1].name);
													if (_team[zhongji4_short - 1].name == _team[zhongji1_short - 1].name) {
														if (xingdongzhi_zheng_D < 5) {
															cout << "�ж�ֵ���㡣" << endl;
															_getch();
															continue;
														}
														else if(_team[zhongji1_short - 1].xingdongcao.size() >= _team[zhongji1_short - 1].xingdongcao_num){
															cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
															for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
																cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
															}
															cout << "	0[����]" << endl;
															short zhongji4_short;
															cin >> zhongji4_short;
															if (zhongji4_short == 0) {
																break;
															}
															else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
																_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
																fightarrey.push_back(zhongji0);
																break;
															}
															else {
																cout << "��������Чѡ���Ӧ�����֡�" << endl;
																_getch();
																continue;
															}
														}
														else {
															xingdongzhi_zheng_D = xingdongzhi_zheng_D - 5;
															fightarrey.push_back(zhongji0);
															_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
															break;
														}
													}
													else {
														if (xingdongzhi_zheng_D < 3) {
															cout << "�ж�ֵ���㡣" << endl;
															_getch();
															continue;
														}
														else if (_team[zhongji1_short - 1].xingdongcao.size() >= _team[zhongji1_short - 1].xingdongcao_num) {
															cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
															for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
																cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
															}
															cout << "	0[����]" << endl;
															short zhongji4_short;
															cin >> zhongji4_short;
															if (zhongji4_short == 0) {
																break;
															}
															else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
																_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
																fightarrey.push_back(zhongji0);
																break;
															}
															else {
																cout << "��������Чѡ���Ӧ�����֡�" << endl;
																_getch();
																continue;
															}
														}
														else {
															xingdongzhi_zheng_D = xingdongzhi_zheng_D - 3;
															fightarrey.push_back(zhongji0);
															_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
															break;
														}
													}
												}
												else if (zhongji4_short == 0) {
													continue;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
											else {
												cout << "��ѡ���Լ���������3���ж�ֵ���Ƿ�ȷ�ϣ�		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
												cout << "0[����]  �������ֽ�Ϊȷ�ϡ�" << endl;
												cin >> zhongji4_short;
												if (zhongji4_short != 0) {
													zhongji0.M.push_back(_team[0].name);
													if (_team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num and xingdongzhi_zheng_D >= 3) {
														xingdongzhi_zheng_D = xingdongzhi_zheng_D - 3;
														fightarrey.push_back(zhongji0);
														_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
														break;
													}
													else if (xingdongzhi_zheng_D < 3) {
														cout << "�ж�ֵ���㡣" << endl;
														_getch();
														continue;
													}
													else {
														cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
														for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
															cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
														}
														cout << "	0[����]" << endl;
														short zhongji4_short;
														cin >> zhongji4_short;
														if (zhongji4_short == 0) {
															break;
														}
														else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
															_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
															fightarrey.push_back(zhongji0);
															break;
														}
														else {
															cout << "��������Чѡ���Ӧ�����֡�" << endl;
															_getch();
															continue;
														}
													}
												}
												else {
													continue;
												}
											}
											cout << "�Ƿ�ȷ�ϣ��������ж�ֵ��5��		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
											cout << "0[����]  �����������ֽ�Ϊȷ�ϡ�" << endl;
											string zhongji3_string;
											if (zhongji3_string == "0") {
												break;
											}
											if (_team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
												fightarrey.push_back(zhongji0);
												_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
												break;
											}
											else {
												cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
												for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
													cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
												}
												cout << "	0[����]" << endl;
												short zhongji4_short;
												cin >> zhongji4_short;
												if (zhongji4_short == 0) {
													break;
												}
												else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
													_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
													fightarrey.push_back(zhongji0);
													break;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
										}
										else if (zhongji2_string == "2") {//д����λ��
											zhandoushuju zhongji0;
											zhongji0.leixing = "�ڻ�";
											zhongji0.name = "��Ļ����";
											zhongji0.left = 1;
											zhongji0.S.push_back(_team[zhongji1_short - 1].name);
											short zhongji4_short;
											if (_team.size() > 1) {
												cout << "��ѡ���ڻ��Ķ��󣺶Լ�����3���ж�ֵ����������5���ж�ֵ��		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
												for (int i = 0; i < _team.size(); i++) {
													cout << "  " << i + 1 << "[" << _team[i].name << "]";
												}
												cout << "  0[����]" << endl;
												cin >> zhongji4_short;
												if (zhongji4_short <= _team.size() and zhongji4_short >= 1) {
													zhongji0.M.push_back(_team[zhongji4_short - 1].name);
													if (_team[zhongji4_short - 1].name == _team[zhongji1_short - 1].name) {
														if (xingdongzhi_zheng_D < 5) {
															cout << "�ж�ֵ���㡣" << endl;
															_getch();
															continue;
														}
														else if (_team[zhongji1_short - 1].xingdongcao.size() >= _team[zhongji1_short - 1].xingdongcao_num) {
															cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
															for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
																cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
															}
															cout << "	0[����]" << endl;
															short zhongji4_short;
															cin >> zhongji4_short;
															if (zhongji4_short == 0) {
																break;
															}
															else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
																_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
																fightarrey.push_back(zhongji0);
																break;
															}
															else {
																cout << "��������Чѡ���Ӧ�����֡�" << endl;
																_getch();
																continue;
															}
														}
														else {
															xingdongzhi_zheng_D = xingdongzhi_zheng_D - 5;
															fightarrey.push_back(zhongji0);
															_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
														}
													}
													else {
														if (xingdongzhi_zheng_D < 3) {
															cout << "�ж�ֵ���㡣" << endl;
															_getch();
															continue;
														}
														else if (_team[zhongji1_short - 1].xingdongcao.size() >= _team[zhongji1_short - 1].xingdongcao_num) {
															cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
															for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
																cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
															}
															cout << "	0[����]" << endl;
															short zhongji4_short;
															cin >> zhongji4_short;
															if (zhongji4_short == 0) {
																break;
															}
															else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
																_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
																fightarrey.push_back(zhongji0);
																break;
															}
															else {
																cout << "��������Чѡ���Ӧ�����֡�" << endl;
																_getch();
																continue;
															}
														}
														else {
															xingdongzhi_zheng_D = xingdongzhi_zheng_D - 3;
															fightarrey.push_back(zhongji0);
															_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
														}
													}
												}
												else if (zhongji4_short == 0) {
													continue;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
											else {
												cout << "��ѡ���Լ���������3���ж�ֵ���Ƿ�ȷ�ϣ�		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
												cout << "0[����]  �������ֽ�Ϊȷ�ϡ�" << endl;
												cin >> zhongji4_short;
												if (zhongji4_short != 0) {
													zhongji0.M.push_back(_team[0].name);
													if (_team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num and xingdongzhi_zheng_D >= 3) {
														xingdongzhi_zheng_D = xingdongzhi_zheng_D - 3;
														fightarrey.push_back(zhongji0);
														_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
														break;
													}
													else if (xingdongzhi_zheng_D < 3) {
														cout << "�ж�ֵ���㡣" << endl;
														_getch();
														continue;
													}
													else {
														cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
														for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
															cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
														}
														cout << "	0[����]" << endl;
														short zhongji4_short;
														cin >> zhongji4_short;
														if (zhongji4_short == 0) {
															break;
														}
														else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
															_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
															fightarrey.push_back(zhongji0);
															break;
														}
														else {
															cout << "��������Чѡ���Ӧ�����֡�" << endl;
															_getch();
															continue;
														}
													}
												}
												else {
													continue;
												}
											}
											cout << "�Ƿ�ȷ�ϣ��������ж�ֵ��5��		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
											cout << "0[����]  �����������ֽ�Ϊȷ�ϡ�" << endl;
											string zhongji3_string;
											if (zhongji3_string == "0") {
												break;
											}
											if (_team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
												fightarrey.push_back(zhongji0);
												_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
												break;
											}
											else {
												cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
												for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
													cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
												}
												cout << "	0[����]" << endl;
												short zhongji4_short;
												cin >> zhongji4_short;
												if (zhongji4_short == 0) {
													break;
												}
												else if (zhongji4_short >= 1 and zhongji4_short <= _team[zhongji1_short - 1].xingdongcao_num) {
													_team[zhongji1_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
													fightarrey.push_back(zhongji0);
													break;
												}
												else {
													cout << "��������Чѡ���Ӧ�����֡�" << endl;
													_getch();
													continue;
												}
											}
											cout << "��ѡ��Ļ��ʽ��" << endl;
											cout << "1[С��]  2[С�׵�]  3[���ⵯ]" << endl;
											cin >> zhongji2_string;
											if (zhongji2_string == "1") {
												cout << "�����뵯Ļ������ÿ2öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 4;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[0][6][0] = zhongji3_int * 4;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
											else if (zhongji2_string == "2") {
												cout << "�����뵯Ļ������ÿ3öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 3;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[0][8][0] = zhongji3_int * 3;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
											else if (zhongji2_string == "3") {
												cout << "�����뵯Ļ������ÿ2öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
												cin >> zhongji3_int;
												if (zhongji3_int == 0) {
													break;
												}
												zhongji3_int = zhongji3_int / 2;
												if (powerzhi_zheng_D >= zhongji3_int and _team[zhongji1_short - 1].xingdongcao.size() < _team[zhongji1_short - 1].xingdongcao_num) {
													powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
													zhongji0.danmu[0][4][0] = zhongji3_int * 2;
													fightarrey.push_back(zhongji0);
													_team[zhongji1_short - 1].xingdongcao.push_back(zhongji0);
													break;
												}
												else if (powerzhi_zheng_D < zhongji3_int) {
													cout << "powerֵ���㡣" << endl;
													_getch();
													continue;
												}
												else {
													cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
													for (int i = 0; i < _team[zhongji1_short - 1].xingdongcao_num; i++) {
														cout << "	" << i + 1 << "[" << _team[zhongji1_short - 1].xingdongcao[i].name << "]";
													}
													cout << "	0[����]" << endl;
													short zhongji5_short;
													cin >> zhongji5_short;
													if (zhongji5_short == 0) {
														break;
													}
													else if (zhongji5_short >= 1 and zhongji5_short <= _team[zhongji1_short - 1].xingdongcao_num) {
														_team[zhongji1_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
														fightarrey.push_back(zhongji0);
														break;
													}
													else {
														cout << "��������Чѡ���Ӧ�����֡�" << endl;
														_getch();
														continue;
													}
												}
											}
										}
									}
								}
								else if (zhongji2_string == "0") {
									break;
								}
								else {
									cout << "��������Чѡ���Ӧ�����֡�" << endl;
									_getch();
									continue;
								}
							}
							_getch();//��ʱ�ϵ�
						}
					}
					_getch();//��ʱ�ϵ�
				}
			}
		}
	}
}


#endif


