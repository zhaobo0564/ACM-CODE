// 环境 ：c++11以上
#include<bits/stdc++.h>

using namespace std;
vector<int> Map[20];
int vis[1000000];

struct node {
    int water, food, money;
    int fine, high, go, stay, mining, day;

};

vector<node> ans;

bool cmp(node x, node y) {
    return x.money > y.money;
}

int main() {

    srand(time(0));

    int time = 10000000;                 // 随机走1000000次。
    Map[1].push_back(4);
    Map[3].push_back(9);
    Map[9].push_back(11);
    Map[11].push_back(13);
    Map[6].push_back(13);
    while (time--) {
        int now = 1;
        int need_water = 0, need_food = 0, money = 10000, day = 0;
        int fi = 0, hi = 0, g = 0, st = 0, mi = 0, f = 0;
        while (now != 13) {             // 到达终点
            day++;
            int weather = rand() % 2;
            
            if (weather == 0) {         // 晴天
                fi++;
                if (now == 4) {         // 随机走3号点或6号点
                    int go = rand() % 3;
                    if (go == 0) {      // 走3号点
                        g++;
                        now = 3;
                        need_water += 6;
                        need_food += 8;
                
                    } else if (go == 1){      // 走7号点
                        g++;
                        now = 6;
                        need_water += 6;
                        need_food += 8;
                        
                    } else {                // 停留
                        st++;
                        need_water += 3;
                        need_food += 4;
                    }
                } else if (now == 9){   // 到达矿山
                    int option = rand() % 3;
                    if (option == 0) {          // 行走
                        g++;
                        now = Map[now][0];
                        need_water += 6;
                        need_food += 8;

                    } else if (option == 1) {   // 停留
                        st++;
                        need_water += 3;
                        need_food += 4;
                        f = 1;
                    } else {                    // 挖矿
                        if (f) {                // 第二天可以挖矿
                            mi++;
                            need_water += 9;
                            need_food += 12;
                            money += 200;
                        } else {
                            st++;
                            need_water += 3;
                            need_food += 4;
                            f = 1;
                        }
                        
                    }
                } else {
                    
                    int option = rand() % 2;
                    if (option == 0) {          // 行走
                        g++;
                        now = Map[now][0];
                        need_water += 6;
                        need_food += 8;

                    } else {                    // 停留
                        st++;
                        need_water += 3;
                        need_food += 4;
                    }
                }
            } else {
                hi++;
                if (now == 4) {                     // 随机走3号点或6号点或停留
                    int go = rand() % 3;
                    if (go == 0) {                  // 走3号点
                        g++;
                        now = 3;
                        need_water += 18;
                        need_food += 18;
                    } else if (go == 1){            // 走6号点
                        g++;
                        now = 6;
                        need_water += 18;
                        need_food += 18;
                    } else {                        // 停留
                        st++;
                        need_water += 9;
                        need_food += 9;
                    }
                } else if (now == 9){   // 到达矿山
                    int option = rand() % 3;
                    if (option == 0) {          // 行走
                        g++;
                        now = Map[now][0];
                        need_water += 18;
                        need_food += 18;
                    } else if (option == 1) {   // 停留
                        st++;
                        need_water += 9;
                        need_food += 9;
                        f = 1;
                    } else {                    // 挖矿
                        if (f) {                // 停留之后才可以挖矿
                            mi++;
                            need_water += 27;
                            need_food += 27;
                            money += 200;
                        } else {
                            st++;
                            need_water += 9;
                            need_food += 9;
                        }
                    }
                } else {
                    int option = rand() % 2;
                    if (option == 0) {          // 行走
                        g++;
                        now = Map[now][0];
                        need_water += 18;
                        need_food += 18;
                    } else {                    // 停留
                        st++;
                        need_water += 9;
                        need_food +=9;
                    }
                }
            }
            if (need_water * 3 + need_food * 2 > 1200) {
                break;
            }
            if (need_water * 5 + need_food * 10 > 10000) {
                break;
            }
            if (day >= 10) break;
        }
         if (now == 13 &&need_water * 3 + need_food * 2 <= 1200 && need_water * 5 + need_food * 10 <= 10000) {
            node cd;
            cd.water = need_water;
            cd.food = need_food;
            cd.money = money - need_water * 5 - need_food * 10;
            cd.day = day;
            cd.fine = fi;
            cd.go = g;
            cd.high = hi;
            cd.mining = mi;
            cd.stay = st;
            if (vis[cd.money]) continue;
            ans.push_back(cd);
             vis[cd.money] = 1;
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    int cnt = 0;
    for (int i = 0; i < ans.size(); i++) {
        
            cout << "食物：" << ans[i].food << " 水：" << ans[i].water << " 天数：" << ans[i].day << " 晴天："  << ans[i].fine << " 高温："<< ans[i].high  << endl;
            cout << "走：" << ans[i].go << " 停:" << ans[i].stay << " 挖：" << ans[i].mining << " 钱：" << ans[i].money <<  endl << endl;
        
        if (cnt == 100) break;
    } 


}