#include<bits/stdc++.h>
using namespace std;

char mp[20][20];
int main(){
    for(int i = 11; i <= 13; i++){
        for(int j = 11; j <= 13; j++){
            scanf(" %c", &mp[i][j]);
        }
    }
    int f = 0;
    for(int i = 11; i <= 13; i++){
        for(int j = 11; j <= 13; j++){
            if(mp[i][j] == 'K'){
               
                int p = j;
                int cnt = 0;
                while(mp[i][p] == 'K')p--, cnt++;
                if(cnt == 3){
                    f = 1;
                    break;
                } 
          
                p = j, cnt = 0;
                while(mp[i][p] == 'K')p++, cnt++;
                if(cnt == 3){
                    f = 1;
                    break;
                }         
                p = i;
                cnt = 0;
                while(mp[p][j] == 'K')p--, cnt++;
                if(cnt == 3){
                    f = 1;
                    break;
                }      
                p = i, cnt = 0;
                while(mp[p][j] == 'K')p++, cnt++;
                if(cnt == 3){
                    f = 1;
                    break;
                }
                p = i;
                int p1 = j;
                cnt = 0;
                while(mp[p][p1] == 'K')p++, p1++, cnt++;
                if(cnt == 3){
                    f = 1;
                    break;
                }
                p = i, p1 = j, cnt = 0;
                while(mp[p][p1] == 'K')p++, p1--, cnt++;
                if(cnt == 3){
                    f = 1;
                    break;
                }
                p = i, p1 = j, cnt = 0;
                while(mp[p][p1] == 'K')p--, p1++, cnt++;
                if(cnt == 3){
                    f = 1;
                    break;
                }
                p = i, p1 = j, cnt = 0;
                while(mp[p][p1] == 'K')p--, p1--, cnt++;
                if(cnt == 3){
                    f = 1;
                    break;
                } 

                
            }else if(mp[i][j] == 'B'){
                 int p = j;
                int cnt = 0;
                while(mp[i][p] == 'B')p--, cnt++;
                if(cnt == 3){
                    f = 2;
                    break;
                } 
          
                p = j, cnt = 0;
                while(mp[i][p] == 'B')p++, cnt++;
                if(cnt == 3){
                    f = 2;
                    break;
                }         
                p = i;
                cnt = 0;
                while(mp[p][j] == 'B')p--, cnt++;
                if(cnt == 3){
                    f = 2;
                    break;
                }      
                p = i, cnt = 0;
                while(mp[p][j] == 'B')p++, cnt++;
                if(cnt == 3){
                    f = 2;
                    break;
                }
                p = i;
                int p1 = j;
                cnt = 0;
                while(mp[p][p1] == 'B')p++, p1++, cnt++;
                if(cnt == 3){
                    f = 2;
                    break;
                }
                p = i, p1 = j, cnt = 0;
                while(mp[p][p1] == 'B')p++, p1--, cnt++;
                if(cnt == 3){
                    f = 2;
                    break;
                }
                p = i, p1 = j, cnt = 0;
                while(mp[p][p1] == 'B')p--, p1++, cnt++;
                if(cnt == 3){
                    f = 2;
                    break;
                }
                p = i, p1 = j, cnt = 0;
                while(mp[p][p1] == 'B')p--, p1--, cnt++;
                if(cnt == 3){
                    f = 2;
                    break;
                } 
            }
        }
        if(f)break;
    }
    if(f == 1){
        puts("KiKi wins!");
    }else if(f == 2){
        puts("BoBo wins!");
    }else{
        puts("No winner!");
    }
    
}