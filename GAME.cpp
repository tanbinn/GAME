//程序准则：不要嫌麻烦！可以简洁，不可以减料！没有一万个if还好意思说这是大型程序？

#include"头文件/jieMian.h"
#include"头文件/jieMian.h"
#include"头文件/kaiPian.h"

void ParseIn_jinengzhuangzai(_renwushuju& name, string jineng) {
	if (jineng[0] == 'A') {
		for (int j = 0; j < quanju_jineng.gongji.size(); j++) {
			if (quanju_jineng.gongji[j].jiaobiao == jineng) {
				name.jineng.gongji.push_back(quanju_jineng.gongji[j]);
			}
		}
	}
	else if (jineng[0] == 'B') {
		for (int j = 0; j < quanju_jineng.yidong.size(); j++) {
			if (quanju_jineng.yidong[j].jiaobiao == jineng) {
				name.jineng.yidong.push_back(quanju_jineng.yidong[j]);
			}
		}
	}

}

void ParseIn() {//载入函数
	//攻击：随机弹
	quanju_jineng.gongji.push_back(suijidan_daodan_level1);
	quanju_jineng.gongji.push_back(suijidan_xiaoyu_level1);

	//移动
	quanju_jineng.yidong.push_back(weiyi_level1);
	quanju_jineng.yidong.push_back(zhongfuyidong_level1);
	quanju_jineng.yidong.push_back(gaosuchuanxing_level1);
	quanju_jineng.yidong.push_back(ceshi_yidongsheji);

	ifstream shuju("renWuShuJu_shuju");
	ifstream daoju("renWuShuJu_daoju");
	ifstream jineng("renWuShuJu_jineng");

	//空白组
	for (int i = 0; i < 29; i++) {
		shuju >> kongBai_shuju[i];
	}
	for (int i = 0; i < 15; i++) {
		daoju >> kongbai_daoju[i];
	}
	for (int i = 0; i < 7; i++) {
		jineng >> kongbai_jineng[i];
	}
	//位号0
	shuju >> zhuRenGong.name >> zhuRenGong.panduan_duiwu >> zhuRenGong.tiLi_D >> zhuRenGong.tiLi_G >> zhuRenGong.jingLi_D >> zhuRenGong.jingLi_G >> zhuRenGong.jingYan
		>> zhuRenGong.liLiang_D >> zhuRenGong.liLiang_G >> zhuRenGong.fangYu_D >> zhuRenGong.fangYu_G >> zhuRenGong.suDu_D >> zhuRenGong.suDu_G
		>> zhuRenGong.faShu_D >> zhuRenGong.faShu_G >> zhuRenGong.moKang_D >> zhuRenGong.moKang_G >> zhuRenGong.zhiLi_D >> zhuRenGong.zhiLi_G
		>> zhuRenGong.baoShiDu_D >> zhuRenGong.baoShiDu_G >> zhuRenGong.wenDu >> zhuRenGong.xinQing >> zhuRenGong.haoGan >> zhuRenGong.daweizhi
		>> zhuRenGong.zhongweizhi >> zhuRenGong.xiaoweizhi >> zhuRenGong.weizhi >> zhuRenGong.xingdongcao_num;
	//重要标注：有些结构体中的数据是不需要在这里载入的，就比如说状态数组可以直接在重置函数中进行重置。同类的行动槽也只是在战斗函数中用得上
	string kongbai;
	daoju >> kongbai >> zhuRenGong.huobi_money >> zhuRenGong.sucai_shuzhi >> zhuRenGong.sucai_muchai >> zhuRenGong.sucai_gancao
		>> zhuRenGong.sucai_shitou >> zhuRenGong.sucai_mogu >> zhuRenGong.sucai_yecai >> zhuRenGong.sucai_yegu >> zhuRenGong.daoju_pingguo
		>> zhuRenGong.daoju_li >> zhuRenGong.daoju_suishi >> zhuRenGong.daoju_shui >> zhuRenGong.fuka_kongbai >> zhuRenGong.fuka_qiluruo_weiding
		>> zhuRenGong.peifang_yinghuo;

	string zhongji1_string;

	jineng >> kongbai;

	while (jineng >> zhongji1_string) {
		if (zhongji1_string[0] >= 'A' and zhongji1_string[0] <= 'Z') {
			ParseIn_jinengzhuangzai(zhuRenGong, zhongji1_string);
		}
		else {
			break;
		}
	}

	_renwu.push_back(zhuRenGong);

	//位号1
	shuju >> siJi.name >> siJi.panduan_duiwu >> siJi.tiLi_D >> siJi.tiLi_G >> siJi.jingLi_D >> siJi.jingLi_G >> siJi.jingYan >> siJi.liLiang_D >> siJi.liLiang_G
		>> siJi.fangYu_D >> siJi.fangYu_G >> siJi.suDu_D >> siJi.suDu_G >> siJi.faShu_D >> siJi.faShu_G >> siJi.moKang_D >> siJi.moKang_G
		>> siJi.zhiLi_D >> siJi.zhiLi_G >> siJi.baoShiDu_D >> siJi.baoShiDu_G >> siJi.wenDu >> siJi.xinQing >> siJi.haoGan >> siJi.daweizhi
		>> siJi.zhongweizhi >> siJi.xiaoweizhi >> siJi.weizhi >> zhuRenGong.xingdongcao_num;
	daoju >> kongbai >> siJi.huobi_money >> siJi.sucai_shuzhi >> siJi.sucai_muchai >> siJi.sucai_gancao >> siJi.sucai_shitou >> siJi.sucai_mogu
		>> siJi.sucai_yecai >> siJi.sucai_yegu >> siJi.daoju_pingguo >> siJi.daoju_li >> siJi.daoju_suishi >> siJi.daoju_shui >> siJi.fuka_kongbai
		>> siJi.fuka_qiluruo_weiding >> siJi.peifang_yinghuo;

	while (jineng >> zhongji1_string) {
		if (zhongji1_string[0] >= 'A' and zhongji1_string[0] <= 'Z') {
			ParseIn_jinengzhuangzai(siJi, zhongji1_string);
		}
		else {
			break;
		}
	}

	_renwu.push_back(siJi);
	for (int i = 0; i < _renwu.size(); i++) {
		if (_renwu[i].panduan_duiwu == true) {
			_team.push_back(_renwu[i]);
		}
	}

	shuju.close();
}

