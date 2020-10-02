//use it by DSU d(N) where n is the number upto which it is supposed to constructed...
struct DSU
{
    int connected;
    int par[MAX], size[MAX];

   // DSU() {}

    DSU(int n)
    {
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            size[i]=1;
        }
        connected=n;
    }

    int getPar(int k)
    {
        while(k!=par[k])
        {
            par[k]=par[par[k]];
            k=par[k];
        }
        return k;
    }

    int getSize(int k)
    {
        return size[getPar(k)];
    }

    void unite(int u, int v)
    {
        int par1=getPar(u), par2=getPar(v);

        if(par1==par2)
            return;

        connected--;

        if(size[par1]>size[par2])
            swap(par1, par2);

        size[par2]+=size[par1];
        size[par1]=0;
        par[par1]=par[par2];
    }
};
