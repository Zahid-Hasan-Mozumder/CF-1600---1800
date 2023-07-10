// Problem link: https://codeforces.com/problemset/problem/1615/C
// Video editorial: https://www.youtube.com/watch?v=q7WRShKzWhM
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
const int N = 2e6 + 2;
const int sz = 1e6 + 2;
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
        int n; cin >> n;
        string a, b; cin >> a >> b;
        bool flag = false;
        if(a == b) flag = true;
        if(flag){
            cout << 0 << '\n';
        }
        else{
            int cnt01 = 0, cnt10 = 0, cnt11 = 0, cnt00 = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == '1' && b[i] == '1') cnt11++;
                if(a[i] == '1' && b[i] == '0') cnt10++;
                if(a[i] == '0' && b[i] == '1') cnt01++;
                if(a[i] == '0' && b[i] == '0') cnt00++;
            }
            int ans = INT_MAX;
            if(cnt01 == cnt10) ans = min(ans, cnt10 + cnt01);
            // Flipping 11
            if(cnt11){
                int curr10 = cnt00, curr01 = cnt11 - 1;
                if(curr01 == curr10) ans = min(ans, 1 + curr01 + curr10);
            }
            // Flipping 10
            if(cnt10){
                int curr10 = cnt00 + 1, curr01 = cnt11;
                if(curr01 == curr10) ans = min(ans, 1 + curr01 + curr10);
            }
            if(ans == INT_MAX) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
}
