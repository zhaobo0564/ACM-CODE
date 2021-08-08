#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
 
long long int n,ans;
long long int k[107],b[107];
double cha=0.000000000000015,x,y;
 
struct madoka{
    double x;
    double y;
};
 
vector<madoka>ho;
 
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&k[i],&b[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(k[i]-k[j]==0){
                continue;
            }
            else{
                x=((double)b[i]-(double)b[j])/((double)k[j]-(double)k[i]);
                y=x*(double)k[i]+(double)b[i];
                int ok=1;
                for(int k=0;k<ho.size();k++){
                    if(abs(x-ho[k].x)<cha&&abs(y-ho[k].y)<cha){
                        ok=0;
                        break;
                    }
                }
                if(ok==1){
                    ans++;
                    ho.push_back({x,y});
                }
            }
        }
    }
    if(ans!=0)printf("%lld\n",ans);
    else{
        printf("No Fire Point.\n");
    }
}