// Problem link: https://codeforces.com/contest/1898/problem/C
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

//const ll mod = 1e9 + 7;
const ll mod = 998244353;
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
        ll n, m, k; cin >> n >> m >> k;
        ll mn = (n - 1) + (m - 1);
        
        if(k < mn){
            cout << "NO" << '\n';
            continue;
        }
        else if(k > mn){
            if((k - mn) & 1){
                cout << "NO" << '\n';
                continue;
            }
        }

        ll nn = n + (n - 1);
        ll mm = m + (m - 1);
        vector<vector<char>> a(nn, vector<char>(mm, 'E'));
        
        for(int j = 1; j < mm; j+=2){
            if(j == 1) a[0][j] = 'R';
            else{
                if(a[0][j - 2] == 'R') a[0][j] = 'B';
                else if(a[0][j - 2] == 'B') a[0][j] = 'R';
            }
        }
        for(int i = 1; i < nn; i+=2){
            if(i == 1){
                if(a[0][mm - 2] == 'B') a[i][mm - 1] = 'R';
                else if(a[0][mm - 2] == 'R') a[i][mm - 1] = 'B';
            }
            else{
                if(a[i - 2][mm - 1] == 'R') a[i][mm - 1] = 'B';
                else if(a[i - 2][mm - 1] == 'B') a[i][mm - 1] = 'R';
            }
        }
        for(int i = 0; i < nn; i++){
            for(int j = 0; j < mm; j++){
                if(i & 1){
                    if(!(j & 1)){
                        if(a[i][j] == 'E') a[i][j] = 'R';
                    }
                }
                else{
                    if(j & 1){
                        if(a[i][j] == 'E') a[i][j] = 'R';
                    }
                }
            }
        }
        if(k - mn == 2){
            if(a[nn - 2][mm - 1] == 'R'){
                a[nn - 1][mm - 2] = 'R';
                a[nn - 3][mm - 2] = 'R';
                a[nn - 2][mm - 3] = 'B';
            }
            else if(a[nn - 2][mm - 1] == 'B'){
                a[nn - 1][mm - 2] = 'B';
                a[nn - 3][mm - 2] = 'B';
                a[nn - 2][mm - 3] = 'R';
            }
        }
        else{
            if((k - mn) % 4 == 0){
                if(a[nn - 2][mm - 1] == 'R') a[nn - 1][mm - 2] = 'B';
                else if(a[nn - 2][mm - 1] == 'B') a[nn - 1][mm - 2] = 'R';

                if(a[nn - 1][mm - 2] == 'R') a[nn - 2][mm - 3] = 'B';
                else if(a[nn - 1][mm - 2] == 'B') a[nn - 2][mm - 3] = 'R';

                if(a[nn - 2][mm - 3] == 'R') a[nn - 3][mm - 2] = 'B';
                else if(a[nn - 2][mm - 3] == 'B') a[nn - 3][mm - 2] = 'R';
            }
            else{
                if(a[nn - 2][mm - 1] == 'R') a[nn - 1][mm - 2] = 'B';
                else if(a[nn - 2][mm - 1] == 'B') a[nn - 1][mm - 2] = 'R';

                if(a[nn - 1][mm - 2] == 'R') a[nn - 2][mm - 3] = 'B';
                else if(a[nn - 1][mm - 2] == 'B') a[nn - 2][mm - 3] = 'R';

                if(a[nn - 2][mm - 3] == 'R') a[nn - 3][mm - 2] = 'B';
                else if(a[nn - 2][mm - 3] == 'B') a[nn - 3][mm - 2] = 'R';

                if(a[0][1] == 'R'){
                    a[1][0] = 'R';
                    a[1][2] = 'R';
                    a[2][1] = 'B';
                }
                else if(a[0][1] == 'B'){
                    a[1][0] = 'B';
                    a[1][2] = 'B';
                    a[2][1] = 'R';
                }
            }
        }
        cout << "YES" << '\n';
        for(int i = 0; i < nn; i+=2){
            for(int j = 1; j < mm; j+=2){
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
        for(int i = 1; i < nn; i+=2){
            for(int j = 0; j < mm; j+=2){
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
}
