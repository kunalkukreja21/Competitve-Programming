#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007


int n,m;

vector<vi> adj;
vector<pii> grph;
vi vis, component;
int s,t,ds,dt;

void dfs(int i, int k) {
    component[i] = k;
    fore(j,0,adj[i].sz) {
        if(vis[adj[i][j]]) {
            continue;
        }
        if(adj[i][j] == s || adj[i][j] == t) {
            continue;
        }
        vis[adj[i][j]] = 1;
        grph.pb(mp(i,adj[i][j]));
        dfs(adj[i][j], k);
    }
}

inline void inputAndInitialSettings() {
    cin>>n>>m;
    adj.resize(n);
    vis.resize(n);
    component.resize(n);
    fore(i,0,m) {
        int u,v;
        cin>>u>>v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
    fore(i,0,n) {
        vis[i] = 0;
    }
    cin>>s>>t>>ds>>dt;
    s--;t--;
}

int main() {
    inputAndInitialSettings();
    int doneComponents = 1;
    fore(i,0,n) {
        if(i == s || i == t) {
            continue;
        }
        if(vis[i] == 0) {
            vis[i] = 1;
            dfs(i, doneComponents);
            doneComponents++;
        }
    }
    vector<vector<pii> > connectedTo(doneComponents-1);
    set<int> added;
    fore(j,0,adj[s].sz) {
        if(vis[adj[s][j]]) {
            if(added.find(component[adj[s][j]] - 1) == added.end()) {
                connectedTo[component[adj[s][j]] - 1].pb(mp(s,adj[s][j]));
                added.insert(component[adj[s][j]] - 1);
            }
        }
    }
    added.clear();
    fore(j,0,adj[t].sz) {
        if(vis[adj[t][j]]) {
            if(added.find(component[adj[t][j]] - 1) == added.end()) {
                connectedTo[component[adj[t][j]] - 1].pb(mp(t,adj[t][j]));
                added.insert(component[adj[t][j]] - 1);
            }
        }
    }
    fore(i,0,doneComponents-1) {
        if(connectedTo[i].sz == 1) {
            if(connectedTo[i][0].ff == s) {
                grph.pb(mp(s,connectedTo[i][0].ss));
                ds--;
            }
            else if(connectedTo[i][0].ff == t){
                grph.pb(mp(t,connectedTo[i][0].ss));
                dt--;
            }
        }
    }
    if(ds<0 || dt<0) {
        cout<<"No";
        return 0;
    }
    bool foundTwoOnce = false;
    fore(i,0,doneComponents-1) {
        if(connectedTo[i].sz == 2) {
            if(!foundTwoOnce) {
                foundTwoOnce = true;
                fore(j,0,2) {
                    if(connectedTo[i][j].ff == s) {
                        grph.pb(mp(s,connectedTo[i][j].ss));
                        ds--;
                    }
                    else if(connectedTo[i][j].ff == t){
                        grph.pb(mp(t,connectedTo[i][j].ss));
                        dt--;
                    }
                }
            }
            else {
                if(ds>0) {
                    ds--;
                    grph.pb(mp(s,connectedTo[i][0].ss));
                }
                else {
                    dt--;
                    grph.pb(mp(t,connectedTo[i][0].ss));
                }
            }
        }
    }
    if(!foundTwoOnce) {
        ds--;
        dt--;
        bool cool = false;
        fore(i,0,adj[s].sz) {
            if(adj[s][i] == t) {
                cool = true;
            }
        }
        if(cool) {
            grph.pb(mp(s,t));
        }
        else {
            cout<<"No";
            return 0;
        }
    }
    if(dt<0 || ds<0) {
        cout << "No";
        return 0;
    }
    cout<<"Yes"<<endl;
    fore(i,0,n-1) {
        cout<<grph[i].ff + 1<<" "<<grph[i].ss + 1<<endl;
    }
    return 0;
}