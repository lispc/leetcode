/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    map<void *,void *> buf;
    map<void*,int> cloned;
    void tra(UndirectedGraphNode *node){
        if(buf.find(node)!=buf.end()){
            return;
        }
        buf[node] = new UndirectedGraphNode(node->label);
        for(auto item:node->neighbors){
            tra(item);
        }
    }
    void clone(UndirectedGraphNode *node){
        cloned[node] = 1;
        for(auto item:node->neighbors){
            static_cast<UndirectedGraphNode*>(buf[node])->neighbors.push_back(static_cast<UndirectedGraphNode*>(buf[item]));
            if(!cloned[item]){
                clone(item);
            }
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node){
            return NULL;
        }
        tra(node);
        clone(node);
        return static_cast<UndirectedGraphNode*>(buf[node]);
        
    }
};