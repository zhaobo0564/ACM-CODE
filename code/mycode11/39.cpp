#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const ll MOD = 1e9 + 7;
const int MAXN = 505;

char mp[MAXN][MAXN];
int cnt[MAXN*MAXN];
int block;
int rnk[MAXN*MAXN],fa[MAXN*MAXN];
ll fac[MAXN*MAXN];
int n;
ll ans = 1;
int sign[4][2]{{1,0},{-1,0},{0,1},{0,-1}};

long long qpower(long long x,long long p,int mod)
{
    long long re=1;
    while (p!=0)
    {
        if (p&1) re=(re*x)%mod;
        x=(x*x)%mod;
        p>>=1;
    }
    return re;
}


inline void init()
{
    fac[0] = 1;
    for (int i=1;i<=MAXN*MAXN-5;i++)
    {
        fa[i] = i;
        rnk[i] = 0;
        fac[i] = fac[i-1] * i;
        fac[i] %= MOD;
    }
}

int F(int x)
{
    return fa[x] == x ? x : F(fa[x]); 
}
void U(int x,int y)
{
    int xf = F(x),yf = F(y);
    if (xf == yf)
        return ;
    if (rnk[xf] < rnk[yf])
    {
        fa[xf] = yf;
        cnt[yf] += cnt[xf];
        cnt[xf] = 0;
    }
    else 
    {
        fa[yf] = xf;
        cnt[xf] += cnt[yf];
        cnt[yf] = 0;
        if (rnk[xf] == rnk[yf])
            rnk[xf]++;
    }
}



inline void change1(int x,int y)
{
    mp[x][y] = '1';
    int mid = (x - 1) * n + y;
    cnt[mid]++;
    block++;
    set<pii> s;
    for (int i=0;i<4;i++)
    {
        int px = x + sign[i][0],py = y + sign[i][1];
        if (mp[px][py] == '\0')
            continue;
        int id = (px - 1) * n + py;
        int f = F(id);
        if (cnt[f] != 0)
            s.insert({f,cnt[f]});
    }
    int all = 1;
    for (auto c : s)
    {
        int a = c.first,b = c.second;
        block--;
        ans *= qpower((ll)b,MOD-2LL,MOD);
        ans %= MOD;
        U(mid,a);all += b;
    }
    ans *= all;
    ans %= MOD;
}


inline void solve()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (mp[i][j] == '1')
                change1(i,j);
        }
    }
    int q;
    cin >> q;
    for (int i=1;i<=q;i++)
    {
        int x,y;
        cin >> x >> y;
        x++,y++;
        if (mp[x][y] == '1')
            cout << (ans * fac[block] % MOD) << endl;
        else 
        {
            change1(x,y);
            cout << (ans * fac[block] % MOD) << endl;
            
        }
    }

}

int main()
{
    init();
    solve();

    return 0;
}