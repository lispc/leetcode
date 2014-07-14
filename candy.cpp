class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        if(size<=1){
            return size; 
        }
        if(size==2){
            if(ratings[0]==ratings[1]){
                return 2;
            }
            return 3;
        }
        vector<int> rbak = ratings;
        sort(rbak.begin(),rbak.end());
        rbak.erase(unique(rbak.begin(),rbak.end()),rbak.end());
        map<int,int> buf;
        for(int i=0;i<rbak.size();i++){
            buf[rbak[i]]=i+1;
        }
        vector<int> cv;
        for(int i=0;i<size;i++){
            cv.push_back(buf[ratings[i]]);
        } 
        int k = 0;
        while(k+1<size&&cv[k]==cv[k+1]){
            k++;
        }
        if(k==size-1||cv[k]<cv[k+1]){
            for(int t = 0;t<=k;t++){
                cv[t]=1;
            }
        }else{
            for(int t = 0;t<k;t++){
                cv[t]=1;
            }
        }
        k = size - 1;
        while(k&&cv[k]==cv[k-1]){
            k--;
        }
        if(!k||cv[k]<cv[k-1]){
            for(int t = size-1;t>=k;t--){
                cv[t]=1;
            }
        }else{
            for(int t = size-1;t>k;t--){
                cv[t]=1;
            }
        }
        int eqf = 0;
        for(int i=1;i<size;i++){
            if(cv[i]==cv[i-1]){
                if(!eqf){
                    eqf = i-1;
                }
                continue;
            }
            if(cv[i]<cv[i-1]){
                if(eqf){
                    int start;
                    if(eqf==0||cv[eqf]<cv[eqf-1]){
                        start = eqf;
                    }else{
                        start = eqf+1;
                    }
                    for(int ss=start;ss<i-1;ss++){
                        cv[ss]=1;
                    }
                }
                eqf = 0;
                if(cv[i]<cv[i+1]){
                    cv[i]=1;
                    continue;
                }
                if(cv[i]>cv[i+1]){
                    continue;
                }
            }
            if(cv[i]>cv[i-1]){
                if(eqf){
                    int start;
                    if(eqf==0||cv[eqf]<cv[eqf-1]){
                        start = eqf;
                    }else{
                        start = eqf+1;
                    }
                    for(int j=start;j<i;j++){
                        cv[j]=1;
                    }
                }
                eqf = 0;
            }
        }
        vector<int> passf(size,1);
        vector<int> passb(size,1);
        vector<int> final(size,1);
        int i = 0;
        while(i<size){
            while(i<size&&cv[i]!=1){
                i++;
            }
            if(i==size){
                break;
            }
            i++;
            while(i<size&&cv[i]>cv[i-1]){
                passf[i]=passf[i-1]+1;
                i++;
            }
        }
        i = size-1;
        while(i>=0){
            while(i>=0&&cv[i]!=1){
                i--;
            }
            if(i==-1){
                break;
            }
            i--;
            while(i>=0&&cv[i]>cv[i+1]){
                passb[i]=passb[i+1]+1;
                i--;
            }
        }
        for(int fuck=0;fuck<cv.size();fuck++){
            final[fuck] = max(passf[fuck],passb[fuck]);
        }
        return accumulate(final.begin(),final.end(),0);
    }
};