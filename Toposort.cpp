vector<ll>order;
void dfs(ll u)
{
    vis[u] = 1;
    for (auto it : g[u])
        if (!vis[it])    dfs(it);
    order.pb(u);
}
void toposort()     //take n as parameter and at last return (ans.size()==n) to check whether topo exist
{
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    reverse(all(order));
}
