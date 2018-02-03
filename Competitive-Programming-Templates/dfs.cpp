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
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef pair< long long, long long > pll;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define pf(a) printf("%d\n",a)
#define scll(a) scanf("%l64d",&a)
#define pfll(a) printf("%l64d\n",a)
#define md 1000000007

vi vis;
vector<vi> adj;

void dfs(int i) {
    fore(j,0,adj[i].sz) {
        if(vis[adj[i][j]])
            continue;
        vis[adj[i][j]] = 1;
        dfs(adj[i][j]);
    }
}
int main() {
    int n, m;
    cin>>n>>m;
    adj.resize(n);
    vis.resize(n);
    fore(i,0,m) {
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fore(i,0,n){
        vis[i] = 0;
        dfs(i);
    }
    return 0;
}
