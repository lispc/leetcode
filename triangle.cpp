class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
     int level = triangle.size();
     vector<int> buf(level,0);
     buf[0]=triangle[0][0];
     for(int i=1;i<level;i++){
         buf[i]=buf[i-1]+triangle[i][i];
         for(int j=i-1;j>0;j--){
             buf[j]=min(buf[j],buf[j-1])+triangle[i][j];
         }
         buf[0]=buf[0]+triangle[i][0];
     }
     return *min_element(buf.begin(),buf.end());
     /*
    int m = buf[0];
    for(int i=1;i<level;i++){
        if(buf[i]<m){
            m=buf[i];
        }
    }
    return m;
    */
    }
};