#include<bits/stdc++.h>
using namespace std;


int  main(){
  int n;
  cin >> n;
    while(n){
       int l, r;
       cin >> l >> r;
       int sum = 0;
       for(int i = l; i <= r; i++){
         int cnt = sqrt(i);
         if(cnt * cnt == i){
           sum++;
         }
       }
       cout << sum;
    }
    
  //  cout << sum << endl;
    //cout << sum + cnt << endl;


}