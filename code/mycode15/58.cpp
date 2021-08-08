#include <bitsdc++.h>
using namespace std;

const double PI = acos(-1);
const double eps = 1e-8;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	double x, y;
	Point(){}
	Point(double _x, double _y) {
		x = _x; y = _y;
	}
	void input() {
		scanf("%lf %lf", &x, &y);
	}
	Point operator + (const Point &b) const {
		return Point(x + b.x, y + b.x);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	double operator * (const Point &b) const {
		return x * b.x + y * b.y;
	}
	double operator ^ (const Point &b) const {
		return x * b.y - y * b.x;
	}
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	double rad(Point a, Point b) {
		Point p = *this;
		return fabs(atan2(fabs((a-p)^(b-p)), (a-p)*(b-p) ));
	}
	double distance(Point p) {
		return hypot(x-p.x, y-p.y);
	}
	double len() {
		return hypot(x, y);
	}
	Point trunc(double r) {
		double l = len();
		if(!sgn(l)) return *this;
		r /= l;
		return Point(x*r, y*r);
	}
	Point roleft() {
		return Point(-y, x);
	}
	Point roright() {
		return Point(y, -x);
	}
};

struct Line {
	Point s, e;
	Line(){}
	Line(Point _s, Point _e) {
		s = _s; e = _e;
	}
};

struct circle {
	Point p;
	double r;
	circle(){}
	circle(Point _p, double _r) {
		p = _p;
		r = _r;
	}
	void input() {
		p.input();
		scanf("%lf", &r);
	}
	int relation(Point b){
		double dst = b.distance(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r)==0)return 1;
		return 0;
	}
	
	int tangentline(Point q, Line &u, Line &v) {
		int x = relation(q);
		if(x == 2) return 0;
		if(x == 1) {
			u = Line(q, q+(q-p).roleft());
			v = u;
			return 1;
		}
		
		double d = p.distance(q);
		double l = r*r/d;
		double h = sqrt(r*r-l*l);
		u = Line(q, p + ((q-p).trunc(l) + (q-p).roleft().trunc(h)));
		v = Line(q, p + ((q-p).trunc(l) + (q-p).roright().trunc(h)));
		return 2;
	}
};

circle c;
Point p, q;

int main() {
	int _; scanf("%d", &_); while(_--) {
		c.input(); p.input();
		q = Point(c.p.x, c.p.y-c.r);
		
		Line l1, l2;
		c.tangentline(p, l1, l2);
		
		Point rs1 = l1.e, rs2 = l2.e;
		
		double rd1 = c.p.rad(q, rs1);
		double rd2 = c.p.rad(q, rs2);
		
		double C = 2 * PI * c.r;
		
		double len1 = C * rd1 / PI, len2 = C * rd2 / PI;
		
		len1 += rs1.distance(p);
		len2 += rs2.distance(p); // ?
		
		printf("%.4f\n", min(len1, len2));
	}
}
