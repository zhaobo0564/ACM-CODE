#include<bits/stdc++.h>
using namespace std;

namespace GenHelper
{
    unsigned z1,z2,z3,z4,b,u;
    unsigned get()
    {
        b=((z1<<6)^z1)>>13;
        z1=((z1&4294967294U)<<18)^b;
        b=((z2<<2)^z2)>>27;
        z2=((z2&4294967288U)<<2)^b;
        b=((z3<<13)^z3)>>21;
        z3=((z3&4294967280U)<<7)^b;
        b=((z4<<3)^z4)>>12;
        z4=((z4&4294967168U)<<13)^b;
        return (z1^z2^z3^z4);
    }
    bool read() {
      while (!u) u = get();
      bool res = u & 1;
      u >>= 1; return res;
    }
    void srand(int x)
    {
        z1=x;
        z2=(~x)^0x233333333U;
        z3=x^0x1234598766U;
        z4=(~x)+51;
      	u = 0;
    }
}
using namespace GenHelper;
bool edge[8005][8005];
typedef long long ll;
const int N = 8005;

int n, seed;

int dfn[N], flow[N], cnt, vis[N];
stack<int>q;

//int cat[N], top = 1;

ll ans = 0;
vector<int> g[8005];
ll cal(ll x) {
    return (x * (x - 1) * (x - 2)) / 6;
}

//int cat[N], top = 1;


void work(int x) {
    cnt = 0;
    while (q.size()) q.top();
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
        dfn[i] = 0;
        flow[i] = 0;
     
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (edge[i][j] == x) {
                g[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j: g[i]) {
           if (g[i].size() > g[j].size()) {
               for(int k: g[j]) {
                   if (edge[i][k] == x) {
                       ans++;
                   }
               }
           } else {
               for (int k: g[i]) {
                   if (k > j && edge[j][k]) {
                       ans++;
                   }
               }
           }
        }
    }
   
}

int main() {
   
    scanf("%d %d", &n, &seed);
    srand(seed);
    for (int i = 0; i < n; i++)
    	for (int j = i + 1; j < n; j++)
        	edge[j][i] = edge[i][j] = read();
    work(0);
    work(1);
    printf("%lld\n", ans);
    
 	return 0;
}