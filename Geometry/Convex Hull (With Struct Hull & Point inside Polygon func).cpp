struct point    
{
    int x, y;
    point(int xx, int yy):x(xx), y(yy){}
    point operator+(const point &p) const {return point(x+p.x, y+p.y);}
    point operator-(const point &p) const {return point(x-p.x, y-p.y);}
    bool operator<(const point &p) const {return x<p.x || (x==p.x and y<p.y);}
    bool operator==(const point &p) const {return x==p.x and y==p.y;}
    int cross(const point &p) const {return x*p.y-y*p.x;}
    int dot(const point &p) const {return x*p.x+y*p.y;}
    int cross(const point &a, const point &b) const {return (a-*this).cross(b-*this);}
    int dot(const point &a, const point &b) const {return (a-(*this)).dot(b-(*this));}
    int sqrlen() const {return this->dot(*this);}
};
 
bool cw(point a, point b, point c){return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;}
bool ccw(point a, point b, point c){return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0;}
 
struct HULL
{
    vector<point> vertices;
    HULL(vector<point> v):vertices(v)
    {
        vertices.pb(vertices[0]);
        reverse(vertices.begin(), vertices.end());
        vertices.pop_back();
        int pos=0, n=(int)vertices.size();
        for(int i=1; i<n; i++)
            if(vertices[i].y<vertices[pos].y or (vertices[i].y==vertices[pos].y and vertices[i].x<vertices[pos].x))
                pos=i;
        rotate(vertices.begin(), vertices.begin()+pos, vertices.end());
        v.clear();
        v.pb(vertices[0]);
        v.pb(vertices[1]);
        for(int i=2; i<=n; i++)
        {
            if((v[(int)v.size()-1]-v[(int)v.size()-2]).cross(vertices[i%n]-v[(int)v.size()-2])==0)
                v.pop_back();
            v.pb(vertices[i]);
        }
        v.pop_back();
        vertices=v;
    }
    bool PIP(point p)
    {
        int n=(int)vertices.size();
        bool ans=true;
        for(int i=0; i<n; i++)
            ans&=ccw(vertices[i], vertices[(i+1)%n], p);
        return ans;
    }
};
 
vector<HULL> hulls;
 
void convex_hull(vector<point> &a)
{
    set<point> allnow;
    for(auto z:a)
        allnow.insert(z);
    while(!((int)allnow.size()<3))
    {
        point p1=*allnow.begin(), p2=*allnow.rbegin();
        vector<point> up, down;
        up.pb(p1);
        down.pb(p1);
        for(auto it=++allnow.begin(); it!=allnow.end(); it++)
        {
            if(it==prev(allnow.end()) || !ccw(p1, *it, p2))
            {
                while((int)up.size()>1 and ccw(up[(int)up.size()-2], up[(int)up.size()-1], *it))
                    up.pop_back();
                up.pb(*it);
            }
            if(it==prev(allnow.end()) || !cw(p1, *it, p2))
            {
                while((int)down.size()>1 and cw(down[(int)down.size()-2], down[(int)down.size()-1], *it))
                    down.pop_back();
                down.pb(*it);
            }
        }
        for(int i=(int)down.size()-2; i>0; i--)
            up.pb(down[i]);
        if((up[1]-up[0]).cross(up[(int)up.size()-1]-up[0])==0)
            break;
        for(auto z:up)
            allnow.erase(z);
        hulls.pb(HULL(up));
    }
}
//ALSO ALL PROBLEMS FROM. GRAHAM SCAN CONVEX HULL.CPP

//Problem 0:https://www.codechef.com/JUNE20A/problems/CONTAIN
//Solution 0: https://www.codechef.com/viewsolution/34657860
