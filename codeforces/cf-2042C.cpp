#include<bits/stdc++.h>
 
using namespace std;
 
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define PER(i,a,b) for(int i = a; i >= b; --i)
#define PB push_back
#define MP make_pair
#define fi first
#define se second
typedef long long LL;
typedef long double LD;
 
int main() {
    ios::sync_with_stdio(0);
    int _; cin >> _;
    while(_--) {
        int n, kk; cin >> n >> kk;
        string ss; cin >> ss;
        vector<int> sfx(n-1);
        for(int i = n-1, t = 0; i >= 1; --i)
            t += (ss[i] == '1') ? 1 : -1, sfx[i-1] = t;
        sort(sfx.begin(), sfx.end());
        LL sum = 0;
        int ans = -1;
        for(int i = 1; i <= n-1; ++i) {
            if(sfx[n-1-i] <= 0) break;
            sum += sfx[n-1-i];
            if(sum >= kk) {
                ans = i+1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
