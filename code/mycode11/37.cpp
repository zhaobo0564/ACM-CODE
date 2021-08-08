#include<bits/stdc++.h>
using namespace std;

double a, r;
double eps = 0.0000000001;
double pai = acos(-1.0);

int main() {
    cin >> a >> r;
    double R = a * sqrt(6.0);
    R = R / 4.0;
  //  cout << "r = " << r << " R = " << R << endl;
    if (r >= R) {
        double ans = a * a * sqrt(3.0);
        printf("%.5f\n", ans);
    } else {
      
        double h1 = (sqrt(3.0) * a) / 6.0;
        double h = sqrt(6) * a;
        h = h / 12.0;
        double R1 = sqrt(r * r - h * h);
      //  cout << "h = " << h << " h1 " << h1 << endl;
        if (r <= h) {
            printf("%.5f\n", 0.0);
        } else if ( R1 <= h1) {
            double ans = pai * R1 * R1;
            printf("%.5f\n", ans * 4);
        } else {
            double sina = h1 / R1;
          //  cout << "sina " << sina << endl;
            double du = acos(sina);
       //     cout << "du " << du << endl;
         //  cout << R1 * cos(du) << " " << h1 << endl;
            du += du;
           // cout << du<< endl;

            double san = R1 * R1 * sin(du);
            san = san / 2.0;
            double shan = du * R1 * R1;
            double sum = shan / 2.0 - san;
           //cout << sum << endl;
            sum = sum * 3;
            
    
            double ans = pai * R1 * R1 * 4;
            ans = ans - sum * 4;
            printf("%.5f\n", ans);
            
        }

    }
}