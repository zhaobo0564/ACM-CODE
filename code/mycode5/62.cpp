#include<bits/stdc++.h>
using namespace std;

long long s;
int up[20];

int work(long long x) {
    int ans = 0;
    while(x) {
        ans += x% 10;
        x = x / 10;
    }
    return ans;
}

int main() {
    cin >> s;
    cout << s%9 << endl;
    // for (int j = 1; j <= 100; j++) {2
    //     s = j;
        for (int i = 1; i <= 1000; i++) {
        s = work(s);
    //}
   
    } cout << s << endl;
   
    

}