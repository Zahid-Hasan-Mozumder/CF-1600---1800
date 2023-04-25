// Problem link: https://codeforces.com/contest/1809/problem/D
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        string s; cin >> s;
        int n = s.size();
        vll one(n), zero(n);
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            one[i] = cnt;
            if(s[i] == '1') cnt++;
        }
        cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            zero[i] = cnt;
            if(s[i] == '0') cnt++;
        }
        ll ans = LLONG_MAX;
        for(int i = 0; i < n; i++){
            ll curr = (1e12 + 1) * (one[i] + zero[i]);
            if(s[i] == '1' && i + 1 < n && s[i + 1] == '0') curr--;
            if(s[i] == '0' && i - 1 >= 0 && s[i - 1] == '1') curr--;
            ans = min(ans, curr);
        }
        cout << ans << '\n';
    }
}
