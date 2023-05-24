// PROBLEM: https://leetcode.com/problems/min-stack/
#include <vector>
#include <iostream>

using namespace std;

struct LinkedList {
    LinkedList *Next;
    int Value;

    LinkedList(LinkedList *n, int v) {
        Next = n;
        Value = v;
    }
};

/* A MinStack is a class that implements all the standard stack operations in O(1) as well
 * as the getMin function which returns the smallest element on the stack. The key to the O(1)
 * complexity of this operation is keeping a linked list of min elements. If we push a new minimum
 * element onto the stack we remember it as the min, and we make it the head of the minimum elements
 * list by setting its successor to the previous minimum element. Now when we put elements with a higher
 * value we know that when we pop them nothing will happen to the minimum element. When we pop the minimum
 * element we just set the new minimum to its successor (the previous minimum), which achieves O(1) time.
*/
class MinStack {
    vector<int> elements;
    int index;
    LinkedList *minHead;
public:
    MinStack() {
        elements = vector<int>(0);
        index = 0;
        minHead = nullptr;
    }

    void push(int val) {
        if (index == elements.size()) {
            elements.push_back(val);
        } else {
            elements[index] = val;
        }

        if (minHead == nullptr || val <= minHead->Value) {
            auto newHead = new LinkedList(minHead, val);
            minHead = newHead;
        }

        ++index;
    }

    void pop() {
        int v = top();
        if (v == minHead->Value) {
            auto t = minHead;
            minHead = minHead->Next;
            delete(t);
        }

        --index;
    }

    int top() {
        return elements[index - 1];
    }

    int getMin() {
        return minHead->Value;
    }
};

int main() {
    auto ms = MinStack();
    ms.push(2147483646);
    ms.push(2147483646);
    ms.push(2147483647); // 2147483646 2147483646 2147483647

    cout << ms.top() << "\n"; // 2147483647
    ms.pop(); // 2147483646 2147483646
    cout << ms.getMin() << "\n"; // 2147483646
    ms.pop(); // 2147483646
    cout << ms.getMin() << "\n"; // 2147483646
    ms.pop(); //

    ms.push(2147483647); // 2147483647
    cout << ms.top() << "\n"; // 2147483646
    cout << ms.getMin() << "\n"; // 2147483646


    ms.push(-2147483648); // 2147483646 -2147483648
    cout << ms.top() << "\n"; // -2147483648
    cout << ms.getMin() << "\n"; // -2147483648
    ms.pop(); // 2147483646
    cout << ms.getMin() << "\n"; // 2147483646
}