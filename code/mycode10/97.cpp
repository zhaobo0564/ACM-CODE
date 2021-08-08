#include<bits/stdc++.h>
using namespace std;

string s;

int work(string a) {
    int count = 0;
    for (char i: a) {
        if (i =='e' || i == 'i') {
            count++;
        }
    }
    return count ;
}

int main() {
    cin >> s;
    int res = 0, all = 0;
    int sum = 0;
    double cnt = 0.0;
    for (int i = 0; i < s.length(); i++) {
        string ans = "";
        for (int j = i; j < s.length(); j++) {
            ans += s[j];
            all = (j - i + 1);
            sum++;
            res = work(ans) ;
            cnt += (double) res / (double) all;

        }
    } 
  
    printf("%.6f\n", cnt / sum);
}