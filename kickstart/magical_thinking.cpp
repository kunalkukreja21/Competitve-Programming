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

string bin(int i) {
	string ans = "";
	do {
		int dig = i%2;
		ans+=(char)('0'+dig);
		i/=2;
	} while(i>0);
	reverse(all(ans));
	return ans;
}

int main() {
	freopen("downloads/in.txt", "r", stdin);
	freopen("downloads/out.txt", "w", stdout);
	int t;
	cin>>t;
	fore(z,0,t) {
		cout<<"Case #"<< z+1 <<": ";

		int n,q;
		cin>>n>>q;

		vector<string> answers(n+1);
		fore(i,0,n+1) {
			string s;
			cin>>s;
			answers[i] = s;
		}
		vi marks(n);
		fore(i,0,n) {
			cin>>marks[i];
		}

		int ma = (1<<(n+1));
		vi occs(ma, 0);
		fore(i,0,q) {
			int mul = 1;
			int sum = 0;
			for(int j = n;j>=0; --j) {
				sum+=(mul*((answers[j][i]=='T')?1:0));
				mul*=2;
			}
			++occs[sum];
		}
		// fore(i,0,ma) {
		// 	cout<<bin(i) << " " << occs[i]<<endl;
		// }

		int fa = 0;
		ll mul = 1;
		fore(i,0,ma) {
			mul*=(1+occs[i]);
		}
		fore(i,0,mul) {
			vi occs_2(ma*2, 0);
			int lft = i;
			vi benf(n+1, 0);
			// distribution logic
			for(int j = 0;j<ma*2; j+=2) {
				occs_2[j] = lft%(occs[j/2]+1);
				lft/=(occs[j/2]+1);
				occs_2[j+1] = occs[j/2]-occs_2[j];

				fore(k,1,n+2) {
					int num = (1<<k);
					if(num&j) {
						benf[k-1]+=occs_2[j+1];
					}
					else {
						benf[k-1]+=occs_2[j];
					}
				}

			}
			bool mismatch = false;
			reverse(all(benf));
			fore(i,0,n) {
				if(benf[i]!=marks[i]) {
					mismatch = true;
				}
			}
			if(!mismatch) {
				fa = max(fa, benf[n]);
			}
			// beneficiary logic
		}
		cout<<fa;
		cout<<endl;
	}
	return 0;
}