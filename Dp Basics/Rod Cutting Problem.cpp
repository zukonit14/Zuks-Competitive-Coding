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
    //CODE FOR FINDING MAX VALUE OBTAINED BY CUTTING ROD INTO PIECES OF Ith SIZE GIVES PRICE OF A[i] AND FINDING FOR ROD OF LENGTH N WITH PRICE[0..N-1] GIVEN.
    ll n;cin>>n;ll a[n];
    forci(0,n)  cin>>a[i];
    ll dp[n+5];ms(dp,0);
    for(ll i=1;i<=n;i++)
    {
        ll max_val=INT_MIN;
        for(ll j=0;j<i;j++)
        {
            max_val=max(max_val,a[j]+dp[i-j-1]);    //i-j is difference needed for j to complete till i
        }
        dp[i]=max_val;
    }
    cout<<dp[n];
}
