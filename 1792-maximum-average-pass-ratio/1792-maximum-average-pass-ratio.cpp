class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        priority_queue<P>pq;
        for(int i=0;i<n;i++){
            double c_pr = (double)arr[i][0]/arr[i][1];
            double new_pr = (double)(arr[i][0]+1)/(arr[i][1]+1);
            double delta = new_pr - c_pr;
            pq.push({delta,i});
        }
        while(k--){
            auto curr = pq.top();
            pq.pop();
            double delta = curr.first;
            int idx = curr.second;
            arr[idx][0]++;
            arr[idx][1]++;

            double c_pr = (double)arr[idx][0]/arr[idx][1];
            double new_pr =(double)(arr[idx][0]+1)/(arr[idx][1]+1);
            delta = new_pr - c_pr;
            pq.push({delta,idx});
        }
        double result =0.0;
        for(int i=0;i<n;i++){
            result += (double)arr[i][0]/arr[i][1];
        }
        return result/n;
    }
};