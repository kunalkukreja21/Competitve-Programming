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
#define N 1123

string s1, s2;
int n,m;
int dp[N][N];

bool match(int i, int j, vector<int> &next_char_idx_1, vector<int> &next_char_idx_2 ) {
	if(i>=n && j>=m) {
		return true;
	}
	if(i>=n) i = n;
	if(j>=m) j = m;
	if(dp[i][j]!=-1) { return dp[i][j]==1; }

	bool matches = false;
	if(s1[i]!='*' && s2[j]!='*') {
		if(s1[i]!=s2[j]) {
			matches = false;
		}
		else {
			matches |= match(i+1, j+1, next_char_idx_1, next_char_idx_2);
		}
	}	
	else if(s1[i] == '*') {
		int cur = j;
		matches |= match(i+1, cur, next_char_idx_1, next_char_idx_2);
		if(s2[j]=='*') {
			cur = next_char_idx_2[j];
		} 
		for(int consume = 1;consume<=4;++consume) {
			matches |= match(i+1, cur+1, next_char_idx_1, next_char_idx_2);
			cur = next_char_idx_2[cur];
		}
	}
	else if(s2[j] == '*') {
		int cur = i;
		matches |= match(cur, j+1, next_char_idx_1, next_char_idx_2);
		if(s1[i]=='*') {
			cur = next_char_idx_1[i];
		} 
		for(int consume = 1;consume<=4;++consume) {
			matches |= match(cur+1, j+1, next_char_idx_1, next_char_idx_2);
			cur = next_char_idx_1[cur];
		}
	}
	dp[i][j] = matches?1:0;
	return matches;
}

int main() {
	freopen("downloads/in.txt", "r", stdin);
	freopen("downloads/out.txt", "w", stdout);
	int t;
	cin>>t;
	fore(z,0,t) {
		cin>>s1>>s2;
		cout<<"Case #"<< z+1 <<": ";
		n = s1.length(), m = s2.length();
		s1+='-';s2+='-';
		vector<int> next_char_idx_1(n+1, n), next_char_idx_2(m+1, m);
		for(int i = n-2; i>=0; --i) {
			if(s1[i+1]!='*') {
				next_char_idx_1[i] = i+1;
			}
			else {
				next_char_idx_1[i] = next_char_idx_1[i+1];
			}
		}
		for(int i = m-2; i>=0; --i) {
			if(s2[i+1]!='*') {
				next_char_idx_2[i] = i+1;
			}
			else {
				next_char_idx_2[i] = next_char_idx_2[i+1];
			}
		}
		for(int i = 0;i<n+1;++i) {
			for(int j = 0;j<m+1;++j) {
				dp[i][j] = -1;
			}
		}
		dp[n][m] = 1;
		cout << (match(0, 0, next_char_idx_1, next_char_idx_2)?"TRUE":"FALSE")<<endl;
	}
	return 0;
}