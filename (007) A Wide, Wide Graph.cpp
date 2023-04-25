// Problem link: https://codeforces.com/problemset/problem/1805/D
// Helpful video: https://www.youtube.com/watch?v=SfwmQ-ZWF8w
// Helpful video: https://www.youtube.com/watch?v=-aOQAxuRb24
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

int n;
vvi al;

int farthestNode(int i){
    int fn = -1;
    queue<int> q;
    vb vis(n + 1, false);
    vis[i] = true;
    q.push(i);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        fn = curr;
        for(int j = 0; j<al[curr].size(); j++){
            if(!vis[al[curr][j]]){
                vis[al[curr][j]] = true;
                q.push(al[curr][j]);
            }
        }
    }
    return fn;
}

vi dist(int i){
    vi d(n + 1, 0);
    queue<int> q;
    vb vis(n + 1, false);
    vis[i] = true;
    q.push(i);  
    d[i] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int j = 0; j < al[curr].size(); j++){
            if(!vis[al[curr][j]]){
                vis[al[curr][j]] = true;
                q.push(al[curr][j]);
                d[al[curr][j]] = d[curr] + 1;
            }
        }
    }
    return d;
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
    
    cin >> n;
    al.resize(n + 1);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        al[u].pb(v);
        al[v].pb(u);
    }
    int x = farthestNode(1);
    int y = farthestNode(x);
    vi distx = dist(x);
    vi disty = dist(y);
    vi mxDist;
    for(int i=1; i<=n; i++){
        mxDist.pb(max(distx[i], disty[i]));
    }
    sort(mxDist.begin(), mxDist.end());
    for(int i=1; i<=n; i++){
        int ind = lower_bound(mxDist.begin(), mxDist.end(), i) - mxDist.begin();
        if(ind == n) cout << n << " ";
        else cout<< ind + 1 << " ";
    }
    cout<< '\n';
}
