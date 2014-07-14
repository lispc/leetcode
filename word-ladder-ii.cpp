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
        vector<vector<string>> gres;
        map<Node*,vector<Node*>> stpar;
        map<Node*,vector<Node*>> edpar;
        void fullfill(Node*pn){
                string s = pn->s;
                //cout<<"fullfilling "<<s<<endl;
                for(int i=0;i<s.size();i++){
                        s = pn->s;
                        for(int j=0;j<26;j++){
                                s[i]='a'+j;
                                if(s==pn->s){
                                        continue;
                                }
                                if(si.find(s)!=si.end()){
                                        auto p = &g[si[s]];
                                        pn->nexts.push_back(p);
                                }
                        }
                }
        }
        void setpar(Node*p,Node*pn,map<Node*,vector<Node*>>&ct){
                if(ct.find(p)!=ct.end()){
                        ct[p].push_back(pn);
                }else{
                        ct[p]=vector<Node*>{pn};
                }
                //cout<<"ful "<<p->s<<" "<<pn->s<<" "<<(&ct==&stpar?"stpar":"edpar")<<endl;
        }
        vector<vector<string>> retra(Node*p,map<Node*,vector<Node*>>&ct){
                //cout<<"retra "<<p->s<<endl;
                if(ct.find(p)==ct.end()){
                        return vector<vector<string>>{vector<string>{p->s}};
                }else{
                        vector<vector<string>> res;
                        for(auto pars:ct[p]){
                                auto data = retra(pars,ct);
                                for(auto lst:data){
                                        vector<string> tp = lst;
                                        tp.push_back(p->s);
                                        res.push_back(tp);
                                }
                        }
                        return res;
                }
        }
        void merge(Node*a){
                //cout<<"meg "<<a->s<<" "<<b->s<<endl;
                //return;
                auto left = retra(a,stpar);
                auto right = retra(a,edpar);
                for(auto ll:left){
                        for(auto rr:right){
                                vector<string> final = ll;
                                final.pop_back();
                                final.insert(final.end(),rr.rbegin(),rr.rend());
                                gres.push_back(final);
                        }
                }
        }
        vector<vector<string>> findLadders(string start, string end,
unordered_set<string> &dict) {
                if(one(start,end)){
                        return vector<vector<string>>(1,vector<string>{start,end});
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
                int s = g.size();
                set<Node*>* cur = new set<Node*>;
                set<Node*>* next_level = new set<Node*>;
                Node snode;
                snode.s = start;
                Node enode;
                enode.s = end;
                fullfill(&snode);
                fullfill(&enode);
                for(auto c:snode.nexts){
                        setpar(c,&snode,stpar);
                }
                for(auto c:enode.nexts){
                        setpar(c,&enode,edpar);
                }
                for(int i=0;i<s;i++){
                        if(one(start,g[i].s)){
                                g[i].vis=1;
                                cur->insert(&g[i]);
                        }
                }
                set<Node*>* edcur = new set<Node*>;
                set<Node*>* ednext_level = new set<Node*>;
                bool findthree = false;
                for(int i=0;i<s;i++){
                        if(one(end,g[i].s)){
                                if(g[i].vis){
                                        findthree = true;
                                        gres.push_back(vector<string>{start,g[i].s,end});
                                }
                                edcur->insert(&g[i]);
                                g[i].vis2 = 1;
                        }
                }
                if(findthree){
                        return gres;
                }
                int len = 3;
                int edlen = 1;
                auto itercur = (edcur->size()<cur->size())?edcur:cur;
                auto found = false;
                while(!found&&!itercur->empty()){
                        len++;
                        int flag = itercur==cur;
                        if(flag){
                                for(auto n:*itercur){
                                        n->vis = 1;
                                        if(n->vis2){
                                                found = true;
                                                merge(n);
                                        }
                                        if(found){
                                                continue;
                                        }
                                        fullfill(n);
                                        for(auto pn:n->nexts){
                                                if(!pn->vis&&itercur->find(pn)==itercur->end()){
                                                          next_level->insert(pn);
                                                          setpar(pn,n,stpar);
                                                }
                                        }
                                }
                                auto tp = next_level;
                                next_level = cur;
                                cur->clear();
                                cur = tp;
                        }else{
                                for(auto n:*itercur){
                                        n->vis2 = 1;
                                        if(n->vis){
                                                found = true;
                                                merge(n);
                                        }
                                        if(found){
                                                continue;
                                        }
                                        fullfill(n);
                                        for(auto pn:n->nexts){
                                                if(!pn->vis2&&itercur->find(pn)==itercur->end()){
                                                          ednext_level->insert(pn);
                                                          setpar(pn,n,edpar);
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
                return gres;

        }
};