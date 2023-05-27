// Problem link: https://codeforces.com/problemset/problem/1714/D
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
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvs vector<vector<string>>
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
#define vvvll vector<vector<vector<ll>>>

const ll mod = 1e9+7;
//const ll mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;


int dp[105];
int used[105];
int depression(string &s, vs &a, int i){
    if(i >= s.size()) return 0;
    if(dp[i] != -1) return dp[i];
    int res = 1000;
    for(int j = 0; j < a.size(); j++){
        string ss = s.substr(i, a[j].size());
        if(ss == a[j]){
            int curr = 1000;
            for(int k = 0; k < ss.size(); k++){
                curr = min(curr, depression(s, a, i + k + 1) + 1);
            }
            if(curr < res){
                res = curr;
                used[i] = j;
            }
        }
    }
    return dp[i] = res;
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

    int t = 1; cin >> t;
    for(int cs = 1; cs <= t; cs++){
        string s; cin >> s;
        int n; cin >> n;
        vs a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        memset(dp, -1, sizeof(dp));
        memset(used, -1, sizeof(used));
        int ans = depression(s, a, 0);
        vb taken(ans + 1, false);
        vpii aa;
        for(int i = 0; i < s.size(); i++){
            if(dp[i] >= 1 && dp[i] <= ans){
                if(!taken[dp[i]]){
                    taken[dp[i]] = true;
                    aa.pb({used[i] + 1, i + 1});
                }
            }
        }
        if(ans == 1000) cout << -1 << '\n';
        else{
            cout << ans << '\n';
            for(auto it : aa){
                cout << it.ff << " " << it.ss << '\n';
            }
        }
    }
}
