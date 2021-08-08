#include <bits/stdc++.h>
#define N_MAX 1000000
#define M_MAX 64
const int INF = 0x3F3F3F3F;
using namespace std;
struct IO {
	operator int() {
		register int c = getchar(), x = 0;
		for (;!isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
		return x;
	}
} fio;
int N, M, Q;
struct Dat {
	int f[M_MAX];
	void init() {
		f[0] = 0;
		for (int j = 1; j < M; ++j)
			f[j] = -INF;
	}
	void init(int a, int v) {
		init(), f[a] = v;
	}
	Dat operator | (const Dat & t) const {
		Dat s;
		s.init();
		for (int i = 0; i < M; ++i)
			if (f[i] >= 0)
				for (int j = 0; j < M; ++j)
					if (t.f[j] >= 0)
						s.f[i ^ j] = max(s.f[i ^ j], f[i] + t.f[j]);
		return s;
	}
	unsigned calc(int x) const {
		unsigned s = 0;
		for (int j = 0; j < M; ++j)
			s += (f[j] < 0 ? -1 : f[j]) * (x ^ j);
		return s;
	}
};
struct Item {
	int a, v;
} z[N_MAX];
struct Seg {
	int pl, pr; Dat t;
} seg[N_MAX * 2];
int seg_cur;
inline void seg_upd(int p) {
	seg[p].t = seg[seg[p].pl].t | seg[seg[p].pr].t;
}
int seg_init( int l, int r) {
	int m = (l + r) >> 1, p = seg_cur++;
	if (l + 1 == r) seg[p].t.init(z[l].a, z[l].v);
	else {
		seg[p].pl = seg_init(l, m), seg[p].pr = seg_init( m, r) ;
		for (int i = 0; i < M; i++) {
			seg[p].t.f[i] = -1;
		}
		
		for (int i = 0; i < M; i++) {
			if (seg[seg[p].pl].t.f[i] > -1) {
				for (int j = 0; j < M; j++) {
					if (seg[seg[p].pr].t.f[j] > - 1) {
						seg[p].t.f[i ^ j] = max(seg[p].t.f[i ^ j], seg[seg[p].pl].t.f[i] +seg[seg[p].pr].t.f[j]);
					}
				}
			}
		}
	}
	return p;
}
Dat seg_qry(int p, int l, int r, int i, int j) {
	int m = (l + r) >> 1;
	if (l == i && r == j) return seg[p].t;
	else if (j <= m) return seg_qry(seg[p].pl, l, m, i, j);
	else if (i >= m) return seg_qry(seg[p].pr, m, r, i, j);
	else return seg_qry(seg[p].pl, l, m, i, m) | seg_qry(seg[p].pr, m, r, m, j);
}
int main() {
	int i, k, l, r;
	N = fio, M = fio, Q = fio;
	for (i = 0; i < N; ++i)
		z[i].a = fio, z[i].v = fio;
	int seg_root = seg_init( 0, N);


	unsigned ans = 0;
	for (k = 1; k <= Q; ++k)
		l = fio, r = fio, ans += k ^ seg_qry(seg_root, 0, N, l, r + 1).calc(fio);
	printf("%u\n", ans);
	return 0;
}
