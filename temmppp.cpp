#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//VVI
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb                  push_back
#define ll                  long long

///BIT MANIPULATION

#define Set(x, k) (x |= (1LL << k))
#define Unset(x, k) (x &= ~(1LL << k))
#define Check(x, k) (x & (1LL << k))
#define Toggle(x, k) (x ^ (1LL << k))


///PRINTING && shortcuts

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define nn '\n'
#define Setpre(n) cout<<fixed<<setprecision(n)
#define mem(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()


//CONSTANTS
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e5+10;
const ll M = 1e9+7;


///INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll Ceil(ll p, ll q)  {return p < 0 ? p / q : p / q + !!(p % q);}
inline ll Floor(ll p, ll q) {return p > 0 ? p / q : p / q - !!(p % q);}
inline double logb(ll base,ll num){ return (double)log(num)/(double)log(base);}
inline bool isPerfectSquare(long double x){ if (x >= 0) { long long sr = sqrt(x);return (sr * sr == x); }return false; }
double euclidean_distance(ll x1,ll y1,ll x2,ll y2){double a=(x2-x1)*(x2-x1);double b=(y2-y1)*(y2-y1);double c=(double)sqrt(a+b);return c;}
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};


/// Data structures
typedef unsigned long long ull;
typedef pair<ll, ll>    pll;
typedef vector<ll>      vl;
typedef vector<pll>     vpll;
typedef vector<vl>      vvl;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using QP = priority_queue<T,vector<T>,greater<T>>;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T,typename R> using ordered_map = tree<T, R , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
;

 
namespace io{
    template<typename First, typename Second> ostream& operator << ( ostream &os, const pair<First, Second> &p ) { return os << p.first << " " << p.second; }
    template<typename First, typename Second> ostream& operator << ( ostream &os, const map<First, Second> &mp ) { for( auto it : mp ) { os << it << endl;  } return os; }
    template<typename First> ostream& operator << ( ostream &os, const vector<First> &v ) { bool space = false; for( First x : v ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const set<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const multiset<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
 
    template<typename First, typename Second> istream& operator >> ( istream &is, pair<First, Second> &p ) { return is >> p.first >> p.second; }
    template<typename First> istream& operator >> ( istream &is, vector<First> &v ) { for( First &x : v ) { is >> x; } return is; }
    
    long long fastread(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x; }
    
    static bool sep = false;
 
    using std::to_string;
 
    string to_string( bool x ){ return ( x ? "true" : "false" ); }
    string to_string( const string & s ){ return "\"" + s + "\""; }
    string to_string( const char * s ){ return "\"" + string( s ) + "\""; }
    string to_string ( const char & c ) { string s; s += c; return "\'" + s + "\'"; }
 
    template<typename Type> string to_string( vector<Type> );
    template<typename First, typename Second> string to_string( pair<First, Second> );
    template<typename Collection> string to_string( Collection );
 
    template<typename First, typename Second> string to_string( pair<First, Second> p ){ return "{" + to_string( p.first ) + ", " + to_string( p.second ) + "}"; }
    template<typename Type> string to_string( vector<Type> v ) { bool sep = false; string s = "["; for( Type x: v ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "]"; return s; }
    template<typename Collection> string to_string( Collection collection ) { bool sep = false; string s = "{"; for( auto x: collection ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "}"; return s; }
 
    void print() { cerr << endl; sep = false; }
    template <typename First, typename... Other> void print( First first, Other... other ) { if( sep ) cerr << " | "; sep = true; cerr << to_string( first ); print( other... ); }
    
} using namespace io;
 

void setIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

}

//DFS
// vector<ll>g[N];
// bool vis[N];


// void dfs(ll vertex){
//     //take action on vertex after entering the vertex
//     vis[vertex]=true;
  
//     for(ll child:g[vertex]){
      
//         if(vis[child]) continue;
//         //take action on the node before entering the child
//         dfs(child);
//         //take action on the node after exiting the child
//     }
//     //take action on the vertex after exiting the node
// }
// //DFS Grid
// ll n,m,t=0;
// vector<string> g;
// vpll Move={ {1,0},{-1,0},{0,1},{0,-1} };

// bool vis[N][N];

// bool isValid(ll x,ll y){
//     return (x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==0&&g[x][y]=='.');
// }

// void dfs(pll vertex){
//     /*
//     take action on vertex after entering the vertex
//     */
//     vis[vertex.first][vertex.second]=true;
//     for(pll &child: Move){
//         /*
//         take action on child before entering the child node
//         */
//         ll x=child.first+vertex.first;
//         ll y=child.second+vertex.second;
//         if(!isValid(x,y)) continue;
//         dfs({x,y});
//         /*
//         take action on child after entering the child node
//         */
//     }
//     /*
//     take action on vertex before exiting the vertex
//     */
// }


// vector<ll>g[N];
// bool vis[N];
// ll level[N];

// //bfs=breadth first search
// //according to level traversal


// void bfs(ll source){
//     queue<ll> q;
//     q.push(source);
//     vis[source]=1;
//     while(!q.empty()){
//         ll curr_v=q.front();
//         q.pop();
//         cout<<curr_v<<" ";
//         for(ll child: g[curr_v]){
//             if(!vis[child]){
//                 q.push(child);
//                 vis[child]=1;
//                 level[child]=level[curr_v]+1;
//             }
//         }
//     }
//     cout<<endl;
// }

///BFS grid
// vpll Move={ {1,0},{-1,0},{0,1},{0,-1} };

// bool vis[N][N];
// ll level[N][N];
// ll n,m;

// bool isValid(ll x,ll y){
//     return (x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0);
// }

// void bfs(pll source){
//     queue<pll> q;
//     q.push(source);
//     vis[source.first][source.second]=1;
//     level[source.first][source.second]=0;
//     while(!q.empty()){
//         pll cur_v=q.front();
//         q.pop();
//         for(pll &child:Move){
//             ll x=cur_v.first+child.first;
//             ll y=cur_v.second+child.second;
//             if(isValid(x,y)){
//                 q.push({x,y});
//                 vis[x][y]=1;
//                 level[x][y]=1+level[cur_v.first][cur_v.second];
//             }
//         }
//     }
// }


//Dijkstra
// vpll g[N];
// vl dist(N,LLONG_MAX);
// vl par(N,-1);

// void dijkstra(int source){
//     QP<pll> pq;
//     pq.push(mp(0,source));
//     dist[source]=0;
//     while(pq.size()){
//         ll v=pq.top().second;
//         ll v_dist=pq.top().first;
//         pq.pop();
//         if(dist[v]<v_dist) continue;
//         for(auto &child:g[v]){
//             ll child_v=child.first;
//             ll wt=child.second;
//             if(dist[v]+wt<dist[child_v]){
//                 dist[child_v]=dist[v]+wt;
//                 par[child_v]=v;
//                 pq.push(mp(dist[child_v],child_v));
//             }
//         }
//     }
// }


/// NCR MOD
// ll FM[N];
// int is_initialized = 0;
// ll factorialMod(ll n, ll x){
//     if (!is_initialized){
//         FM[0] = 1 % x;
//         for (int i = 1; i < N; i++)
//             FM[i] = (FM[i - 1] * i) % x;
//         is_initialized = 1;
//     }
//     return FM[n];
// }

// ll powerMod(ll x, ll y, ll p){
//     ll res = 1 % p;
//     x = x % p;
//     while (y > 0){
//         if (y & 1) res = (res * x) % p;
//         y = y >> 1;
//         x = (x * x) % p;
//     }
//     return res;
// }

// ll inverseMod(ll a, ll x){
//     return powerMod(a, x - 2, x);
// }

// ll nCrMod(ll n, ll r, ll x){
//     if (r == 0) return 1;
//     if (r > n) return 0;
//     ll res = factorialMod(n, x);
//     ll fr = factorialMod(r, x);
//     ll zr = factorialMod(n - r, x);
//     res = (res * inverseMod((fr * zr) % x, x)) % x;
//     return res;
// }

// struct item{
//     ll value;//current value
//     ll lazy;//value to be lazyed 
//     ll assign;//value to be assigned
// };

// struct segment_tree{
//     ll size;
//     vector<item>tree;
//     ll neutral=0;
//     ll no_op=LLONG_MIN;
    
//     //General operations : O(1)

//     ll merge(ll a,ll b){
//        if(a==no_op) return b;
//         return (a+b);
//     }
//     ll addnodes(ll a,ll b){
//         return a+b;
//     }

   
//     //INITIALIZATION: O(log2 n)

//     void init(ll n){
//         size=1;
//         while(size<n) size*=2;
//         tree.resize(2*size);
//         tree.assign(2*size,{0,no_op,no_op});
//     }
    
//     ///BUILD
//     void build(vector<ll> &a,ll x,ll lx,ll rx){
//         if(rx-lx==1){
//             if(lx<a.size()){
//                 tree[x]={a[lx],no_op,no_op};
//             }
//             return;
//         }
//         ll m=(lx+rx)/2;
//         build(a,2*x+1,lx,m);
//         build(a,2*x+2,m,rx);
//         tree[x]={ tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value),no_op,no_op};
//     }

//     void build(vector<ll> &a){
//         //linear time
//         build(a,0,0,size);
//     }

//     ///LAZY PROPAGATION
    
//     //throws lazy values to its children nodes 
//      //updates values to children nodes
//         item propagate_op(item par,item child,ll len){
//         item ret=child;
//         if(par.assign!=no_op)
//         {
//             ret.assign=par.assign;
//             ret.lazy=no_op;
//             ret.value=len*(par.assign);
//         }
 
//         if(par.lazy!=no_op){
//             ret.lazy=merge(ret.lazy,par.lazy);
//             ret.value+=len*par.lazy;
//         }
 
//         return ret;
//     }
 
//     void propagate(ll x,ll lx,ll rx){
//         if(rx-lx==1 || (tree[x].assign==no_op && tree[x].lazy==no_op)){
//             return;
//         }
//         ll m=(rx+lx)/2;
//         tree[2*x+1]=propagate_op(tree[x],tree[2*x+1],m-lx);
//         tree[2*x+2]=propagate_op(tree[x],tree[2*x+2],rx-m);
//         tree[x].lazy=tree[x].assign=no_op;
//     }



//     ///RANGE SUM
//     ll sum(ll l,ll r,ll x,ll lx,ll rx){
//         propagate(x,lx,rx);
//         if(lx>=r || l>=rx){
//             return 0;
//         }
//         if(lx>=l && rx<=r){
//             return tree[x].value;
//         }
//         ll m=(lx+rx)/2;
//         ll s1=sum(l,r,2*x+1,lx,m);
//         ll s2=sum(l,r,2*x+2,m,rx);
//         return  addnodes(s1,s2);
//     }

    
//     ll sum(ll l,ll r){
//         //returns sum from l to r
       
//         return sum(l,r,0,0,size);
//     }

//     //RANGE operation
    
//     void RangeUpdate(ll l,ll r,ll v,ll x,ll lx,ll rx){
//         propagate(x,lx,rx);
//         if(lx>=r || l>=rx){
//             return;
//         }
//         if(lx>=l && rx<=r){
//             tree[x].lazy=merge(tree[x].lazy,v);
//             tree[x].value+=(rx-lx)*v;
//             return;
//         }
//         ll m=(lx+rx)/2;
//         RangeUpdate(l,r,v,2*x+1,lx,m);
//         RangeUpdate(l,r,v,2*x+2,m,rx);  
//          tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value);
//     }
    

//     void RangeUpdate(ll l,ll r,ll v){
//         //multipliess v from l to r
//         RangeUpdate(l,r,v,0,0,size);
//     }
//     ///RANGE ASSIGN
//      void RangeAssign(ll l,ll r,ll v,ll x,ll lx,ll rx){
//         propagate(x,lx,rx);
//         if(lx>=r || l>=rx){
//             return;
//         }
//         if(lx>=l && rx<=r){
//             tree[x].assign=v;
//             tree[x].lazy=no_op;
//             tree[x].value=(rx-lx)*v;
            
//             return;
//         }
//         ll m=(lx+rx)/2;
//         RangeAssign(l,r,v,2*x+1,lx,m);
//         RangeAssign(l,r,v,2*x+2,m,rx);  
//         tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value);
//     }
    
//     void RangeAssign(ll l,ll r,ll v){
//         //assigns v from l to r
//       RangeAssign(l,r,v,0,0,size);
//     }   
// };

// const int  m=11;
// ll Trie[N][m];
// ll nnode;
// bool isword[N];

// void reset(int k){
//     for(int i=0;i<m;i++){
//         Trie[k][i]=-1;
//     }
// }

// void Insert(string &s){
//     int n=s.size(),node=0;
//     for(int i=0;i<n;i++){
//         if(Trie[node][s[i]-'0']==-1){
//             Trie[node][s[i]-'0']=++nnode;
//             reset(nnode);
//         }
//         node=Trie[node][s[i]-'0'];
//     }
//     isword[node]=1;
// }

// string Search(string &s){
//     // print(s);
//     ll n=s.size(),node=0;
//     string res;
//     for(int i=0;i<n;i++){
//         pll temp={-1,-1};
//         for(int j=0;j<10;j++){
//             if(Trie[node][j]!=-1){
//                 if(temp.first<((j+(s[i]-48))%10)){
//                     temp={((j+s[i]-48)%10),j};
//                 }
//             }
//         }
//         res.pb(temp.second+48);
//         node=Trie[node][temp.second];
//     }
//     return res;
// }

//SIEVE and prime nos
// vector<bool> Primes(N,1);
// vector<ll>primenos;
// void SieveOfEratosthenes(ll n)
// {
//     Primes[1]=0;
//     for (ll i=2;i*i<=n;i++) {
//     if(Primes[i]==1){     
//     for(ll j=i*i;j<=n;j+=i)
//         Primes[j]=0;
//         }
//     }
//     for(ll i=1;i<n;i++){
//         if(Primes[i]){
//             primenos.push_back(i);
//         }
//     }
// }

//SIEVE LINEAR
// vector<int> smallest_factor;
// vector<bool> prime;
// vector<int> primes;
 
// void sieve(int maximum) {
//     maximum = max(maximum, 2);
//     smallest_factor.assign(maximum + 1, 0);
//     prime.assign(maximum + 1, true);
//     prime[0] = prime[1] = false;
//     primes = {2};
 
//     for (int p = 2; p <= maximum; p += 2) {
//         prime[p] = p == 2;
//         smallest_factor[p] = 2;
//     }
 
//     for (int p = 3; p * p <= maximum; p += 2)
//         if (prime[p])
//             for (int i = p * p; i <= maximum; i += 2 * p)
//                 if (prime[i]) {
//                     prime[i] = false;
//                     smallest_factor[i] = p;
//                 }
 
//     for (int p = 3; p <= maximum; p += 2)
//         if (prime[p]) {
//             smallest_factor[p] = p;
//             primes.push_back(p);
//         }
// }

//divisor store sieve

// vl divisors[N];

// void divisor_store(){
//     for(int i=2;i<N;i++){
//         for(int j=i;j<N;j+=i) {
//             divisors[j].push_back(i);
//         }  
//     }
// }


int main()
{
    fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    //cin>>t;

    while(t--){
      
    }


    return 0;
}

