#include <cstdio>
#include <vector>
#include <iostream>

#define ll long long
#define forn(i,n) for(int i = 0 ; i < n; i++)

int n, m, k ,s;
const ll INF = (ll) 1e19;

std::vector<std::vector<ll>> short_path;

class point{
public:
    int x;
    int y;
    ll len;
    point() = default;
    point(int x, int y, int len) : x(x), y(y), len(len){};
};

std::vector<point> vec;

void find(){
    short_path[0][s] = 0;
    forn (i, k){
        forn (j,m){
            int from = vec[j].x;
            int to =  vec[j].y;
            ll len = vec[j].len;
            if (short_path[] < INF){

            }
        }
    }
}

int main(){
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    short_path.assign(k + 1,std::vector<ll>(n,INF));
    std::cin >> n >> m >> k >> s;
    int t1, t2, t3;
    forn(i,m){
        std::cin >> t1 >> t2 >> t3;
        --t1;
        --t2;
        vec.emplace_back(t1,t2,t3);
    }
}