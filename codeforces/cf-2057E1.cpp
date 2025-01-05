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
        int n, m, kk; cin >> n >> m >> kk;
        vector<vector<pair<int,int>>> G(n+5);
        vector<int> segw(m+5);
        vector<vector<vector<int>>> ans(n+5, vector<vector<int>>(n+5, vector<int>(n+5, 2e9)));
        for(int i = 1, u,v,w; i <= m; ++i) {
            cin >> u >> v >> w;
            G[u].push_back(pair<int,int>(v, w));
            G[v].push_back(pair<int,int>(u, w));
            segw[i] = w;
        }
        sort(segw.begin() + 1, segw.begin() + (1+m));
        m = unique(segw.begin() + 1, segw.begin() + (1+m)) - segw.begin() - 1;
 
        for(int t = 1;  t <= m; ++t) {
            vector<vector<int>> dis(n+5, vector<int>(n+5, 2e9));
            for(int i = 1; i <= n; ++i) {
                deque<int> qq;
                qq.push_back(i);
                dis[i][i] = 0;
                while(!qq.empty()) {
                    int x = qq.front(); qq.pop_front();
                    for(auto pp : G[x]) {
                        int d = (pp.second > segw[t]);
                        if(d + dis[i][x] < dis[i][pp.first]) {
                            dis[i][pp.first] = d + dis[i][x];
                            if(d) qq.push_back(pp.first);
                            else qq.push_front(pp.first);
                        }
                    }
                }
                for(int k = 1; k <= n; ++k)
                    ans[i][k][dis[i][k]+1] = min(ans[i][k][dis[i][k]+1], segw[t]);
            }
        }
 
        for(int i = 1, a,b,c; i <= kk; ++i) {
            cin >> a >> b >> c;
            cout << ans[a][b][c] << ((i==kk) ? '\n' : ' ');
        }
    }
    return 0;
}
