/*
 KUNAL RAUT (ZUKONIT14)  :- "DO WHAT YOU LIKE!"
 -PICT,PUNE! :)
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define mod9 1000000009
#define pi 3.1415926535
#define MAXN 1000001
#define N 1000001
#define MAX2N 1*1000 + 10
#define all(v) v.begin(), v.end()
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define forci(p,n) for(ll i=p;i<(ll)n;i++)
#define forcj(p,n) for(ll j=p;j<(ll)n;j++)
#define bolt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define bits(a) __builtin_popcount(a)
#define test ll t;cin>>t;while(t--)
ll zero=0;
ll one=1;
ll gcd(ll a,ll b){    if(b==0) return a;    return gcd(b,a%b);}
ll lcm(ll a,ll b) {    return (a/gcd(a,b)*b);}
ll expo(ll x, ll y) {ll res=1;x=x%mod;while(y>0){if(y&1)res=(1ll*res*x)%mod;
    y=y>>1;x=(1ll*x*x)%mod;} return res;}
ll ncr(ll n,ll r){ ll res=1; if(r>n-r)r=n-r; for(ll i=0;i<r;i++) {  res*=n-i;  res/=i+1; } return res;}
ll max(ll a,ll b){return (a>b)?a:b;}
bool prime(ll n){ll i;for(i=2;i<=sqrt(n);i++){if(n%i==0)return false;}return true;}
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{   if(a.second == b.second)
    return a.first < b.first;
    return (a.second < b.second);}

//https://www.youtube.com/watch?v=WTJSt4wP2ME

ll rr[]={0,1,1,1,0,-1,-1,-1,};
ll cc[]={1,1,0,-1,-1,-1,0,1};

signed main()
{
    bolt;
    string s,t;cin>>s>>t;
    ll dp[s.length()+5][t.length()+5];ms(dp,0);
    ll n=s.length(),m=t.length();
    forci(1,s.length()+1)
    {
        forcj(1,t.length()+1)
        {
            if(s[i-1]==t[j-1])  //matches
                dp[i][j]=dp[i-1][j-1]+1;
            else        //doesnt matches
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    ll val=dp[n][m];
    string ans;
    ll i=n,j=m;
    while(i&&j)
    {
        if(dp[i][j]!=max(dp[i-1][j],dp[i][j-1]))
        {
            ans.pb(s[i-1]);i--;j--;
        }
        else
        {
            if(dp[i][j]==dp[i-1][j])
                i--;
            else
                j--;
        }
    }
    reverse(all(ans));
    cout<<ans;
}
