#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par,siz,edge;
    UnionFind(int sz) : par(sz),siz(sz,1),edge(sz) {
        for(int i = 0; i < sz; i++) par[i] = i;
    }
    int root(int x) {
        while(par[x] != x) {
            x = par[x];
        }
        return x;
    }
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) {
            edge[x]++;
            return false;
        }
        if(siz[x] < siz[y]) swap(x,y);
        siz[x] += siz[y];
        edge[x] += edge[y]+1;
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {return root(x) == root(y);}
    int size(int x) {return siz[root(x)];}
    int cal_edge(int x) {return edge[root(x)];}
};