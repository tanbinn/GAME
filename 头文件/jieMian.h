#ifndef _JIEMIAN_H_
#define _JIEMIAN_H_
#include"juBen.h"

//在主函数中先定义初始位置，后续的位移可以通过地图文件试试看 

void zhuangtai(string gongneng, string name, string zhuangtai) {//在状态上，我想给人物单独创造一套数列，以字符串的形式向内存储。然后向该函数输入数据时，分别指明人物、功能、 增减状态（根据情况可以选择是否空着） 
	if (gongneng == "输出") {
		if (name == "你") {
			for (int i = 0; i < _renwu[0]->zhuangtai.size(); i++) {
				cout << _renwu[0]->zhuangtai[i] << " ";
			}
		}
		if (name == "司机") {
			for (int i = 0; i < siJi.zhuangtai.size(); i++) {
				cout << siJi.zhuangtai[i] << " ";
			}
		}
	}
	else if (gongneng == "重置") {//因为没想到更好的判定方法，所以每次要重置一遍人物的状态数组（注意是每次，即任何与状态有关的指令前！）， 判断前提为该人物是否在现场（小位置）,另外提一句，在状态函数里就写与状态有关系的代码，别想着在这里顺路把NPC位移给写了
		//先清空所有人的状态数组中的数据，然后根据不同的参数分别给每个人加上状态数据
		for (int i = 0; i < _renwu.size(); i++) {
			_renwu[i]->zhuangtai.clear();
		}
		for (int i = 0; i < _renwu.size(); i++) {//算了，还是分不同的区域来重置好了（以大位置为单元）
			if (_renwu[i]->daweizhi == _renwu[0]->daweizhi) {
				if (_renwu[i]->name == "你") {
					if (_renwu[0]->baoShiDu_D <= 50 && _renwu[0]->baoShiDu_D > 20) {
						_renwu[0]->zhuangtai.push_back("<略饿>");
					}
					if (_renwu[0]->baoShiDu_D <= 20 && _renwu[0]->baoShiDu_D > 0) {
						_renwu[0]->zhuangtai.push_back("<饥饿>");
					}
					if (_renwu[0]->baoShiDu_D == 0) {
						_renwu[0]->zhuangtai.push_back("<饥肠辘辘>");
					}
					if (_renwu[0]->jingLi_D >= (0.8 * _renwu[0]->jingLi_G) && _renwu[0]->tiLi_D >= (0.8 * _renwu[0]->tiLi_G)) {
						_renwu[0]->zhuangtai.push_back("<精神抖擞>");
					}
					if (_renwu[0]->jingLi_D < (0.1 * _renwu[0]->jingLi_G)) {
						_renwu[0]->zhuangtai.push_back("<劳累>");
					}
					if (_renwu[0]->tiLi_D < (0.5 * _renwu[0]->tiLi_G) && _renwu[0]->tiLi_D >= (0.2 * _renwu[0]->tiLi_G)) {
						_renwu[0]->zhuangtai.push_back("<虚弱>");
					}
					if (_renwu[0]->wenDu >= 75 && _renwu[0]->wenDu < 100) {
						_renwu[0]->zhuangtai.push_back("<较热>");
					}
					if (_renwu[0]->wenDu == 100) {
						_renwu[0]->zhuangtai.push_back("<高温>");
					}
					if (_renwu[0]->wenDu == 0) {
						_renwu[0]->zhuangtai.push_back("<冰冻>");
					}
					if (_renwu[0]->wenDu > 0 && _renwu[0]->wenDu <= 25) {
						_renwu[0]->zhuangtai.push_back("<较冷>");
					}
					sort(_renwu[0]->zhuangtai.begin(), _renwu[0]->zhuangtai.end());
					for (int o = 1; o < _renwu[0]->zhuangtai.size(); o++) {
						if (_renwu[0]->zhuangtai[o] == _renwu[0]->zhuangtai[o - 1]) {
							_renwu[0]->zhuangtai.erase(_renwu[0]->zhuangtai.begin() + o);
						}
					}
					_renwu[0]->zhuangtai_num = _renwu[0]->zhuangtai.size();
				}
				if (_renwu[i]->name == "司机") {
					if (_renwu[1]->baoShiDu_D <= 50 && _renwu[1]->baoShiDu_D > 20) {
						_renwu[1]->zhuangtai.push_back("<略饿>");
					}
					if (_renwu[1]->baoShiDu_D <= 20 && _renwu[1]->baoShiDu_D > 0) {
						_renwu[1]->zhuangtai.push_back("<饥饿>");
					}
					if (_renwu[1]->baoShiDu_D == 0) {
						_renwu[1]->zhuangtai.push_back("<饥肠辘辘>");
					}
					if (_renwu[1]->jingLi_D >= (0.8 * _renwu[1]->jingLi_G) && _renwu[1]->tiLi_D >= (0.8 * _renwu[1]->tiLi_G)) {
						_renwu[1]->zhuangtai.push_back("<精神抖擞>");
					}
					if (_renwu[1]->jingLi_D < (0.1 * _renwu[1]->jingLi_D)) {
						_renwu[1]->zhuangtai.push_back("<劳累>");
					}
					if (_renwu[1]->tiLi_D < (0.5 * _renwu[1]->tiLi_G) && _renwu[1]->tiLi_D >= (0.2 * _renwu[1]->tiLi_G)) {
						_renwu[1]->zhuangtai.push_back("<虚弱>");
					}
					if (_renwu[1]->wenDu >= 75 && _renwu[1]->wenDu < 100) {
						_renwu[1]->zhuangtai.push_back("<较热>");
					}
					if (_renwu[1]->wenDu == 100) {
						_renwu[1]->zhuangtai.push_back("<高温>");
					}
					if (_renwu[1]->wenDu == 0) {
						_renwu[1]->zhuangtai.push_back("<冰冻>");
					}
					if (_renwu[1]->wenDu > 0 && _renwu[1]->wenDu <= 25) {
						_renwu[1]->zhuangtai.push_back("<较冷>");
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
	else if (gongneng == "调用") {
	}
}

void tianqi() {//天气函数可以初步做完善一点。天气变动是以大地图为一个重置单位，以一个或多个中位置组合为计算单位。计算时，先提供临时字符数组，往里面编入不同类型、数量的天气名称， 
			  //然后利用随机数抽取来给字符数组提供下标，从而做到随机重置天气
			  //重置时间有一定间隔，具体调整的话我希望在120分钟到720分钟之间，然后进行下一次重置
			  //当然，不同的季节、地点、人物技能都会影响到天气变化。节气、地点方面的影响写入该函数即可，但人物因素产生的影响就直接在函数外改动（而且要重置天气重置时间） 
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
		srand((unsigned)time(NULL));//随机数的种子设置一次即可
		int suijinum = 0;
		if (_renwu[0]->daweizhi == "交接点") {
			string zhongji;
			shiJianJieMian(180, "重置天气");
			if (tianqi_jiaojiedian == "晴") {
				string tianqi[5] = { "晴","晴","多云","多云","多云" };
				tianqi_jiaojiedian = tianqi[rand() % 5];
				zhongji = tianqi_jiaojiedian;
				if (zhongji == "晴") {
					return;
				}
				else if (zhongji == "多云" && hour_quanju >= 6 && hour_quanju <= 16) {//白天 
					cout << "云朵聚集了起来，略微遮住了点太阳。" << endl;
					cout << "感到不是很热了。" << endl;
					return;
				}
				else if (zhongji == "多云" && hour_quanju > 16 && hour_quanju <= 18) {//黄昏 
					if (rand() % 2 == 0) {
						cout << "夕阳西下，眼看着光芒将逝，云朵们仿佛感到十分不舍，纷纷从对面远远地奔来，转眼间便组成壮观的金色云浪，贪心地揽下了足足半边天的光辉。" << endl;
						cout << "很迷人的景色呢。" << endl;
						return;
					}
					else if (rand() % 2 == 1) {
						cout << "这边太阳还没落下，月亮便早早地来接班了。云朵们兴奋地从四面八方跑了出来，簇拥着月亮向天空中央移动。" << endl;
						cout << "今晚看来要隔云观月呢。" << endl;
						return;
					}
				}
				else {//夜晚 
					cout << "云朵聚集了起来，给皎洁的月亮披上了一层轻薄的面纱。" << endl;
					cout << "虽说不无美感，但环境变得更加黑暗了。" << endl;
					return;
				}
			}
			else if (tianqi_jiaojiedian == "多云") {
				string tianqi[3] = { "晴","阴","阴" };
				tianqi_jiaojiedian = tianqi[rand() % 3];
				zhongji = tianqi_jiaojiedian;
				if (zhongji == "晴" && hour_quanju >= 6 && hour_quanju <= 16) {
					//	if(rand() % 3 == 0)  这是很重要的一个算法，目前处于建设期，暂时搁着，以后有灵感了请务必来添补额外文本（不要让玩家过早感到单调乏味） 
					cout << "太阳拨开重重的云层，在高空展示他的身姿。" << endl;
					cout << "阳光很暖和呢。" << endl;
					return;
				}
				else if (zhongji == "晴" && hour_quanju > 16 && hour_quanju <= 18) {
					cout << "完成恭送太阳回家的仪式后，金色的云浪逐渐散开，变成一块块小的云团结伴而回了。" << endl;
					return;
				}
				else if (zhongji == "阴" && hour_quanju >= 6 && hour_quanju <= 16) {
					cout << "云朵层层堆积，不一会儿便变成了厚重的云层，直压在上空，让人喘不过气来。" << endl;
					cout << "阳光难以透进。天空是压抑的黑色，大地是慑人的灰色。恐怕会下雨呢。" << endl;
					return;
				}
				else if (zhongji == "阴" && hour_quanju > 16 && hour_quanju <= 18) {
					cout << "更多的云朵参与到夺取金色光辉的行列中，直挤得天空上连一点缝隙都没有。仅剩的一点光芒也被吞噬，大地仿佛提前进入了夜晚。" << endl;
					cout << "这可不妙呀……" << endl;
					return;
				}
				else if (zhongji == "晴" && hour_quanju > 18 && hour_quanju < 24 && hour_quanju >= 0 && hour_quanju < 6) {
					cout << "云朵散开了，月光毫无遮拦地倾泻下来，给大地披上银色的衣装。" << endl;
					cout << "虽然并不是很亮，但仅凭肉眼足以看清周围的环境了。" << endl;
					return;
				}
				else if (zhongji == "阴" && hour_quanju > 18 && hour_quanju < 24 && hour_quanju >= 0 && hour_quanju < 6)
				{
					cout << "云朵进一步聚集，很快抢占了整片天空，不一会儿，最后一丝光芒也被夺取了。" << endl;
					cout << "没有其他光源的话，几乎是伸手不见五指。" << endl;
					return;
				}
			}
			else if (tianqi_jiaojiedian == "阴") {
				string tianqi[6] = { "多云","晴","雨" };
				tianqi_jiaojiedian = tianqi[rand() % 3];
				zhongji = tianqi_jiaojiedian;
				if (zhongji == "多云" && hour_quanju >= 6 && hour_quanju <= 16) {
					cout << "积云散开了一点，稍微能瞧见太阳了。" << endl;
				}
				else if (zhongji == "雨" && hour_quanju >= 6 && hour_quanju <= 16) {
					if (rand() % 2 == 0) {//当心文本bug，如果主角在山洞地形中的话千万不要用这个文本，到时候记得添加条件
						cout << "一道闪光划过天空，直直地刺在远方的一棵大树上，只一瞬间便劈断了它。" << endl;
						_getch();
						cout << "“轰隆隆——————”" << endl;
						cout << "紧随其后的，是几声沉闷的雷鸣。" << endl;
						cout << "突然，周围刮起了狂风，花草、树木皆被压制得直不起腰，有的甚至被卷起，被撕扯成碎片飞散到各处。" << endl;
						_getch();
						cout << "噼啪！" << endl;
						cout << "果不其然，一道闪电落在不远处的一颗大树上，这次不只是被腰斩，焦黑的树枝上还携带着可怕的火焰，倒塌在草地上。" << endl;
						cout << "可怕的暴风助长了火势蔓延。眼看着就要烧过来了，一丝清凉感从" << _NAME << "额头上传了过来……" << endl;
						_getch();
						cout << "是雨水。" << endl;
						_getch();
						cout << "只是一眨眼的功夫，雨水便倾覆了下来。无数的雨点拉出无数的雨丝，无数的雨丝汇集成漫天的雨针，";
						cout << "打碎了花草，击散了树叶，淹没了火焰。它与暴风一同呼号着，席卷着大地上的一切。" << endl;
						cout << "看来得躲一下。" << endl;
						return;
					}
					if (rand() % 2 == 1) {

						return;
					}
				}
			}
			else if (tianqi_jiaojiedian == "雨") {
				string tianqi_jiaojiedian[6] = { "阴","雨" };
			}

		}
	}
}


void ChongZhi(string gongneng) {
	if (gongneng == "全局") {
		for (int i = 0; i < _renwu.size(); i++) {
			if (_renwu[i]->panduan_duiwu == true) {
				for (int o = 0; o < _team.size(); o++) {
					if (_team[o]->name == _renwu[i]->name) {
						_team[o] = _renwu[i];
					}
				}
			}
		}
		shiJianJieMian(0, "天气重置");
		zhuangtai("重置", ".", ".");
	}
	//if (gongneng == "队伍覆盖") {
	//	for (int i = 0; i < _team.size(); i++) {
	//		if (_team[i]->name == "你") {
	//			_renwu[0] = _team[i];
	//		}
	//		else if (_team[i]->name == "司机") {
	//			_renwu[1] = _team[i];
	//		}
	//	}
	//	shiJianJieMian(0, "天气重置");
	//	zhuangtai("重置", ".", ".");
	//}
}

void daoju(string gongneng) {
	while (true) {
		ChongZhi("全局");
		if (gongneng == "背包") {
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
			cout << "您所有的物品:" << endl;
			cout << "素材：";
			int zhongji1 = 0;
			if (_renwu[0]->sucai_shuzhi > 0) {
				cout << "   01[树枝]：" << _renwu[0]->sucai_shuzhi;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_muchai > 0) {
				cout << "   02[木柴]：" << _renwu[0]->sucai_muchai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_gancao > 0) {
				cout << "   03[干草]：" << _renwu[0]->sucai_gancao;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_shitou > 0) {
				cout << "   04[石头]：" << _renwu[0]->sucai_shitou;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_mogu > 0) {
				cout << "   05[蘑菇]：" << _renwu[0]->sucai_mogu;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_yecai > 0) {
				cout << "   06[野菜]：" << _renwu[0]->sucai_yecai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->sucai_yegu > 0) {
				cout << "   07[野谷]：" << _renwu[0]->sucai_yegu;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "道具";
			if (_renwu[0]->daoju_pingguo > 0) {
				cout << "   11[苹果]：" << _renwu[0]->daoju_pingguo;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->daoju_li > 0) {
				cout << "   12[梨]：" << _renwu[0]->daoju_li;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->daoju_suishi > 0) {
				cout << "   13[燧石]：" << _renwu[0]->daoju_suishi;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->daoju_shui > 0) {
				cout << "   14[水]：" << _renwu[0]->daoju_shui;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "符卡";
			if (_renwu[0]->fuka_kongbai > 0) {
				cout << "   21[空白符卡]：" << _renwu[0]->fuka_kongbai;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			if (_renwu[0]->fuka_qiluruo_weiding > 0) {
				cout << "   22[(baka的)未定模板符卡]：" << _renwu[0]->fuka_qiluruo_weiding;
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl << "配方";
			if (_renwu[0]->peifang_yinghuo > 0) {
				cout << "   31[营火]";
				zhongji1++;
				if (zhongji1 >= 4) {
					zhongji1 = 0;
					cout << endl;
				}
			}
			cout << endl;
			char zhongji2;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "1[使用]   2[丢弃]  3[查看]  0[返回]" << endl;
			cin >> zhongji2;
			if (zhongji2 == '1') {
				int zhongji3 = 0;
				cout << endl;
				color(3);
				cout << "请输入所选道具的对应数字。" << endl;
				color(7);
				cin >> zhongji3;
				if (zhongji3 == 01) {//首先先判定该物品是否可以使用，如树枝可以用来加火，还可以在特定环境中触发机关等，下面以这个为模板
					while (true) {
						string weiding;
						if (weiding == "这里还没有可调用的函数，放在这里做标记，定为——如果此处（位置）有营火") {
							for (int i = 0; i < _team.size(); i++) {
								if (_team[i]->name == "你") {
									if (_renwu[0]->sucai_shuzhi > 0) {//这个可以用来增加火势

									}
								}

							}
						}
						else {
							cout << "请输入有效选项对应的数字。" << endl;
							_getch();
							continue;
						}
					}
				}
				else if (zhongji3 == 31 and _renwu[0]->peifang_yinghuo > 0) {//营火（配方）
					while (true) {
						ChongZhi("全局");
						char zhongji4;
						cout << endl;
						color(3);
						cout << "所需素材：①[10 * 树枝 + 1 * 燧石（不消耗） + 3 * 石头]" << endl;
						cout << "         ②[3 * 木柴 + 1 * 燧石（不消耗）+ 3 * 石头]" << endl;
						color(7);
						cout << "请选择相应的配方。	0[返回]" << endl;
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
								cout << "材料不够哦。" << endl;
								if (num_shuzhi < 10) {
									cout << "还缺树枝：" << 10 - num_shuzhi;
								}
								if (num_suishi < 1) {
									cout << "  还缺燧石:" << 1 - num_suishi;
								}
								if (num_suishi < 3) {
									cout << "  还缺石头:" << 3 - num_shitou;
								}
								_getch();
								continue;
							}
							else if ((zongzhong_dongtai + 5) > zongzhong_guding) {
								cout << "背包空间不足" << endl;
								cout << "营火重量为5，还差" << (zongzhong_dongtai + 5) - zongzhong_guding;
								_getch();
							}

						}
						else if (zhongji4 == '2') {

						}
						else {
							cout << "请输入有效选项对应的数字" << endl;
							_getch();
							continue;
						}
					}
				}
				else {
					cout << "请输入有效选项对应的数字" << endl;
					_getch();
				}
			}
			else if (zhongji2 == '0') {
				return;
			}
			else {
				cout << "请输入有效选项对应的数字" << endl;
				_getch();
				cout << endl;
			}
		}
		else if (gongneng == "调用") {

		}
		else if (gongneng == "采集") {

		}
		else if (gongneng == "掉落") {

		}
	}
}


void zhandoujiemian_xingDongZhuangZai(zhandou_gongji* ParseIn_gongji,zhandou_yidong* ParseIn_yidong,vector <zhandoushuju_save>& fightarray,vector <_renwushuju*> & team_fu,_renwushuju* S) {//string name,int danmu,int beilv,short use_power,short use_xingdongzhi	名称（必须注明类型），弹幕，倍率(多用)，power值和行动值的单位消耗量
	zhandoushuju_save res;
	res.S.push_back(S);//日后可能还会加入组合技这种机制，所以先备注一下
	res.save.gongji = ParseIn_gongji;
	res.save.yidong = ParseIn_yidong;
	if (ParseIn_gongji->toubiao != "空白") {
		res.toubiao = ParseIn_gongji->toubiao;
		res.name_global = ParseIn_gongji->name_global;
		res.name = ParseIn_gongji->name;
		if (ParseIn_gongji->name_global == "随机弹") {
			vector <zhandou_gongji*> danmu_type;//将所有一级名称相符的攻击技能存入临时数组

			for (short i = 0; i < S->jineng.gongji.size();i++) {
				if (S->jineng.gongji[i]->name_global == ParseIn_gongji->name_global) {
					danmu_type.push_back(S->jineng.gongji[i]);
				}
			}

			//记得加一个while循环
			while (true) {
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "请选择弹幕样式。" << endl;
				for (short i = 1; i <= danmu_type.size(); i++) {
					cout << i << "[" << danmu_type[i - 1]->name << "]  ";
				}
				cout << "0[返回]" << endl;

				short yangshi_short;
				cin >> yangshi_short;

				short dis_xingdongzhi;
				short dis_power;

				if (yangshi_short > 0 and yangshi_short <= danmu_type.size()) {
					cout << "请输入弹幕数量						---- " << danmu_type[yangshi_short - 1]->danmu->xiaohao_power << "点power值 and " << danmu_type[yangshi_short - 1]->danmu->xiaohao_xingdongzhi << "点行动值 / 枚" << endl;
					int danmu_num;
					cin >> danmu_num;
					if (danmu_num <= 0) {
						break;
					}
					else {
						dis_xingdongzhi = danmu_num * danmu_type[yangshi_short - 1]->danmu->xiaohao_xingdongzhi - S->xingodngzhi_D;
						dis_power = danmu_num * danmu_type[yangshi_short - 1]->danmu->xiaohao_power - S->power_D;
						if (dis_power > 0) {
							cout << "power值不足（还差" << dis_power << "点）" << endl;
						}
						if (dis_xingdongzhi > 0) {
							cout << "行动值不足（还差" << dis_xingdongzhi << "点）" << endl;
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
					cout << "请输入有效选项对应的数字。" << endl;
					_getch();
					continue;
				}
			}
		}
		else if (ParseIn_gongji->name_global == "自机狙" or ParseIn_gongji->name_global == "偏向弹" or ParseIn_gongji->name_global == "限位弹") {//这种攻击形式需要指定攻击对象，所以单独拉出
			vector <zhandou_gongji*> danmu_type;//将所有一级名称相符的攻击技能存入临时数组
			for (short i = 0; i < S->jineng.gongji.size(); i++) {
				if (S->jineng.gongji[i]->name_global == ParseIn_gongji->name_global) {
					danmu_type.push_back(S->jineng.gongji[i]);
				}
			}
			while (true) {
				res.M.clear();
				if (binary_search(ParseIn_gongji->beizhu.begin(), ParseIn_gongji->beizhu.end(), "全场")) {
					for (short i = 0; i < team_fu.size(); i++) {
						res.M.push_back(team_fu[i]);//如果有“全场”备注词条，直接将全部敌人塞进来
					}
				}
				else {//指定攻击对象
					if (team_fu.size() > 1) {
						cout << "请选择锁定的对象：";
						for (int i = 0; i < team_fu.size(); i++) {
							cout << "  " << i + 1 << "[" << team_fu[i]->name << "]";
						}
						cout << "  0[返回]" << endl;
						short zhongji_choose_enemey;
						cin >> zhongji_choose_enemey;
						if (zhongji_choose_enemey <= team_fu.size() and zhongji_choose_enemey >= 1) {
							res.M.push_back(team_fu[zhongji_choose_enemey - 1]);
						}
						else if (zhongji_choose_enemey == 0) {
							continue;
						}
						else {
							cout << "请输入有效选项对应的数字。" << endl;
							_getch();
							continue;
						}
					}
					else {
						res.M.push_back(team_fu[0]);
					}
				}
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "请选择弹幕样式。" << endl;
				for (short i = 1; i <= danmu_type.size(); i++) {
					cout << i << "[" << danmu_type[i - 1]->name << "]  ";
				}
				cout << "0[返回]" << endl;

				short yangshi_short;
				cin >> yangshi_short;

				if (not(yangshi_short > 0 and yangshi_short <= danmu_type.size())) {
					cout << "请输入有效选项对应的数字" << endl;
					_getch();
					continue;
				}

				short dis_xingdongzhi;
				short dis_power;

				if (yangshi_short > 0 and yangshi_short <= danmu_type.size()) {
					cout << "请输入弹幕数量						---- " << danmu_type[yangshi_short - 1]->danmu->xiaohao_power << "点power值 and " << danmu_type[yangshi_short - 1]->danmu->xiaohao_xingdongzhi << "点行动值 / 枚" << endl;
					int danmu_num;
					cin >> danmu_num;
					if (danmu_num <= 0) {
						break;
					}
					else {
						dis_xingdongzhi = danmu_num * danmu_type[yangshi_short - 1]->danmu->xiaohao_xingdongzhi - S->xingodngzhi_D;
						dis_power = danmu_num * danmu_type[yangshi_short - 1]->danmu->xiaohao_power - S->power_D;
						if (dis_power > 0) {
							cout << "power值不足（还差" << dis_power << "点）" << endl;
						}
						if (dis_xingdongzhi > 0) {
							cout << "行动值不足（还差" << dis_xingdongzhi << "点）" << endl;
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
					cout << "请输入有效选项对应的数字。" << endl;
					_getch();
					continue;
				}
			}
		}
	}
	else {//参数为闪避技能
		res.toubiao = ParseIn_yidong->toubiao;
		res.name_global = ParseIn_yidong->name_global;
		if (ParseIn_yidong->name_global == "闪避") {//以后“移动”还会增加单纯用于位移的技能
			vector <zhandou_yidong*> yidong_type;//将所有一级名称相符的移动形式存入临时数组

			for (short i = 0; i < S->jineng.yidong.size(); i++) {
				if (S->jineng.yidong[i]->name_global == ParseIn_yidong->name_global) {
					yidong_type.push_back(S->jineng.yidong[i]);
				}
			}

			while (true) {
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "请选择移动形式。" << endl;
				for (short i = 1; i <= yidong_type.size(); i++) {
					cout << i << "[" << yidong_type[i - 1]->name << "]  ";
				}
				cout << "0[返回]" << endl;

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
						cout << "请输入有效选项对应的数字" << endl;
						_getch();
						continue;
					}
				}

				if (binary_search(yidong_type[yangshi_short -1]->beizhu.begin(), yidong_type[yangshi_short - 1]->beizhu.end(), "专注")) {
					if (team_fu.size() > 1) {
						cout << "请选择关注的对象: ";
						for (short i = 0; i < team_fu.size(); i++) {
							cout << i + 1 << "[" << team_fu[i]->name << "]   ";
						}
						cout << "0[返回]" << endl;

						short zhongji_guanzhuduixiang;
						cin >> zhongji_guanzhuduixiang;
						if (zhongji_guanzhuduixiang <= team_fu.size() and zhongji_guanzhuduixiang >= 1) {
							res.M.push_back(team_fu[zhongji_guanzhuduixiang - 1]);
						}
						else if (zhongji_guanzhuduixiang == 0) {
							continue;
						}
						else {
							cout << "请输入有效选项对应的数字。" << endl;
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
						cout << "power值不足（还差" << dis_power << "点）" << endl;
						_getch();
						continue;
					}
					if (dis_xingdongzhi > 0) {
						cout << "行动值不足（还差" << dis_xingdongzhi << "点）" << endl;
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
					cout << "请输入有效选项对应的数字。" << endl;
					_getch();
					continue;
				}
			}
		}
		else if (ParseIn_yidong->name_global == "位移") {

		}
	}
}

void zhandoujiemian(string leixing,string diren) {
	if (nandu == "普通") {
		if (leixing == "弹幕战") {

			vector <zhandoushuju_save> fightarrey;

			int totalblood_zheng = 0;
			int totalblood_fu = 0;
			int xingdongzhi_zheng_G = 0; int xingdongzhi_zheng_D = 0;
			int xingdongzhi_fu_G = 0; int xingdongzhi_fu_D = 0;
			int powerzhi_zheng_G = 0;int powerzhi_zheng_D = 0;
			int powerzhi_fu_G = 0;int powerzhi_fu_D = 0;

			if (diren == "测试用NPC") {

				int danmu[1][3][9][7] = {0};
/***************************已废除**************************
				//属性系列注释
				danmu[0][0][0][0] = 0;//danmu_zheng_zijiju_daodan_wushuxing
				danmu[0][0][0][1] = 0;//danmu_zheng_zijiju_daodan_huo
				danmu[0][0][0][2] = 0;//danmu_zheng_zijiju_daodan_shui
				danmu[0][0][0][3] = 0;//danmu_zheng_zijiju_daodan_jin
				danmu[0][0][0][4] = 0;//danmu_zheng_zijiju_dandao_mu
				danmu[0][0][0][5] = 0;//danmu_zheng_zijiju_daodan_tu
				danmu[0][0][0][6] = 0;//danmu_zheng_zijiju_daodan_ri
				danmu[0][0][0][7] = 0;//danmu_zheng_zijiju_daodan_yue
				
				//弹幕样式注释
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

				//弹幕类型注释
				danmu[0][0][0][2] = 0;//danmu_zheng_zijiju
				danmu[0][1][0][2] = 0;//danmu_zheng_pianxiangju
				danmu[0][2][0][2] = 0;//danmu_zheng_suijidan
				danmu[0][3][0][2] = 0;//danmu_zheng_xianweidan

				//队伍注释
				danmu[0][0][0][3] = 0;//danmu_zheng
				danmu[1][0][0][3] = 0;//danmu_fu
*/
				for (int i = 0; i < _team.size(); i++) {
					totalblood_zheng = totalblood_zheng + _team[i]->tiLi_D;
					powerzhi_zheng_G = powerzhi_zheng_G + _team[i]->power_D;
					xingdongzhi_zheng_G = xingdongzhi_zheng_G + _team[i]->xingodngzhi_D;
				}

				struct _renwushuju NPC_1 = {"NPC_1", 0,1000,1000,1000,1000,0,20,20,10,10,10,10,10,10,5,5,10,10,100,100,0,10,0,50,50,0,"交接点","山脚","入口","入口",3};
				struct _renwushuju NPC_2 = {"NPC_2", 0,1000,1000,1000,1000,0,20,20,10,10,10,10,10,10,5,5,10,10,100,100,0,10,0,50,50,0,"交接点","山脚","入口","入口",3};
				vector <_renwushuju*> team_fu;
				team_fu.push_back(&NPC_1);	team_fu.push_back(&NPC_2);
				for (int i = 0; i < team_fu.size(); i++) {
					totalblood_fu = totalblood_fu + team_fu[i]->tiLi_D;
					powerzhi_fu_G = powerzhi_fu_G + team_fu[i]->power_D;
					xingdongzhi_fu_G = xingdongzhi_fu_G + team_fu[i]->xingodngzhi_D;
				}
				while (totalblood_zheng >= 0 or totalblood_fu >= 0) {
					ChongZhi("全局");
					cout << "========================================================================================================================" << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					for (int i = 0; i < _team.size(); i++) {
						color(11);
						cout << _team[i]->name << ":" << endl;
						color(7);
						cout << "体力：【" << _team[i]->tiLi_D << "/" << _team[i]->tiLi_G << "】";
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
									if (binary_search(fightarrey[o].save.yidong->beizhu.begin(), fightarrey[o].save.yidong->beizhu.end(), "全场") or binary_search(fightarrey[o].save.gongji->beizhu.begin(), fightarrey[o].save.gongji->beizhu.end(), "全场") ){
										cout << "(全场)";
									}
									else {
										//for(short j = 0;j < )
									}
								}
							}
						}
					}
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

					for (int i = 0; i < team_fu.size(); i++) {//临时从状态重置函数中搬过来的东西，记得到时候在修改那个函数的时候在这里也补一下。
						team_fu[i]->zhuangtai.clear();
					}
					for (int i = 0; i < team_fu.size(); i++) {//说白了就是我懒得用指针（）
						if (team_fu[i]->baoShiDu_D <= 50 && team_fu[i]->baoShiDu_D > 20) {
							team_fu[i]->zhuangtai.push_back("<略饿>");
						}
						if (team_fu[i]->baoShiDu_D <= 20 && team_fu[i]->baoShiDu_D > 0) {
							team_fu[i]->zhuangtai.push_back("<饥饿>");
						}
						if (team_fu[i]->baoShiDu_D == 0) {
							team_fu[i]->zhuangtai.push_back("<饥肠辘辘>");
						}
						if (team_fu[i]->jingLi_D >= (0.8 * team_fu[i]->jingLi_G) && team_fu[i]->tiLi_D >= (0.8 * team_fu[i]->tiLi_G)) {
							team_fu[i]->zhuangtai.push_back("<精神抖擞>");
						}
						if (team_fu[i]->jingLi_D < (0.1 * team_fu[i]->jingLi_G)) {
							team_fu[i]->zhuangtai.push_back("<劳累>");
						}
						if (team_fu[i]->tiLi_D < (0.5 * team_fu[i]->tiLi_G) && team_fu[i]->tiLi_D >= (0.2 * team_fu[i]->tiLi_G)) {
							team_fu[i]->zhuangtai.push_back("<虚弱>");
						}
						if (team_fu[i]->wenDu >= 75 && team_fu[i]->wenDu < 100) {
							team_fu[i]->zhuangtai.push_back("<较热>");
						}
						if (team_fu[i]->wenDu == 100) {
							team_fu[i]->zhuangtai.push_back("<高温>");
						}
						if (team_fu[i]->wenDu == 0) {
							team_fu[i]->zhuangtai.push_back("<冰冻>");
						}
						if (team_fu[i]->wenDu > 0 && team_fu[i]->wenDu <= 25) {
							team_fu[i]->zhuangtai.push_back("<较冷>");
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
						cout << "体力：【" << team_fu[i]->tiLi_D << "/" << team_fu[i]->tiLi_G << "】";
						for (int o = 0; o < team_fu[i]->zhuangtai.size(); o++) {
							cout << team_fu[i]->zhuangtai[o] << " ";
						}
						cout << endl;
					}
					cout << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "请先选择人物对象或者其他的功能选项。" << endl;
					for (int i = 0; i < _team.size(); i++) {
						cout << i + 1 << "[" << _team[i]->name << "]  ";
					}
					for (int i = 0; i < team_fu.size(); i++) {
						cout << _team.size() + i + 1 << "[" << team_fu[i]->name << "]  ";
					}
					cout << _team.size() + team_fu.size() + 1 << "[逃跑]（未开发）";
					cout << endl << endl;
					short chrater_xuanze_short; cin >> chrater_xuanze_short;
					if (chrater_xuanze_short > 0 and chrater_xuanze_short <= _team.size()) {
						string mune_xuanze_string;
						while (true) {
							cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
							cout << "已选中人物：" << _team[chrater_xuanze_short - 1]->name << endl;
							cout << "1[攻击]  2[移动]  3[掩护]  4[符卡]  5[查看]  0[返回]" << endl;
							cin >> mune_xuanze_string;
							if (mune_xuanze_string == "1") {//攻击
								bool danmuleixing_bool[4] = { false };//四种类型一一对应
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
													//不可能的事情~
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
											cout << i + 1 << "[自机狙]  ";
											break;
										case 1:
											cout << i + 1 << "[偏向狙]  ";
											break;
										case 2:
											cout << i + 1 << "[随机弹]  ";
											break;
										case 3:
											cout << i + 1 << "[限位弹]  ";
											break;
										}
									}
									cout << "0[返回]" << endl;
									cin >> zhongji3_int;
									if (zhongji3_int > 0 and zhongji3_int <= danmuleixing_xuanze.size()) {
										for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.gongji.size(); i++) {
											if (_team[chrater_xuanze_short - 1]->jineng.gongji[i]->danmu->type == danmuleixing_xuanze[zhongji3_int - 1]) {//类型已确定，带入装载函数确定形式及属性
												zhandoujiemian_xingDongZhuangZai(_team[chrater_xuanze_short - 1]->jineng.gongji[i], &NULL_yidong, fightarrey, team_fu, _team[chrater_xuanze_short - 1]);
												break;
											}
										}
									}
									else if (zhongji3_int == 0) {
										break;
									}
									else {
										cout << "请输入有效选项对应的数字" << endl;
										_getch();
										continue;
									}
								}
							}
							else if(mune_xuanze_string == "2"){//移动
								bool yidongleixing_bool[2] = { false };
								for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.yidong.size(); i++) {
									//遍历人物所持有的移动技能的种类
									bool zhongji_bool = false;
									for (short j = 0; j < 2; j++) {
										if (yidongleixing_bool[j] == false) {
											zhongji_bool = true;
										}
									}

									if (zhongji_bool) {
										for (short j = 0; j < 2; j++) {
											if (_team[chrater_xuanze_short - 1]->jineng.yidong[j]->name_global == "闪避") {
												yidongleixing_bool[0] = true;
											}
											else if (_team[chrater_xuanze_short - 1]->jineng.yidong[j]->name_global == "位移") {//以后打算加入的东西
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
											yidongleixing_choose_vector.push_back("闪避");
										}
										else if (i == 1) {
											yidongleixing_choose_vector.push_back("位移");
										}
									}
								}

								if (yidongleixing_choose_vector.size() == 0) {
									cout << "没有移动技能。" << endl;
									_getch();
									break;
								}
								else if(yidongleixing_choose_vector.size() == 1){
									cout << "已选择仅有的移动类型：" << yidongleixing_choose_vector[0] << endl;
									_getch();
									for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.yidong.size(); i++) {
										if (_team[chrater_xuanze_short - 1]->jineng.yidong[i]->name_global == yidongleixing_choose_vector[0]) {//类型已确定，带入装载函数确定形式及属性
											zhandoujiemian_xingDongZhuangZai(&NULL_gongji, _team[chrater_xuanze_short - 1]->jineng.yidong[i], fightarrey, team_fu, _team[chrater_xuanze_short - 1]);
											break;
										}
									}
								}
								else {
									cout << "请选择移动类型。" << endl;
									for (short i = 0; i < yidongleixing_choose_vector.size(); i++) {
										cout << i + 1 << "[" << yidongleixing_choose_vector[i] << "]  ";
									}
									cout << "0[返回]" << endl;

									short yidongleixing_choose_short;
									cin >> yidongleixing_choose_short;
									if (yidongleixing_choose_short == 0) {
										break;
									}
									else if(yidongleixing_choose_short > 0 and yidongleixing_choose_short <= yidongleixing_choose_vector.size()){
										for (short i = 0; i < _team[chrater_xuanze_short - 1]->jineng.yidong.size(); i++) {
											if (_team[chrater_xuanze_short - 1]->jineng.yidong[i]->name_global == yidongleixing_choose_vector[yidongleixing_choose_short - 1]) {//类型已确定，带入装载函数确定形式及属性
												zhandoujiemian_xingDongZhuangZai(&NULL_gongji, _team[chrater_xuanze_short - 1]->jineng.yidong[i], fightarrey, team_fu, _team[chrater_xuanze_short - 1]);
												break;
											}
										}
									}
									else {
										cout << "请输入有效选项对应的数字" << endl;
										_getch();
										continue;
									}
								}
							}


							/*		cout << "1[随机弹]  2[自机狙]  3[偏向狙]  0[返回]" << endl;
							//		cin >> mune_xuanze_string;
							//		if (mune_xuanze_string == "0") {
							//			break;
							//		}
							//		else if (mune_xuanze_string == "1") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "攻击";
							//			zhongji0.name = "随机弹";
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			zhongji0.left = 1;
							//			cout << "请选择弹幕样式。" << endl;
							//			cout << "1[刀弹]  2[小玉]  3[中玉]" << endl;
							//			cin >> mune_xuanze_string;
							//			if (mune_xuanze_string == "1") {
							//				cout << "请输入弹幕数量(每5枚一点power值，若不足则去掉多余的值)。		当前剩余power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "2") {
							//				cout << "请输入弹幕数量（每4枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "3") {
							//				cout << "请输入弹幕数量（每3枚一点power值，若不足则去掉多余的值）。";
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "2") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "攻击";
							//			zhongji0.name = "自机狙";
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			zhongji0.left = 1;
							//			if (team_fu.size() > 1) {
							//				cout << "请选择锁定的对象：";
							//				for (int i = 0; i < team_fu.size(); i++) {
							//					cout << "  " << i + 1 << "[" << team_fu[i]->name << "]";
							//				}
							//				cout << "  0[返回]" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short <= team_fu.size() and zhongji4_short >= 1) {
							//					zhongji0.M.push_back(team_fu[zhongji4_short - 1].name);
							//				}
							//				else if (zhongji4_short == 0) {
							//					continue;
							//				}
							//				else {
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			else {
							//				zhongji0.M.push_back(team_fu[0].name);
							//			}
							//			cout << "请选择弹幕样式。" << endl;
							//			cout << "1[刀弹]  2[小玉]  3[中玉]  4[激光弹]" << endl;
							//			cin >> mune_xuanze_string;
							//			if (mune_xuanze_string == "1") {
							//				cout << "请输入弹幕数量(每5枚一点power值，若不足则去掉多余的值)。		当前剩余power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "2") {
							//				cout << "请输入弹幕数量（每4枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "3") {
							//				cout << "请输入弹幕数量（每3枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "4") {
							//				cout << "请输入弹幕数量（每2枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "3") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "攻击";
							//			zhongji0.name = "偏向狙";
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			zhongji0.left = 1;
							//			if (team_fu.size() > 1) {
							//				cout << "请选择锁定的对象：";
							//				for (int i = 0; i < team_fu.size(); i++) {
							//					cout << "  " << i + 1 << "[" << team_fu[i]->name << "]";
							//				}
							//				cout << "  0[返回]" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short <= team_fu.size() and zhongji4_short >= 1) {
							//					zhongji0.M.push_back(team_fu[zhongji4_short - 1].name);
							//				}
							//				else if (zhongji4_short == 0) {
							//					continue;
							//				}
							//				else {
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			else {
							//				zhongji0.M.push_back(team_fu[0].name);
							//			}
							//			cout << "请选择弹幕样式。" << endl;
							//			cout << "1[刀弹]  2[鳞弹]  3[小米弹]" << endl;
							//			cin >> mune_xuanze_string;
							//			if (mune_xuanze_string == "1") {
							//				cout << "请输入弹幕数量(每5枚一点power值，若不足则去掉多余的值)。		当前剩余power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}

							//			}
							//			else if (mune_xuanze_string == "2") {
							//				cout << "请输入弹幕数量（每5枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}

							//			}
							//			else if (mune_xuanze_string == "3") {
							//				cout << "请输入弹幕数量（每8枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}

							//			}
							//		}
								}
							}
							//else if (mune_xuanze_string == "2") {//移动
							//	while (true) {
							//		cout << "已选中人物：" << _team[chrater_xuanze_short - 1].name << endl;
							//		cout << "1[微移]  2[中幅移动]  3[高速穿行]  0[返回]" << endl;
							//		cin >> mune_xuanze_string;
							//		if (mune_xuanze_string == "0") {
							//			break;
							//		}
							//		else if (mune_xuanze_string == "1") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "移动";
							//			zhongji0.name = "微移";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			cout << "请输入移动强度（3点行动值为一段）。		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
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
							//				cout << "行动值不足。" << endl;
							//				_getch();
							//				continue;
							//			}
							//			else {
							//				cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[返回]" << endl;
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
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "2") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "闪避";
							//			zhongji0.name = "中幅移动";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			cout << "请输入移动强度（5点行动值为一段）。		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
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
							//				cout << "行动值不足。" << endl;
							//				_getch();
							//				continue;
							//			}
							//			else {
							//				cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[返回]" << endl;
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
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "3") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "闪避";
							//			zhongji0.name = "高速穿行";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			cout << "请输入移动强度（7点行动值为一段）。		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
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
							//				cout << "行动值不足。" << endl;
							//				_getch();
							//				continue;
							//			}
							//			else {
							//				cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[返回]" << endl;
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
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//		}
							//	}
							//}
							//else if (mune_xuanze_string == "3") {
							//	while (true) {
							//		cout << "已选中人物：" << _team[chrater_xuanze_short - 1].name << endl;
							//		cout << "1[防御]  2[弹幕防御]  3[弹幕干扰]  4[弹幕限位]  0[返回]" << endl;
							//		cin >> mune_xuanze_string;
							//		int zhongji3_int;
							//		if (mune_xuanze_string == "0") {
							//			break;
							//		}
							//		else if (mune_xuanze_string == "1") {
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "掩护";
							//			zhongji0.name = "防御";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			short zhongji4_short;
							//			if (_team.size() > 1) {
							//				cout << "请选择掩护的对象：对己消耗3点行动值，对他消耗5点行动值。		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
							//				for (int i = 0; i < _team.size(); i++) {
							//					cout << "  " << i + 1 << "[" << _team[i].name << "]";
							//				}
							//				cout << "  0[返回]" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short <= _team.size() and zhongji4_short >= 1) {
							//					zhongji0.M.push_back(_team[zhongji4_short - 1].name);
							//					if (_team[zhongji4_short - 1].name == _team[chrater_xuanze_short - 1].name) {
							//						if (xingdongzhi_zheng_D < 5) {
							//							cout << "行动值不足。" << endl;
							//							_getch();
							//							continue;
							//						}
							//						else if(_team[chrater_xuanze_short - 1].xingdongcao.size() >= _team[chrater_xuanze_short - 1].xingdongcao_num){
							//							cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//							for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//								cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//							}
							//							cout << "	0[返回]" << endl;
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
							//								cout << "请输入有效选项对应的数字。" << endl;
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
							//							cout << "行动值不足。" << endl;
							//							_getch();
							//							continue;
							//						}
							//						else if (_team[chrater_xuanze_short - 1].xingdongcao.size() >= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//							cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//							for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//								cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//							}
							//							cout << "	0[返回]" << endl;
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
							//								cout << "请输入有效选项对应的数字。" << endl;
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
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			else {
							//				cout << "已选中自己，需消耗3点行动值，是否确认？		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
							//				cout << "0[返回]  其他数字皆为确认。" << endl;
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
							//						cout << "行动值不足。" << endl;
							//						_getch();
							//						continue;
							//					}
							//					else {
							//						cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//						for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//							cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//						}
							//						cout << "	0[返回]" << endl;
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
							//							cout << "请输入有效选项对应的数字。" << endl;
							//							_getch();
							//							continue;
							//						}
							//					}
							//				}
							//				else {
							//					continue;
							//				}
							//			}
							//			cout << "是否确认？（所需行动值：5）		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
							//			cout << "0[返回]  其他任意数字皆为确认。" << endl;
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
							//				cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[返回]" << endl;
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
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//		}
							//		else if (mune_xuanze_string == "2") {//写到的位置
							//			zhandoushuju_save zhongji0;
							//			zhongji0.toubiao = "掩护";
							//			zhongji0.name = "弹幕防御";
							//			zhongji0.left = 1;
							//			zhongji0.S.push_back(_team[chrater_xuanze_short - 1].name);
							//			short zhongji4_short;
							//			if (_team.size() > 1) {
							//				cout << "请选择掩护的对象：对己消耗3点行动值，对他消耗5点行动值。		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
							//				for (int i = 0; i < _team.size(); i++) {
							//					cout << "  " << i + 1 << "[" << _team[i].name << "]";
							//				}
							//				cout << "  0[返回]" << endl;
							//				cin >> zhongji4_short;
							//				if (zhongji4_short <= _team.size() and zhongji4_short >= 1) {
							//					zhongji0.M.push_back(_team[zhongji4_short - 1].name);
							//					if (_team[zhongji4_short - 1].name == _team[chrater_xuanze_short - 1].name) {
							//						if (xingdongzhi_zheng_D < 5) {
							//							cout << "行动值不足。" << endl;
							//							_getch();
							//							continue;
							//						}
							//						else if (_team[chrater_xuanze_short - 1].xingdongcao.size() >= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//							cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//							for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//								cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//							}
							//							cout << "	0[返回]" << endl;
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
							//								cout << "请输入有效选项对应的数字。" << endl;
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
							//							cout << "行动值不足。" << endl;
							//							_getch();
							//							continue;
							//						}
							//						else if (_team[chrater_xuanze_short - 1].xingdongcao.size() >= _team[chrater_xuanze_short - 1].xingdongcao_num) {
							//							cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//							for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//								cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//							}
							//							cout << "	0[返回]" << endl;
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
							//								cout << "请输入有效选项对应的数字。" << endl;
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
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			else {
							//				cout << "已选中自己，需消耗3点行动值，是否确认？		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
							//				cout << "0[返回]  其他数字皆为确认。" << endl;
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
							//						cout << "行动值不足。" << endl;
							//						_getch();
							//						continue;
							//					}
							//					else {
							//						cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//						for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//							cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//						}
							//						cout << "	0[返回]" << endl;
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
							//							cout << "请输入有效选项对应的数字。" << endl;
							//							_getch();
							//							continue;
							//						}
							//					}
							//				}
							//				else {
							//					continue;
							//				}
							//			}
							//			cout << "是否确认？（所需行动值：5）		当前剩余的行动值：" << xingdongzhi_zheng_D << endl;
							//			cout << "0[返回]  其他任意数字皆为确认。" << endl;
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
							//				cout << "行动槽已满，请替换其中的内容或者返回。" << endl;
							//				for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//					cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//				}
							//				cout << "	0[返回]" << endl;
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
							//					cout << "请输入有效选项对应的数字。" << endl;
							//					_getch();
							//					continue;
							//				}
							//			}
							//			cout << "请选择弹幕样式。" << endl;
							//			cout << "1[小玉]  2[小米弹]  3[激光弹]" << endl;
							//			cin >> mune_xuanze_string;
							//			if (mune_xuanze_string == "1") {
							//				cout << "请输入弹幕数量（每2枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "2") {
							//				cout << "请输入弹幕数量（每3枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
							//						_getch();
							//						continue;
							//					}
							//				}
							//			}
							//			else if (mune_xuanze_string == "3") {
							//				cout << "请输入弹幕数量（每2枚一点power值，若不足则去掉多余的值）。		当前剩余的power值：" << powerzhi_zheng_D << endl;
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
							//					cout << "power值不足。" << endl;
							//					_getch();
							//					continue;
							//				}
							//				else {
							//					cout << "行动槽已满，请替换已有的内容或者返回。" << endl;
							//					for (int i = 0; i < _team[chrater_xuanze_short - 1].xingdongcao_num; i++) {
							//						cout << "	" << i + 1 << "[" << _team[chrater_xuanze_short - 1].xingdongcao[i].name << "]";
							//					}
							//					cout << "	0[返回]" << endl;
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
							//						cout << "请输入有效选项对应的数字。" << endl;
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
								cout << "请输入有效选项对应的数字。" << endl;
								_getch();
								continue;
							}
							
							_getch();//临时断点
						}
					}
					_getch();//临时断点
				}
			}
		}
	}
}


#endif


