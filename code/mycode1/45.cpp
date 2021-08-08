// 几何模板

#include<bits/stdc++.h>

const int  eps = 1e-9; // 控制误差 一般取1e-7 -- 1e-10

int dcmp(double x){
    if(fabs(x) < eps)
        return 0;
    return x < 0? -1 : 1;
}



struct Vector{
    double x, y;
    Vector(double x, double y){
        this-> x = x;
        this-> y = y;
    }
};

typedef Vector point;


// 向量的四则运算

Vector operator + (Vector a, Vector b){return Vector(a.x + b.x, a.y + b.y);}

Vector operator - (Vector a, Vector b){return Vector(a.x - b.x, a.y - b.y);}

// 向量与数字相乘
Vector operator * (Vector a, double b){return Vector(a.x * b, a.y * b);}

// 向量与向量相乘
Vector operator * (Vector a, Vector b){return Vector(a.x * a.x, a.y * a.y);}

// 向量与数字相除
Vector operator / (Vector a, double b){return Vector(a.x / b, a.y / b);}

// 向量与向量相除
Vector operator / (Vector a, Vector b){return Vector(a.x / b.x, a.y / b.y);}

bool operator < (const Vector& a, const Vector & b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);      // 以x先优先
}

bool operator == (const Vector& a, const Vector& b){
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

// 求向量的模长

// 向量的点积
double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

// 求向量的模长
double len(Vector a){
    return sqrt(dot(a, a));
}

// 求两向量的夹角
double angle(Vector a, Vector b){
    return acos(dot(a, b) / len(a) / len(b));
}

// 求两向量的叉积
// a b共线叉积为0
double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

// 已知三点求面积(三角形，平行四边形)
double area(point a, point b, point c){
    return cross(b - a, c - a);
}

//点到直线的距离
double distanceToLine(point p, point a, point b){
    Vector v1 = b - a, v2 = p - a;
    return fabs(cross(v1, v2)) / len(v1);
}

// 点到线段的距离
double distanceToSegment(point p, point a, point b){
    if (a==b) return len(p-a);
    Vector v1=b-a,v2=p-a,v3=p-b;
    if (dcmp(dot(v1, v2)) < 0) return len(v2);
    else if (dcmp(dot(v1, v3)) > 0) return len(v3);
    return fabs(cross(v1, v2)) / len(v1);
}

// 判断两直线是否相交
bool segment(point a, point b, point c, point d){
    double c1=cross(b-a, c-a), c2=cross(b-a,d-a);
    double d1=cross(d-c, a-c), d2=cross(d-c,b-c);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp (d1) * dcmp(d2) < 0;
}

// 判断点是否在线段上（不含端点）
bool onSegment(point p, point a1, point a2){
    return dcmp(cross(a1 - p, a2 - p)) == 0 && dcmp(dot(a1 - p, a2 - p)) < 0;
}


// 求两直线的交点
point getPoint(point a,point a0,point b,point b0) { 
 
    double a1,b1,c1,a2,b2,c2; 
 
    a1 = a.y - a0.y; 
 
    b1 = a0.x - a.x; 
 
    c1 = cross(a,a0); 
 
    a2 = b.y - b0.y; 
 
    b2 = b0.x - b.x; 
 
    c2 = cross(b,b0); 
 
    double d = a1 * b2 - a2 * b1; 
 
    return point((b1 * c2 - b2 * c1) / d,(c1 * a2 - c2 * a1) / d); 
 
}  

//**********多边形********************


// 判断 点p是否在 多边形a的内部
int pointin(point p, point* a, int n){ 
 
    int wn=0,k,d1,d2; 
    for (int i=1;i<=n;i++){ 
        if (dcmp(distanceToSegment(p,a[i],a[(i+1-1)%n+1]))==0)  return -1;//判断点是否在多边形的边界上  
        k=dcmp(cross(a[(i+1-1)%n+1]-a[i],p-a[i])); 
        d1=dcmp(a[i].y-p.y); 
        d2=dcmp(a[(i+1-1)%n+1].y-p.y); 
        if (k>0&&d1<=0&&d2>0)  wn++; 
        if (k<0&&d2<=0&&d1>0)  wn--; 
    } 
 
    if (wn)  return 1; 
    else return 0; 
 
} 

// 求多边形的面积
double allArea(point *p, int n){
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}

// 三角形外心
point CircumCenter(point A, point B, point C){
 
    double a1 = B.x - A.x, b1 = B.y - A.y, c1 = (a1 * a1 + b1 * b1) / 2;
 
    double a2 = C.x - A.x, b2 = C.y - A.y, c2 = (a2 * a2 + b2 * b2) / 2;
 
    double d = a1 * b2 - a2 * b1;
 
    double Ox = A.x + (b2 * c1 - b1 * c2) / d;
 
    double Oy = A.y + (a1 * c2 - a2 * c1) / d;
 
    return point(Ox, Oy);
}

double dis(point a, point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


// 三角形内心
point InternalCenter(point A, point B, point C) {
 
    double a = dis(B, C);
 
    double b = dis(A, C);
 
    double c = dis(A, B);
 
    double Ix = (a * A.x + b * B.x + c * C.x) / (a + b + c);
 
    double Iy = (a * A.y + b * B.y + c * C.y) / (a + b + c);
 
    return point(Ix, Iy);
 
}

// *********************圆****************************
struct Circle{
    Point c;
    double r;
    Circle(Point c, double r):c(c), r(r) {}
    Point point(double a){//通过圆心角求坐标
        return Point(c.x + cos(a)*r, c.y + sin(a)*r);
    }
};




int main(){

}

