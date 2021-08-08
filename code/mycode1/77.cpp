#include <bits/stdc++.h>
using namespace std;

struct circle {
	double x, y, r;
	int dir;
	int ans1, ans2;
} cir[1005];
int _, n;
vector <int> rela[1005];

double dis(int i, int j) {
	return sqrt((cir[i].x-cir[j].x)*(cir[i].x-cir[j].x)+(cir[i].y-cir[j].y)*(cir[i].y-cir[j].y));
}

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		for(int i = 0;i < 1001; i++) rela[i].clear();
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf %lf", &cir[i].x, &cir[i].y, &cir[i].r);
			cir[i].dir = 0;
		}
		cir[1].dir = 1; cir[1].ans1 = 1; cir[1].ans2 = 1;
		
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				if(dis(i,j) == cir[i].r+cir[j].r) {
					rela[i].push_back(j); 
				}
			}
		}
		
//		for(int i = 1;i <= n; i++) {
//			for(int j = 0;j < rela[i].size(); j++) {
//				printf("%d %d\n", i, rela[i][j]);
//			}
//		}
//		return 0;
		
		for(int i = 1;i <= n; i++) {
			for(int j = 0;j < rela[i].size(); j++) {
//				printf("%d %d\n", i, rela[i][j]);
				int pos = rela[i][j];
				cir[pos].dir = -cir[i].dir;
				
				cir[pos].ans1 = cir[i].ans1*cir[i].r;
				cir[pos].ans2 = cir[i].ans2*cir[pos].r;
//				cout <<"ans: " << cir[pos].ans1 << " " << cir[pos].ans2 << endl;
				int t = gcd(cir[pos].ans1, cir[pos].ans2);
				cir[pos].ans1 /= t;
				cir[pos].ans2 /= t;
//				cout <<"ans: " << cir[pos].ans1 << " " << cir[pos].ans2 << endl;
			}
		}
		
		puts("1 clockwise");
		for(int i = 2;i <= n; i++) {
			if(cir[i].dir == 0) puts("not moving");
			else {
				if(cir[i].ans1%cir[i].ans2 == 0) printf("%d ", cir[i].ans1/cir[i].ans2);
				else printf("%d/%d ", cir[i].ans1, cir[i].ans2);
				if(cir[i].dir == 1) puts("clockwise");
				else if(cir[i].dir == -1) puts("counterclockwise");
			}
			
		}
	}
}

/*
1
5
0 0 6
6 8 4
-9 0 3
6 16 4
0 -11 4
*/
