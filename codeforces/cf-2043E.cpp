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
 
const int maxn = 1e3;
 
int n, m;
vector<vector<int>> A(maxn+5, vector<int>(maxn+5));
vector<vector<int>> B(maxn+5, vector<int>(maxn+5));
vector<vector<int>> bitA = A, bitB = B;
 
bool dfs(int x, vector<vector<int>> &G, vector<int> &vis) {
    vis[x] = 1;
    for(auto y : G[x]) {
        if(vis[y] == 1) return false;
        if(vis[y] == 2) continue;
        if(!dfs(y, G, vis)) return false;
    }
    vis[x] = 2;
    return true;
}
 
bool check() {
    vector<vector<int>> G(n+m+5);
    vector<int> must(n+m+5, 0), vis(n+m+5, 0);
    REP(i,1,n) REP(k,1,m) {
        if(bitA[i][k] != bitB[i][k]) {
            if(bitA[i][k]) must[i] = 1;
            else must[n+k] = 1;
        }
        if(bitB[i][k]) G[i].push_back(n+k);
        else G[n+k].push_back(i);
    }
    REP(i,1,n+m) if(must[i] && !vis[i]) {
        if(!dfs(i, G, vis)) return false;
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(0);
    int _; cin >> _;
    while(_--) {
        cin >> n >> m;
        REP(i,1,n) REP(k,1,m) cin >> A[i][k];
        REP(i,1,n) REP(k,1,m) cin >> B[i][k];
        int flag = 1;
        for(int t = 0; t < 31 && flag; ++t) {
            REP(i,1,n) REP(k,1,m) {
                bitA[i][k] = (A[i][k] >> t & 1);
                bitB[i][k] = (B[i][k] >> t & 1);
            }
            flag &= check();
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
