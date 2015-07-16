// <map> is a powerful magic
#include <map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        small.clear();
        large.clear();
        ns = nl = 0;
        
        vector<int> ans;
        vector<int> &a = nums;
        int n = a.size();
        if (n == 0 || k == 0) {
            return ans;
        }
        
        ns = nl = 0;
        int s, l;
        int i;
        for (i = 0; i < k - 1; ++i) {
            add(a[i]);
        }
        for (i = k - 1; i < n; ++i) {
            add(a[i]);
            ans.push_back(small.rbegin()->first);
            remove(a[i - k + 1]);
        }
        return ans;
    }
private:
    map<int, int> small, large;
    int ns, nl;
    
    void del(map<int, int> &m, int x) {
        --m[x];
        if (m[x] == 0) {
            m.erase(x);
        }
    }
    
    void adjust() {
        if (small.empty() || large.empty()) {
            return;
        }
        
        int n1, n2;
        n1 = small.rbegin()->first;
        n2 = large.begin()->first;
        if (n1 <= n2) {
            return;
        }
        
        del(small, n1);
        ++small[n2];
        
        del(large, n2);
        ++large[n1];
    }
    
    void add(int x) {
        if (ns == nl) {
            ++small[x];
            ++ns;
        } else {
            ++large[x];
            ++nl;
        }
        adjust();
    }
    
    void remove(int x) {
        if (small.find(x) != small.end()) {
            del(small, x);
            --ns;
        } else {
            del(large, x);
            --nl;
        }
        if (ns < nl) {
            ++small[large.begin()->first];
            del(large, large.begin()->first);
            ++ns;
            --nl;
        } else if (ns > nl + 1) {
            ++large[small.rbegin()->first];
            del(small, small.rbegin()->first);
            --ns;
            ++nl;
        }
        adjust();
    }
};