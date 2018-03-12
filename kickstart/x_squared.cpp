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

bool sane(vector<vi> &tst) {
	bool done_one = false;
	fore(i,0,tst.size()) {
		if(tst[i].size() == 1) {
			if(done_one) { return false; }
			done_one = true;
		}
		else if(tst[i].size()!=2) {
			return false;
		}
	}
	return true;
}

int find_other(int row, int col, vector<vi> &tst) {
	const vi &mat = tst[row];
	if(mat.sz == 1) {
		return col;
	} 
	fore(i,0,mat.sz) {
		if(mat[i] == col) {
			continue;
		}
		else {
			return mat[i];
		}
	}
	return col;
}

int main() {
	freopen("downloads/in.txt", "r", stdin);
	freopen("downloads/out.txt", "w", stdout);
	int t;
	cin>>t;
	fore(z,0,t) {
		int n;
		cin>>n;
		vector<vector<char> > mat(n, vector<char>(n));
		fore(i,0,n) {
			fore(j,0,n) {
				cin>>mat[i][j];
			}
		}
		cout<<"Case #"<< z+1 <<": ";
		vector<vi> row(n), col(n);
		map<pii, int> pts;		

		fore(i,0,n) {
			fore(j,0,n) {
				if(mat[i][j] == 'X') {
					pts[mp(i, j)] = 0;
					row[i].pb(j);
					col[j].pb(i);
				}
			}
		}
		bool possible = true;
		if(sane(row) && sane(col)) {
			//cout<<"Sane"<<endl;
			for(auto &pt : pts) {
				if(pt.second) {
					continue;
				}
				pii row_pt = mp(pt.first.first, find_other(pt.first.first, pt.first.second, row));
				pii col_pt = mp(find_other(pt.first.second, pt.first.first, col), pt.first.second);
				pii thrd_pt = mp(col_pt.first, row_pt.second);

				//cout << "Current point: " << pt.first.first << " " <<  pt.first.second <<endl;
				//cout << "Third point: " << thrd_pt.first << " " <<  thrd_pt.second <<endl;
				if(pts.count(thrd_pt)>0) {
					pts[row_pt] = pts[col_pt] = pts[thrd_pt] = 1;
				}
				else {
					possible = false;
				}
			}
 		}
 		else {
 			possible = false;
 		}
 		cout << (possible?"POSSIBLE":"IMPOSSIBLE");
 		cout<<endl;
	}
	return 0;
}