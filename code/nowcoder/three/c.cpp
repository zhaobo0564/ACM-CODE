#include<bits/stdc++.h>
using namespace std;
double eps = 0.00000000000001;

struct point {
    double x, y;
}p[30];

int t;

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


int main() {
    scanf("%d", &t);
    point small[3], big[3];
    vector<point> g;
    while (t--) {
        for (int i = 1; i <= 20; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }

        for (int i = 1; i <= 20; i++) {
            for (int j = i + 1; j <= 20; j++) {
                double d = dist(p[i], p[j]);
                if (fabs(d - 8) <= eps) {
                    g.push_back(p[i]);
                    g.push_back(p[j]);
                } else if (fabs(d - 6) <= eps) {
                    g.push_back(p[i]);
                    g.push_back(p[j]);
                }
            }
        }
        for (int i = 0; i < g.size(); i++) {
            for (int j = i + 1; j < g.size(); j++) {
                double d = dist(g[i], g[j]);
                if (fabs(d - 9) <= eps) {
                    
                }
            }
        }

    }
}