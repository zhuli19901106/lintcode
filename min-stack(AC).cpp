#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int number) {
        if (st.empty() || number <= mst.top()) {
            mst.push(number);
        }
        st.push(number);
    }

    int pop() {
        int val = st.top();
        if (mst.top() == st.top()) {
            mst.pop();
        }
        st.pop();
        return val;
    }

    int min() {
        return mst.top();
    }
private:
    stack<int> st, mst;
};