#include<bits/stdc++.h>
using namespace std;
int su = 0, cnt = 0;

void dfs(int sum, int p) {
    if (p <= 10) {
        su += sum;
        cnt++;
        return;
    }

    for (int i = 1; i <= p; i++) {
        dfs(sum + 1, p - i);
    }

}

int main() {
    
    dfs(0, 20);
    cout << su << " " << cnt << endl;

    cout << (double) su / (double) cnt << endl;
}