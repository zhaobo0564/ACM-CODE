#include<bits/stdc++.h>
using namespace std;
int n, k, t;
const int N = 5e6 + 7;
  
int a[N];
  
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}

unordered_map<int, int>q;
  
int main(){
    t = read();
    while(t--){
        n = read();
        k = read();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            q[a[i]]++;
        }
        
    }
}