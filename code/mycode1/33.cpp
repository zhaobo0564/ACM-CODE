#include<bits/stdc++.h>
using namespace std;

int day_diff(int year_start, int month_start, int day_start, int year_end, int month_end, int day_end){
    int y2, m2, d2;
    int y1, m1, d1;
    
    m1 = (month_start + 9) % 12;
    y1 = year_start - m1/10;
    d1 = 365*y1 + y1/4 - y1/100 + y1/400 + (m1*306 + 5)/10 + (day_start - 1);

    m2 = (month_end + 9) % 12;
    y2 = year_end - m2/10;
    d2 = 365*y2 + y2/4 - y2/100 + y2/400 + (m2*306 + 5)/10 + (day_end - 1);
    
    return abs(d2 - d1);
}

map<int, string>v, m;

int main(){
    int n;   
    for(int i = 1; i <= 31; i++){
        string a = to_string(i);
        a += "th";
        v[i] = a;
    }
    v[1] = "1st", v[2] ="2nd", v[3] = "3rd";
    v[21] = "21st", v[22] ="22nd", v[23] = "23rd";
    v[31] = "31st";

 

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int year, day, month;
        scanf("%d %d %d", &year, &month, &day);
        // int days = day_diff(2000, 5, 14, year, month, day);
        // int cnt = days % 7;
        if(month < 5){
            int f = 0;
            for(int i = 1; i <= 31; i++){
                int days = day_diff(2000, 5, 14, year, 5, i);
                if(days % 7 == 0){
                    f++;
                }
                if(f == 2){
                    month = 5;
                    day = i;
                    break;
                }
            }
            cout <<"Mother's Day: May " << v[day] <<", " << year << endl;
        }else if(month == 5){
            int f = 0;
            for(int i = 1; i <= day; i++){
                int days = day_diff(2000, 5, 14, year, 5, i);
                if(days % 7 == 0){
                    f++;
                }
                if(f == 2){
                    break;
                }
            }
        //    cout << "f = " <<f << endl;
            if(f < 2){
                for(int i =day + 1; i <= 31; i++){
                    int days = day_diff(2000, 5, 14, year, 5, i);
                    if(days % 7 ==0){
                        f++;
                    }
                    if(f == 2){
                        day = i;
                        break;
                    }
                }
                 cout <<"Mother's Day: May " << v[day] <<", " << year << endl;

            }else{
                 f =0;
                for(int i = 1; i <= 30; i++){
                    int days = day_diff(2020, 6, 21, year, 6, i);
                    if(days % 7 == 0){
                        f++;
                    }
                    if(f == 3){
                        day = i;
                        break;
                    }
                }

                cout <<"Father's Day: June "<< v[day] << ", " << year << endl;

            }

        
        }else if(month == 6){
            int f = 0;
            for(int i = 1; i <= day; i++){
                int days = day_diff(2020, 6, 21, year, 6, i);
                if(days % 7 == 0){
                    f++;
                }
                if(f == 3){
                    break;
                }

            }
            if(f < 3){
                for(int i = day + 1; i <= 30; i++){
                    int days = day_diff(2020, 6, 21, year, 6, i);
                    if(days % 7 == 0){
                        f++;
                    }
                    if(f == 3){
                        day = i;
                        break;
                    }
                }
                cout <<"Father's Day: June "<< v[day] << ", " << year << endl;
            }else{
                f = 0;
                 for(int i = 1; i <= 31; i++){
                    int days = day_diff(2000, 5, 14, year + 1, 5, i);
                    if(days % 7 == 0){
                        f++;
                    }
                    if(f == 2){
                        month = 5;
                        day = i;
                        break;
                    }
                }
                cout <<"Mother's Day: May " << v[day] <<", " << year + 1 << endl;
            }
        }else{
            int f = 0;
            for(int i = 1; i <= 31; i++){
                int days = day_diff(2000, 5, 14, year + 1, 5, i);
                if(days % 7 == 0){
                    f++;
                }
                if(f == 2){
                    month = 5;
                    day = i;
                    break;
                }
            }
            cout <<"Mother's Day: May " << v[day] <<", " << year + 1 << endl;
        }

    }

}
