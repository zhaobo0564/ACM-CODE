#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 4e4;

int mod = 999911659;
int n,q,jc[N],jcinv[N],inv[N];

int pow(int a,int b,int p)
{
    int res = 1;
    for(;b;b >>= 1)
    {
        if(b&1)res = (LL)res * a % p;
        a = (LL)a * a % p;
    }
    return res;
}

void init(int p)
{
    jcinv[0] = jcinv[1] = inv[1] = jc[1] = jc[0] = 1;
    for(int i = 2;i <= p;i ++)
    {
        inv[i]=(LL)(p-p/i)*inv[p%i]%p;
        jcinv[i] = jcinv[i-1] * inv[i] % p;
        jc[i] =(LL)jc[i-1] * i % p;
    }
}

int C(int x,int y,int p)
{
    if(y > x)return 0;
    return (LL)jc[x]*jcinv[y]*jcinv[x-y]%p;
}

int lucas(int x,int y,int p)
{
    if(y == 0)return 1;
    return (LL)C(x%p,y%p,p) * lucas(x/p,y/p,p) % p;
}

int get(int p)
{
    init(p);
    int res = 0;
    for(int i = 1;i <= n / i;i ++)
        if(n % i == 0)
        {
            res = (res + lucas(n,i,p)) % p;
            if(i * i == n)break;
            res = (res + lucas(n,n/i,p)) % p;
        }
    return res;
}

int main()
{
    cin >> n >> q;
    if(q == mod){puts("0");return 0;}

    int a1 = get(2);
    int a2 = get(3);
    int a3 = get(4679);
    int a4 = get(35617);

    int res = 0;
    res = ((LL)(mod-1)/2 * a1 + res) % (mod - 1);
    res = ((LL)(mod-1)/3 * a2 * pow((mod-1)/3,3-2,3) + res) % (mod - 1);
    res = ((LL)(mod-1)/4679 * a3 % (mod - 1) * pow((mod-1)/4679,4679-2,4679) % (mod - 1) + res) % (mod - 1);
    res = ((LL)(mod-1)/35617 * a4 % (mod - 1) * pow((mod-1)/35617,35617-2,35617) % (mod - 1) + res) % (mod - 1);
    cout << "Res " << res << endl;
    cout << pow(q,res,mod);
}

