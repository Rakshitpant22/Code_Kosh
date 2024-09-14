
class DSU {
vector<int> rank, parent, size; 
public: 
    Dsu(int n) { // initializer
        rank.resize(n+1,0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int find(int node) { //!find the parent of particular node
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulparent_u = findUPar(u); 
        int ulparent_v = findUPar(v); 
        if(ulparent_u == ulparent_v) return; 
        if(rank[ulparent_u] < rank[ulparent_v]) {
            parent[ulparent_u] = ulparent_v; 
        }
        else if(rank[ulparent_v] < rank[ulparent_u]) {
            parent[ulparent_v] = ulparent_u; 
        }
        else {
            parent[ulparent_v] = ulparent_u; 
            rank[ulparent_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulparent_u = findUPar(u); 
        int ulparent_v = findUPar(v); 
        if(ulparent_u == ulparent_v) return; 
        if(size[ulparent_u] < size[ulparent_v]) {
            parent[ulparent_u] = ulparent_v; 
            size[ulparent_v] += size[ulparent_u]; 
        }
        else {
            parent[ulparent_v] = ulparent_u;
            size[ulparent_u] += size[ulparent_v]; 
        }
    }

}; 











 