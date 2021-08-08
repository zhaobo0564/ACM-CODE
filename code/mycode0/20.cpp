#include<bits/stdc++.h>
using namespace std;

int t ;
int x, y;

int work(int l, int r ){
  //cout << l << " " << r << endl;
  if(r - l <= 10){
    int ans = 0;
    int maxn = 0;
    for(int i = l; i <= r; i++){
      ans = i + min((x - i * 2) / 4, y - i * 3);
      maxn = max(maxn, ans);
    }
    return maxn;
  }
  int m1 = (l + r) / 2;
  int m2 = (m1 + r) / 2;
  int ans1 = m1 + min((x - m1 * 2) / 4, y - m1 * 3);
  int ans2 = m2 + min ((x - m2 * 2) / 4,y - m2 * 3);
 // cout << ans1 << "  " << ans2 << endl;
  if(ans1 > ans2){
    return work(l , m2);
  }else{
    return work(m1 , r);
  }
}


int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%d%d", &x, &y);
    int ans = work(0, min(x / 2, y / 3));
   // cout<<"ans="<<ans<<endl;
    printf("%d\n", ans);
  }

  
}