#include<bits/stdc++.h>
using namespace std;

set< pair<int, int> >q;
int x[300], y[300];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int gcd = __gcd(x[i] - x[j], y[i] - y[j]);
            int a = (x[i] - x[j]) / gcd;
            int b = (y[i] - y[j]) / gcd;
            q.insert({a, b});
        }
    }
    cout << q.size() << endl;
}