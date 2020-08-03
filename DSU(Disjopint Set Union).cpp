struct DSU
{
    ll connected;
    vector<ll> par, sz;

    void init(ll n)
    {
        par = sz = vector<ll> (n + 1, 0);
        for (ll i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
        connected = n;
    }

    ll getpar(ll u)
    {
        while (u != par[u])
        {
            par[u] = par[par[u]];
            u = par[u];
        }
        return u;
    }

    ll getsize(ll u)
    {
        return sz[getpar(u)];
    }

    void unite(ll u, ll v)
    {
        ll par1 = getpar(u), par2 = getpar(v);

        if (par1 == par2)
            return;

        connected--;

        if (sz[par1] > sz[par2])
            swap(par1, par2);

        sz[par2] += sz[par1];
        sz[par1] = 0;
        par[par1] = par[par2];
    }
};


//DSU dsu;
//dsu.init(n);
