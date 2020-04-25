//程序准则：不要嫌麻烦！可以简洁，不可以减料！没有一万个if还好意思说这是大型程序？
//行为准则：编程是爱好，学业是现实！你可以加很多东方群用以收集资料，但是，在一天的作业完成之前，你的QQ不允许打开！此外，希望你能再向外拓展点知识，不要整天
//		   都蒙在你这个技术肤浅的菜鸡程序上！
//只要你能遵循这两点，我想你会找到幻想与现实的平衡点的。

#include"头文件/jieMian.h"
#include"conio.h"
#include"头文件/jieMian.h"
#include<fstream>
#include<string>
#include"头文件/kaiPian.h"
using namespace std;


void ParseIn() {

	ifstream shuju("renWuShuJu_shuju");
	ifstream daoju("renWuShuJu_daoju");

	//空白组
	for (int i = 0; i < 28; i++) {//空白数组0 
		shuju >> kongBai_shuju[i];
	}
	for (int i = 0; i < 16; i++) {
		daoju >> kongbai_daoju[i];
	}
	//位号0
	shuju >> zhuRenGong.name >> zhuRenGong.tiLi_D >> zhuRenGong.tiLi_G >> zhuRenGong.jingLi_D >> zhuRenGong.jingLi_G >> zhuRenGong.jingYan
		>> zhuRenGong.liLiang_D >> zhuRenGong.liLiang_G >> zhuRenGong.fangYu_D >> zhuRenGong.fangYu_G >> zhuRenGong.suDu_D >> zhuRenGong.suDu_G 
		>> zhuRenGong.faShu_D >> zhuRenGong.faShu_G >> zhuRenGong.moKang_D >> zhuRenGong.moKang_G >> zhuRenGong.zhiLi_D >> zhuRenGong.zhiLi_G 
		>> zhuRenGong.baoShiDu_D >> zhuRenGong.baoShiDu_G >> zhuRenGong.wenDu >> zhuRenGong.xinQing >> zhuRenGong.haoGan >> zhuRenGong.daweizhi 
		>> zhuRenGong.zhongweizhi >> zhuRenGong.xiaoweizhi >> zhuRenGong.weizhi >> zhuRenGong.zhuangtai_num;
	for (int i = 0; i < zhuRenGong.zhuangtai_num; i++) {
		shuju >> zhuRenGong.zhuangtai[i];
	}
	string kongbai;
	daoju >> kongbai >> zhuRenGong.huobi_money >> zhuRenGong.sucai_shuzhi >> zhuRenGong.sucai_muchai >> zhuRenGong.sucai_gancao 
		>> zhuRenGong.sucai_shitou >> zhuRenGong.sucai_mogu >> zhuRenGong.sucai_yecai >> zhuRenGong.sucai_yegu >> zhuRenGong.daoju_pingguo 
		>> zhuRenGong.daoju_li >> zhuRenGong.daoju_suishi >> zhuRenGong.daoju_shui >> zhuRenGong.fuka_kongbai >> zhuRenGong.fuka_qiluruo_weiding 
		>> zhuRenGong.peifang_yinghuo;
	_renwu.push_back(zhuRenGong);

	//位号1
	shuju >> siJi.name >> siJi.tiLi_D >> siJi.tiLi_G >> siJi.jingLi_D >> siJi.jingLi_G >> siJi.jingYan >> siJi.liLiang_D >> siJi.liLiang_G 
		>> siJi.fangYu_D >> siJi.fangYu_G >> siJi.suDu_D >> siJi.suDu_G >> siJi.faShu_D >> siJi.faShu_G >> siJi.moKang_D >> siJi.moKang_G 
		>> siJi.zhiLi_D >> siJi.zhiLi_G >> siJi.baoShiDu_D >> siJi.baoShiDu_G >> siJi.wenDu >> siJi.xinQing >> siJi.haoGan >> siJi.daweizhi 
		>> siJi.zhongweizhi >> siJi.xiaoweizhi >> siJi.weizhi >> siJi.zhuangtai_num;
	for (int i = 0; i < siJi.zhuangtai_num; i ++) {
		shuju >> siJi.zhuangtai[i];
	}
	daoju >> kongbai >> siJi.huobi_money >> siJi.sucai_shuzhi >> siJi.sucai_muchai >> siJi.sucai_gancao >> siJi.sucai_shitou >> siJi.sucai_mogu 
		>> siJi.sucai_yecai >> siJi.sucai_yegu >> siJi.daoju_pingguo >> siJi.daoju_li >> siJi.daoju_suishi >> siJi.daoju_shui >> siJi.fuka_kongbai 
		>> siJi.fuka_qiluruo_weiding >> siJi.peifang_yinghuo;
	_renwu.push_back(siJi);

	shuju.close();
}

