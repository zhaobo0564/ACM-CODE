#include<iostream>
#include<queue>
using namespace std;
 
int t,n,a[107],sum,lin;
priority_queue <int, vector<int>, greater<int> > ho;
int main(){
    scanf("%d",&t);
    while(t--){
        while(!ho.empty()){
            ho.pop();
        }
        sum=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ho.push(a[i]);
            sum+=a[i];
        }
        if(sum%n==0){
            sum/=n;
        }
        else{
            printf("No\n");
            continue;
        }
        int ok=0;
        for(int i=0;i<=10000;i++){
            lin=ho.top();
            //printf("top=%d i=%d\n",ho.top(),i);
            ho.pop();
            if(lin-i<0){
                break;
            }
            if(lin-i==sum){
                ok=1;
                break;
            }
            lin+=n;
            ho.push(lin);
        }
        if(ok)printf("Yes\n");
        else{
            printf("No\n");
        }
    }
}