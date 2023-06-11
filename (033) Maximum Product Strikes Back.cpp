// Problem link: https://codeforces.com/problemset/problem/1660/D
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        int n; cin >> n;
        vi a;
        a.pb(0);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a.pb(x);
        }
        a.pb(0);
        int mx = 0;
        int front = 0, back = n;
        int zero = 0, neg = 0;
        int l = -1, r = -1;
        int L = -1, R = -1;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 0){
                zero++;
                if(l == -1) l = i, r = i;
                else r = i;
            }
            if(a[i] < 0){
                neg++;
                if(L == -1) L = i, R = i;
                else R = i;
            }
            if(zero == 2){
                if(neg & 1){
                    // Ignoring the first negative value
                    int cnt = 0;
                    for(int j = L + 1; j < r; j++){
                        if(a[j] == 2 || a[j] == -2) cnt++;
                    }
                    if(cnt > mx){
                        mx = cnt;
                        front = L, back = a.size() - r - 1;
                    }
                    // Ignoring the last negative value
                    cnt = 0;
                    for(int j = l + 1; j < R; j++){
                        if(a[j] == 2 || a[j] == -2) cnt++;
                    }
                    if(cnt > mx){
                        mx = cnt;
                        front = l, back = a.size() - R - 1;
                    }
                    zero = 1;
                    l = r;
                    neg = 0;
                    L = -1, R = -1;
                }
                else{
                    int cnt = 0;
                    for(int j = l + 1; j < r; j++){
                        if(a[j] == 2 || a[j] == -2) cnt++;
                    }
                    if(cnt > mx){
                        mx = cnt;
                        front = l, back = a.size() - r - 1;
                    }
                    zero = 1;
                    l = r;
                    neg = 0;
                    L = -1, R = -1;
                }
            }
        }
        cout << front << " " << back << '\n';
    }
}
