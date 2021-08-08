#include<bits/stdc++.h>
using namespace std;

const int N = 107;

#define LL long long

const LL MOD = 998244353;
const LL mod = 998244353;



LL K[N][N];
LL gauss(int n){//求矩阵K的n-1阶顺序主子式
    LL res=1;
    for(int i=1;i<=n-1;i++){//枚举主对角线上第i个元素
        for(int j=i+1;j<=n-1;j++){//枚举剩下的行
            while(K[j][i]){//辗转相除
                int t=K[i][i]/K[j][i];
                for(int k=i;k<=n-1;k++)//转为倒三角
                    K[i][k]=(K[i][k]-t*K[j][k]+MOD)%MOD;
                swap(K[i],K[j]);//交换i、j两行
                res=-res;//取负
            }
        }
        res=(res*K[i][i])%MOD;
    }
    return (res+MOD)%MOD;
}

struct edge{
    int u, v, w;
}e[10007];

LL ksm(LL a, LL b) {
    LL base = 1;
    while (b) {
        if (b & 1) {
            base = (base * a) % mod;
        }
        b = b / 2;
        a = a * a % mod;
    }
    return base % mod;
}

int main(){

    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        memset(K, 0, sizeof(K));
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            e[i] = {u, v, w};
            K[u][u]++;
            K[v][v]++;
            K[u][v]--;
            K[v][u]--;
        }
        LL total = gauss(n);
        LL ans = 0;
        LL inv = ksm(total, mod - 2);
        for (int i = 0; i < 30; i++) {
            memset(K, 0, sizeof(K));
            for (int j = 1; j <= m; j++) {
                if (((1 << i) & e[j].w)) {
                    K[e[j].u][e[j].u]++;
                    K[e[j].v][e[j].v]++;
                    K[e[j].u][e[j].v]--;
                    K[e[j].v][e[j].u]--;
                }
            }
            LL cnt = (1 << i);
            LL cat = gauss(n);

            cnt = (cnt % mod * cat % mod) % mod;
            ans = (ans + cnt) % mod;
        }
        ans = (ans % mod * inv % mod) % mod;
        printf("%lld\n", ans);
    }
}