// Problem link: https://codeforces.com/problemset/problem/1778/C
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
//const int mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

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
        ll n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                mp[a[i]]++;
            }
        }
        string s;
        for(auto it : mp){
            s.pb(it.ff);
        }
        if(s.size()){
            if(k >= s.size()){
                ll ans = n * (n + 1) / 2;
                cout << ans << '\n';
            }
            else{
                int p = s.size();
                int sz = pow(2, p);
                map<char, int> mpp;
                for(int i = 0; i < s.size(); i++){
                    mpp[s[i]] = i;
                }
                ll ans = 0;
                for(int mask = 0; mask < sz; mask++){
                    if(__builtin_popcount(mask) <= k){
                        ll curr = 0;
                        vb taken(n, false);
                        for(int i = 0; i < n; i++){
                            if(a[i] == b[i] || (mask & (1 << mpp[a[i]]))) taken[i] = true;
                        }
                        ll con = 0;
                        for(int j = 0; j < n; j++){
                            if(taken[j]) con++;
                            else{
                                curr += con * (con + 1) / 2;
                                con = 0;
                            }
                        }
                        curr += con * (con + 1) / 2;
                        ans = max(ans, curr);
                    }
                }
                cout << ans << '\n';
            }
        }
        else{
            ll ans = n * (n + 1) / 2;
            cout << ans << '\n';
        }
    }
}
