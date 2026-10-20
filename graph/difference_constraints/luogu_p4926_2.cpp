// 差分约束 SPFA 算法 O(NM*log(10^7))

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
#include <limits>
#include <climits>
using namespace std;

#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugE(x) cerr << (#x) << " = " << (x) << endl;

template<typename... Args> void debug_print(const char* names, Args&&... args) { cout << names << " = "; ((cout << args << " "), ...); cout << endl; }
template<typename... Args> void debug_err_print(const char* names, Args&&... args) { cerr << names << " = "; ((cerr << args << " "), ...); cerr << endl; }
#define debugs(...) debug_print(#__VA_ARGS__, __VA_ARGS__)
#define debugsE(...) debug_err_print(#__VA_ARGS__, __VA_ARGS__)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) { ans *= x; ans %= m; }
        x *= x; x %= m; 
        b >>= 1;
    }
    return ans;
}

const int N=1010,M=N*3;
int h[N],idx,ne[M],to[M]; double ww[M];
void add(int x,int y,double w){
  to[++idx]=y;ww[idx]=w;ne[idx]=h[x];h[x]=idx;
}
int n,s,t,x[N],cnt[N],vis[N];
struct F{int o,A,B,k;}f[N];
double d[N];

void build(double T){
  idx=0; memset(h,0,sizeof(h));
  for(int i=1;i<=s;i++){
    auto [o,A,B,k]=f[i];
    if(o==1) add(B,A,k-T);
    else add(B,A,1.0/(k+T));
  }  
  for(int i=1;i<=n;i++) if(x[i]){
    add(0,i,x[i]);
    add(i,0,1.0/x[i]);
  }
}
int spfa(double T){
  build(T); //建图
  queue<int> q;
  for(int i=0;i<=n;i++) d[i]=1,cnt[i]=0,q.push(i),vis[i]=1;    

  while(!q.empty()){
    int u=q.front(); q.pop();vis[u]=0;
    for(int i=h[u];i;i=ne[i]){
      int v=to[i]; double w=ww[i];
      if(d[u]*w > d[v]){
        d[v]=d[u]*w; //乘积最长路
        cnt[v]=cnt[u]+1;
        if(cnt[v]>=n+1) return true; //有环
        if(!vis[v]) q.push(v),vis[v]=1;
      }
    }
  }
  return false; //无环
}
int main(){
  cin>>n>>s>>t;
  for(int i=1,o,A,B,k;i<=s;i++){
    cin>>o>>A>>B>>k;
    f[i]={o,A,B,k};
  }
  for(int i=1,C,x1;i<=t;i++) cin>>C>>x1,x[C]=x1;
  
  double l=0,r=10,mid;
  while(r-l>1e-6){
    mid=(l+r)/2;
    spfa(mid)?l=mid:r=mid;
  }
  if(l==0) puts("-1"); //找不到正T,无解
  else printf("%.6lf\n",l);
}