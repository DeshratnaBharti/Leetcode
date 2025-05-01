class Solution {
public:
    bool checks(vector<int>& tasks, vector<int>& workers, int pills, int strength,int mid){
        int pillsUsed=0;
        multiset<int>st(begin(workers),begin(workers)+mid);
        for(int i=mid-1;i>=0;i--){
            int required=tasks[i];
            auto it=prev(st.end());
            if(*it >=required) st.erase(it);
            else if(pillsUsed >=pills) return false;
            else{
                //find the weakest worker which can do this strong task using pills
                auto weakestWorker = st.lower_bound(required-strength);
                if(weakestWorker ==st.end()) return false;//matlab nahi mila weakest worker
                st.erase(weakestWorker);
                pillsUsed++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
         int m =tasks.size();
        int n=workers.size();
        int l=0,r=min(m,n);
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());
        int res=0;
        while(l<=r){
            int mid =l+(r-l)/2;
            if(checks(tasks,workers,pills,strength,mid)){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res;
    }
};