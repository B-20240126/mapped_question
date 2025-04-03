class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> freq;
            for(int num : nums) freq[num]++;
    
            // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
            // for(auto& entry : freq){
            //     minHeap.push({entry.second, entry.first});
            //     if(minHeap.size() > k) minHeap.pop();
            // }
    
            // vector<int> res;
            // while(!minHeap.empty()){
            //     res.push_back(minHeap.top().second);
            //     minHeap.pop();
            // }
            // return res;
    
            // BucketSort
            vector<vector<int>> bucket(nums.size() + 1);
    
            for(auto& entry : freq){
                bucket[entry.second].push_back(entry.first);
            }
    
            vector<int> result;
            for(int i = bucket.size() - 1; i >= 0 && result.size() < k; i--){
                for(int num : bucket[i]){
                    result.push_back(num);
                    if(result.size() == k) break;
                }
            }
            return result;
        }
    };