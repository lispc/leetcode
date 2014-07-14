class LRUCache{
public:
    map<int,int> tk;
    map<int,pair<int,int>> kvt;
    int c;
    LRUCache(int capacity) {
        this->c = capacity;
    }
    
    int get(int key) {
        if(kvt.find(key)==kvt.end()){
            return -1;
        }
        int v = kvt[key].first;
        int maxt = tk.rbegin()->first;
        int lastt = kvt[key].second;
        tk.erase(lastt);
        tk[maxt+1]=key;
        kvt[key]=make_pair(v,maxt+1);
        return v;
    }
    void set(int key, int value) {
        if(kvt.size()==0){
            tk[0]=key;
            kvt[key]=make_pair(value,0);
            return;
        }
        int maxt = tk.rbegin()->first;
        if(kvt.find(key)!=kvt.end()){
            int lastt = kvt[key].second;
            tk.erase(lastt);
            tk[maxt+1]=key;
            kvt[key]=make_pair(value,maxt+1);
            return;
        }
        if(kvt.size()<c){
            kvt[key]=make_pair(value,maxt+1);
            tk[maxt+1]=key;
        }else{
            int victim = tk.begin()->second;
            int mint = tk.begin()->first;
            kvt.erase(victim);
            kvt[key]=make_pair(value,maxt+1);
            tk.erase(mint);
            tk[maxt+1]=key;
        }
    }
};