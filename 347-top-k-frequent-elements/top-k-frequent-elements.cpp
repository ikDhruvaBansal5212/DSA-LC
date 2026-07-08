class compare {
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;   // smaller frequency has higher priority
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        for (int num : nums)
            mp[num]++;

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       compare> pq;

        for (auto &it : mp) {
            pq.push(it);          // {number, frequency}

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};