void bianDui_chakan(_renwushuju& name) {
	short zhongji_setw = 15;
	color(3);
	cout << "姓名：" << name.name << endl;
	color(1);
	cout << setw_quanjiao("体力值：" + banjiao_quanjiao(name.tiLi_D), zhongji_setw) << setw_quanjiao("体力值线：" + banjiao_quanjiao(name.tiLi_G), zhongji_setw) << setw_quanjiao("精力：" + banjiao_quanjiao(name.jingLi_D), zhongji_setw) << setw_quanjiao("精力值线：" + banjiao_quanjiao(name.jingLi_G), zhongji_setw) << endl;
	cout << setw_quanjiao("等级：未定，暂存", zhongji_setw) << setw_quanjiao("力量值：" + banjiao_quanjiao(name.liLiang_D), zhongji_setw) << setw_quanjiao("力量值线：" + banjiao_quanjiao(name.liLiang_G), zhongji_setw) << setw_quanjiao("防御值：" + banjiao_quanjiao(name.fangYu_D), zhongji_setw) << endl;
	cout << setw_quanjiao("防御值线：" + banjiao_quanjiao(name.fangYu_G), zhongji_setw) << setw_quanjiao("速度：" + banjiao_quanjiao(name.suDu_D), zhongji_setw) << setw_quanjiao("速度线：" + banjiao_quanjiao(name.suDu_G), zhongji_setw) << setw_quanjiao("法术：" + banjiao_quanjiao(name.faShu_D), zhongji_setw) << endl;
	cout << setw_quanjiao("法术线：" + banjiao_quanjiao(name.faShu_G),zhongji_setw) << setw_quanjiao("魔抗：" + banjiao_quanjiao(name.moKang_D),zhongji_setw) << setw_quanjiao("魔抗线：" + banjiao_quanjiao(name.moKang_G),zhongji_setw) << setw_quanjiao("智力：" + banjiao_quanjiao(name.zhiLi_D),zhongji_setw) << endl;
	cout << setw_quanjiao("智力线：" + banjiao_quanjiao(name.zhiLi_G),zhongji_setw) << setw_quanjiao("饱食度：" + banjiao_quanjiao(name.baoShiDu_D),zhongji_setw) << setw_quanjiao("饱食度线：" + banjiao_quanjiao(name.baoShiDu_G),zhongji_setw) << setw_quanjiao("温度：" + banjiao_quanjiao(name.wenDu),zhongji_setw) << endl;
	cout << "状态：";
	for (int i = 0; i < name.zhuangtai.size(); i++) {
		cout << name.zhuangtai[i] << setw(16) << " ";
	}
	color(7);
	_getch();
	cout << endl;
}

