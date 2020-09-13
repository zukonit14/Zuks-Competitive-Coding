vector<ll>order; //Stores the Topological Order

bool toposort(ll n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	queue<ll> q;
	vector<ll> indeg(n + 1, 0);
	for(ll i = 1; i <= n; i++)
		for(auto &it:g[i])
			indeg[it]++;
	for(ll i = 1; i <= n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
	while(!q.empty())
	{
		ll u = q.front();
		q.pop();
		order.push_back(u);
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}



//Also another implementation for finding order if toposort exists;
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
