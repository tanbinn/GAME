#ifndef _KAIPIAN_H_
#define _KAIPIAN_H_
#include"jieMian.h"
using namespace std;

int jiaojiedian_shanjiao2 = 0; int jiaojiedian_shanjiao3 = 0; int jiaojiedian_shanjiao4 = 0; int jiaojiedian_shanjiao6 = 0; int jiaojiedian_shanjiao7 = 0; int jiaojiedian_shanjiao5 = 0;
int jiaojiedian_shanjiao_ruko4 = 0;//隐藏地点的判定点


//1000-->小型地图。 2000-->中型地图。 3000-->大型地图。 4000-->世界地图。
void map(int point){//初步设想，在移动界面中，通过输入不同的数字来切换不同的地图界面，这个数字最好是特殊值，如10.20.30这样的，不要与个位数数字起冲突
	ChongZhi();
	if (point == 2000) {
		if (zhuRenGong.daweizhi == "交接点") {
			if(zhuRenGong.zhongweizhi == "山脚"){
				string w2 = "2【小路1】  "; 
				string w5 = "           ";
				string w3 = "               ";
				string w6 = "               ";
				string w4 = "          "; 
				string w7 = "         ";
				if(jiaojiedian_shanjiao2 >= 1){
					w2 = "2【小路1】——"; 
					w3 = "3【苍劲的大树】";
					w4 = "4【小路2】";
				}
				if(jiaojiedian_shanjiao3 >= 1){
					w6 = "6【废弃的房屋】";
					w3 = "3【苍劲的大树】 ——";
				}
				if(jiaojiedian_shanjiao4 >= 1){
					w4 = "4【小路2】———————"; 
					w7 = "7【山路】" ;
				}
				if(jiaojiedian_shanjiao7 >= 1){
					w6 = "6【废弃的房屋】———— ";
					if(jiaojiedian_shanjiao3 == 0){
						w3 = "3【苍劲的大树】 ——" ; 
					}
				}
				if(jiaojiedian_shanjiao6 >= 1){
					w6 = "6【废弃的房屋】————";
					w7 = "7【山路】"; 
					w4 = "4【小路2】———————"; 
				}
				if (jiaojiedian_shanjiao2 > 0) {
					if ((jiaojiedian_shanjiao6 >= 1) or (jiaojiedian_shanjiao7 >= 1)) {
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "                                                                                                                        " << endl;
						cout << "                " << w3 << w6 << "                                                             " << endl;
						cout << "                        |                                   |                                                             " << endl;
						cout << "    1【入口】——" << w2 << w4 << w7 << "                                                      " << endl;
						if (jiaojiedian_shanjiao_ruko4 == 0) {
							cout << "                                                                                                                        " << endl;
							cout << "                                                                                                                        " << endl;
						}
						else {
							cout << "         |                                                                                                              " << endl;
							cout << "    5【大石块】                                                                                                         " << endl;
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
						cout << "    1【入口】——" << w2 << w4 << w7 << "                                                      " << endl;
						if (jiaojiedian_shanjiao_ruko4 == 0) {
							cout << "                                                                                                                        " << endl;
							cout << "                                                                                                                        " << endl;
						}
						else {
							cout << "         |                                                                                                              " << endl;
							cout << "    5【大石块】                                                                                                         " << endl;
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
					cout << "    1【入口】——" << w2 << w4 << w7 << "                                                      " << endl;
					if (jiaojiedian_shanjiao_ruko4 == 0) {
						cout << "                                                                                                                        " << endl;
						cout << "                                                                                                                        " << endl;
					}
					else {
						cout << "         |                                                                                                              " << endl;
						cout << "    5【大石块】                                                                                                         " << endl;
					}
					cout << "                                                                                                                        " << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					return;
				}
			  //cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			  //cout << "                                                                                                                        " << endl;
			  //cout << "                3【苍劲的大树】 ——6【废弃的房屋】————                                                             " << endl;
			  //cout << "                      |                                  |                                                              " << endl;
			  //cout << "    1【入口】——2【小路1】——4【小路2】————————7【山路】                                                        " << endl;
			  //cout << "         |                                                                                                              " << endl;
			  //cout << "    5【大石块】                                                                                                         " << endl;
			  //cout << "                                                                                                                        " << endl;
			}
		}
		
	}
	else if (point == 1000) {
		//受未知力量的影响，以后在字符串中打“\”时记得每个字符写两遍（即想要输出一个“\”，就要打两个“\”，输出两个就打四个）
		if (zhuRenGong.daweizhi == "交接点") {
			if (zhuRenGong.zhongweizhi == "山脚") {
				if (zhuRenGong.xiaoweizhi == "入口") {
					if (jiaojiedian_shanjiao_ruko4 > 0) {
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "        ///////////////////////////////////////////////////////////////////////////////////////                         " << endl;
						cout << "       ////////////////////////////////////////////////////// ________ ////////////////////                             " << endl;
						cout << "       ///////////////////////////////////////////////////// |******  | ////////////////                                " << endl;
						cout << "     /////////////////////////////////////////////////////// |________|///////////////                                  " << endl;
						cout << "        _________________________________________________________||____________                                         " << endl;
						cout << "       |                                                                                                                " << endl;
						cout << "       |                                 [2]岔口              [3]木牌          [5]小道 ————>{小路1}                      " << endl;
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
						cout << "    ///|1[入口] |\\\\  //////////     |     ||||||   |     //////////////////////                                         " << endl;
						cout << "   ////|        |\\\\\\//////////      |4[树]||||||   |     //////////////////////                                         " << endl;
						cout << "  /////|        |\\\\\\\\               |    //||||\\\\  |                                                                    " << endl;
						cout << "                                    |              |                                                                    " << endl;
						cout << "                                    |              |                                                                    " << endl;
						cout << "                                    | 6[小道]      |                                                                    " << endl;
						cout << "                                          |                                                                             " << endl;
						cout << "                                          |                                                                             " << endl;
						cout << "                                          V                                                                             " << endl;
						cout << "                                      {大石块}                                                            welcome^_^    " << endl;
					}
					else if (jiaojiedian_shanjiao_ruko4 == 0) {
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "        ///////////////////////////////////////////////////////////////////////////////////////                         " << endl;
						cout << "       ////////////////////////////////////////////////////// ________ ////////////////////                             " << endl;
						cout << "       ///////////////////////////////////////////////////// |******  | ////////////////                                " << endl;
						cout << "     /////////////////////////////////////////////////////// |________|///////////////                                  " << endl;
						cout << "        _________________________________________________________||____________                                         " << endl;
						cout << "       |                                                                                                                " << endl;
						cout << "       |                                 [2]岔口              [3]木牌          [5]小路 ————>{小路1}                      " << endl;
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
						cout << "    ///|1[入口] |\\\\  //////////     |     ||||||   |     //////////////////////                                         " << endl;
						cout << "   ////|        |\\\\\\//////////      |4[树]||||||   |     //////////////////////                                         " << endl;
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

//1000-->小型地图。 2000-->中型地图。 3000-->大型地图。 4000-->世界地图
void yidong(int point){
	ChongZhi();
	int zhongji = 0;
	if (point == 2000) {
		cout << endl << endl << endl << "方位:" << zhuRenGong.zhongweizhi << "   地点：" << zhuRenGong.xiaoweizhi << "   天气：(尚在开发中)   时间：" << month_quanju << "月" << day_quanju << "日 " << hour_quanju << ":" << min_quanju << endl;
		map(2000);
		cout << "1000[小地图] 3000[大地图] 4000[全局地图] 0[返回]" << endl;
		cout << "您目前还无法直接移动如此大范围" << endl;
		cin >> zhongji;
		if(zhuRenGong.daweizhi == "交接点"){
			if(zhuRenGong.zhongweizhi == "山脚") {
				if (zhongji == 1000 or zhongji == 3000 or zhongji == 4000) {
					return yidong(zhongji);
				}
				if (zhongji == 0) {
					return;
				}
				string kongbai;
				if (kongbai == "这里先空着，待开发出技能系统后进行“飞行”技能的判定") {
					if(zhongji == 5 && jiaojiedian_shanjiao5 > 0){
						zhuRenGong.xiaoweizhi = "大石块";
					}
					else if(zhongji == 2){
							zhuRenGong.xiaoweizhi = "小路1";
							jiaojiedian_shanjiao2 = jiaojiedian_shanjiao2 + 1;
					}
					else if(zhongji == 3 && jiaojiedian_shanjiao2 >= 1){
							zhuRenGong.xiaoweizhi = "苍劲的大树";
							jiaojiedian_shanjiao3 = jiaojiedian_shanjiao3 + 1;
					}
					else if(zhongji == 6 && ((jiaojiedian_shanjiao3 >= 1) or (jiaojiedian_shanjiao7 >= 1))){
							zhuRenGong.xiaoweizhi = "废弃的房屋";
							jiaojiedian_shanjiao6 ++;
					}
					else if(zhongji == 4 && jiaojiedian_shanjiao2 >= 1){
							zhuRenGong.xiaoweizhi = "小路2";
							jiaojiedian_shanjiao4 ++;
					}
					else if(zhongji == 7 && ((jiaojiedian_shanjiao4 >= 1) or (jiaojiedian_shanjiao6 >= 1))){
							zhuRenGong.xiaoweizhi = "山路";
							jiaojiedian_shanjiao7 ++; 
					}
					else {//这个else已经把无效的选项过滤掉了，所以可以放心编辑下面的数据
						cout << "请输入有效选项对应的数字。" << endl;
						_getch();
						return yidong(2000);
					}
					if (zhuRenGong.zhongweizhi == _renwu[0].zhongweizhi && zhuRenGong.xiaoweizhi == _renwu[0].xiaoweizhi) {
						cout << "你在原地踏步哦" << endl;
						_getch();
						return yidong(2000);
					}
					else {
						cout << "移动到了" << zhuRenGong.xiaoweizhi << "  " << zhuRenGong.weizhi;
						shiJianJieMian(20, "全局");
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
		cout << endl << endl << endl << "地点:" << zhuRenGong.xiaoweizhi << "   位置：" << zhuRenGong.weizhi << "   天气：(尚在开发中)   时间：" << month_quanju << "月" << day_quanju << "日 " << hour_quanju << ":" << min_quanju << endl;
		map(1000);
		cout << "2000[中地图] 3000[大地图] 4000[全局地图] 0[返回]" << endl;
		cout << "输入你想要前去的地方" << endl;
		cin >> zhongji;
		if (zhuRenGong.daweizhi == "交接点") {
			if (zhuRenGong.zhongweizhi == "山脚") {
				if (zhuRenGong.xiaoweizhi == "入口") {
					if (zhongji == 2000 or zhongji == 3000 or zhongji == 4000) {
						return yidong(zhongji);
					}
					else if (zhongji == 0) {
						return;
					}
					else if (zhongji == 1) {
						zhuRenGong.weizhi = "入口";
					}
					else if (zhongji == 2) {
						zhuRenGong.weizhi = "岔口";
					}
					else if (zhongji == 3) {
						zhuRenGong.weizhi = "木牌";
					}
					else if (zhongji == 5) {
						zhuRenGong.weizhi = "小道";
						zhuRenGong.zhongweizhi = "小路1";
					}
					else if (zhongji == 4) {
						zhuRenGong.weizhi = "树";
						jiaojiedian_shanjiao_ruko4 ++;
					}
					else if (zhongji == 6 && jiaojiedian_shanjiao_ruko4 > 0) {
						zhuRenGong.weizhi = "小道";
						zhuRenGong.xiaoweizhi = "大石块";
						jiaojiedian_shanjiao5 ++;
					}
					else {
						cout << "请输入有效选项对应的数字。" << endl;
						_getch();
						return yidong(1000);
					}
					if (zhuRenGong.xiaoweizhi == _renwu[0].xiaoweizhi && zhuRenGong.weizhi == _renwu[0].weizhi) {
						cout << "你在原地踏步哦" << endl;
						_getch();
						return yidong(1000);
					}
					else {
						cout << "移动到了" << zhuRenGong.weizhi;
						_getch();
						shiJianJieMian(2, "全局");
						return yidong(1000);
					}
				}
			}
		}
	}
}

#endif

//如果想计算移动时间的话，最好还是以移动次数来记（小地图范围内移动，以及中范围和大范围，以不同时间为一次来计数） 

