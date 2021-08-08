// 环境 ：c++11以上
#include<bits/stdc++.h>
using namespace std;



int main() {
    srand(time(0));
    int x, y, x1, y1, x2, y2;
    x = x1 = x2 = 1;
    y = y1 = y2 = 1;
    int sum = 0, sum1 = 0, sum2 = 0, count = 0;
    for (int t = 1; t <= 1000; t++) {

        int water = 0, food = 0, water1 = 0, food1 = 0, water2 = 0, food2 = 0, money = 10000, money1 = 10000, money2 = 10000;
        int day = 20;
        while (day--) {
            int weather = rand() % 100;
            if (0 <= weather && weather <= 39) {
                if (x == 5) {
                    y++;
                } else if (y == 5) {
                    x++;
                } else {
                    int op = rand() % 2;
                    if (op == 0) {
                         x += 1;
                    } else {
                        y += 1;
                    }
                }
                if (x1 == 5) {
                    y1++;
                } else if (y1 == 5) {
                    x1++;
                } else {
                    int op1 = rand() % 2;
                    if (op1 == 0) {
                        x1 += 1;
                    } else {
                        y1 += 1;
                    }

                }
                if (x2 == 5) {
                    y2++;
                } else if (y2 == 5) {
                    x2++;
                } else {
                    int op2 = rand() % 2;
                
                    
                    if (op2 == 0) {
                        x2 += 1;
                    } else {
                        y2 += 1;
                    }
                }
                
                
            
                if (x == x1 && y == y1 && x == x2 && y == y2) {
                    water += 18;
                    food += 24;
                    water1 += 18;
                    food1 += 24;
                    water2 += 18;
                    food2 += 18;
                } else if (x == x1 && y == y1 ) {
                    water += 12;
                    food += 16;
                    water1 += 12;
                    food1 += 16;
                    water2 += 6;
                    food2 += 8;
                } else if (x == x2 && y == y2) {
                    water += 12;
                    food += 16;
                    water += 6;
                    food += 8;
                    water2 += 12;
                    food2 += 16;
                } else {
                    water += 6;
                    food += 8;
                    water1 += 6;
                    food1 += 8;
                    water2 += 6;
                    food2 += 8;
                }


            } else if (weather > 39 &&  weather < 90) {
                if (x == 5) {
                    y++;
                } else if (y == 5) {
                    x++;
                } else {
                    int op = rand() % 2;
                    if (op == 0) {
                    x += 1;
                    } else {
                        y += 1;
                    }
                }
                if (x1 == 5) {
                    y1++;
                } else if (y1 == 5) {
                    x1++;
                } else {
                    int op1 = rand() % 2;
                    if (op1 == 0) {
                        x1 += 1;
                    } else {
                        y1 += 1;
                    }

                }
                if (x2 == 5) {
                    y2++;
                } else if (y2 == 5) {
                    x2++;
                } else {
                    int op2 = rand() % 2;
                
                    
                    if (op2 == 0) {
                        x2 += 1;
                    } else {
                        y2 += 1;
                    }
                }
                
                if (x == x1 && y == y1 && x == x2 && y == y2) {
                    water += 54;
                    food += 54;
                    water1 += 54;
                    food1 += 54;
                    water2 += 54;
                    food2 += 54;
                } else if (x == x1 && y == y1 ) {
                    water += 36;
                    food += 36;
                    water1 += 36;
                    food1 += 36;
                    water2 += 18;
                    food2 += 18;
                } else if (x == x2 && y == y2) {
                    water += 36;
                    food += 36;
                    water += 18;
                    food += 18;
                    water2 += 36;
                    food2 += 36;
                } else {
                    water += 18;
                    food += 18;
                    water1 += 18;
                    food1 += 18;
                    water2 += 18;
                    food2 += 18;
                }

            } else {
                
                if (x == x1 && y == y1 && x == x2 && y == y2) {
                    water += 30;
                    food += 30;
                    water1 += 30;
                    food1 += 30;
                    water2 += 30;
                    food2 += 30;
                } else if (x == x1 && y == y1 ) {
                    water += 20;
                    food += 20;
                    water1 += 20;
                    food1 += 20;
                    water2 += 10;
                    food2 += 10;
                } else if (x == x2 && y == y2) {
                    water += 20;
                    food += 20;
                    water += 10;
                    food += 10;
                    water2 += 20;
                    food2 += 20;
                } else {
                    water += 10;
                    food += 10;
                    water1 += 10;
                    food1 += 10;
                    water2 += 10;
                    food2 += 10;
                }
            }
    
            if (x == 5 && y == 5 && x1 == 5 && y1 == 5 && x2 == 5 && y2 == 5) {
                money -= (water * 5 + food * 10);
                money1 -= (water1 * 5 + food1 * 10);
                money2 -= (water2 * 5 + food2 * 10);
                sum += money;
                sum1 += money1;
                sum2 += money2;
                count++;
                break;
            }
            
        
        }
    }
    cout << (double)sum / (double)count << " " << (double)sum1 / (double)count << " " << (double)sum2 / (double)count << endl;

}