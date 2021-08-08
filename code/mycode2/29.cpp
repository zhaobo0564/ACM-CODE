// #include<iostream>
// using namespace std;
// double a,b, s;

// bool judge(double m){
//     if(m * m * 3 > s)return false;
//     if(3 * m <= a && b >= m)return true;
//     if(3 * m <= b && a >= m)return true;
//     if(2 * m <= a && 2 * m <= b)return true;
//     return false;

// }

// int main(){
//     while(~scanf("%lf %lf", &a, &b)){
//        s = a * b; 
//        double l = 0.0, r = 1000.0;
//        double ans;
//        while(l + 0.0000001 <= r){
//            double m = (l + r) / 2;
//            if(judge(m)){
//                l = m + 0.0000001;
//                ans = m;
//            }else{
//                r = m -0.0000001;
//            }
//        }
//        printf("%.5lf\n", ans);
//     }
    
	
// }


#include<iostream>
using namespace std;
double a,b,ans1,ans2;
int main(){
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
    while(~scanf("%lf %lf", &a, &b)){
        ans1=max(min(a/3,b),min(b/3,a));
        ans2=min(a/2,b/2);
        printf("%lf\n",max(ans1,ans2));
    }
    
	
}
