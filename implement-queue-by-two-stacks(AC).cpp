#include <stack>
using namespace std;

class Queue {
public:
    Queue() {}

    void push(int element) {
        s1.push(element);
    }
    
    int pop() {
        if (s2.empty()) {
            pour();
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int top() {
        if (s2.empty()) {
            pour();
        }
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
    
    void pour() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
};