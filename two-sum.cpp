class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res(2,0);
        if(numbers.size()<=1){
            return res;
        }
        vector<int> vi = numbers;
        sort(vi.begin(),vi.end());
        int st = 0;
        int ed = vi.size()-1;
        while(st<=ed){
            int tsum = vi[st]+vi[ed];
            if(tsum==target){
                int t1 = vi[st];
                int t2 = vi[ed];
                for(int i=0;i<numbers.size();i++){
                    if(numbers[i]==t1||numbers[i]==t2){
                        res[0]=i+1;
                        int newt = t1+t2-numbers[i];
                        for(int j=i+1;j<numbers.size();j++){
                            if(numbers[j]==newt){
                                res[1]=j+1;
                                return res;
                            }
                        }
                        
                    }
                }
            }else if(tsum<target){
                st++;
            }else{
                ed--;
            }
            
        }
        return res;
    }
};