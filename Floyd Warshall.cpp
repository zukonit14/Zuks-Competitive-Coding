ll d[MAX2N][MAX2N];   //INF initially,0 for i->i and w for u->v & v->u;

void FloydWarshall()
{
    for (ll k = 1; k <= n; k++)         //i->source,j->destination,k->mid;
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (d[i][k] < INF && d[k][j] < INF)             //ensures ther is edge between i->k & k->j; 
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
