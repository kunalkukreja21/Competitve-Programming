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

vi tree;

void increase(int i, int delta)
{
    for (; i < (int)tree.size(); i |= i + 1)
    	tree[i] += delta;
}

int sum(int ind)
{
    int sum = 0;
    while (ind>=0)
    {
        sum += tree[ind];
        ind &= ind + 1;
        ind--;
    }
    return sum;
}

int getsum(int left, int right)
{
    return sum(right) - sum(left-1); 
}

int main() {
	int n;
	cin>>n;
	tree.resize(n);
	fore(i,0,n)
		tree[i] = 0;
	return 0;
}