void bianDui() {
	cout << endl << endl;
	int n = 0;
	while (true) {
		ChongZhi();
		char zhongji1;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "请输入界面所对应的数字。" << endl;
		cout << "1[查看]  2[编队]  0[返回]" << endl;
		cin >> zhongji1;
		if (zhongji1 == '1') {
			while (true) {
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "您的队伍成员： ";
				for (int i = 0; i < duiWu.size(); i++) {
					cout << i + 1 << "[" << duiWu[i] << "] ";
				}
				cout << endl << "目前位置未在队伍中的人物: ";
				for (int i = 0; i < dangDiRenWu_other_weizhi.size(); i++) {
					cout << i + duiWu.size() + 1 << "[" << dangDiRenWu_other_weizhi[i] << "] ";
				}
				cout << endl << "请选择欲查看的人物的编号。" << endl;
				short zhongji2;
				cin >> zhongji2;
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < _renwu.size(); i++) {
					if (_renwu[i].name == dangDiRenWu_all_weizhi[zhongji2 - 1]) {
						if (_renwu[i].name == "你") {//列表原则：单条数据场宽定为14。由于是直接输出字符串和数字的组合，所以具体场宽必须随着字符串的大小进行相应变动
							color(3);
							cout << "姓名：" << _NAME << endl;
							color(2);
							cout <<"体力值:" << zhuRenGong.tiLi_D << setw(19) << "体力值线:" << zhuRenGong.tiLi_G << setw(18) << "精力:" << zhuRenGong.jingLi_D << setw(20) << "精力值线:" << zhuRenGong.jingLi_G << endl;
							cout <<"等级:未定,暂存" << setw(16) << "力量值:" << zhuRenGong.liLiang_D << setw(19) << "力量值线:" << zhuRenGong.liLiang_G << setw(18) << "防御值:" << zhuRenGong.fangYu_D << endl;
							cout << "防御值线:" << zhuRenGong.fangYu_G << setw(18) << "速度:" << zhuRenGong.suDu_D << setw(20) << "速度线:" << zhuRenGong.suDu_G << setw(19) << "法术:" << zhuRenGong.faShu_D << endl;
							cout << "法术线:" << zhuRenGong.faShu_G << setw(19) << "魔抗:" << zhuRenGong.moKang_D << setw(20) << "魔抗线:" << zhuRenGong.moKang_G << setw(19) << "智力:" << zhuRenGong.zhiLi_D << endl;
							cout << "智力线:" << zhuRenGong.zhiLi_G << setw(19) << "饱食度:" << zhuRenGong.baoShiDu_D << setw(19) << "饱食度线:" << zhuRenGong.baoShiDu_G << setw(18) << "温度:" << zhuRenGong.wenDu << endl;
							cout << "状态:";
							for (int i = 0; i < zhuRenGong.zhuangtai.size(); i++) {
								cout << zhuRenGong.zhuangtai[i] << setw(16) << " ";
							}
							color(7);
							_getch();
							/*姓名：我
								体力值 : 1000          体力值线 : 1000             精力 : 1000           精力值线 : 1000
								等级 : 未定, 暂存         力量值 : 20          力量值线 : 20           防御值 : 10
								防御值线 : 10             速度 : 10             速度线 : 10              法术 : 10
								法术线 : 10              魔抗 : 5             魔抗线 : 5              智力 : 10
								智力线 : 10            饱食度 : 100          饱食度线 : 100             温度 : 50
								状态 : <精神抖擞>*/
						}
					}
				}
			}
		}
		else if (zhongji1 == '2') {
			while (true) {
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "您的队伍成员： ";
				for (int i = 0; i < duiWu.size(); i++) {
					cout << i + 1 << "[" << duiWu[i] << "] ";
				}
				cout << endl << "目前位置未在队伍中的人物: ";
				for (int i = 0; i < dangDiRenWu_other_weizhi.size(); i++) {
					cout << i + duiWu.size() + 1 << "[" << dangDiRenWu_other_weizhi[i] << "] ";
				}
				cout << endl << "0[返回]" << endl;
				cout << endl << "请选择编入或踢出成员。" << endl << "------------------------------------------------------------------------------------------------------------------------" << endl ;
				cin >> n;
				if (n == 0) {
					break;
				}
				else if (n == 1) {
					cout << endl;
					cout << "亲，您不能自己踢掉自己的哦（认真脸）。";
					_getch();
					cout << endl << endl;
				}
				else if (n > 1 && n <= duiWu.size()) {
					dangDiRenWu_other_weizhi.push_back(duiWu[n - 1]);
					duiWu.erase(duiWu.begin() + n - 1);
					cout << endl << endl;
					_getch();
				}
				else if (n > duiWu.size() && n <= duiWu.size() + dangDiRenWu_other_weizhi.size()) {
					if (dangDiRenWu_other_weizhi.size() != 0) {
						int zhongji2 = n - (duiWu.size() + 1);
						duiWu.push_back(dangDiRenWu_other_weizhi[zhongji2]);
						dangDiRenWu_other_weizhi.erase(dangDiRenWu_other_weizhi.begin() + zhongji2);
						cout << endl << endl;
					}
				}
				else {
					cout << "请输入有效选项对应的数字";
					_getch();
					cout << endl << endl;
				}
			}
		}
		else if (zhongji1 == '0') {
			return;
		}
		else {
			cout << "请输入有效选项对应的数字" << endl;
			_getch();
		}
	}
}

