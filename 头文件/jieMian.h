#ifndef _JIEMIAN_H_
#define _JIEMIAN_H_
#include"juBen.h"

//�����������ȶ����ʼλ�ã�������λ�ƿ���ͨ����ͼ�ļ����Կ� 

void zhuangtai(string gongneng, string name, string zhuangtai) {//��״̬�ϣ���������ﵥ������һ�����У����ַ�������ʽ���ڴ洢��Ȼ����ú�����������ʱ���ֱ�ָ��������ܡ� ����״̬�������������ѡ���Ƿ���ţ� 
	if (gongneng == "���") {
		if (name == "��") {
			for (int i = 0; i < _renwu[0]->zhuangtai.size(); i++) {
				cout << _renwu[0]->zhuangtai[i] << " ";
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
			_renwu[i]->zhuangtai.clear();
		}
		for (int i = 0; i < _renwu.size(); i++) {//���ˣ����Ƿֲ�ͬ�����������ú��ˣ��Դ�λ��Ϊ��Ԫ��
			if (_renwu[i]->daweizhi == _renwu[0]->daweizhi) {
				if (_renwu[i]->name == "��") {
					if (_renwu[0]->baoShiDu_D <= 50 && _renwu[0]->baoShiDu_D > 20) {
						_renwu[0]->zhuangtai.push_back("<�Զ�>");
					}
					if (_renwu[0]->baoShiDu_D <= 20 && _renwu[0]->baoShiDu_D > 0) {
						_renwu[0]->zhuangtai.push_back("<����>");
					}
					if (_renwu[0]->baoShiDu_D == 0) {
						_renwu[0]->zhuangtai.push_back("<������>");
					}
					if (_renwu[0]->jingLi_D >= (0.8 * _renwu[0]->jingLi_G) && _renwu[0]->tiLi_D >= (0.8 * _renwu[0]->tiLi_G)) {
						_renwu[0]->zhuangtai.push_back("<������>");
					}
					if (_renwu[0]->jingLi_D < (0.1 * _renwu[0]->jingLi_G)) {
						_renwu[0]->zhuangtai.push_back("<����>");
					}
					if (_renwu[0]->tiLi_D < (0.5 * _renwu[0]->tiLi_G) && _renwu[0]->tiLi_D >= (0.2 * _renwu[0]->tiLi_G)) {
						_renwu[0]->zhuangtai.push_back("<����>");
					}
					if (_renwu[0]->wenDu >= 75 && _renwu[0]->wenDu < 100) {
						_renwu[0]->zhuangtai.push_back("<����>");
					}
					if (_renwu[0]->wenDu == 100) {
						_renwu[0]->zhuangtai.push_back("<����>");
					}
					if (_renwu[0]->wenDu == 0) {
						_renwu[0]->zhuangtai.push_back("<����>");
					}
					if (_renwu[0]->wenDu > 0 && _renwu[0]->wenDu <= 25) {
						_renwu[0]->zhuangtai.push_back("<����>");
					}
					sort(_renwu[0]->zhuangtai.begin(), _renwu[0]->zhuangtai.end());
					for (int o = 1; o < _renwu[0]->zhuangtai.size(); o++) {
						if (_renwu[0]->zhuangtai[o] == _renwu[0]->zhuangtai[o - 1]) {
							_renwu[0]->zhuangtai.erase(_renwu[0]->zhuangtai.begin() + o);
						}
					}
					_renwu[0]->zhuangtai_num = _renwu[0]->zhuangtai.size();
				}
				if (_renwu[i]->name == "˾��") {
					if (_renwu[1]->baoShiDu_D <= 50 && _renwu[1]->baoShiDu_D > 20) {
						_renwu[1]->zhuangtai.push_back("<�Զ�>");
					}
					if (_renwu[1]->baoShiDu_D <= 20 && _renwu[1]->baoShiDu_D > 0) {
						_renwu[1]->zhuangtai.push_back("<����>");
					}
					if (_renwu[1]->baoShiDu_D == 0) {
						_renwu[1]->zhuangtai.push_back("<������>");
					}
					if (_renwu[1]->jingLi_D >= (0.8 * _renwu[1]->jingLi_G) && _renwu[1]->tiLi_D >= (0.8 * _renwu[1]->tiLi_G)) {
						_renwu[1]->zhuangtai.push_back("<������>");
					}
					if (_renwu[1]->jingLi_D < (0.1 * _renwu[1]->jingLi_D)) {
						_renwu[1]->zhuangtai.push_back("<����>");
					}
					if (_renwu[1]->tiLi_D < (0.5 * _renwu[1]->tiLi_G) && _renwu[1]->tiLi_D >= (0.2 * _renwu[1]->tiLi_G)) {
						_renwu[1]->zhuangtai.push_back("<����>");
					}
					if (_renwu[1]->wenDu >= 75 && _renwu[1]->wenDu < 100) {
						_renwu[1]->zhuangtai.push_back("<����>");
					}
					if (_renwu[1]->wenDu == 100) {
						_renwu[1]->zhuangtai.push_back("<����>");
					}
					if (_renwu[1]->wenDu == 0) {
						_renwu[1]->zhuangtai.push_back("<����>");
					}
					if (_renwu[1]->wenDu > 0 && _renwu[1]->wenDu <= 25) {
						_renwu[1]->zhuangtai.push_back("<����>");
					}
					sort(_renwu[1]->zhuangtai.begin(), _renwu[1]->zhuangtai.end());
					for (int o = 1; o < _renwu[1]->zhuangtai.size(); o++) {
						if (_renwu[1]->zhuangtai[o] == _renwu[1]->zhuangtai[o - 1]) {
							_renwu[1]->zhuangtai.erase(_renwu[1]->zhuangtai.begin() + o);
						}
					}
					_renwu[1]->zhuangtai_num = _renwu[1]->zhuangtai.size();
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
		srand((unsigned)time(NULL));//���������������һ�μ���
		int suijinum = 0;
		if (_renwu[0]->daweizhi == "���ӵ�") {
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


void ChongZhi(string gongneng) {
	if (gongneng == "ȫ��") {
		for (int i = 0; i < _renwu.size(); i++) {
			if (_renwu[i]->panduan_duiwu == true) {
				for (int o = 0; o < _team.size(); o++) {
					if (_team[o]->name == _renwu[i]->name) {
						_team[o] = _renwu[i];
					}
				}
			}
		}
		shiJianJieMian(0, "��������");
		zhuangtai("����", ".", ".");
	}
	//if (gongneng == "���鸲��") {
	//	for (int i = 0; i < _team.size(); i++) {
	//		if (_team[i]->name == "��") {
	//			_renwu[0] = _team[i];
	//		}
	//		else if (_team[i]->name == "˾��") {
	//			_renwu[1] = _team[i];
	//		}
	//	}
	//	shiJianJieMian(0, "��������");
	//	zhuangtai("����", ".", ".");
	//}
}

void daoju(string gongneng) {
	while (true) {
		ChongZhi("ȫ��");
		if (gongneng == "����") {
			double zongzhong_dongtai = 0;
			int zongzhong_guding = 0;
			zongzhong_dongtai = zongzhong_dongtai + _renwu[0]->sucai_shuzhi * 0.2 + _renwu[0]->sucai_muchai * 0.5 + _renwu[0]->sucai_gancao * 0.1 + _renwu[0]->sucai_shitou * 0.5 +
				_renwu[0]->sucai_mogu * 0.1 + _renwu[0]->sucai_yecai * 0.2 + _renwu[0]->sucai_yegu * 0.1 + _renwu[0]->daoju_pingguo * 0.5 +
				_renwu[0]->daoju_li * 0.5 + _renwu[0]->daoju_suishi * 0.5 + _renwu[0]->daoju_shui * 0.5 + _renwu[0]->fuka_kongbai * 1 +
				_renwu[0]->fuka_qiluruo_weiding * 1;
			for (int i = 0; i < _team.size(); i++) {
				zongzhong_guding = zongzhong_guding + _team[i]->liLiang_D;
			}
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "�����е���Ʒ:" << endl;
			cout << "�زģ�";
			int zhongji1 = 0;
			if (_renwu[0]->sucai_shuzhi > 0) {
				cout << "   01[��֦]��" << _renwu[0]->sucai_shuzhi;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_muchai > 0) {
				cout << "   02[ľ��]��" << _renwu[0]->sucai_muchai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_gancao > 0) {
				cout << "   03[�ɲ�]��" << _renwu[0]->sucai_gancao;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_shitou > 0) {
				cout << "   04[ʯͷ]��" << _renwu[0]->sucai_shitou;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_mogu > 0) {
				cout << "   05[Ģ��]��" << _renwu[0]->sucai_mogu;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_yecai > 0) {
				cout << "   06[Ұ��]��" << _renwu[0]->sucai_yecai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_yegu > 0) {
				cout << "   07[Ұ��]��" << _renwu[0]->sucai_yegu;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "����";
			if (_renwu[0]->daoju_pingguo > 0) {
				cout << "   11[ƻ��]��" << _renwu[0]->daoju_pingguo;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->daoju_li > 0) {
				cout << "   12[��]��" << _renwu[0]->daoju_li;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->daoju_suishi > 0) {
				cout << "   13[��ʯ]��" << _renwu[0]->daoju_suishi;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->daoju_shui > 0) {
				cout << "   14[ˮ]��" << _renwu[0]->daoju_shui;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "����";
			if (_renwu[0]->fuka_kongbai > 0) {
				cout << "   21[�հ׷���]��" << _renwu[0]->fuka_kongbai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->fuka_qiluruo_weiding > 0) {
				cout << "   22[(baka��)δ��ģ�����]��" << _renwu[0]->fuka_qiluruo_weiding;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "�䷽";
			if (_renwu[0]->peifang_yinghuo > 0) {
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
								if (_team[i]->name == "��") {
									if (_renwu[0]->sucai_shuzhi > 0) {//��������������ӻ���

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
				else if (zhongji3 == 31 and _renwu[0]->peifang_yinghuo > 0) {//Ӫ���䷽��
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
							zhongji6 = _renwu[0]->sucai_shuzhi;
							while (zhongji6 > 0) {
								zhongji6--;
								num_shuzhi++;
							}
							zhongji6 = _renwu[0]->daoju_suishi;
							while (zhongji6 > 0) {
								zhongji6--;
								num_suishi++;
							}
							zhongji6 = _renwu[0]->sucai_shitou;
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


void zhandoujiemian_xingDongZhuangZai(zhandou_gongji* ParseIn_gongji,zhandou_yidong* ParseIn_yidong,vector <zhandoushuju_save>& fightarray,vector <_renwushuju*> & team_fu,_renwushuju* S) {//string name,int danmu,int beilv,short use_power,short use_xingdongzhi	���ƣ�����ע�����ͣ�����Ļ������(����)��powerֵ���ж�ֵ�ĵ�λ������
	zhandoushuju_save res;
	res.S.push_back(S);//�պ���ܻ��������ϼ����ֻ��ƣ������ȱ�עһ��
	res.save.gongji = ParseIn_gongji;
	res.save.yidong = ParseIn_yidong;
	if (ParseIn_gongji->toubiao != "�հ�") {
		res.toubiao = ParseIn_gongji->toubiao;
		res.name_global = ParseIn_gongji->name_global;
		res.name = ParseIn_gongji->name;
		if (ParseIn_gongji->name_global == "�����") {
			vector <zhandou_gongji*> danmu_type;//������һ����������Ĺ������ܴ�����ʱ����

			for (short i = 0; i < S->jineng.gongji.size();i++) {
				if (S->jineng.gongji[i]->name_global == ParseIn_gongji->name_global) {
					danmu_type.push_back(S->jineng.gongji[i]);
				}
			}

			//�ǵü�һ��whileѭ��
			while (true) {
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "��ѡ��Ļ��ʽ��" << endl;
				for (short i = 1; i <= danmu_type.size(); i++) {
					cout << i << "[" << danmu_type[i - 1]->name << "]  ";
				}
				cout << "0[����]" << endl;

				short yangshi_short;
				cin >> yangshi_short;

				short dis_xingdongzhi;
				short dis_power;

				if (yangshi_short > 0 and yangshi_short <= danmu_type.size()) {
					cout << "�����뵯Ļ����						---- " << danmu_type[yangshi_short - 1]->danmu->xiaohao_power << "��powerֵ and " << danmu_type[yangshi_short - 1]->danmu->xiaohao_xingdongzhi << "���ж�ֵ / ö" << endl;
					int danmu_num;
					cin >> danmu_num;
					if (danmu_num <= 0) {
						break;
					}
					else {
						dis_xingdongzhi = danmu_num * danmu_type[yangshi_short - 1]->danmu->xiaohao_xingdongzhi - S->xingodngzhi_D;
						dis_power = danmu_num * danmu_type[yangshi_short - 1]->danmu->xiaohao_power - S->power_D;
						if (dis_power > 0) {
							cout << "powerֵ���㣨����" << dis_power << "�㣩" << endl;
						}
						if (dis_xingdongzhi > 0) {
							cout << "�ж�ֵ���㣨����" << dis_xingdongzhi << "�㣩" << endl;
						}
						_getch();
						continue;
					}
					S->xingodngzhi_D = -dis_xingdongzhi;
					S->power_D = -dis_power;
					res.left = danmu_type[yangshi_short - 1]->left;
					fightarray.push_back(res);

					return;
				}
				else if (yangshi_short == 0) {
					break;
				}
				else {
					cout << "��������Чѡ���Ӧ�����֡�" << endl;
					_getch();
					continue;
				}
			}
		}
		else if (ParseIn_gongji->name_global == "�Ի���" or ParseIn_gongji->name_global == "ƫ��" or ParseIn_gongji->name_global == "��λ��") {//���ֹ�����ʽ��Ҫָ�������������Ե�������
			vector <zhandou_gongji*> danmu_type;//������һ����������Ĺ������ܴ�����ʱ����
			for (short i = 0; i < S->jineng.gongji.size(); i++) {
				if (S->jineng.gongji[i]->name_global == ParseIn_gongji->name_global) {
					danmu_type.push_back(S->jineng.gongji[i]);
				}
			}
			while (true) {
				res.M.clear();
				if (binary_search(ParseIn_gongji->beizhu.begin(), ParseIn_gongji->beizhu.end(), "ȫ��")) {
					for (short i = 0; i < team_fu.size(); i++) {
						res.M.push_back(team_fu[i]);//����С�ȫ������ע������ֱ�ӽ�ȫ������������
					}
				}
				else {//ָ����������
					if (team_fu.size() > 1) {
						cout << "��ѡ�������Ķ���";
						for (int i = 0; i < team_fu.size(); i++) {
							cout << "  " << i + 1 << "[" << team_fu[i]->name << "]";
						}
						cout << "  0[����]" << endl;
						short zhongji_choose_enemey;
						cin >> zhongji_choose_enemey;
						if (zhongji_choose_enemey <= team_fu.size() and zhongji_choose_enemey >= 1) {
							res.M.push_back(team_fu[zhongji_choose_enemey - 1]);
						}
						else if (zhongji_choose_enemey == 0) {
							continue;
						}
						else {
							cout << "��������Чѡ���Ӧ�����֡�" << endl;
							_getch();
							continue;
						}
					}
					else {
						res.M.push_back(team_fu[0]);
					}
				}
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "��ѡ��Ļ��ʽ��" << endl;
				for (short i = 1; i <= danmu_type.size(); i++) {
					cout << i << "[" << danmu_type[i - 1]->name << "]  ";
				}
				cout << "0[����]" << endl;

				short yangshi_short;
				cin >> yangshi_short;

				if (not(yangshi_short > 0 and yangshi_short <= danmu_type.size())) {
					cout << "��������Чѡ���Ӧ������" << endl;
					_getch();
					continue;
				}

				short dis_xingdongzhi;
				short dis_power;

				if (yangshi_short > 0 and yangshi_short <= danmu_type.size()) {
					cout << "�����뵯Ļ����						---- " << danmu_type[yangshi_short - 1]->danmu->xiaohao_power << "��powerֵ and " << danmu_type[yangshi_short - 1]->danmu->xiaohao_xingdongzhi << "���ж�ֵ / ö" << endl;
					int danmu_num;
					cin >> danmu_num;
					if (danmu_num <= 0) {
						break;
					}
					else {
						dis_xingdongzhi = danmu_num * danmu_type[yangshi_short - 1]->danmu->xiaohao_xingdongzhi - S->xingodngzhi_D;
						dis_power = danmu_num * danmu_type[yangshi_short - 1]->danmu->xiaohao_power - S->power_D;
						if (dis_power > 0) {
							cout << "powerֵ���㣨����" << dis_power << "�㣩" << endl;
						}
						if (dis_xingdongzhi > 0) {
							cout << "�ж�ֵ���㣨����" << dis_xingdongzhi << "�㣩" << endl;
						}
						_getch();
						continue;
					}
					S->xingodngzhi_D = -dis_xingdongzhi;
					S->power_D = -dis_power;
					res.left = danmu_type[yangshi_short - 1]->left;
					fightarray.push_back(res);

					return;
				}
				else if (yangshi_short == 0) {
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
	else {//����Ϊ���ܼ���
		res.toubiao = ParseIn_yidong->toubiao;
		res.name_global = ParseIn_yidong->name_global;
		if (ParseIn_yidong->name_global == "����") {//�Ժ��ƶ����������ӵ�������λ�Ƶļ���
			vector <zhandou_yidong*> yidong_type;//������һ������������ƶ���ʽ������ʱ����

			for (short i = 0; i < S->jineng.yidong.size(); i++) {
				if (S->jineng.yidong[i]->name_global == ParseIn_yidong->name_global) {
					yidong_type.push_back(S->jineng.yidong[i]);
				}
			}

			while (true) {
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "��ѡ���ƶ���ʽ��" << endl;
				for (short i = 1; i <= yidong_type.size(); i++) {
					cout << i << "[" << yidong_type[i - 1]->name << "]  ";
				}
				cout << "0[����]" << endl;

				short yangshi_short;
				cin >> yangshi_short;

				short dis_xingdongzhi;
				short dis_power;

				if (not(yangshi_short > 0 and yangshi_short <= yidong_type.size())) {
					if (yangshi_short == 0) {
						cout << endl;
						break;
					}
					else {
						cout << "��������Чѡ���Ӧ������" << endl;
						_getch();
						continue;
					}
				}

				if (binary_search(yidong_type[yangshi_short -1]->beizhu.begin(), yidong_type[yangshi_short - 1]->beizhu.end(), "רע")) {
					if (team_fu.size() > 1) {
						cout << "��ѡ���ע�Ķ���: ";
						for (short i = 0; i < team_fu.size(); i++) {
							cout << i + 1 << "[" << team_fu[i]->name << "]   ";
						}
						cout << "0[����]" << endl;

						short zhongji_guanzhuduixiang;
						cin >> zhongji_guanzhuduixiang;
						if (zhongji_guanzhuduixiang <= team_fu.size() and zhongji_guanzhuduixiang >= 1) {
							res.M.push_back(team_fu[zhongji_guanzhuduixiang - 1]);
						}
						else if (zhongji_guanzhuduixiang == 0) {
							continue;
						}
						else {
							cout << "��������Чѡ���Ӧ�����֡�" << endl;
							_getch();
							continue;
						}
					}
					else {
						res.M.push_back(team_fu[0]);
					}
				}

				if (yangshi_short > 0 and yangshi_short <= yidong_type.size()) {
					dis_xingdongzhi = yidong_type[yangshi_short - 1]->xiaohao_xingdongzhi - S->xingodngzhi_D;
					dis_power = yidong_type[yangshi_short - 1]->xiaohao_power - S->power_D;
					if (dis_power > 0) {
						cout << "powerֵ���㣨����" << dis_power << "�㣩" << endl;
						_getch();
						continue;
					}
					if (dis_xingdongzhi > 0) {
						cout << "�ж�ֵ���㣨����" << dis_xingdongzhi << "�㣩" << endl;
						_getch();
						continue;
					}
					
					S->xingodngzhi_D = -dis_xingdongzhi;
					S->power_D = -dis_power;
					res.name = yidong_type[yangshi_short - 1]->name;
					res.left = yidong_type[yangshi_short - 1]->left;
					fightarray.push_back(res);

					return;
				}
				else if (yangshi_short == 0) {
					break;
				}
				else {
					cout << "��������Чѡ���Ӧ�����֡�" << endl;
					_getch();
					continue;
				}
			}
		}
		else if (ParseIn_yidong->name_global == "λ��") {

		}
	}
}

void zhandoujiemian(string leixing,string diren) {
	if (nandu == "��ͨ") {
		if (leixing == "��Ļս") {

			vector <zhandoushuju_save> fightarrey;

			int totalblood_zheng = 0;
			int totalblood_fu = 0;
			int xingdongzhi_zheng_G = 0; int xingdongzhi_zheng_D = 0;
			int xingdongzhi_fu_G = 0; int xingdongzhi_fu_D = 0;
			int powerzhi_zheng_G = 0;int powerzhi_zheng_D = 0;
			int powerzhi_fu_G = 0;int powerzhi_fu_D = 0;

			if (diren == "������NPC") {

				int danmu[1][3][9][7] = {0};
/***************************�ѷϳ�**************************
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
*/
				for (int i = 0; i < _team.size(); i++) {
					totalblood_zheng = totalblood_zheng + _team[i]->tiLi_D;
					powerzhi_zheng_G = powerzhi_zheng_G + _team[i]->power_D;
					xingdongzhi_zheng_G = xingdongzhi_zheng_G + _team[i]->xingodngzhi_D;
				}

				struct _renwushuju NPC_1 = {"NPC_1", 0,1000,1000,1000,1000,0,20,20,10,10,10,10,10,10,5,5,10,10,100,100,0,10,0,50,50,0,"���ӵ�","ɽ��","���","���",3};
				struct _renwushuju NPC_2 = {"NPC_2", 0,1000,1000,1000,1000,0,20,20,10,10,10,10,10,10,5,5,10,10,100,100,0,10,0,50,50,0,"���ӵ�","ɽ��","���","���",3};
				vector <_renwushuju*> team_fu;
				team_fu.push_back(&NPC_1);	team_fu.push_back(&NPC_2);
				for (int i = 0; i < team_fu.size(); i++) {
					totalblood_fu = totalblood_fu + team_fu[i]->tiLi_D;
					powerzhi_fu_G = powerzhi_fu_G + team_fu[i]->power_D;
					xingdongzhi_fu_G = xingdongzhi_fu_G + team_fu[i]->xingodngzhi_D;
				}
				while (totalblood_zheng >= 0 or totalblood_fu >= 0) {
					ChongZhi("ȫ��");
					cout << "========================================================================================================================" << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					for (int i = 0; i < _team.size(); i++) {
						color(11);
						cout << _team[i]->name << ":" << endl;
						color(7);
						cout << "��������" << _team[i]->tiLi_D << "/" << _team[i]->tiLi_G << "��";
						for (int o = 0; o < _team[i]->zhuangtai.size(); o++) {
							cout << _team[i]->zhuangtai[o] << " ";
						}
						cout << endl;
						short num = 0;
						for (short o = 0; o < fightarrey.size(); o++) {
							if (binary_search(fightarrey[o].S.begin(), fightarrey[o].S.end(), _team[i])) {
								num++;
								cout << "  " << num << ": <" << fightarrey[o].name_global << "> " << fightarrey[o].name;
								if (fightarrey[o].M.size() > 0) {
									if (binary_search(fightarrey[o].save.yidong->beizhu.begin(), fightarrey[o].save.yidong->beizhu.end(), "ȫ��") or binary_search(fightarrey[o].save.gongji->beizhu.begin(), fightarrey[o].save.gongji->beizhu.end(), "ȫ��") ){
										cout << "(ȫ��)";
									}
									else {
										//for(short j = 0;j < )
									}
								}
							}
						}
					}
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

					for (int i = 0; i < team_fu.size(); i++) {//��ʱ��״̬���ú����а�����Ķ������ǵõ�ʱ�����޸��Ǹ�������ʱ��������Ҳ��һ�¡�
						team_fu[i]->zhuangtai.clear();
					}
					for (int i = 0; i < team_fu.size(); i++) {//˵���˾�����������ָ�루��
						if (team_fu[i]->baoShiDu_D <= 50 && team_fu[i]->baoShiDu_D > 20) {
							team_fu[i]->zhuangtai.push_back("<�Զ�>");
						}
						if (team_fu[i]->baoShiDu_D <= 20 && team_fu[i]->baoShiDu_D > 0) {
							team_fu[i]->zhuangtai.push_back("<����>");
						}
						if (team_fu[i]->baoShiDu_D == 0) {
							team_fu[i]->zhuangtai.push_back("<������>");
						}
						if (team_fu[i]->jingLi_D >= (0.8 * team_fu[i]->jingLi_G) && team_fu[i]->tiLi_D >= (0.8 * team_fu[i]->tiLi_G)) {
							team_fu[i]->zhuangtai.push_back("<������>");
						}
						if (team_fu[i]->jingLi_D < (0.1 * team_fu[i]->jingLi_G)) {
							team_fu[i]->zhuangtai.push_back("<����>");
						}
						if (team_fu[i]->tiLi_D < (0.5 * team_fu[i]->tiLi_G) && team_fu[i]->tiLi_D >= (0.2 * team_fu[i]->tiLi_G)) {
							team_fu[i]->zhuangtai.push_back("<����>");
						}
						if (team_fu[i]->wenDu >= 75 && team_fu[i]->wenDu < 100) {
							team_fu[i]->zhuangtai.push_back("<����>");
						}
						if (team_fu[i]->wenDu == 100) {
							team_fu[i]->zhuangtai.push_back("<����>");
						}
						if (team_fu[i]->wenDu == 0) {
							team_fu[i]->zhuangtai.push_back("<����>");
						}
						if (team_fu[i]->wenDu > 0 && team_fu[i]->wenDu <= 25) {
							team_fu[i]->zhuangtai.push_back("<����>");
						}
						sort(team_fu[i]->zhuangtai.begin(), team_fu[i]->zhuangtai.end());
						for (int o = 1; o < team_fu[i]->zhuangtai.size(); o++) {
							if (team_fu[i]->zhuangtai[o] == team_fu[i]->zhuangtai[o - 1]) {
								team_fu[i]->zhuangtai.erase(team_fu[i]->zhuangtai.begin() + i);
							}
						}
						team_fu[i]->zhuangtai_num = team_fu[i]->zhuangtai.size();
					}

					for (int i = 0; i < team_fu.size(); i++) {
						color(12);
						cout << team_fu[i]->name << ":" << endl;
						color(7);
						cout << "��������" << team_fu[i]->tiLi_D << "/" << team_fu[i]->tiLi_G << "��";
						for (int o = 0; o < team_fu[i]->zhuangtai.size(); o++) {
							cout << team_fu[i]->zhuangtai[o] << " ";
						}
						cout << endl;
					}
					cout << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "����ѡ�����������������Ĺ���ѡ�" << endl;
					for (int i = 0; i < _team.size(); i++) {
						cout << i + 1 << "[" << _team[i]->name << "]  ";
					}
					for (int i = 0; i < team_fu.size(); i++) {
						cout << _team.size() + i + 1 << "[" << team_fu[i]->name << "]  ";
					}
					cout << _team.size() + team_fu.size() + 1 << "[����]��δ������";
					cout << endl << endl;
					short chrater_xuanze_short; cin >> chrater_xuanze_short;
					if (chrater_xuanze_short > 0 and chrater_xuanze_short <= _team.size()) {
						string mune_xuanze_string;
						while (true) {
							cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
							cout << "��ѡ�����" << _team[chrater_xuanze_short - 1]->name << endl;
							cout << "1[����]  2[�ƶ�]  3[�ڻ�]  4[����]  5[�鿴]  0[����]" << endl;
							cin >> mune_xuanze_string;
							if (mune_xuanze_string == "1") {//����
								bool danmuleixing_bool[4] = { false };//��������һһ��Ӧ
								for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.gongji.size(); i++) {
									bool zhongji_bool = false;
									for (short j = 0; j < 4; j++) {
										if (danmuleixing_bool[j] == 0) {
											zhongji_bool = true;
											break;
										}
									}
									if (zhongji_bool) {
										for (short j = 0; j < 5; j++) {
											if (_team[chrater_xuanze_short - 1]->jineng.gongji[j]->danmu->sudu != 0) {
												switch (_team[chrater_xuanze_short - 1]->jineng.gongji[i]->danmu[j].type) {
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
											else {
												break;
											}
										}
									}
									else {
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
									cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
									for (int i = 0; i < danmuleixing_xuanze.size(); i++) {
										switch (danmuleixing_xuanze[i]) {
										case 0:
											cout << i + 1 << "[�Ի���]  ";
											break;
										case 1:
											cout << i + 1 << "[ƫ���]  ";
											break;
										case 2:
											cout << i + 1 << "[�����]  ";
											break;
										case 3:
											cout << i + 1 << "[��λ��]  ";
											break;
										}
									}
									cout << "0[����]" << endl;
									cin >> zhongji3_int;
									if (zhongji3_int > 0 and zhongji3_int <= danmuleixing_xuanze.size()) {
										for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.gongji.size(); i++) {
											if (_team[chrater_xuanze_short - 1]->jineng.gongji[i]->danmu->type == danmuleixing_xuanze[zhongji3_int - 1]) {//������ȷ��������װ�غ���ȷ����ʽ������
												zhandoujiemian_xingDongZhuangZai(_team[chrater_xuanze_short - 1]->jineng.gongji[i], &NULL_yidong, fightarrey, team_fu, _team[chrater_xuanze_short - 1]);
												break;
											}
										}
									}
									else if (zhongji3_int == 0) {
										break;
									}
									else {
										cout << "��������Чѡ���Ӧ������" << endl;
										_getch();
										continue;
									}
								}
							}
							else if(mune_xuanze_string == "2"){//�ƶ�
								bool yidongleixing_bool[2] = { false };
								for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.yidong.size(); i++) {
									//�������������е��ƶ����ܵ�����
									bool zhongji_bool = false;
									for (short j = 0; j < 2; j++) {
										if (yidongleixing_bool[j] == false) {
											zhongji_bool = true;
										}
									}

									if (zhongji_bool) {
										for (short j = 0; j < 2; j++) {
											if (_team[chrater_xuanze_short - 1]->jineng.yidong[j]->name_global == "����") {
												yidongleixing_bool[0] = true;
											}
											else if (_team[chrater_xuanze_short - 1]->jineng.yidong[j]->name_global == "λ��") {//�Ժ�������Ķ���
												yidongleixing_bool[1] = true;
											}
										}
									}
									else {
										break;
									}
								}

								vector <string> yidongleixing_choose_vector;

								for (short i = 0; i < 2; i++) {
									if (yidongleixing_bool[i] == true) {
										if (i == 0) {
											yidongleixing_choose_vector.push_back("����");
										}
										else if (i == 1) {
											yidongleixing_choose_vector.push_back("λ��");
										}
									}
								}

								if (yidongleixing_choose_vector.size() == 0) {
									cout << "û���ƶ����ܡ�" << endl;
									_getch();
									break;
								}
								else if(yidongleixing_choose_vector.size() == 1){
									cout << "��ѡ����е��ƶ����ͣ�" << yidongleixing_choose_vector[0] << endl;
									_getch();
									for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.yidong.size(); i++) {
										if (_team[chrater_xuanze_short - 1]->jineng.yidong[i]->name_global == yidongleixing_choose_vector[0]) {//������ȷ��������װ�غ���ȷ����ʽ������
											zhandoujiemian_xingDongZhuangZai(&NULL_gongji, _team[chrater_xuanze_short - 1]->jineng.yidong[i], fightarrey, team_fu, _team[chrater_xuanze_short - 1]);
											break;
										}
									}
								}
								else {
									cout << "��ѡ���ƶ����͡�" << endl;
									for (short i = 0; i < yidongleixing_choose_vector.size(); i++) {
										cout << i + 1 << "[" << yidongleixing_choose_vector[i] << "]  ";
									}
									cout << "0[����]" << endl;

									short yidongleixing_choose_short;
									cin >> yidongleixing_choose_short;
									if (yidongleixing_choose_short == 0) {
										break;
									}
									else if(yidongleixing_choose_short > 0 and yidongleixing_choose_short <= yidongleixing_choose_vector.size()){
										for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.yidong.size(); i++) {
											if (_team[chrater_xuanze_short - 1]->jineng.yidong[i]->name_global == yidongleixing_choose_vector[yidongleixing_choose_short - 1]) {//������ȷ��������װ�غ���ȷ����ʽ������
												zhandoujiemian_xingDongZhuangZai(&NULL_gongji, _team[chrater_xuanze_short - 1]->jineng.yidong[i], fightarrey, team_fu, _team[chrater_xuanze_short - 1]);
												break;
											}
										}
									}
									else {
										cout << "��������Чѡ���Ӧ������" << endl;
										_getch();
										continue;
									}
								}
							}


							/*		cout << "1[�����]  2[�Ի���]  3[ƫ���]  0[����]" << endl;
							//		cin >> mune_xuanze_string;
							//		if (mune_xuanze_string == "0") {
							//			break;
							//		}
							//		else if (mune_xuanze_string == "1") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "����";
							//			zhongji0.name = "�����";
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			zhongji0.left = 1;
							//			cout << "��ѡ��Ļ��ʽ��" << endl;
							//			cout << "1[����]  2[С��]  3[����]" << endl;
							//			cin >> mune_xuanze_string;
							//			if (mune_xuanze_string == "1") {
							//				cout << "�����뵯Ļ����(ÿ5öһ��powerֵ����������ȥ�������ֵ)��		��ǰʣ��powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 5;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[2][0][0] = zhongji3_int * 5;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "2") {
							//				cout << "�����뵯Ļ������ÿ4öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 4;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[2][6][0] = zhongji3_int * 4;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "3") {
							//				cout << "�����뵯Ļ������ÿ3öһ��powerֵ����������ȥ�������ֵ����";
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 3;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[2][8][0] = zhongji3_int * 3;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "2") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "����";
							//			zhongji0.name = "�Ի���";
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			zhongji0.left = 1;
							//			if (team_fu.size() > 1) {
							//				cout << "��ѡ�������Ķ���";
							//				for (int i = 0; i < team_fu.size(); i++) {
							//					cout << "  " << i + 1 << "[" << team_fu[i]->name << "]";
							//				}
							//				cout << "  0[����]" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short <= team_fu.size() and zhongji4_short >= 1) {
							//					zhongji0.M.push_back(team_fu[zhongji4_short - 1].name);
							//				}
							//				else if (zhongji4_short == 0) {
							//					continue;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			else {
							//				zhongji0.M.push_back(team_fu[0].name);
							//			}
							//			cout << "��ѡ��Ļ��ʽ��" << endl;
							//			cout << "1[����]  2[С��]  3[����]  4[���ⵯ]" << endl;
							//			cin >> mune_xuanze_string;
							//			if (mune_xuanze_string == "1") {
							//				cout << "�����뵯Ļ����(ÿ5öһ��powerֵ����������ȥ�������ֵ)��		��ǰʣ��powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 5;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[0][0][0] = zhongji3_int * 5;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "2") {
							//				cout << "�����뵯Ļ������ÿ4öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 4;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[0][6][0] = zhongji3_int * 4;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "3") {
							//				cout << "�����뵯Ļ������ÿ3öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 3;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[0][8][0] = zhongji3_int * 3;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "4") {
							//				cout << "�����뵯Ļ������ÿ2öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 2;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[0][4][0] = zhongji3_int * 2;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "3") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "����";
							//			zhongji0.name = "ƫ���";
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			zhongji0.left = 1;
							//			if (team_fu.size() > 1) {
							//				cout << "��ѡ�������Ķ���";
							//				for (int i = 0; i < team_fu.size(); i++) {
							//					cout << "  " << i + 1 << "[" << team_fu[i]->name << "]";
							//				}
							//				cout << "  0[����]" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short <= team_fu.size() and zhongji4_short >= 1) {
							//					zhongji0.M.push_back(team_fu[zhongji4_short - 1].name);
							//				}
							//				else if (zhongji4_short == 0) {
							//					continue;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			else {
							//				zhongji0.M.push_back(team_fu[0].name);
							//			}
							//			cout << "��ѡ��Ļ��ʽ��" << endl;
							//			cout << "1[����]  2[�۵�]  3[С�׵�]" << endl;
							//			cin >> mune_xuanze_string;
							//			if (mune_xuanze_string == "1") {
							//				cout << "�����뵯Ļ����(ÿ5öһ��powerֵ����������ȥ�������ֵ)��		��ǰʣ��powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 5;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[1][0][0] = zhongji3_int * 5;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}

							//			}
							//			else if (mune_xuanze_string == "2") {
							//				cout << "�����뵯Ļ������ÿ5öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 5;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[1][9][0] = zhongji3_int * 5;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}

							//			}
							//			else if (mune_xuanze_string == "3") {
							//				cout << "�����뵯Ļ������ÿ8öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 8;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[1][5][0] = zhongji3_int * 8;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}

							//			}
							//		}
								}
							}
							//else if (mune_xuanze_string == "2") {//�ƶ�
							//	while (true) {
							//		cout << "��ѡ�����" << _team[chrater_xuanze_short - 1].name << endl;
							//		cout << "1[΢��]  2[�з��ƶ�]  3[���ٴ���]  0[����]" << endl;
							//		cin >> mune_xuanze_string;
							//		if (mune_xuanze_string == "0") {
							//			break;
							//		}
							//		else if (mune_xuanze_string == "1") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "�ƶ�";
							//			zhongji0.name = "΢��";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			cout << "�������ƶ�ǿ�ȣ�3���ж�ֵΪһ�Σ���		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//			short zhongji3_short;
							//			cin >> zhongji3_short;
							//			if (zhongji3_short == 0) {
							//				break;
							//			}
							//			if (xingdongzhi_zheng_D >= zhongji3_short * 3 and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//				xingdongzhi_zheng_D = xingdongzhi_zheng_D - zhongji3_short * 3;
							//				zhongji0.danmu[0][0][0] = zhongji3_short;
							//				fightarrey.push_back(zhongji0);
							//				_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//				break;
							//			}
							//			else if (xingdongzhi_zheng_D < zhongji3_short * 3) {
							//				cout << "�ж�ֵ���㡣" << endl;
							//				_getch();
							//				continue;
							//			}
							//			else {
							//				cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[����]" << endl;
							//				short zhongji4_short;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short == 0) {
							//					break;
							//				}
							//				else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//					fightarrey.push_back(zhongji0);
							//					break;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "2") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "����";
							//			zhongji0.name = "�з��ƶ�";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			cout << "�������ƶ�ǿ�ȣ�5���ж�ֵΪһ�Σ���		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//			short zhongji3_short;
							//			cin >> zhongji3_short;
							//			if (zhongji3_short == 0) {
							//				break;
							//			}
							//			if (xingdongzhi_zheng_D >= zhongji3_short * 5 and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//				xingdongzhi_zheng_D = xingdongzhi_zheng_D - zhongji3_short * 5;
							//				zhongji0.danmu[0][0][0] = zhongji3_short;
							//				fightarrey.push_back(zhongji0);
							//				_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//				break;
							//			}
							//			else if (xingdongzhi_zheng_D < zhongji3_short * 5) {
							//				cout << "�ж�ֵ���㡣" << endl;
							//				_getch();
							//				continue;
							//			}
							//			else {
							//				cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[����]" << endl;
							//				short zhongji4_short;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short == 0) {
							//					break;
							//				}
							//				else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//					fightarrey.push_back(zhongji0);
							//					break;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "3") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "����";
							//			zhongji0.name = "���ٴ���";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			cout << "�������ƶ�ǿ�ȣ�7���ж�ֵΪһ�Σ���		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//			short zhongji3_short;
							//			cin >> zhongji3_short;
							//			if (zhongji3_short == 0) {
							//				break;
							//			}
							//			if (xingdongzhi_zheng_D >= zhongji3_short * 7 and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//				xingdongzhi_zheng_D = xingdongzhi_zheng_D - zhongji3_short * 7;
							//				zhongji0.danmu[0][0][0] = zhongji3_short;
							//				fightarrey.push_back(zhongji0);
							//				_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//				break;
							//			}
							//			else if (xingdongzhi_zheng_D < zhongji3_short * 7) {
							//				cout << "�ж�ֵ���㡣" << endl;
							//				_getch();
							//				continue;
							//			}
							//			else {
							//				cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[����]" << endl;
							//				short zhongji4_short;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short == 0) {
							//					break;
							//				}
							//				else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//					fightarrey.push_back(zhongji0);
							//					break;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//		}
							//	}
							//}
							//else if (mune_xuanze_string == "3") {
							//	while (true) {
							//		cout << "��ѡ�����" << _team[chrater_xuanze_short - 1].name << endl;
							//		cout << "1[����]  2[��Ļ����]  3[��Ļ����]  4[��Ļ��λ]  0[����]" << endl;
							//		cin >> mune_xuanze_string;
							//		int zhongji3_int;
							//		if (mune_xuanze_string == "0") {
							//			break;
							//		}
							//		else if (mune_xuanze_string == "1") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "�ڻ�";
							//			zhongji0.name = "����";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			short zhongji4_short;
							//			if (_team.size() > 1) {
							//				cout << "��ѡ���ڻ��Ķ��󣺶Լ�����3���ж�ֵ����������5���ж�ֵ��		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//				for (int i = 0; i < _team.size(); i++) {
							//					cout << "  " << i + 1 << "[" << _team[i].name << "]";
							//				}
							//				cout << "  0[����]" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short <= _team.size() and zhongji4_short >= 1) {
							//					zhongji0.M.push_back(_team[zhongji4_short - 1].name);
							//					if (_team[zhongji4_short - 1].name == _team[chrater_xuanze_short - 1].name) {
							//						if (xingdongzhi_zheng_D < 5) {
							//							cout << "�ж�ֵ���㡣" << endl;
							//							_getch();
							//							continue;
							//						}
							//						else if(_team[chrater_xuanze_short - 1].xingdongcao.size() >= _team[chrater_xuanze_short - 1].xingdongcao_num){
							//							cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//							for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//								cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//							}
							//							cout << "	0[����]" << endl;
							//							short zhongji4_short;
							//							cin >> zhongji4_short;
							//							if (zhongji4_short == 0) {
							//								break;
							//							}
							//							else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//								_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//								fightarrey.push_back(zhongji0);
							//								break;
							//							}
							//							else {
							//								cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//								_getch();
							//								continue;
							//							}
							//						}
							//						else {
							//							xingdongzhi_zheng_D = xingdongzhi_zheng_D - 5;
							//							fightarrey.push_back(zhongji0);
							//							_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//							break;
							//						}
							//					}
							//					else {
							//						if (xingdongzhi_zheng_D < 3) {
							//							cout << "�ж�ֵ���㡣" << endl;
							//							_getch();
							//							continue;
							//						}
							//						else if (_team[chrater_xuanze_short - 1].xingdongcao.size() >= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//							cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//							for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//								cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//							}
							//							cout << "	0[����]" << endl;
							//							short zhongji4_short;
							//							cin >> zhongji4_short;
							//							if (zhongji4_short == 0) {
							//								break;
							//							}
							//							else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//								_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//								fightarrey.push_back(zhongji0);
							//								break;
							//							}
							//							else {
							//								cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//								_getch();
							//								continue;
							//							}
							//						}
							//						else {
							//							xingdongzhi_zheng_D = xingdongzhi_zheng_D - 3;
							//							fightarrey.push_back(zhongji0);
							//							_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//							break;
							//						}
							//					}
							//				}
							//				else if (zhongji4_short == 0) {
							//					continue;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			else {
							//				cout << "��ѡ���Լ���������3���ж�ֵ���Ƿ�ȷ�ϣ�		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//				cout << "0[����]  �������ֽ�Ϊȷ�ϡ�" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short != 0) {
							//					zhongji0.M.push_back(_team[0].name);
							//					if (_team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num and xingdongzhi_zheng_D >= 3) {
							//						xingdongzhi_zheng_D = xingdongzhi_zheng_D - 3;
							//						fightarrey.push_back(zhongji0);
							//						_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//						break;
							//					}
							//					else if (xingdongzhi_zheng_D < 3) {
							//						cout << "�ж�ֵ���㡣" << endl;
							//						_getch();
							//						continue;
							//					}
							//					else {
							//						cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//						for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//							cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//						}
							//						cout << "	0[����]" << endl;
							//						short zhongji4_short;
							//						cin >> zhongji4_short;
							//						if (zhongji4_short == 0) {
							//							break;
							//						}
							//						else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//							_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//							fightarrey.push_back(zhongji0);
							//							break;
							//						}
							//						else {
							//							cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//							_getch();
							//							continue;
							//						}
							//					}
							//				}
							//				else {
							//					continue;
							//				}
							//			}
							//			cout << "�Ƿ�ȷ�ϣ��������ж�ֵ��5��		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//			cout << "0[����]  �����������ֽ�Ϊȷ�ϡ�" << endl;
							//			string zhongji3_string;
							//			if (zhongji3_string == "0") {
							//				break;
							//			}
							//			if (_team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//				fightarrey.push_back(zhongji0);
							//				_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//				break;
							//			}
							//			else {
							//				cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[����]" << endl;
							//				short zhongji4_short;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short == 0) {
							//					break;
							//				}
							//				else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//					fightarrey.push_back(zhongji0);
							//					break;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "2") {//д����λ��
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "�ڻ�";
							//			zhongji0.name = "��Ļ����";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			short zhongji4_short;
							//			if (_team.size() > 1) {
							//				cout << "��ѡ���ڻ��Ķ��󣺶Լ�����3���ж�ֵ����������5���ж�ֵ��		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//				for (int i = 0; i < _team.size(); i++) {
							//					cout << "  " << i + 1 << "[" << _team[i].name << "]";
							//				}
							//				cout << "  0[����]" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short <= _team.size() and zhongji4_short >= 1) {
							//					zhongji0.M.push_back(_team[zhongji4_short - 1].name);
							//					if (_team[zhongji4_short - 1].name == _team[chrater_xuanze_short - 1].name) {
							//						if (xingdongzhi_zheng_D < 5) {
							//							cout << "�ж�ֵ���㡣" << endl;
							//							_getch();
							//							continue;
							//						}
							//						else if (_team[chrater_xuanze_short - 1].xingdongcao.size() >= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//							cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//							for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//								cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//							}
							//							cout << "	0[����]" << endl;
							//							short zhongji4_short;
							//							cin >> zhongji4_short;
							//							if (zhongji4_short == 0) {
							//								break;
							//							}
							//							else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//								_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//								fightarrey.push_back(zhongji0);
							//								break;
							//							}
							//							else {
							//								cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//								_getch();
							//								continue;
							//							}
							//						}
							//						else {
							//							xingdongzhi_zheng_D = xingdongzhi_zheng_D - 5;
							//							fightarrey.push_back(zhongji0);
							//							_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//						}
							//					}
							//					else {
							//						if (xingdongzhi_zheng_D < 3) {
							//							cout << "�ж�ֵ���㡣" << endl;
							//							_getch();
							//							continue;
							//						}
							//						else if (_team[chrater_xuanze_short - 1].xingdongcao.size() >= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//							cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//							for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//								cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//							}
							//							cout << "	0[����]" << endl;
							//							short zhongji4_short;
							//							cin >> zhongji4_short;
							//							if (zhongji4_short == 0) {
							//								break;
							//							}
							//							else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//								_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//								fightarrey.push_back(zhongji0);
							//								break;
							//							}
							//							else {
							//								cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//								_getch();
							//								continue;
							//							}
							//						}
							//						else {
							//							xingdongzhi_zheng_D = xingdongzhi_zheng_D - 3;
							//							fightarrey.push_back(zhongji0);
							//							_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//						}
							//					}
							//				}
							//				else if (zhongji4_short == 0) {
							//					continue;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			else {
							//				cout << "��ѡ���Լ���������3���ж�ֵ���Ƿ�ȷ�ϣ�		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//				cout << "0[����]  �������ֽ�Ϊȷ�ϡ�" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short != 0) {
							//					zhongji0.M.push_back(_team[0].name);
							//					if (_team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num and xingdongzhi_zheng_D >= 3) {
							//						xingdongzhi_zheng_D = xingdongzhi_zheng_D - 3;
							//						fightarrey.push_back(zhongji0);
							//						_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//						break;
							//					}
							//					else if (xingdongzhi_zheng_D < 3) {
							//						cout << "�ж�ֵ���㡣" << endl;
							//						_getch();
							//						continue;
							//					}
							//					else {
							//						cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//						for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//							cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//						}
							//						cout << "	0[����]" << endl;
							//						short zhongji4_short;
							//						cin >> zhongji4_short;
							//						if (zhongji4_short == 0) {
							//							break;
							//						}
							//						else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//							_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//							fightarrey.push_back(zhongji0);
							//							break;
							//						}
							//						else {
							//							cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//							_getch();
							//							continue;
							//						}
							//					}
							//				}
							//				else {
							//					continue;
							//				}
							//			}
							//			cout << "�Ƿ�ȷ�ϣ��������ж�ֵ��5��		��ǰʣ����ж�ֵ��" << xingdongzhi_zheng_D << endl;
							//			cout << "0[����]  �����������ֽ�Ϊȷ�ϡ�" << endl;
							//			string zhongji3_string;
							//			if (zhongji3_string == "0") {
							//				break;
							//			}
							//			if (_team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//				fightarrey.push_back(zhongji0);
							//				_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//				break;
							//			}
							//			else {
							//				cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[����]" << endl;
							//				short zhongji4_short;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short == 0) {
							//					break;
							//				}
							//				else if (zhongji4_short >= 1 and zhongji4_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					_team[chrater_xuanze_short - 1].xingdongcao[zhongji4_short - 1] = zhongji0;
							//					fightarrey.push_back(zhongji0);
							//					break;
							//				}
							//				else {
							//					cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			cout << "��ѡ��Ļ��ʽ��" << endl;
							//			cout << "1[С��]  2[С�׵�]  3[���ⵯ]" << endl;
							//			cin >> mune_xuanze_string;
							//			if (mune_xuanze_string == "1") {
							//				cout << "�����뵯Ļ������ÿ2öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 4;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[0][6][0] = zhongji3_int * 4;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "2") {
							//				cout << "�����뵯Ļ������ÿ3öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 3;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[0][8][0] = zhongji3_int * 3;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "3") {
							//				cout << "�����뵯Ļ������ÿ2öһ��powerֵ����������ȥ�������ֵ����		��ǰʣ���powerֵ��" << powerzhi_zheng_D << endl;
							//				cin >> zhongji3_int;
							//				if (zhongji3_int == 0) {
							//					break;
							//				}
							//				zhongji3_int = zhongji3_int / 2;
							//				if (powerzhi_zheng_D >= zhongji3_int and _team[chrater_xuanze_short - 1].xingdongcao.size() < _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//					powerzhi_zheng_D = powerzhi_zheng_D - zhongji3_int;
							//					zhongji0.danmu[0][4][0] = zhongji3_int * 2;
							//					fightarrey.push_back(zhongji0);
							//					_team[chrater_xuanze_short - 1].xingdongcao.push_back(zhongji0);
							//					break;
							//				}
							//				else if (powerzhi_zheng_D < zhongji3_int) {
							//					cout << "powerֵ���㡣" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "�ж������������滻���е����ݻ��߷��ء�" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[����]" << endl;
							//					short zhongji5_short;
							//					cin >> zhongji5_short;
							//					if (zhongji5_short == 0) {
							//						break;
							//					}
							//					else if (zhongji5_short >= 1 and zhongji5_short <= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//						_team[chrater_xuanze_short - 1].xingdongcao[zhongji5_short - 1] = zhongji0;
							//						fightarrey.push_back(zhongji0);
							//						break;
							//					}
							//					else {
							//						cout << "��������Чѡ���Ӧ�����֡�" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
									}
								}*/
							else if (mune_xuanze_string == "0") {
								break;
							}
							else {
								cout << "��������Чѡ���Ӧ�����֡�" << endl;
								_getch();
								continue;
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


