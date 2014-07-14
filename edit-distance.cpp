class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        int** buf = new int*[l1+1];
        for(int i=0;i<=l1;i++){
            buf[i] = new int[l2+1];
        }
        for(int i=0;i<=l1;i++){
            buf[i][0]=i;
        }
        for(int i=0;i<=l2;i++){
            buf[0][i]=i;
        }
        int m;
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                
                int mm = buf[i-1][j-1];
                if(word1[i-1]!=word2[j-1]){
                    mm++;
                }
                m = min(buf[i-1][j],buf[i][j-1])+1;
                buf[i][j] = min(m,mm);
                /*
                m = min(buf[i-1][j], buf[i][j-1]) + 1;
                buf[i][j] = min(m, buf[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
                */
            }
        }
        return buf[l1][l2];
        
    }
};