#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int 
#define mp make_pair 
#define pb push_back 
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define all(v) v.begin(),v.end()
#define pll pair<ll , ll>
using namespace std;
template<typename T> T lcm(T a ,T b) {return a*b/__gcd(a,b);}

const int mod = 1000000007;
void solve() {
   int n,m;
   cin >> n >> m;
   vector<vector<int>> v(n,vector<int>(m)) , dp(n,vector<int>(m , -1));
   for(int i = 0;i<n;++i) {
   	for(int j = 0;j<m;++j) {
   		cin >> v[i][j];
   	}
   }
   int a,b,x,y;
   cin >> a >> b >> x >> y;
   
   dp[a-1][b-1] = v[a-1][b-1];
   for(int i = b;i<m;++i) dp[a-1][i] = v[a-1][i] + dp[a-1][i-1];
   for(int i = a;i<n;++i) dp[i][b-1] = v[i][b-1] + dp[i- 1][b-1];   // base cases
    
   for(int i = a;i<n;++i) {
   	for(int j = b;j<m;++j) {
   		dp[i][j] = v[i][j] + min(dp[i-1][j] , dp[i][j-1]);
   	}
   }
   cout << dp[x-1][y-1] << endl;
    
}
int main(){
    std::ios::sync_with_stdio(false);
        solve();
   
}

