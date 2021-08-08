#include<bits/stdc++.h>
using namespace std;
int vis[400][400];

int day_diff(int year_start, int month_start, int day_start,int year_end , int month_end, int day_end){
    int y2, m2, d2;
    int y1, m1, d1;
     
    
    m1 = (month_start + 9) % 12;
    y1 = year_start - m1/10;
    d1 = 365*y1 + y1/4 - y1/100 + y1/400 + (m1*306 + 5)/10 + (day_start - 1);

    m2 = (month_end + 9) % 12;
    y2 = year_end - m2/10;
    d2 = 365*y2 + y2/4 - y2/100 + y2/400 + (m2*306 + 5)/10 + (day_end - 1);
    
    return d2 - d1;
}

struct node{
    int month, day;
};

vector<node>v;
vector<node>g[1000];

bool cmp(node x, node y){
    if(x.month == y.month){
        return x.day < y.day;
    }else{
        return x.month < y.month;
    }
}

int num[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct node change(struct node a){
    if(a.day == 1){
        
        a.month--;
        if(a.month == 0){
            a.month = 12;
        }
        a.day = num[a.month];
    }else{
        a.day--;
    }
    return a;
}


int main(){
    int n;
    
    scanf("%d", &n);
    string name, date;

    for(int i = 1; i <= n; i++){
        cin >> name >> date;
        int a = 0, b = 0;
        if(date[0] != '0') {
			a += date[0]-'0'; 
			a *= 10;
		}
		a += date[1]-'0';
		
		if(date[3] != '0') {
			b += date[3]-'0'; 
			b *= 10;
		}
		b += date[4]-'0';
        // if(a == 10 && b == 28){
        //     b = 27;
        // }
        v.push_back({a, b});
        vis[a][b] = 1;

    }

    sort(v.begin(), v.end(), cmp);
  
    for(int i = 1; i < v.size(); i++){
        int cnt = day_diff(2018, v[i -1].month, v[i - 1].day, 2018, v[i].month, v[i].day);
        node cd = change(v[i]);
   
        
        if(vis[cd.month][cd.day])continue;
        
        g[cnt].push_back(cd);
    }
    int cnt = day_diff(2018, v[v.size() - 1].month, v[v.size() - 1].day, 2019, v[0].month, v[0].day);
    node cd = change(v[0]);
   
    if(vis[cd.month][cd.day] == 0){

        g[cnt].push_back(cd);
    }
    int f = 0;
    int ans =1000, mo = 0,da = 0;
    for(int i = 400; i; i--){
        if(g[i].size()){
     
            for(int j = 0; j < g[i].size(); j++){
                 int cnt = day_diff(2019, 10, 28, 2019, g[i][j].month, g[i][j].day);
                 
                 if(cnt < 0){
                     cnt = day_diff(2018, 10, 28, 2019, g[i][j].month, g[i][j].day);
                 }
                 if(ans > cnt){
                     ans = cnt;
                     da = g[i][j].day;
                     mo = g[i][j].month;
                     f = 1;
                 }
                
            } 
            if(f == 1)break;
           
        }
    }
    if(mo < 10){
        printf("0");
    }
    printf("%d-", mo);
    if(da <10){
        printf("0");
    }
    printf("%d\n", da);

}

