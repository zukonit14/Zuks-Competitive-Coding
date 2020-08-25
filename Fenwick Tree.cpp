ll bit[MAXN+10];

void upd(ll i,ll x) 
{
    i++;
    for(;i<MAXN;i+=i&-i)
        bit[i]+=x;
}

ll qry(ll i)    
{
    ll r=0;
    i++;
    for(;i;i-=i&-i)
        r+=bit[i];
    return r;
}
