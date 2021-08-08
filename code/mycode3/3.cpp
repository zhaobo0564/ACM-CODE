    #include<bits/stdc++.h>
    using namespace std;
    int t;
     
    double c, h, te;
     
    vector<int>g;
     
    int main(){
        g.push_back(0);
        scanf("%d", &t);
        while(t--){
            scanf("%lf %lf %lf", &h, &c, &te);
            double cnt = (h + c) / 2;
            double cnt1 = te - cnt;
            double eps = 1e-9;
            if(cnt1 < 0){
                puts("2");
                continue;
            }
            
            double cat = h - cnt;
            long long j = cat / cnt1;
            long long be = j - 10;
            long long end = j + 10;
            double maxn = 100000000.0;
            long long ans;
            for(int i = max((long long)3, be); i <= end; i++){
                //cout << "cnt" << cnt << endl;
                cat = ((double)(i / 2) * (h + c));
               // cout <<cat << endl;
                if(i % 2){
                    cat += h;
                }
                cat = cat /(double)(i);
               // cout << cat <<" " << i <<endl;
                if(fabs(cat - te) < maxn){
                    maxn = fabs(cat - te);
                    ans = i;
                }
     
            }
            if(fabs(h - te) <= maxn){
                maxn = fabs(h - te);
                ans = 1;
            }
            if(fabs(cnt - te) <= maxn){
                maxn = fabs(cnt - te);
                ans = 2;
            }
            
     
          
            printf("%lld\n", ans);
        }
    }