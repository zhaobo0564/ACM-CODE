#include<bits/stdc++.h>
using namespace std;
double eps = 0.0000000001;
typedef long long ll;
struct node{
    double x, y;
    double k;
}p[200000];

map<long long, int>q;

int n, qq;

int main(){
    scanf("%d %d", &n, &qq);
    ll cn = 100000000;
    for(int i = 1; i <= n; i++){
        double x, y;
        scanf("%lf %lf", &x, &y);
        p[i].x = x;
        p[i].y = y;
        double k;
        if(y == 0 ){
            k = 0.0;
        }else if(x == 0){
            k = 1e10;
        }else{
            k = y / x;
        }
        p[i].k;
        q[k * cn] = 1;
    }
    if(n == 1){
        while(qq--){
            double x, y;
            scanf("%lf %lf", &x, &y);
            if(fabs(x - 0) <= eps && fabs(y - 0) <= eps){
                puts("0");
                continue;
            }
            double k;
            if(y == 0 ){
                k = 0.0;
            }else if(x == 0){
                k = 1e10;
            }else{
                k = y / x;
            }
            if(q[k * cn]){
                puts("1");
            }else{
                puts("-1");
            }
        }
    
    }else if(n == 2){
        while(qq--){
            double x, y;
            scanf("%lf, %lf", &x, &y);
            if(fabs(x - 0) <= eps && fabs(y - 0) <= eps){
                puts("0");
                continue;
            }
            double k = (y - p[1].y) /(x - p[1].x);
            int f =0;
            if(fabs(p[2].k - k) <= eps){
                f++;
            }
            k = (y - p[2].y) / (x - p[2].x);
            if(fabs(p[1].k - k) <= eps){
                f++;
            }
            if(f == 2){
                puts("3");
            }else{
                if(y == 0 ){
                    k = 0.0;
                }else if(x == 0){
                    k = 1e10;
                }else{
                    k = y / x;
                }
                if(q[k * cn]){
                    puts("1");
                }else{
                    puts("2");
                }
            }

        }
    }else{
        while(qq--){
            double x, y;
            //scanf("%")
        }
    }
}