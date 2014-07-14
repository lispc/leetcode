class Solution {
public:
    string data[3][3]= {{"I","V","X"},{"X","L","C"},{"C","D","M"}};
    string dc(int num,int p){//0-9 0-2
        if(num==0){
            return "";
        }
        if(5<=num&&num<=8){
            string pre = data[p][1];
            string t = dc(num-5,p);
            pre.append(t);
            return pre;
        }
        if(1<=num&&num<=3){
            return string(num,data[p][0][0]);
        }
        if(num==4){
            return data[p][0]+data[p][1];
        }
        if(num==9){
            return data[p][0]+data[p][2];
        }
    }
    string intToRoman(int num) {
        int th = num/1000;
        string res(th,'M');
        num%=1000;
        res.append(dc(num/100,2));
        num%=100;
        res.append(dc(num/10,1));
        num%=10;
        res.append(dc(num,0));
        return res;
        
    }
};