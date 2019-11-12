#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < n; i++)
#define fi first
#define se second
#define ll long long
#define mk(a,b) std::make_pair(a,b)

int n, m, a, b, c;
const ll INF= (ll)1e18;

std::vector<std::vector<std::pair<int, ll>>> vec;
std::vector<ll> froma, fromb, fromc;

std::vector<ll> dijkstra(int s){
    std::vector<ll> short_path;
    short_path.assign(n,INF);
    short_path[s] = 0;
    std::set<std::pair<ll, int>> q;
    auto first_add = mk(0,s);
    q.insert(first_add);
    while(q.size()!= 0){
        auto top = q.begin();
        int start = top->se;
        q.erase(top);
        for(auto to : vec[start]){
            auto v = to.fi;
            auto len = to.se;
            if (short_path[v] > short_path[start] + len){
                auto to_delete = mk(short_path[v],v);
                q.erase(to_delete);
                short_path[v] = short_path[start] + len;
                auto to_add = mk(short_path[v],v);
                q.insert(to_add);
            }
        }
    }
    return short_path;
}

ll max_ (ll a, ll b){
    if (a > b) return a;
    return b;
}
bool check = false;
ll dist(ll a, ll b, ll c){
    if (fromb[c] != INF && fromc[a] != INF){
        if (a >= b && a >= c)
            return b + c;
    }
    else check = 1;
    if (froma[b] != INF && fromb[c]!= INF){
        if (b >= a && b >= c)
            return a + b;
    }
    else check = 1;
    if (froma[b] != INF && fromc[a] != INF) {
        if (c >= a && c >= b) return a + c;
    }
    else check = 1;

}

ll min_(ll a , ll b){
    if (a > b) return b;
    return a;
}
ll res = INF;
void ans_(){
    forn(i,n) {
        ll distAtoX = froma[i];
        ll distBtoX = fromb[i];
        ll distCtoX = fromc[i];
        if (distAtoX != INF || distBtoX != INF || distCtoX != INF){
            ll minDist = dist(distAtoX, distBtoX, distCtoX);
            if (minDist == distAtoX){
                //res = min_(res,)
            }
            if (minDist == distBtoX){

            }
            if (minDist == distCtoX){

            }
        }
    }
}

//bool check (ll a, ll b, ll c){
//    if (max_(a,b) == )
//}
int main(){
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    vec.resize(m);
    //short_path.assign(n,INF);
    int from, to;
    ll len;
    forn(i,m){
        std::cin >> from >> to >> len;
        --from;
        --to;
        auto v = mk(from,len);
        auto u = mk(to,len);
        vec[from].emplace_back(u);
        vec[to].emplace_back(v);
    }
    //std::vector <ll> ans = dijkstra()
    std::cin >> a >> b >> c;
    --a;
    --b;
    --c;
    froma = dijkstra(a);
    fromb = dijkstra(b);
    fromc = dijkstra(c);
//    std::cout << "for a: ";
//    for (auto i : froma) std::cout << i << ' ';
//    std::cout << std::endl << "for b: ";
//    for (auto i : fromb) std::cout << i << ' ';
//    std::cout << std::endl << "for c: ";
//    for (auto i : fromc) std::cout << i << ' ';

//    auto froma_ = mk(min_(froma[b],froma[c]), max_(froma[b],froma[c]));
//    auto fromb_ = mk(min_(fromb[a], fromb[c]), max_(fromb[a], fromb[c]));
//    auto fromc_ = mk(min_(fromc[a],fromc[b]),max_(fromc[a],fromc[b]));
//    std::vector<std::pair<ll,ll> arr;
//    arr.emplace_back(mk(froma[b],froma[c]));
//    arr.emplace_back(mk(fromb[a], fromb[c]));
//    arr.emplace_back(mk(fromc[a],fromc[b]));
//    ll fromA = froma[b];
//    ll fromB = fromb[c];
//    ll fromC = fromc[a];
//    if (dist(froma[b],fromb[c],fromc[a]) >= INF){
//        std::cout << "-1";
//        return 0;
//    }
if (check == 1) {
    std::cout << "-1";
    return 0;
}
    std::cout << dist(froma[b],fromb[c],fromc[a]);
}
