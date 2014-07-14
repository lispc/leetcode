class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        auto rv = vector<int>(digits.rbegin(),digits.rend());
        int l = rv.size();
        int carry = 1;
        for(int i=0;i<l;i++){
            int v = rv[i];
            int res = v+carry;
            rv[i] = res%10;
            if(res<10){
                carry=0;
                break;
            }
        }
        if(carry){
            rv.push_back(1);
        }
        return vector<int>(rv.rbegin(),rv.rend());
        
    }
};