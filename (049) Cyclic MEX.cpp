// Problem link: https://codeforces.com/contest/1905/problem/D
// Explanation video: https://www.youtube.com/watch?v=_6YbD3gI5PI
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        ll n; cin >> n;
        vll a(n), aa, dp(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        int j = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                aa.pb(a[i]);
                break;
            }
            j++;
        }
        while(a[(j + 1) % n] != 0){
            aa.pb(a[(j + 1) % n]);
            j++;
        }
        priority_queue<int> pq;
        map<int, int> mp;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[aa[i]] = 0;
            }
            else{
                while(pq.top() > aa[i]) pq.pop();
                dp[aa[i]] = dp[pq.top()] + ((i - mp[pq.top()]) * aa[i]);
            }
            ans = max(ans, dp[aa[i]] + n);
            pq.push(aa[i]);
            mp[aa[i]] = i;
        }
        cout << ans << '\n';
    }
}
