ll n, m, k, x, y, q, a[MAXN], vis[MAXN];
ll t[4 * MAXN];
vector<ll>g[MAXN], s;
void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = s[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm))
           + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
void dfs(ll u)
{
    vis[u] = 1;
    s.pb(u);
    for (auto it : g[u])
        if (!vis[it])    dfs(it);
    s.pb(u);
}
void solve()
{
    cin >> n >> q;
    forci(1, n + 1)  cin >> a[i];
    forci(0, n - 1)
    {
        ll u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    s.pb(0);    //adjusting for 1 based indexing;
    dfs(1);
    map<ll, ll>in, out; ll c = 1;
    for (ll i = 1; i < s.size(); i++)
    {
        if (in[s[i]] == 0)
            in[s[i]] = c++;
        else
            out[s[i]] = c++;
    }
    trace(s);
    for (ll i = 1; i <= n; i++)
    {
        s[in[i]] = a[i];
        s[out[i]] = a[i];
        trace(i, in[i], out[i]);
    }
    build(1, 0, s.size() - 1);
    while (q--)
    {
        ll x; cin >> x;
        if (x == 1)
        {
            ll idx, value; cin >> idx >> value;
            update(1, 0, s.size() - 1, in[idx], value);
            update(1, 0, s.size() - 1, out[idx], value);
            a[idx] = value;
        }
        else
        {
            ll idx; cin >> idx; //subtree sum
            cout << query(1, 0, s.size() - 1, in[idx], out[idx]) / 2 << "\n";
        }
    }
}
