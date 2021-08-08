// c++ 11 以上
#include<bits/stdc++.h>

using namespace std;

int day[20];

int main() {
    srand(time(0));
    int sum = 0, sum1 = 0, sum2 = 0;
    for (int t = 1; t <= 10000; t++) {

    
        for (int i = 1; i <= 30; i++) {         // 随机出十天的天气
            int weather = rand() % 100;
            if (weather >= 0 && weather < 49) {
                day[i] = 0;                     // 晴朗
            } else if (weather >= 49 && weather < 90) {
                day[i] = 1;                     // 高温
            } else {
                day[i] = 2;                     // 沙暴
            }
        }
   
        int count = 8;
        int water = 0, food = 0, water1 = 0, food1 =0, water2 = 0, food2 = 0;
        for (int i = 1; i <= 8; i++) {
            if (day[i] == 3) {
                count++;
                water += 10;
                food += 10;
                water1 += 10;
                food1 += 10;
                water2 += 10;
                food2 += 10;
            } else if (day[i] == 1) {
                water += 18;
                food += 18;
                water1 += 18;
                food1 += 18;
                water2 += 18;
                food2 += 18;
            } else {
                water += 6;
                food += 8;
                water1 += 6;
                food1 += 8;
                water2 += 6;
                food2 += 8;
            }
        }
  
        sum += 10000 - (water * 5 + food * 10);
        sum1 += 10000 - (water1 * 5 + food1 * 10);
        sum2 += 10000 - (water2 * 5 + food2 * 10);
    }
    cout << (double)sum / 10000.0 << " " << (double)sum1 / 10000.0 << " " << (double)sum2 / 10000.0 << endl;

}