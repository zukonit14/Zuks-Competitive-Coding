ll bit[MAXN];

void upd(ll i,ll x) 
{
    for(;i<n;i+=i&-i)
        bit[i]+=x;
}

ll qry(ll i)    
{
    ll r=0;
    for(;i;i-=i&-i)
        r+=bit[i];
    return r;
}
