// Problem link: https://codeforces.com/contest/1873/problem/H
// Video tutorial: https://www.youtube.com/watch?v=jLMyshkymE8
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define pipll pair<int, pair<ll, ll>>
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
#define vvvi vector<vector<vector<int>>>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vpipll vector<pair<int, pair<ll, ll>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

vi bfs(vvi al, int n, int a){
    vb vis(n + 1, false);
    vi depth(n + 1, 0);
    queue<int> q;
    q.push(a);
    vis[a] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto it : al[curr]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
                depth[it] = depth[curr] + 1;
            }
        }
    }
    return depth;
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

    int t; cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        vvi al(n + 1);
        vi deg(n + 1, 0);
        for(int i = 0; i < n; i++){
            int u, v; cin >> u >> v;
            al[u].pb(v);
            al[v].pb(u);
            deg[u]++;
            deg[v]++;
        }

        if(a == b){
            cout << "NO" << '\n';
            continue;
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(deg[i] == 1) q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            deg[curr]--;
            for(auto it : al[curr]){
                deg[it]--;
                if(deg[it] == 1) q.push(it);
            }
        }
        
        if(deg[b] >= 2) cout << "YES" << '\n';
        else{
            vi amin = bfs(al, n, a);
            vi bmin = bfs(al, n, b);
            bool flag = false;
            for(int i = 1; i <= n; i++){
                if(deg[i] >= 2 && bmin[i] < amin[i]){
                    flag = true;
                    break;
                }
            }
            if(flag) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}
