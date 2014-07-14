class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(x<10){
            return true;
        }
        if(x<100){
            return !(x%11);
        }
        int tail = x%10;
        int head = x/10;
        int mid = 0;
        int zpl = 0;
        int pre = 1;
        while(head>=10){
            mid*=10;
            if(head%10==0&&pre){
                zpl++;
            }else{
                pre = 0;
            }
            mid+=head%10;
            head/=10;
        }
        if(head!=tail){
            return false;
        }
        if(zpl){
            while(zpl){
                int r = mid%10;
                if(r){
                    return false;
                }
                mid/=10;
                zpl--;
            }
        }
        int dim = 0;
        int cur = mid;
        while(cur){
            dim*=10;
            dim+=cur%10;
            cur/=10;
        }
        return dim == mid;
        
    }
};