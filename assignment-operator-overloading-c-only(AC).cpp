#include <cstring>
using namespace std;

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    
    Solution(char *pData) {
        this->m_pData = pData;
    }
    
    ~Solution() {
        delete m_pData;
        m_pData = NULL;
    }

    // Implement an assignment operator
    Solution &operator = (const Solution &object) {
		if (m_pData == object.m_pData) {
            // No need to clone yourself
			return *this;
		}

        if (m_pData != NULL) {
            delete[] m_pData;
            m_pData = NULL;
        }
        char *ptr = NULL;
        if (object.m_pData != NULL) {
			int len = strlen(object.m_pData);
            m_pData = new char[len + 1];
            strcpy(m_pData, object.m_pData);
        }
        return *this;
    }
};