void bianDui() {
	ChongZhi("全局");
	cout << endl << endl;
	int n = 0;
	while (true) {
		ChongZhi("全局");
		char zhongji1;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "请输入界面所对应的数字。" << endl;
		cout << "1[查看]  2[编队]  0[返回]" << endl;
		cin >> zhongji1;
		if (zhongji1 == '1') {
			while (true) {
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "您的队伍成员： ";
				vector <_renwushuju> zhongji_shuzu_other;
				vector <_renwushuju> zhongji_shuzu_all;
				for (int i = 0; i < _team.size(); i++) {
					cout << i + 1 << "[" << _team[i].name << "] ";
				}
				cout << endl << "目前位置未在队伍中的人物: ";
				for (int i = 0; i < _renwu.size(); i++) {
					if (_renwu[i].weizhi == _renwu[0].weizhi) {
						zhongji_shuzu_all.push_back(_renwu[i]);
						if (_renwu[i].panduan_duiwu == false) {
							zhongji_shuzu_other.push_back(_renwu[i]);
						}
					}
				}
				for (int i = 0; i < zhongji_shuzu_other.size(); i++) {
					cout << i + _team.size() + 1 << "[" << zhongji_shuzu_other[i].name << "] ";
				}
				cout << endl << "请选择欲查看的人物的编号。" << endl;
				short zhongji2;
				cin >> zhongji2;
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				if (zhongji2 == 0) {
					return;
				}
				else if (zhongji2 > 0 and zhongji2 <= (zhongji_shuzu_all.size() + 1)) {
					for (int i = 0; i < _renwu.size(); i++) {
						if (_renwu[i].name == zhongji_shuzu_all[zhongji2 - 1].name) {
							if (_renwu[i].name == "你") {
								bianDui_chakan(zhuRenGong);
							}
							else if (_renwu[i].name == "司机") {
								bianDui_chakan(siJi);
							}
						}
					}
				}
				else {
					cout << "请输入有效选项对应的数字" << endl;
					_getch();
				}
			}
		}
		else if (zhongji1 == '2') {
			short num_dangdirenwu_other = 0;
			vector <_renwushuju> zhongji_shuzu;
			for (int i = 0; i < _renwu.size(); i++) {
				if (_renwu[i].weizhi == _renwu[0].weizhi and _renwu[i].panduan_duiwu == false) {
					num_dangdirenwu_other++;
					zhongji_shuzu.push_back(_renwu[i]);
				}
			}
			while (true) {
				ChongZhi("全局");
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "您的队伍成员： ";
				for (int i = 0; i < _team.size(); i++) {
					cout << i + 1 << "[" << _team[i].name << "] ";
				}
				cout << endl << "目前位置未在队伍中的人物: ";
				for (int i = 0; i < _renwu.size(); i++) {
					if (_renwu[i].panduan_duiwu == false and _renwu[i].weizhi == zhuRenGong.weizhi) {
						cout << i + _team.size() << "[" << _renwu[i].name << "] ";
					}
				}
				cout << endl << "0[返回]" << endl;
				cout << endl << "请选择编入或踢出成员。" << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
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
				else if (n > 1 && n <= _team.size()) {
					_team[n - 1].panduan_duiwu = false;
					if (_team[n - 1].name == "司机") {//记得以后添加新人物时在这里进行补充
						_renwu[1].panduan_duiwu = false;
					}
					_team.erase(_team.begin() + n - 1);
					cout << endl << endl;
				}
				else if (n > _team.size() and n <= (_team.size() + num_dangdirenwu_other)) {
					if (num_dangdirenwu_other != 0) {
						int zhongji2 = n - (_team.size() + 1);
						if (zhongji_shuzu[zhongji2].name == "司机") {
							_renwu[1].panduan_duiwu = true;
							_team.push_back(_renwu[1]);
						}
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
		ChongZhi("全局");
		char zhongji1 = 0;
		cout << "_______________________________________________________________________________________________________________________" << endl;
		cout << "地点:" << _renwu[0].xiaoweizhi << "   位置：" << _renwu[0].weizhi << "   天气：" << tianqi_jiaojiedian << "   时间：" << month_quanju << "月" << day_quanju << "日 " << hour_quanju << ":" << min_quanju << endl;
		for (int i = 0; i < _team.size(); i++) {
			if (_team[i].name == "你") {
				cout << "姓名：" << _NAME << "  体力【" << _team[0].tiLi_D << "/" << _team[0].tiLi_G << "】  " << "精力【"
					<< _team[0].jingLi_D << "/" << _team[0].jingLi_G << "】   饱食度【" << _team[0].baoShiDu_D << "/"
					<< _team[0].baoShiDu_G << "】  ";
				cout << "   状态: "; zhuangtai("输出", "你", ""); cout << endl;
			}
			else {
				cout << "姓名：" << _team[i].name << "  体力【" << _team[i].tiLi_D << "/" << _team[i].tiLi_G << "】  " << "精力【"
					<< _team[i].jingLi_D << "/" << _team[i].jingLi_G << "】   饱食度【" << _team[i].baoShiDu_D << "/"
					<< _team[i].baoShiDu_G << "】  ";
				cout << "   状态: "; zhuangtai("输出", _team[i].name, ""); cout << endl;
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
	cout << "你好啊" << endl;
	_getch();
	cout << "这游戏是我心血来潮的试制品，不过打这串字符估计也只是给我自己看看。要是您愿意花下宝贵的来玩我的作品，我感激不尽。" << endl;
	_getch();
	cout << "那么，我们开始吧。" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	_getch();
	//if (kaiShiJieMian() == 1) {//等所有的界面内容设计完毕后，再开始做存档功能
	//	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	//	zhangJie = "开篇";
	//	nandu = "普通";
	//	//tianqi_jiaojiedian = '晴';
	//	ZhangJie0();
	//}
	ParseIn();
	ChongZhi("全局");
	zhandoujiemian("弹幕战", "测试用NPC");
	yiBanJieMian();
	return 0;
}


//下一个任务：结合目前较为完善的地图制作采集、道具等系统
//规划：再制作一个背包结构体（可以给每个人都定义一份，用不上大不了放着，有用的时候可以丰富系统），结构体里面要包括游戏里所有会出现的道具
//武器防具之类的。。。也可以算进去！就这样决定了。加油
//2020.4.14记录：请立即修改如下结构：1.编队系统：这玩意你在前期不可能用得上，给我卸了。（不过可以存下来用以以后的特殊游戏模式，好歹我写了那么久……）
//								   2.道具系统：别真的给每个人都分配一个背包，即没用又烦人
//2020.4.18记录：已完成的数据修改：1.道具系统重新设置，具体道具只有主人公和一些商人类NPC拥有，不过，如果以后要配置掉落系统，或许可以顺便用上。
//								 2.将编队系统变成“队伍”系统的子项，并新增人物查看系统。或许，编队系统在一些地方会有意想不到的作用。
//				接下来的规划任务：1.编队系统直接留着吧，会有用的，如果嫌写口上麻烦，直接写个“先判定是否符合编入踢出的条件，然后才进行操作，否则直接返回”的算法即可。
//								2.然后这边框架差不多该有的都有了，可以开始着手于编写战斗系统了。
//                                                       
//紧急规划：迅速将所有的直接调用或赋值结构体的算法全部换成全局数组renwu和team!



