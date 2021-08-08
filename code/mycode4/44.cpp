#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000];
const ll mod = 1e9 + 7;

int main(){
    a[1] = 0;
    a[2] = 0;
    a[3] = 4;
    a[4] = 4;
    for(int i = 5; i <= 100; i++){
        a[i] = a[i - 2] + 4 + a[i - 2];
        a[i] %= mod;
    }
    cout << a[100] << endl;
}