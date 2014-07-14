class Solution {
public:
 int pw(int a,int b){
        if(b==0){
            return 1;
        }
        int half = pw(a,b/2);
        return half*half*(b%2?a:1);
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int l = gas.size();
        vector<int> delta(l);
        for(int i=0;i<l;i++){
            delta[i]=gas[i]-cost[i];
        }
        vector<vector<pair<int,int>>> buf;//delta,summin
        vector<pair<int,int>> local;//2**0==1
        for(int i=0;i<l;i++){
            local.push_back(make_pair(delta[i],delta[i]));   
        }
        buf.push_back(local);
        int ll = l/2;
        int level = 0;
        while(ll){
            level++;
            vector<pair<int,int>> local;//2**0==1
            for(int i=0;i<ll;i++){
                int tmp_delta = buf[level-1][i*2].first+buf[level-1][i*2+1].first;
                int tmp_sumin = min(buf[level-1][i*2].second,buf[level-1][i*2+1].second+buf[level-1][i*2].first);
                local.push_back(make_pair(tmp_delta,tmp_sumin));   
            }
            buf.push_back(local);
            ll/=2;
        }
        for(int s=0;s<l;s++){
			int overlap=0;
            int save = 0;
            int cur = s;
            while(1){
                int ss = cur%l;
                int pwr = 0;
                int carry=ss%2;
                while(carry==0&&pwr<level){
                    pwr++;
                    ss/=2;
                    carry=ss%2;
                }
                int inc = pw(2,pwr);
				if(inc*(buf[pwr].size())==cur){
					pwr = 0;
					inc = 1;
				}
                int adelta = buf[pwr][(cur%l)/inc].first;
                int asumin = buf[pwr][(cur%l)/inc].second;
                if(asumin+save<0){
                    break;
                }
				//cout<<"add "<<inc<<" to "<<cur<<" start "<<s<<endl;
                cur+=inc;
                save+=adelta;
                if(cur>=s+l){
                    return s;
                }
            }
        }
        return -1;
    }
        
};