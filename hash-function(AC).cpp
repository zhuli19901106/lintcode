typedef long long int LL;

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        int n = key.size();
        LL ans = 0;
        int i;
        for (i = 0; i < n; ++i) {
            ans = (ans * 33 + key[i]) % HASH_SIZE;
        }
        return ans;
    }
};