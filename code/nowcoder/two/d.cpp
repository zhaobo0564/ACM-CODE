#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
 
double eps = 0.000000000000000001;
 
double X,Y,R;
struct Point{
    double x,y;
}pp[maxn];
double dis(Point x,Point y){
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
 
void solve(Point a,Point b,Point c)//三点共圆圆心公式
{
 
    X=( (a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y)*(a.y-c.y)-(a.x*a.x-c.x*c.x+a.y*a.y-c.y*c.y)*(a.y-b.y) ) / (2*(a.y-c.y)*(a.x-b.x)-2*(a.y-b.y)*(a.x-c.x));
    Y=( (a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y)*(a.x-c.x)-(a.x*a.x-c.x*c.x+a.y*a.y-c.y*c.y)*(a.x-b.x) ) / (2*(a.y-b.y)*(a.x-c.x)-2*(a.y-c.y)*(a.x-b.x));
    R=sqrt((X-a.x)*(X-a.x)+(Y-a.y)*(Y-a.y));
 
    
}
#define fr first
#define sc second
#define ll long long
 
 
#define pb push_back
 const ll mod=1e9+7;
const int maxsz=3e5+7;
const ll mood=1e9+7;
 
template<typename key,typename val>
class hash_map{public:
  struct node{key u;val v;int next;};
  vector<node> e;
  int head[maxsz],nume,numk,id[maxsz];
  int geths(pair<ll,ll> &u){
    int x=(1ll*u.first*mood+u.second)%maxsz;
    if(x<0) return x+maxsz;
    return x;
  }
  val& operator[](key u){
    int hs=geths(u);
    for(int i=head[hs];i;i=e[i].next)if(e[i].u==u) return e[i].v;
    if(!head[hs])id[++numk]=hs;
    if(++nume>=e.size())e.resize(nume<<1);
    return e[nume]=(node){u,0,head[hs]},head[hs]=nume,e[nume].v;
  }
  void clear(){
    for(int i=0;i<=numk;i++) head[id[i]]=0;
    numk=nume=0;
  }
};
 
hash_map<pair<ll, ll>, int >v;
 
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &pp[i].x, &pp[i].y);
    }
    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        v.clear();
        ans = 0;
        for (int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(fabs(pp[i].x * pp[j].y - pp[j].x * pp[i].y) <= eps)continue;
            solve({0, 0}, pp[i], pp[j]);
            ll x = X * 1e10;
            ll y = Y * 1e10;
            v[{x, y }]++;
            ans = max(ans, v[{x, y}]);
        }
        mx = max(mx, ans);
    }
    printf("%d\n", mx + 1);
}