int kaiShiJieMian() {
	int n = 0;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "游戏名：      幻想诗篇" << endl << "                                                    by.古明地核" << endl;
	cout << "1[开始游戏]" << "     2[读档]（暂未开发）" << endl << endl;
	cin >> n;
	for (int i = 0; i < 1000; i = 0) {
		if (n == 1) {
			return 1;
		}
		else {
			cout << endl << "请输入有效选项对应的数字" << endl << endl;
			return kaiShiJieMian();
		}
	}
}


void yiBanJieMian() {//谨防无限套娃！！以一般界面为中心，分散到其他函数后最终必须返回到一般界面中去！！！！！！！！
	while (true) {
		ChongZhi();
		char zhongji1 = 0;
		cout << "_______________________________________________________________________________________________________________________" << endl;
		cout << "地点:" << zhuRenGong.xiaoweizhi << "   位置：" << zhuRenGong.weizhi << "   天气：" <<  tianqi_jiaojiedian <<"   时间：" << month_quanju << "月" << day_quanju << "日 " << hour_quanju << ":" << min_quanju << endl;
		for (int i = 0; i < duiWu.size(); i++) {//临时想了一下，我最好还是对人物数据分别创建 两个数组，一个用来进行动态计算，另一个用来固定显示。 
			if (duiWu[i] == "你") {
				cout << "姓名：你   体力【" << zhuRenGong.tiLi_D << "/" << zhuRenGong.tiLi_G << "】  " << "精力【" << zhuRenGong.jingLi_D << "/" << zhuRenGong.jingLi_G << "】   饱食度【" << zhuRenGong.baoShiDu_D << "/" << zhuRenGong.baoShiDu_G << "】  ";
				cout << "   状态: "; zhuangtai("输出", "你", ""); cout << endl;
			}
			else if (duiWu[i] == "司机") {
				cout << "姓名：司机  体力【" << siJi.tiLi_D << "/" << siJi.tiLi_G << "】  " << "精力【" << siJi.jingLi_D << "/" << siJi.jingLi_G << "】   饱食度【" << siJi.baoShiDu_D << "/" << siJi.baoShiDu_G << "】  ";
				cout << "   状态: "; zhuangtai("输出", "司机", ""); cout << endl;
			}
		}
		map(1000);
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "1[移动]" << "  2[队伍]" << "  3[背包]" << endl;
		cin >> zhongji1;
		if (zhongji1 == '1') {
			yidong(1000);
		}
		else if (zhongji1 == '2') {
			bianDui();
		}
		else if (zhongji1 == '3') {
			daoju("背包");
		}
		else {
			cout << "请输入有效选项对应的数字" << endl;
			_getch();
		}
	}
}


int main() {
	cout << "试作品，很多功能日后加以完善" << endl;
	_getch();
	hello();
	if (kaiShiJieMian() == 1) {//等所有的界面内容设计完毕后，再开始做存档功能
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		zhangJie = "开篇";
		duiWu.push_back("你");
		tianqi_jiaojiedian = "晴";
		ZhangJie0();
	}
	ParseIn();
	ChongZhi();
	yiBanJieMian();
	return 0;
}


//下一个任务：结合目前较为完善的地图制作采集、道具等系统
//规划：再制作一个背包结构体（可以给每个人都定义一份，用不上大不了放着，有用的时候可以丰富系统），结构体里面要包括游戏里所有会出现的道具
//武器防具之类的。。。也可以算进去！就这样决定了。加油
//2020.4.14记录：请立即修改如下结构：1.编队系统：这玩意你在前期不可能用得上，给我卸了。（不过可以存下来用以以后的特殊游戏模式，好歹我写了那么久……）
//								   2.道具系统：别真的给每个人都分配一个