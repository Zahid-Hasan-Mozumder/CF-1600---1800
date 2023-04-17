// Problem link: https://codeforces.com/contest/1807/problem/F
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        int n, m, i1, j1, i2, j2, x, y; string s;
        cin>> n >> m >> i1 >> j1 >> i2 >> j2 >> s;
        int bounce = 0, ans = -1;
        vvi vis(n + 1, vi(m + 1, 0));
        int i = i1, j = j1;
        while(true){
            if((i == 1 || i == n) && (j == 1 || j == m) && vis[i][j] == 1) break;
            else if(vis[i][j] >= 2) break;
            int mn = INT_MAX;
            //cout<< "(" << i << ", " << j << ") ";
            if(s[0] == 'U') mn = min(mn, abs(1 - i));
            else mn = min(mn, abs(n - i));
            if(s[1] == 'L') mn = min(mn, abs(1 - j));
            else mn = min(mn, abs(m - j));

            if(s[0] == 'U'){
                x = i - mn; if(x == 1) s[0] = 'D';
            }
            else{
                x = i + mn; if(x == n) s[0] = 'U';
            }
            if(s[1] == 'L'){
                y = j - mn; if(y == 1) s[1] = 'R';
            }
            else{
                y = j + mn; if(y == m) s[1] = 'L';
            }

            if(abs(i2 - i) == abs(j2 - j) && abs(i2 - x) == abs(j2 - y) && abs(i2 - i) + abs(i2 - x) == abs(i - x)){
                ans = bounce;
                break;
            }

            if(i1 != -1 && j1 != -1) i1 = -1, j1 = -1;
            else vis[i][j]++;
            i = x; j = y;
            bounce++;
        }
        cout << ans << '\n';
    }
}
