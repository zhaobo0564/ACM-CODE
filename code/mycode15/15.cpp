#include<iostream>
#include<queue>
using namespace std;
#define ll long long
int dis[5][5], n, m, diss[5][5];
char s[5][5];
ll ans;
ll answer;
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
struct point {
	ll way;
	int t;
	int cx, cy, ox, oy;
}a,b;
int OK(int x, int y)
{
	if (x <= n && x >= 1 && y <= m && y >= 1 && s[x][y] == 'O')
		return 1;
	return 0;
}
void gai()//ans->dis
{
	for (int i = n;i >= 1;i--) {
		for (int j = m;j >= 1;j--) {
			dis[i][j] = ans & 1;
			ans = ans >> 1;
		}
	}
	return;
}
void yuan()//dis->ans
{
	ans = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			ans = (ans << 1) + dis[i][j];
		}
	}
	return;
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		getchar();
		for (int j = 1;j <= m;j++) {
			scanf("%c", &s[i][j]);
			if (s[i][j] == 'X')
				dis[i][j] = 1;
			if (s[i][j] == 'O')
				dis[i][j] = 0;
			if (s[i][j] == 'S') {
				dis[i][j] = 1;
				s[i][j] = 'O';
				a.cx = a.ox = i;
				a.cy = a.oy = j;
				a.t = 0;
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			answer = (answer << 1) + 1;
		}
	}
	queue<point> r;
	yuan();
	a.way = ans;
	r.push(a);
	while (!r.empty()) {
		a = r.front();
		r.pop();
		if (a.way == answer) {
			cout << a.t;
			break;
		}
		ans = a.way;
		gai();
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				diss[i][j] = dis[i][j];
		for (int i = 0;i < 4;i++) {
			b.cx = a.cx + xx[i];
			b.cy = a.cy + yy[i];
			if (OK(b.cx, b.cy)) {
				for (int j = 0;j < 4;j++) {
					b.ox = a.ox + xx[j];
					b.oy = a.oy + yy[j];
					if (OK(b.ox, b.oy)) {
						b.t = a.t + 1;
						dis[b.cx][b.cy] = 1;
						dis[b.ox][b.oy] = 1;
						yuan();
						b.way = ans;
						r.push(b);
						for (int i = 1;i <= n;i++)
							for (int j = 1;j <= m;j++)
								dis[i][j] = diss[i][j];
					}
				}
			}
		}
	}
	return 0;
}