#include <algorithm>
#include <cmath>
using namespace std;

typedef vector<int> VI;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(VI A, VI B) {
        double normA = sqrt(innerProduct(A, A));
        double normB = sqrt(innerProduct(B, B));
        if (fabs(normA) < EPS || fabs(normB) < EPS) {
            return INVALID_VALUE;
        }
        
        return innerProduct(A, B) / (normA * normB);
    }
protected:
    double EPS = 1e-7;
    double INVALID_VALUE = 2.0;
    
    double innerProduct(const VI &a, const VI &b) {
        int n = min(a.size(), b.size());
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += 1.0 * a[i] * b[i];
        }
        return sum;
    }
};
