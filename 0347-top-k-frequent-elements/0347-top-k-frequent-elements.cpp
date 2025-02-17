class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)m[nums[i]]++;
        priority_queue<pair<int,int>>q;
        for(auto i:m)
        {
            q.push({i.second,i.first});
        }
        while(!q.empty()&& k>0)
        {
  res.push_back(q.top().second);
  q.pop();
  k--;
        }
    return res;     
    }
   
};