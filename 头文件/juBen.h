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

std::string banjiao_quanjiao(int num)//改造过，用来把数字转换成全角的字符串形式
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
		{//是半角字符
			result += 163;//第一个字节设置为163
			result += (unsigned char)str[i] + 128;//第二个字节+128;   
		}
		else if (tmp >= 163)
		{//是全角字符   
			result += str.substr(i, 2);
			i++;
			continue;
		}
		else if (tmp == 32)
		{//处理半角空格   
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

void color(short x)	//自定义函根据参数改变颜色 
{
	if (x >= 0 && x <= 15)//参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
	else//默认的颜色白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

struct zhandou_gongji {//测试功能，主要是想利用结构体来给每种弹幕定义倍率和消耗量
	//内容可以从头写起，比如随机弹中囊括多种弹幕样式，那你可以针对每种弹幕样式写一个升级树，然后通过弹幕类型结构体进行指针形式的调用
	string toubiao;//头标
	string name_global;//概括式名称
	string name;//名称
	short leixing;//弹幕类型
	short yangshi;//弹幕样式		//实际要调用的只是样式这一层，但定义弹幕类型和头标是方便遍历（反正多写几个量又不会有多大事）
	short shuxing;//弹幕属性
	short xiaohao_power;//单位弹幕所需的power值
	short xiaohao_xingdongzhi;//单位弹幕所需要的行动值
	short shanghai_beilv;//（换算人物攻击值的）伤害倍率
	int shanghai_shuzhi;//(技能本身自带的)基础伤害
	short sudu;//基础弹速
	short level;//等级（不直接代入计算，仅做标记）
	string jiaobiao;//脚标
	vector <string> beizhu;
};

//因为要用文件流进行数据存储和调用，所以需要给每个技能定义一个头标和脚标，格式参照人物数据的读入方式
zhandou_gongji NULL_gongji = { "空白","","",0,0,0,0,0,0,0,0,0,"" };//A-1
zhandou_gongji suijidan_daodan_level1 = { "攻击","随机弹","刀弹",2,0,0,5,0,10,10,0,1,"A0l1" };//A0l1
zhandou_gongji suijidan_xiaoyu_level1 = { "攻击","随机弹","小玉",2,6,0,4,0,10,8,0,1,"A1l1" };//A1l1

struct zhandou_yidong {
	string toubiao;//头标
	string name;//名称
	short xiaohao_power;//所需的power值
	short xiaohao_xingdongzhi;//所需的行动值
	short sudu;//移动强度
	short level;//等级
	zhandou_gongji* danmu;//少数的移动形式可以边闪避边进行弹幕输出，这里是有备无患(当然，指针形式可能会出错，到时候注意一下)
	string jiaobiao;//脚标
};
//记住，技能的定义相当于常量定义，不要随便在调用时进行改动（因为套不上指针，原理和人物数据的覆盖分组是一样的）
zhandou_yidong NULL_yidong = { "空白","",0,0,0,0,NULL,"" };//B-1
zhandou_yidong weiyi_level1 = { "移动","微移",0,3,2,1,NULL,"B0l1"};//B0l1
zhandou_yidong zhongfuyidong_level1 = { "移动","中幅移动",0,5,4,1,NULL,"B1l1"};//B1	l1
zhandou_yidong gaosuchuanxing_level1 = { "移动","高速穿行",0,7,6,1,NULL,"B2l1"};//B2l1
zhandou_yidong ceshi_yidongsheji = { "移动","测试——移动射击",5,5,3,1,&suijidan_daodan_level1,"B1000" };//B1000	记得到时候把这个指针删掉（我只是为了调试一下移动时发射弹幕的功能）

struct quanju_jineng_dingyi {
	vector <zhandou_yidong> yidong;//这是一个用于存储全局的弹幕攻击类型的动态数组，载入数据需要在parsein函数中进行（对应的移动类型也是）
	vector <zhandou_gongji> gongji;//用于全局存储移动技能信息的数组
};
quanju_jineng_dingyi quanju_jineng;//谨慎调用及修改，里边可不是指针

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

struct _renwushuju {//用于定义人物数据的结构体
//人物数据
	string name;
	bool panduan_duiwu;
	int tiLi_D;
	int tiLi_G;
	int jingLi_D;
	int jingLi_G;
	int jingYan;
	int liLiang_D;
	int liLiang_G;//游戏中再设置一个“负重”概念，一点力量对应一点负重
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

	//——————————————————————————————————————
	//道具还是分这几种吧：钱币（泛指用于交易的货币）、素材和道具（两者没有明显界定，道具本身也可以成为素材，主要是把基础素材区分出来）、符卡、配方
	int huobi_money;//钱
	//（标头是用于后期添置新数据时进行辅助区分的）
	//素材标头为0
	int sucai_shuzhi;//0 1 树枝 0.2
	int sucai_muchai;//0 2 木柴 0.5
	int sucai_gancao;//0 3 干草 0.1
	int sucai_shitou;//0 4 石头 0.5
	int sucai_mogu;//0 5 蘑菇 0.1
	int sucai_yecai;//0 6 野菜 0.2
	int sucai_yegu;//0 7 野谷 0.1

	//道具标头为1
	int daoju_pingguo;//1 1 苹果 0.5
	int daoju_li;//1 2 梨 0.5
	int daoju_suishi;//1 3 燧石 0.5
	int daoju_shui;//1 4 水 0.5
	int daoju_yinghuo;//1 5  营火 2

	//符卡标头为2
	int fuka_kongbai;//2 1 空白符卡 1
	int fuka_qiluruo_weiding;//2 2 （标准符卡格式）1

	//配方标头为3
	int peifang_yinghuo;//3 1 营火（配方）


	quanju_jineng_dingyi jineng;
};

string zhangJie;
string nandu;

int year_quanju = 0; int hour_quanju = 8; int min_quanju = 30; int day_quanju = 20; int month_quanju = 11;//这行为时间的全局变量 
int year_tianqi = 0; int hour_tianqi = 9; int min_tianqi = 30; int day_tianqi = 20; int month_tianqi = 11; bool panduan_tianqi = false;//用于天气函数来判定时间间隔 

string tianqi_jiaojiedian;

string kongBai_shuju[30];
string kongbai_daoju[16];
string kongbai_jineng[7];
vector <_renwushuju> _renwu;
vector <_renwushuju> _team;
_renwushuju siJi;_renwushuju zhuRenGong;
string _NAME = "我";


void shiJianJieMian(int jiaFen, string gongneng) {//注意：时间函数已移植
	if (gongneng == "全局") {
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
	if (gongneng == "重置天气") {
		int kaiFen = hour_quanju * 60 + min_quanju;//注意，这里我将起始时间换做全局时间 
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
	if (gongneng == "剧情") {
		if (zhangJie == "开篇") {
			if (bianhao == 1) {
				cout << "请输入您的名字" << endl;
				cin >> _NAME;
				cout << _NAME << "是吗？那好，我们开始吧！" << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "..." << endl << ".." << endl << "." << endl;
				_getch();
				cout << "“真无聊啊．．．”," << _NAME << "深深地打了个哈欠:“真是的，这才休假没多久，又要叫我去做任务了。”" << endl;
				_getch();
				cout << "话说回来，上次坐车还是什么时候来着？似乎是十几年前的事了。" << endl;
				_getch();
				cout << "自从那位大人带来新科技后，整个世界都变了样。城市只需一晚上便全面翻新，没了街道，没了电线，留下的只是一座座宏伟的高楼大厦，土地利用率大大提高。即便在万里开外，物资传输依靠传送门便可在眨眼间解决。" << endl;
				_getch();
				cout << "工厂进行了全面翻新，无论是原料还是能源都被最大化利用，污染也是被降低至微乎其微。说到能源，成熟可控的核聚变技术几乎冲击所有的传统发电厂.通过这个技术，只需要一水库的水，便可供给全球一年的所有能耗。" << endl;
				_getch();
				cout << "拥有了近乎用之不尽的资源，国家之间失去了争斗的必要。在那位大人的劝说下，很多国家放下过去的恩怨，尝试发展友好的关系。虽然偶尔也有争论声，但也总是在大人的调解下平息了。" << endl;
				_getch();
				cout << "仅仅过了一年，过去的影子便消失得无影无踪，有的只是新科技的产物。又过了几年，警察局失去了设立的意义，甚至有的国家带头销毁所有的武器。" << endl;
				_getch();
				cout << "没有邪恶，没有争端，留下的只有和平。" << endl;
				_getch();
				cout << "“我的心也被改造了吧……”" << endl;
				_getch();
				cout << "起初确实有这么想过，但很快，这种想法确乎发生了。" << endl;
				_getch();
				cout << "“我前往异世界，想帮助我们的邻居脱离落后悲惨的原始环境。在与对方交谈多次后，她们非但不领情，反而将我赶了出来，扬言要断绝与我们的联系。”" << endl;
				_getch();
				cout << "“我们大可不必热脸去贴冷屁股，但我知道，在座的各位肯定不忍心看到我们的邻居仅仅是为了基本的生存而无时无刻冒着生命危险。他们虽然对我们不感冒，但那也只是因为他们的思想过于迂腐。”" << endl;
				_getch();
				cout << "“伙伴们，我们得把他们从深渊中拯救出来！即使起初会有诸多不愉快的经历，但一切的最后，他们一定会懂得我们的良苦用心，和我们一起加入致力于世界大同的行列中来……”" << endl;
				_getch();
				cout << "那位大人这么说了后，得到了各国的支持。在一夜之间，许许多多的新式武器被造了出来。坐在营后，动动手指，完全机械化的钢铁军队便涌入其中，仿佛可以碾压一切。" << endl;
				_getch();
				cout << "奇怪的是，钢铁大军不但没能攻下对方，而且对面的防御越来越牢固了。" << endl;
				_getch();
				cout << "“他们在使用魔法！这种毫无依据和逻辑可言的东西，如果让其传播开来，将会毁掉我们一直以来的所有成果！伙伴们，他们的思想已经迂腐到无可救药了，他们的命运已经无法为我们所挽回了。";
				cout << "为了多数人的未来，我们不得不牺牲少数人的利益，让我们把新的灾难扼杀在摇篮里吧！”" << endl;
				_getch();
				cout << "于是乎，全球的人们空前地团结在一起，为了守护自己的家园而战。" << endl;
				_getch();
				cout << "但至于" << _NAME << "是怎么到这里来的，事实上，他自己也不清楚了。记忆在被军队征用时出现断层，余下的便是不断地训练，被命令，被指示去完成特殊任务的记忆了。" << endl;
				_getch();
				cout << "而现在" << _NAME << "所要去的地方，甚至连传送门都无法设置，只能靠传统的汽车抵达。" << endl;
				cout << "不甘心地检视了一圈，" << _NAME << "想从这运输车上找到哪怕一条缝隙。" << endl << "很可惜，车上密封得像罐头一样。除了那小到可怜的排气扇，唯一感受到的估计只有汽车的轰鸣声了。" << endl;
				_getch();
				cout << "“我们已经临近计划的最后阶段，得趁大人打开的空间裂缝被他们察觉前控制那个地方。不然的话，我们前面所做的一切都会是徒劳。”听到" << _NAME << "的抱怨，司机洪亮的声音从车前传了过来。" << endl;
				_getch();
				cout << "“就是因为这样，" << _NAME << "才会觉得不安啊......”" << _NAME << "凝视着眼前这双伤痕累累的手掌，叹道：“妖精、妖怪、神明、仙人，连不少普通人都掌握神秘的力量……报告上所提供的信息令人匪夷所思，何况我将要独自面对这一切……”" << endl;
				_getch();
				cout << "迄今为止，我本应该死过多少回了呢？见识无数的家破人亡，牺牲难以胜数的同胞，而这一回恐怕是凶多吉少吧……想到这，" << _NAME << "忍不住将脸埋进那双手中." << endl;
				_getch();
				cout << "沉默片刻后，司机无奈的声音透了过来：“没办法，为了保证隐秘性，空间裂缝只能容纳一个人进去。你的任务也只是去侦察一番，获取尽可能多的情报就行。记住，在大军突入前，你获取的每一个情报都会影响无数人的生死。”" << endl;
				_getch();
				cout << "现实与幻想的决斗吗？没办法呢。" << endl;
				_getch();
				cout << "想象着届时的遭遇，" << _NAME << "不知不觉睡着了。" << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
				_getch();
				cout << "..." << endl << ".." << endl << "." << endl;
				_getch();
				cout << "“到了，快下来吧！”车门被打开了。" << _NAME << "揉了揉双眼，打着哈欠下了车。" << endl;
				_getch();
				cout << "面前的这位女子，有着一头金色的长发，在阳光下反射出耀眼的光辉。标致的脸蛋上，一双深邃的双眼镶嵌在雪白的肌肤中，散发着慑人的红色。身材笔挺高挑，着装者一套用料考究的黑西服，颇为英气。腰间别有配枪。看不出型号，估计是很少见的特制装备。" << endl;
				_getch();
				cout << "虽然车内有亮度不低的LED灯，但一来到外面，" << _NAME << "还是被阳光照射得下意识半遮着眼。" << endl;
				_getch();
				cout << "“咦，这是……”" << _NAME << "稍微适应一点后，首先映入眼帘的，是前方一栋栋高耸入云，却早已被废弃的楼房。" << endl;
				_getch();
				cout << "没有生机，没有阳光，甚至连色彩都没有，残破不堪的城市似乎把空气都染上了死气沉沉的灰色。只有单调的风声在一旁佐证着他们的存在。" << endl;
				_getch();
				cout << "因转型失败而被遗弃的城市吗？" << _NAME << "托着下巴，细细地审视着：“如今这种地方已经不多见了。托那位大人的福，几乎所有的地方都完成了现代化改造。这么说来，此处被遗弃的原因是……”" << endl;
				_getch();
				cout << "“没错，就是因为那个地方。”停顿了一下，司机继续说道：“这附近的空间线非常扭曲，无法利用新科技的空间技术对这个城市进行转型。可惜了呀，多么好的区位和环境啊……虽说资源少了点，但如果进行完善的改造，综合指标肯定不输于那些大城市呀……”" << endl;
				_getch();
				cout << "话是这么说，但从她的语气里可完全没听出来惋惜的意思。" << endl;
				_getch();
				cout << "“很不理解我为什么会这么说吧？”，察觉到" << _NAME << "的视线，司机说道；“那就请转个身吧。”" << endl;
				_getch();
				cout << "转身？" << _NAME << "虽然有些不解，但还是怀着期待缓慢地转了过去……" << endl;
				_getch();
				cout << "起初仍旧是单调的灰色，随着转动幅度的加大，一抹夺目的绿色出现在眼角，让" << _NAME << "不由得惊呼了一声。" << endl;
				_getch();
				cout << "又转动了一点，略显暗淡的蓝色被涂抹在视野上方，而下方出现了纯洁的淡黄色。一道淡淡的痕迹在远方若隐若现，仿佛连接到天边。" << endl;
				_getch();
				cout << "最后一点。蔚蓝的天空上精心地点缀着几朵白里透黄的云朵。一座高山，披着深绿色的外衣，稳重地在那边托举着天地。一片平原，青草在阳光的照射下交相辉映，树木和草丛在微风的吹拂下同大自然一同呼吸。一条小河，像一条银色的缎带，伴随着汩汩的声音带来无限的生命……" << endl;
				_getch();
				cout << "迎着折射出七彩色的太阳光晕，抚摸着柔和的清风," << _NAME << "呆呆地凝视着眼前幻想般的美景，一时之间居然震惊得说不出话。" << endl;
				_getch();
				cout << "那是最纯粹的自然风光，没有任何人类活动的痕迹。" << endl;
				_getch();
				cout << "“很可惜啊……”" << _NAME << "笑着说道；“我不懂文学，完全没法描述我所看到的东西啊。”" << endl;
				_getch();
				cout << "仿佛连心灵都被淘洗了一番。" << endl;
				_getch();
				cout << "仿佛是幻想一般的地方。" << endl;
				_getch();
				cout << "“像做梦一样吧？”司机欣慰地说道；“我到过很多顶级公园，也深入过不少自然保护区，当我第一次来到这片区域时，我便明白，这地方已经自然得近乎不自然了。”" << endl;
				_getch();
				cout << "“这么说，我将要前往的地方就在那里？”" << _NAME << "说道。至少从面前的景象来看，那地方确实是挺原始的" << endl;
				_getch();
				cout << "“说对了一半，但你真正的目的地还远着，那里只是个入口而已。走吧，我们还有任务在身呢。”司机在前边带头，向着那座大山走了过去。" << endl;
				_getch();
				cout << "在走之前，" << _NAME << "又环视了一圈。这片区域像是被刻意划分出来的，仅仅是隔一条河流，就是两个截然不同的世界。";
				cout << "再向远方望去，那片区域的周围同样是被灰色的建筑群环绕起来。" << endl;
				_getch();
				cout << "再远一点就看不到了。" << endl;
				_getch();
				cout << "心中有数后，" << _NAME << "快步跟了上去。" << endl;
				_getch();
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "..." << endl;
				_getch();
				cout << ".." << endl;
				_getch();
				cout << "." << endl;
				_getch();
				cout << "起初在远方望去，这里像是一片原始区域。但事实上，走进之后便能发现，有少数地方已经被初步探索过了，地上的小路和标识的木牌可以证明这一点。" << endl;
				_getch();
				cout << "“在很久以前，这里本来有一片规模不小的村庄，结果随着时代发展，很多人都向外地迁走，就算是对此地留念不已的人也搬到附近的城镇，使得此地逐渐没落了。”";
				cout << "司机一边在前面带路，一边饶有兴致地说道；“当这个地方重新被人所关注时，此地早已回归自然本色了。有人来探索这地方，结果发现，在这片区域不仅用不了指南针、GPS，甚至连卫星拍摄都模糊得完全无法辨认。”" << endl << endl;
				_getch();
				cout << "“听起来像都市传说般不可思议啊。”" << endl;
				_getch();
				cout << "“嘿，那可不。但这还不是最可怕的。平原区域还好说，做个标记，遥望一下建筑群，好歹可以确定个方向，但一进入那座大山，呵呵……”司机故意停顿了下来。像是为了配合渲染气氛一般，从山的方向那边传出一阵诡异的声响，沉闷、压抑，又不太像是什么动物的声音。" << endl;
				_getch();
				cout << "“大风吹过山谷的声音吧……”虽然心中有底，但" << _NAME << "还是被吓得哆嗦了一下，略带埋怨但不失好奇地说道；“你还真适合去讲恐怖故事啊。那之后呢，山中有什么奇怪的东西吗？”" << endl;
				_getch();
				cout << "“哈哈，谢谢你的赞赏，”司机爽朗地笑了几声后，突然靠近过来，用神秘的语气说道；“山中当然没有奇怪的东西——毕竟前去探索的人一个都没有回来，谁又会知道呢？”" << endl;
				_getch();
				cout << "……似乎有点明白为什么这附近的城市被遗弃了。" << endl;
				_getch();
				cout << "“人虽然没找着，但毕竟是探索队，他们每隔一段距离便会留下一节储存卡。从较外围回收到的储存卡来看，他们虽然没遇上什么危险，但无一例外都在其中迷了路，而且他们还都反复强调自己看见了什么莫名的东西，常常是还没看清就消失得无影无踪了。”" << endl;
				_getch();
				cout << "“原来如此。是他们捣的鬼吗？”" << _NAME << "听到这番话后，不由得有些生气；“呵，还真是一群领土意识高于一切的守旧者呢。”" << endl << endl;
				_getch();
				cout << "“这么早就下定论未免也太着急了，毕竟世界上这样的灵异事件并不少——至少在看到那个地方前我是这么想的。”" << _NAME << "能明显听出来司机语气中的不满了。" << endl;
				_getch();
				cout << "“不过那也是后面的事情了，”司机紧接着叙述道：“至少在当时，得知传闻的人们唯恐避之不及，纷纷撤到距离山区一大段的地方——这也就成为了你刚刚所看见的格局。不过，就当时的污染控制水平来看，这地方的风景真的是稀世难得";
				cout << "。于是，等风头一过，很多人过来抢购周边的套房，让这里成为全国最有名的高端住宅区之一。当然，无论房价被炒得多高，也没有哪个房产商敢往内再迈一步的。最后，也就是你刚刚所看到的情景，仅仅也是新科技普及后这些年的成果罢了。”" << endl << endl;
				_getch();
				cout << "挺有意思啊。" << endl;
				_getch();
				cout << _NAME << "点点头，随后问道；“这地方的情况我大概清楚了。所以说，我们接下来要上山？”" << endl;
				_getch();
				cout << "司机点点头，答道：“那是当然。而且，是进入山区深处。不过你不必担心，这片区域不久前已有专人探索过，我们直接顺着这条路走下去就行了。”" << endl;
				_getch();
				cout << "“这样啊……”" << _NAME << "抬头望了一眼山头，大概的估算一下距离后，叹道；“看起来还有一段不小的距离啊……”" << endl;
				_getch();
				cout << "“好好珍惜一下你在现世界的时光吧，”司机打趣道；“指不定这会是你最后的机会哦~”" << endl << endl;
				_getch();
				cout << "“咳！请别开这种玩笑。我虽然没指望能活着回来，但也不希望真的交代在那儿了。”" << _NAME << "愁苦着脸地说道，突然发现司机在掩着嘴发笑。" << endl;
				_getch();
				cout << "“喂！你这家伙……”" << _NAME << "大步走到司机面前，生气地想与之对线，结果她随意地拨开了" << _NAME << "伸过来的手，主动低下头道歉道；“不好意思啦,看你这么可爱，我便忍不住想要捉弄你一下，没想到你比我想象中还要没心眼呢。”" << endl;
				_getch();
				cout << "真是一点道歉的意思都没有……" << _NAME << "无奈地摇摇头，说道；“真是拿你没办法。”" << endl;
				_getch();
				cout << "“好了好了，不说这个了。你看，我们已经到了入口了。”";
			}
		}

	}
	else if (gongneng == "口上") {

	}
	else if (gongneng == "环境") {

	}
}

void ZhangJie0() {
	//	JuBen("剧情",1);
}

#endif


//基础世界观上，我这样想的，主世界即主人公所在的世界，其中包括现在的幻想乡， 但剧情中主人公将要攻占的是过去的幻想乡。
//在动机上，首先黑幕是月都的那批人，他们打算脱离赫卡的控制，方法是利用超现代的空间技术切断赫卡与地球、月球、地狱的联系。
//月球和地球已被控制，想前往地狱，即需要通过幻想乡进入。很可惜，现实的幻想乡原住民顽强抵抗，外人根本打不进去。
//于是月之民利用空间技术，在长野县强行打开一个时空裂缝，通往过去的幻想乡。打击过去的幻想乡可以直接 影响现在的幻想乡，但需要主人公进行必要的侦察。
//开头主人公所了解到的信息只是需要他渗透进敌方，并不知道自己进行了一场时间旅行，这是重点。 


