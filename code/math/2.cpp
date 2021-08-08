// 环境 ：c++11以上
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<int> Map[67];

int dp[32][26][402][602];

// begin 表示起点，end表示终点， village表示第一个村庄，village1表示第二个村长，mine 表示第二个矿山,mine1 
int day[32], end, begin, village, village1, limit, mine, mine1;

// 找到最优解的方案
void dfs(int time, int now, int wt, int fd) {
    if (time < 0) return;
     cout << "时间 = " << time << "地点 = " << now << "剩余的水 =  " << wt<< "剩余的食品 = " << fd << "剩余的金额 = " << dp[time][now][wt][fd] << endl; 
    if (now == village || now == village1) {
        for (int i = 0; i <= 400; i++) {
            for (int j = 0; j <= 600; j++) {
                if (i * 3 + j * 2 <= 1200 && wt >= i && fd >= j) {
                    if (wt == i && fd == j) continue;
                    if (dp[time][now][i][j] == dp[time][now][wt][fd] + (wt - i) * 10 + (fd - j) * 20) {
                        dfs(time, now, i, j);
                        return;
                    }
                }
            }
        }
    }

    if (now == mine || now == mine1) {
        if (day[time] == 1) {
            if ((wt + 15) * 3 + (fd + 21) * 2 <= 1200) {
                if (dp[time - 1][now][wt + 15][fd + 21] + 1000 == dp[time][now][wt][fd]) {
                    dfs(time - 1, now, wt + 15, fd + 21);
                    return;
                } else if (dp[time - 1][now][wt + 15][fd + 21] == dp[time][now][wt][fd]) {
                    dfs(time - 1, now, wt + 15, fd + 21);
                    return;
                }
            }
        } else if (day[time] == 2) {
            if ((wt + 24) * 3 + (fd + 18) * 2 <= 1200) {
                if (dp[time - 1][now][wt + 24][fd + 18] + 1000 == dp[time][now][wt][fd]) {
                    dfs(time - 1, now, wt + 24, fd + 18);
                    return;
                } else if (dp[time - 1][now][wt + 24][fd + 18] == dp[time][now][wt][fd]) {
                    dfs(time - 1, now, wt + 24, fd + 18);
                    return;
                }
            }
        } else {
            if ((wt + 30) * 3 + (fd + 30) * 2 <= 1200) {
                if (dp[time - 1][now][wt + 30][fd + 30] + 1000 == dp[time][now][wt][fd]) {
                    dfs(time - 1, now, wt + 30, fd + 30);
                    return;
                } else if (dp[time - 1][now][wt + 30][fd + 30] == dp[time][now][wt][fd]) {
                    dfs(time - 1, now, wt + 30, fd + 30);
                    return;
                }
            }
        }
    }

    for (int to: Map[now]) {
        if (day[time] == 1) {
            if ((wt + 10) * 3 + (fd + 14) * 2 <= 1200) {
                if (dp[time - 1][to][wt + 10][fd + 14] == dp[time][now][wt][fd]) {
                    dfs(time - 1, to, wt + 10, fd + 14);
                    return;
                }
            }
            

        } else if (day[time] == 2) {
            if ((wt + 16) * 3 + (fd + 12) * 2 <= 1200) {
                if (dp[time - 1][to][wt + 16][fd + 12] == dp[time][now][wt][fd]) {
                    dfs(time - 1, to, wt + 16, fd + 12);
                    return;
                }
            }
        } else {
            if ((wt + 10) * 3 + (fd + 10) * 2) {
                if (dp[time - 1][now][wt + 10][fd + 10] == dp[time][now][wt][fd]) {
                    dfs(time - 1, now, wt + 10, fd + 10);
                    return;
                }
            }
        }
    }
}

