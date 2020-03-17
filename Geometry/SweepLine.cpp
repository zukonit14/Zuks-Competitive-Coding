//HERE SWEEPLINE IS PARALLEL TO X AXIS AND MOVING UPWARDS


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

ll n,q,a[MAXN],ft[MAXN],ql[MAXN],qr[MAXN],qy[MAXN],ans[MAXN];

void upd(ll i,ll x) 
{
    for(++i;i<n;i+=i&-i)
        ft[i]+=x;
}

ll qry(ll i)    
{
    ll r=0;
    for(;i;i-=i&-i)
        r+=ft[i];
    return r;
}

struct event
{
    ll y,t,i;
    // bool operator<(const event &o)  const
    // {
    //     return make_pair(y,t)<make_pair(o.y,o.t);
    // }
};

bool comp(const event &a,const event &b)
{   
    if(a.y==b.y)
        return (a.t<b.t);
    return (a.y<b.y);
}
signed main()
{
    bolt;
    test
    {
        cin>>n>>q;
        forci(0,n)  cin>>a[i];
        forci(0,q)  cin>>ql[i]>>qr[i]>>qy[i],ql[i]--,qr[i]--;
        vector<event>ve;
        for(ll i=0;i+1<n;i++)
        {
            ve.pb({min(a[i],a[i+1]),1,i});//ADD SEGMENT
            ve.pb({max(a[i],a[i+1]),3,i});//DELETE SEGMENT
        }
        for(ll i=0;i<q;i++)
            ve.pb({qy[i],2,i}); //QUERIES ADDED
        sort(all(ve),comp);//SORTING QUERIES ACCORDING TO Y
        //OUR SWEEPLINE IS PARALLEL TO X AXIS AND MOVING UPWARDS
        for(event e: ve)
        {
            if(e.t==1)
                upd(e.i,1);//ADD SEGMENT AND IN THAT RANGE ANS INC BY 1
            else if(e.t==2)
                ans[e.i]=qry(qr[e.i])-qry(ql[e.i]);   //ANSWER NO OF 1's IN L TO R
            else
                upd(e.i,-1);// DELETE SEGMENT FROM RANGE
        }
        forci(0,q)  cout<<ans[i]<<"\n";
    }
}


//PROBLEM 1: https://www.codechef.com/problems/LAZER
//SOLUTION 1: https://www.codechef.com/viewsolution/30539369
