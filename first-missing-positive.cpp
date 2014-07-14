class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_map<int,int> buf;
        for(int i=0;i<n;i++){
            buf[A[i]]=1;
        }
        int t = 1;
        while(1){
            if(buf.find(t)==buf.end()){
                return t;
            }else{
                t++;
            }
        }
    }
};