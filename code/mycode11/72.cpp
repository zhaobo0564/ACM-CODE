#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100; 
const int mod=10000;

struct Matrix{
  ll m[N][N];
  Matrix(){
    memset(m,0,sizeof(m));
  }
};

Matrix multi(Matrix a,Matrix b,int c){ // 定义矩阵的乘法  c是矩阵的大小 
  Matrix res;
  for(int i=1;i<=c;i++){
    for(int j=1;j<=c;j++){
      for(int k=1;k<=c;k++){
        res.m[i][j]+=a.m[i][k]*b.m[k][j] % mod; 
        res.m[i][j] %= mod;
      }
    }
  }
  return res;
}

Matrix fastpow(Matrix a,ll n,int c){
  Matrix base;
  for(int i=1;i<=c;i++) base.m[i][i]=1; // 矩阵的对角线为1 单位矩阵 类型与上面base=1; 
  while(n){
    if(n&1) base=multi(base,a,c);
    a=multi(a,a,c);
    n=n/2;
  }
  return base;
}

int main(){
	
	ll n;
	
	while (cin>>n && n >= 0) {
        Matrix ans,answer;
        ans.m[1][1]=1,ans.m[1][2]=1,ans.m[2][1]=1;
        if(n==0) cout<<0<<endl;
        else if(n==1) cout<<1<<endl;
        else {
            answer=fastpow(ans,n-1,2);      // 构造的是2阶矩阵
            Matrix cnt;
            cnt.m[1][1]=1,cnt.m[2][1]=0;
            answer=multi(cnt,answer,2);
            cout<<answer.m[1][1] % mod<<endl; 
        }
    }
}