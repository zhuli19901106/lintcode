#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> ans;
        unordered_map<int, int> um;
        int n = nums.size();
        int i;
        int sum = 0;
        for (i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum == 0) {
                ans.push_back(0);
                ans.push_back(i);
                return ans;
            }
            if (um.find(sum) != um.end()) {
                ans.push_back(um[sum] + 1);
                ans.push_back(i);
                return ans;
            }
            um[sum] = i;
        }
        return ans;
    }
};