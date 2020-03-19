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
#define test ll t;cin>>t;for(ll testi=1;testi<=t;testi++)
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
ll l,r,diff,pos=0,ans=0,power2=1;
signed main()
{
    bolt;
    cin>>l>>r;
    diff=r-l;
    //CHECKING IN THE DIFFERENCE THAT iTH BIT LIES IN RANGE OR NOT
    while(diff>=power2)
    {
        ans+=power2;
        power2*=2;
        pos++;
    }
    //CHECKING IN RIGHT NUMBER IF LEFT BITS ARE NOT SET AND RIGHT SET AND VICE VERSA
    while(r>=power2)
    {
        if((((l>>pos)^(r>>pos))&1LL)==1LL)    ans+=power2;
        power2*=2;
        pos++;
    }
    cout<<ans;
}

//PROBLEM 1:  https://codeforces.com/contest/276/problem/D
//SOLUTION 1: https://codeforces.com/contest/276/submission/73639767 
