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
vi getInput(string &s ) {
    stringstream ss(s);
    int num;
    vi temp;
    while(ss >> num) {
        temp.pb(num);
    }
    return temp;
}
int f(int ind,int tar , vector<vector<pii>> &v) {
    if(ind == 0) return 0;
    
    int mx = f(ind - 1, tar,v), n = v[ind].size();
    for(int i = 0;i<n;++i) {
        if(tar >= v[ind][i].second)
            mx = max(mx , v[ind][i].first );
    }
    return mx;
}
void solve() {
   string s1,s2,s3;
   getline(cin ,s1);
   getline(cin ,s2);
   getline(cin ,s3);
   vector<int> v1,v2,v3;
   v1 = getInput(s1);
   v2 = getInput(s2);
   v3 = getInput(s3);
   int n = v1.size() , bsize ;
   cin >> bsize;                // Input ends
   
   int mx = *max_element(all(v3));
   
   // Build a 2D matrix  where v[i] represents list of {damage,size} of category i
   
   vector<vector<pii>> v(mx+1,vector<pii>());    
   for(int i = 0;i<n;++i) {                      
     v[v3[i] - 1].pb({v1[i] , v2[i]});
   }
   n = v.size();
   vector<vector<int>> dp(n, vector<int>(bsize+1,0));
   
   for(int i = 0;i<(int)v[0].size();++i) {
    for(int j = 0;j<=bsize;++j) {
        if(v[0][i].second <= j) dp[0][j] = max(dp[0][j] , v[0][i].first);   // base case
    }
   }
   for(int i = 1;i<(int)v.size();++i) {
    for(int j = 0;j<=bsize;++j) {
        int mx = dp[i-1][j];
        for(int k = 0;k<(int)v[i].size();++k) {
            if(v[i][k].second <= j) 
                mx = max(mx,v[i][k].first + dp[i-1][j - v[i][k].second]);
        }
        dp[i][j] = mx;
    }
   }
   
   cout << dp[n-1][bsize] << endl;
   
    
}
int main(){
    std::ios::sync_with_stdio(false);
    solve();
    
}

