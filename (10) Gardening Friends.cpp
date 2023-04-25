// Problem link: https://codeforces.com/contest/1822/problem/F
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define plpii pair<ll, pair<int, int>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const int mod = 1e9+7;
const int MOD = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

vll depth(sz);
vvll lvl(sz);
ll ans;
ll n, k, c;
vvi al(sz);

void dfs(int u, int p){
    depth[u] = 0;
    for(int j=0; j<al[u].size(); j++){
        if(al[u][j] != p){
            dfs(al[u][j], u);
            depth[u] = max(depth[u], depth[al[u][j]] + 1);
            lvl[u].pb(depth[al[u][j]] + 1);
        }
    }
}

void dfs2(int u, int p, ll up, ll cng){
    lvl[u].pb(up);
    sort(lvl[u].begin(), lvl[u].end());
    ll curr = (lvl[u].back() * k) - (cng * c);
    ans = max(ans, curr);
    int sz = lvl[u].size();
    for(int j=0; j<al[u].size(); j++){
        if(al[u][j] != p){
            ll down = depth[al[u][j]] + 1;
            if(down < lvl[u][sz -1]) dfs2(al[u][j], u, lvl[u][sz - 1] + 1, cng + 1);
            else dfs2(al[u][j], u, lvl[u][sz - 2] + 1, cng + 1);
        }
    }
}

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();
    
    int t; cin>>t;
    while(t--){
        lvl.clear(), depth.clear(), al.clear();
        cin >> n >> k >> c;
        al.resize(n + 1);
        lvl.resize(n + 1);
        for(int i = 1; i <= n - 1; i++){
            int u, v; cin >> u >> v;
            al[u].pb(v);
            al[v].pb(u);
        }
        dfs(1, 0);
        if(c >= k){
            cout<< depth[1] * k << '\n';
        }
        else{
            ans = LLONG_MIN;
            dfs2(1, 0, 0, 0);
            cout<< ans << '\n';
        }
    }
}
