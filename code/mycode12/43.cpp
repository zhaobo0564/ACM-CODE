#include<bits/stdc++.h>
using namespace std;
const int N = 20;
typedef long long ll;
int  n;

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
        res.m[i][j]+=a.m[i][k]*b.m[k][j]; 
        res.m[i][j] %= 2;
      }
    }
  }
  return res;
}


bool same(Matrix x, Matrix y) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x.m[i][j] != y.m[i][j]) {
                return false;
            }
        }
    }
    return true;
}

Matrix work(Matrix x, Matrix y) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            x.m[i][j] *= y.m[i][j];
        }
    }
    return x;
} 

Matrix c;
Matrix a;
Matrix b;

int ans = 0;

void print(Matrix x) {
    cout << "************\n\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << x.m[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> v;

void dfs(int p) {
    if (p > n * n) {
        for (int i = 0; i < v.size(); i++) {
            c.m[i / n + 1][i % n + 1] = v[i];
        }
      //  print(c);
        if (same(multi(a, c, n), work(b, c))) {
                print(c);
                ans++;
        } 
        return;
    }
    v.push_back(1);
    dfs(p + 1);
    v.pop_back();
    v.push_back(0);
    dfs(p + 1);
    v.pop_back();
    
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a.m[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            cin >> b.m[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;

}