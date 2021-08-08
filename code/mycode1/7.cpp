#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
int tree[1000][4], fail[1000], vis[1000];
map<char, int>q;
int cnt = 0, n;
typedef long long ll;

void insert(char str[]){
    int len = strlen(str);
    int now = 0;
    for(int i = 0; i < len; i++){
        if(!tree[now][q[str[i]]]){
            tree[now][q[str[i]]] = ++cnt;
        }
        now = tree[now][q[str[i]]];
    }
    vis[now]++;

}

void bfs(){
    queue<int>q;
    for(int i = 0; i < 4; i++){
        if(tree[0][i]){
            q.push(tree[0][i]);
        }
    }

    while(q.size()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            if(tree[now][i]){
                fail[tree[now][i]] = tree[fail[now]][i];
                q.push(tree[now][i]);
            }else{
                tree[now][i] = tree[fail[now]][i];
            }
            vis[tree[now][i]] |= vis[fail[tree[now][i]]]; 
        }
    }
}

#define N 120

int mod = 100000;

struct Matrix{
  ll m[N][N];
  Matrix(){
    memset(m,0,sizeof(m));
  }
};

Matrix multi(Matrix a,Matrix b,int c){ // 定义矩阵的乘法  c是矩阵的大小 
  Matrix res;
  for(int i=0;i<=c;i++){
    for(int j=0;j<=c;j++){
      for(int k=0;k<=c;k++){
        res.m[i][j]+=a.m[i][k]*b.m[k][j];
        res.m[i][j] = res.m[i][j] % mod; 
      }
    }
  }
  return res;
}

Matrix fastpow(Matrix a,ll n,int c){
  Matrix base;
  for(int i=0;i<=c;i++) base.m[i][i]=1; // 矩阵的对角线为1 单位矩阵 类型与上面base=1; 
  while(n){
    if(n&1) base=multi(base,a,c);
    a=multi(a,a,c);
    n=n/2;
  }
  return base;
}


int main(){
    ll m;
    scanf("%d %lld", &n, &m);
    q['A'] = 0;
    q['T'] = 1;
    q['C'] = 2;
    q['G'] = 3;
    char s[20];
    for(int i = 1; i <= n; i++){
        scanf("%s", s);
        insert(s);
    }
    bfs();

    Matrix ans;

    for(int i = 0; i <= cnt; i++){
        for(int j = 0; j < 4; j++){
            if(vis[tree[i][j]])continue;
            ans.m[i][tree[i][j]]++;
        }
    }

    ans = fastpow(ans, m, cnt);

    ll Ans = 0;
    for(int i = 0; i <= cnt; i++){
        Ans += ans.m[0][i];
    }
    printf("%d\n", Ans % mod);





}