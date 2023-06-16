// Problem link: https://codeforces.com/problemset/problem/1633/D
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define plpii pair<ll, pair<int, int>>
#define plpll pair<ll, pair<ll, ll>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
//const ll mod = 998244353;
const int N = 2e5 + 5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

vi mn(1e3 + 1, -1);
vi bb, cc;

void bfs(){
    vb vis(1e3 + 1, false);
    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = true;
    while(!q.empty()){
        int curr = q.front().ff;
        int mnOp = q.front().ss;
        q.pop();
        if(curr > 1e3) continue;
        mn[curr] = mnOp;
        for(int i = 1; i <= curr; i++){
            int x = curr / i;
            int xx = curr + x;
            if(xx <= 1e3 && !vis[xx]){
                vis[xx] = true;
                q.push({xx, mnOp + 1});
            }
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
    bfs();

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vi b(n), c(n);
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++) cin >> c[i];
        bb.clear(); cc.clear();
        for(int i = 0; i < n; i++){
            if(mn[b[i]] != -1 && mn[b[i]] <= k){
                bb.pb(b[i]);
                cc.pb(c[i]);
            }
        }
        vi dp(k + 1, -1);
        dp[0] = 0;
        for(int i = 0; i < bb.size(); i++){
            for(int j = k; j >= 0; j--){
                if(j - mn[bb[i]] >= 0 && dp[j - mn[bb[i]]] != -1) dp[j] = max(dp[j], dp[j - mn[bb[i]]] + cc[i]);
            }
        }
        int mx = *max_element(dp.begin(), dp.end());
        if(mx == -1) cout << 0 << '\n';
        else cout << mx << '\n';
    }
}
