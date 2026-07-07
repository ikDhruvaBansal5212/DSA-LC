class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }

        unordered_map<int,int>mpp;   //{value,rank};

        int rank=1;

        while(!pq.empty()){
            int temp=pq.top();
            pq.pop();
            if(mpp.find(temp)==mpp.end()){
                mpp[temp]=rank;
                rank++;
            }
        }

        vector<int>res;
        for(int i=0;i<arr.size();i++){
            res.push_back(mpp[arr[i]]);
        }
        return res;
    }
};