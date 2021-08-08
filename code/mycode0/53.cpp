#include<bits/stdc++.h>
using namespace std;

double  rm, R, r, e, f, vx, vy;

int main(){
    while(~scanf("%lf %lf %lf %lf %lf %lf",&rm, &R, &r, &e, &f, &vx, &vy)){
        double a = vy * vy;
        double b = vx * vx;
        double c = (f * vx - vy * e) *  (f * vx - vy * e);
        double d = sqrt(c / (a + b));
        d = d - r;
        if(d < 0)d = 0;
        double len1, len2;
        if(d >= rm) len1 = rm;
        else len1 = d;
        if(d >= R) len2 = R;
        else len2 = d;
        double ans1 = (rm * rm)- (len1 * len1);
        ans1 = sqrt(ans1) * 2;
        double ans2 = (R * R) - (len2 * len2);
        ans2 = sqrt(ans2) * 2;
        double ans = ans2 - ans1;
        double v = sqrt(a + b);
        cout << ans / v << endl;
       


    }
}