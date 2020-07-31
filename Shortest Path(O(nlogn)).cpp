ll n, m, k, x, y, z, q, a[MAXN], p[MAXN], d[MAXN];
vector<pair<ll, ll>>g[MAXN];
void dijkstra(ll s) {

    d[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : g[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    for (ll i = 1; i <= n; i++)
    {
        d[i] = INF; p[i] = -1;
    }
    dijkstra(1);
    for (ll i = 1; i <= n; i++)
        cout << d[i] << " ";
}
