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

int solve(ll req, ll tot, int med, int mean, int done, int min, int max) {
	if(req == tot) {
		return done;
	}
	if(tot>req) {
		int least = min + med;
		if(((double)least/2)>=mean) {
			return md;
		}
		tot+=med;
		req+=2*mean;
		ll dest = req - tot;
		if(dest>=min) {
			tot+=dest;
		}
		else {
			tot+=min;
		}
		return solve(req, tot, med, mean, done+2, min, max);
	}
	else {
		int most = max + med;
		if(((double)most/2)<=mean) {
			return md;
		}
		tot+=med;
		req+=2*mean;
		ll dest = req - tot;
		if(dest<=max) {
			tot+=dest;
		}
		else {
			tot+=max;
		}
		return solve(req, tot, med, mean, done+2, min, max);
	}
}

int main() {
	freopen("downloads/in.txt", "r", stdin);
	freopen("downloads/out.txt", "w", stdout);
	int t;
	cin>>t;
	fore(z,0,t) {
		cout<<"Case #"<< z+1 <<": ";
		int min, max, med, mean;
		cin>>min>>max>>mean>>med;
		// Exceptional cases
		if(min == max) {
			if(med == mean && med == min) {
				cout<<1<<endl;
				continue;
			}
			else {
				cout<<"IMPOSSIBLE"<<endl;
				continue;
			}
		}
		else if(max<min) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		if(med>max || med<min) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		if(mean>=max || mean<=min) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		if(min + max == 2*mean && mean == med) {
			cout<<2<<endl;
			continue;
		}
		// Test the 2 possibilities
		int fa = std::min(solve(mean*3, min+max+med, med, mean, 3, min, max), solve(mean*4, min+max+2*med, med, mean, 4, min, max));
		if(fa == md) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		cout<<fa;
		cout<<endl;
	}
	return 0;
}