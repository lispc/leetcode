class Solution {
public:
        bool one(string s1,string s2){
        int i = 0;
        int l = s1.size();
        while(i<l&&s1[i]==s2[i++]);
        return s1.substr(i)==s2.substr(i);
    }
    struct Node{
        string s;
        int vis;
        int vis2;
        vector<Node*> nexts;
    };
    unordered_map<string,int> si;
    vector<Node> g;
    void fullfill(Node*pn){
        string s = pn->s;
        for(int i=0;i<s.size();i++){
            s = pn->s;
            for(int j=0;j<26;j++){
                s[i]='a'+j;
                if(si.find(s)!=si.end()){
                    pn->nexts.push_back(&g[si[s]]);
                }
            }
        }
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(one(start,end)){
            return 2;
        }
        int sub = 0;
        for(auto s1:dict){
            Node n;
            n.s = s1;
            n.vis = 0;
            n.vis2 = 0;
            g.push_back(n);
            si[s1]=sub++;
        } 
        //"hit" -> "hot" -> "dot" -> "dog" -> "cog"
        int s = g.size();
        /*
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                if(one(g[i].s,g[j].s)){
                    //cout<<"link "<<g[i].s<<" "<<g[j].s<<endl;
                    g[i].nexts.push_back(&g[j]);
                    g[j].nexts.push_back(&g[i]);
                }                   
            }
        }*/
        set<Node*>* cur = new set<Node*>;
        set<Node*>* next_level = new set<Node*>;
        for(int i=0;i<s;i++){
            if(one(start,g[i].s)){
                g[i].vis=1;
                //cout<<"init "<<g[i].s<<endl;
                cur->insert(&g[i]);
            }
        }
        set<Node*>* edcur = new set<Node*>;
        set<Node*>* ednext_level = new set<Node*>;
        for(int i=0;i<s;i++){
            if(one(end,g[i].s)){
                if(g[i].vis){
                    return 3;
                }
                //cout<<"init "<<g[i].s<<endl;
                edcur->insert(&g[i]);
                g[i].vis2 = 1;
            }
        }
        int len = 3;
        int edlen = 1;
        auto itercur = (edcur->size()<cur->size())?edcur:cur;
        while(!itercur->empty()){
            len++;
            int flag = itercur==cur;
            if(flag){
                for(auto n:*itercur){
                    //cout<<"child of "<<n->s<<endl;
                    fullfill(n);
                    for(auto pn:n->nexts){
                        if(!pn->vis){
                            if(pn->vis2){
                                return len;
                            }
                            pn->vis=1;
                            next_level->insert(pn);
                            //cout<<"push "<<pn->s<<endl;
                        }
                    }
                }
                auto tp = next_level;
                next_level = cur;
                cur->clear();
                cur = tp;
            }else{
                for(auto n:*itercur){
                   // cout<<"child of "<<n->s<<endl;
                    fullfill(n);
                    for(auto pn:n->nexts){
                        if(!pn->vis2){
                            if(pn->vis){
                                return len;
                            }
                            pn->vis2=1;
                            ednext_level->insert(pn);
                            //cout<<"push "<<pn->s<<endl;
                        }
                    }
                }
                auto tp = ednext_level;
                ednext_level = edcur;
                edcur->clear();
                edcur = tp;
            }
            itercur = (edcur->size()<cur->size())?edcur:cur;
        }
        return 0;
        
    }
};