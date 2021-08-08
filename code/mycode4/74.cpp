#include <bits/stdc++.h>
using namespace std;

int n, now = 300;
int num[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int peo[105];
bool vis[400];
string name, intime;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		cin >> name;
		cin >> intime;
		int a = 0, b = 0;
		if(intime[0] != '0') {
			a += intime[0]-'0'; 
			a *= 10;
		}
		a += intime[1]-'0';
		
		if(intime[3] != '0') {
			b += intime[3]-'0'; 
			b *= 10;
		}
		b += intime[4]-'0';
		
		int res = b;
		for(int i = 1;i < a; i++) {
			res += num[i];
		}
		peo[i] = res;
//		printf("%d-%d=%d\n",a,b,res);
		vis[res] = 1;
	}
	n++;
	peo[n] = 300;
	sort(peo+1, peo+1+n);
//	for(int i = 1;i <= n; i++) cout << peo[i] << endl;
	
	int ans = 0;
	vector <int> v; v.clear();
	for(int i = 2;i <= n; i++) {
		if(vis[peo[i]-1] || peo[i]-1 == now) continue;
		int cha = peo[i]-peo[i-1];
		if(ans < cha) {
			v.clear();
			ans = cha;
			v.push_back(peo[i]-1);
		}
		else if(ans == cha) v.push_back(peo[i]-1);
//		for(int i = 0;i < v.size(); i++) printf("%d\n", v[i]);
	}
	
	if(!vis[peo[1]-1] && peo[1]-1 != now) {
		int cha = peo[n]-peo[1];
		cha = 365-cha;
		if(peo[1] == peo[n]) cha = 0;
		if(ans < cha) {
			v.clear();
			ans = cha;
			v.push_back(peo[1]-1);
		}
		else if(ans == cha) v.push_back(peo[1]-1);
	}
	
//	for(int i = 0;i < v.size(); i++) printf("%d\n", v[i]);
	
	int fin = 1000, pri;
	for(int i = 0;i < v.size(); i++) {
		int cha = max(now, v[i]) - min(now, v[i]);
		if(now > v[i]) cha = 365-cha;
		if(fin > cha) {
			fin = cha;
			pri = v[i];
		}
	}
	
	int mon = 1, day = 0;
	for(int i = 1;i <= 12; i++) {
		if(pri > num[i]) {
			mon++;
			pri -= num[i];
		} 
		else day = pri;
	}
	if(day == 0) {
		puts("12-31\n");
	}
	else {
		if(mon < 10) printf("0");
		printf("%d-", mon);
		if(day < 10) printf("0");
		printf("%d\n", day);
	}
	
}