int main() {
    
    /*
    day[i] = 1, 表示日期为i的天气是晴朗（其中1表示晴朗）。
    day[i] = 2, 表示日期为i的天气是高温（其中2表示高温）。
    day[i] = 3, 表示日期为i的天气是沙暴（其中3表示沙暴）。
    */
    day[1] = 2, day[2] = 2, day[3] = 1, day[4] = 3, day[5] = 1;
    day[6] = 2, day[7] = 3, day[8] = 1, day[9] = 2, day[10] = 2;
    day[11] = 3, day[12] = 2, day[13] = 1, day[14] = 2, day[15] = 2;
    day[16] = 2, day[17] = 3, day[18] = 3, day[19] = 2, day[20] = 2;
    day[21] = 1, day[22] = 1, day[23] = 2, day[24] = 1, day[25] = 3;
    day[26] = 2, day[27] = 1, day[28] = 1, day[29] = 2, day[30] = 2;

    // 导入地图
    Map[1].push_back(2), Map[2].push_back(1);
    Map[2].push_back(3), Map[3].push_back(2);
    Map[3].push_back(4), Map[4].push_back(3);
    Map[4].push_back(5), Map[5].push_back(4);
    Map[5].push_back(6), Map[6].push_back(5);
    Map[6].push_back(7), Map[7].push_back(6);
    Map[7].push_back(8), Map[8].push_back(7); 
    Map[8].push_back(9), Map[9].push_back(8); 
    Map[9].push_back(10), Map[10].push_back(9); 
    Map[10].push_back(11), Map[11].push_back(10);
    Map[10].push_back(12), Map[12].push_back(10); 
    Map[11].push_back(13), Map[13].push_back(11); 
    ap[12].push_back(15), Map[15].push_back(12); 
    Map[13].push_back(14), Map[14].push_back(13);
    Map[14].push_back(15), Map[15].push_back(14);
    Map[11].push_back(12), Map[12].push_back(11);
    Map[1].push_back(16), Map[16].push_back(1);    
    Map[16].push_back(17), Map[17].push_back(16); 
    Map[18].push_back(17), Map[17].push_back(18);
    Map[19].push_back(18), Map[18].push_back(19);   
    Map[20].push_back(19), Map[19].push_back(20);
    Map[21].push_back(20), Map[20].push_back(21);
    Map[22].push_back(21), Map[21].push_back(22);
    Map[23].push_back(22), Map[22].push_back(23);               
    Map[11].push_back(23), Map[23].push_back(11);
    Map[13].push_back(23), Map[23].push_back(13);

    village = 9, mine = 8, village1= 13, mine1 = 11;
    for (int i = 0; i <= 31; i++) {
        for (int j = 0; j <= 24; j++) {
            for (int z = 0; z <= 400; z++) {
                for (int k = 0; k <= 600; k++) {
                    dp[i][j][z][k] = -100000000;
                
                }
            }
        }
    }
   // 算法复杂度可能较高，运行完在10分钟左右
    for (int water = 0; water <= 400; water++) {
        for (int food = 0; food <= 600; food++) {
            if (water * 3 + food * 2 <= 1200 && water * 5 + food * 10 <= 10000) {
                 dp[0][1][water][food] = max(dp[0][1][water][food], 10000 - water * 5 - food * 10);
            }
               
        }
    }
    for (int time = 1; time <= 30; time++) {
        for (int node = 2; node <= 23; node++) {
            if (node == village || node == village1) {
                  for (int to: Map[node]) {
                        for (int water = 0; water <= 400; water++) {
                            for (int food = 0; food <= 600; food++) {
                                if (day[time] == 1) {
                                    if (water * 3 + 30 + food * 2 + 28 <= 1200) {
                                        dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][to][water + 10][food + 14]);
                                       
                                    } else {
                                        break;
                                    }
                                        
                                    
                                } else if (day[time] == 2) {
                                    if (water * 3 + 48 + food * 2 + 24 <= 1200) {
                                        dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][to][water + 16][food + 12]);   
                                    } else {
                                        break;
                                    }
                                } else if (day[time] == 3) {
                                    if (water * 3 + food * 2 + 30 + 20 <= 1200) {
                                        dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][node][water + 10][food + 10]);
                                        
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                    }

                for (int water = 0; water <=400; water++) {
                    for (int food = 0; food <= 600; food++) {
                        if (water * 3 + food * 2 >= 1200) break;
                        if (dp[time][node][water][food] < 0) continue;
                        
                        for (int need_water = 0; need_water <= 400; need_water++) {
                            if (water * 3 + food * 2 + need_water * 3 >= 1200) break;
                            if (dp[time][node][water][food] - need_water * 10 < 0) continue;
                           
                            for (int need_food = 0 ; need_food <= 600; need_food++) {
                                if (water * 3 + food * 2 + need_water * 3 + need_food * 2<= 1200) {
                                    if (dp[time][node][water][food] - need_water * 10 - need_food * 20 >= 0) {
                                        dp[time][node][water + need_water][food + need_food] = max(dp[time][node][water + need_water][food + need_food], 
                                        dp[time][node][water][food] - 10 * need_water - 20 * need_food);
                                      
                                    } 
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                }



                
            }  else if (node == mine || node == mine1) {
                    
                    for (int water = 0; water <= 400; water++) {
                        for (int food = 0; food <= 600; food++) {
                            if (day[time] == 1) {
                                if (water * 3 + 15 * 3 + food * 2 + 21 * 2 <= 1200) {
                                    dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][node][water + 15][food + 21] + 1000);
                                } else {
                                    break;
                                }

                            } else if (day[time] == 2) {
                                if (water * 3 + 24 * 3 + food  * 2 + 18 * 2 <= 1200) {
                                    dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][node][water + 24][food + 18] + 1000);   
                                } else {
                                    break;
                                }
                            } else if (day[time] == 3) {
                                if (water * 3 + 30 * 3 + food * 2 + 30 * 2 <= 1200) {
                                    dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][node][water + 30][food + 30] + 1000);
                                    

                                } else {
                                    break; 
                                }
                                if (water * 3  + 10 * 3 + food * 2 + 10 * 2 <= 1200) {
                                    dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][node][water + 10][food + 10]);
                                } else {
                                    break;
                                }
                                
                            } 
                        }
                    }

                    for (int to: Map[node]) {
                        for (int water = 0; water <= 400; water++) {
                            for (int food = 0; food <= 600; food++) {
                                if (day[time] == 1) {
                                    if (water * 3 + 30 + food * 2 + 28 <= 1200) {
                                        dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][to][water + 10][food + 14]);
                                    } else {
                                        break;
                                    }
                                        
                                    
                                } else if (day[time] == 2) {
                                    if (water * 3 + 48 + food * 2 + 24 <= 1200) {
                                        dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][to][water + 16][food + 12]);   
                                    } else {
                                        break;
                                    }
                                } else if (day[time] == 3) {
                        
                                }
                            }
                        }
                    }
                } else {
                    for (int to: Map[node]) {
                        for (int water = 0; water <= 400; water++) {
                            for (int food = 0; food <= 600; food++) {
                               if (day[time] == 1) {
                                    if (water * 3 + 30 + food * 2 + 28 <= 1200) {
                                        dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][to][water + 10][food + 14]);
                                       
                                    } else {
                                        break;
                                    }
                                        
                                    
                                } else if (day[time] == 2) {
                                    if (water * 3 + 48 + food * 2 + 24 <= 1200) {
                                        dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][to][water + 16][food + 12]);   
                                    } else {
                                        break;
                                    }
                                } else if (day[time] == 3) {
                                    if (water * 3 + food * 2 + 30 + 20 <= 1200) {
                                        dp[time][node][water][food] = max(dp[time][node][water][food], dp[time - 1][node][water + 10][food + 10]);
                                        
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                    }
               }
        }
    }
    int ans = -1e9;
    for (int i = 1; i <= 30; i++) {
        for(int water = 0; water <= 400; water++) {
            for (int food = 0; food <= 600; food++) {
                if (water * 3 + food * 2 <= 1200) {
                    ans = max(ans, dp[i][15][water][food]);
                }
            }
        }
    }
    cout << "剩余的金额：" << ans << endl;
     for (int i = 1; i <= 30; i++) {
        for(int water = 0; water <= 400; water++) {
            for (int food = 0; food <= 600; food++) {
                if (water * 3 + food * 2 <= 1200) {
                    if (ans == dp[i][15][water][food]) {
                        dfs(i, 15, water, food);
                        return 0;
                    }
                }
                    
            }
        }
    }
}
