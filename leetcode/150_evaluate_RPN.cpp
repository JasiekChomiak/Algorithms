// PROBLEM: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Stack {
    vector<int> elements;
    int index;
public:
    Stack() {
        elements = vector<int>(0);
        index = 0;
    }

    void push(int val) {
        if (index == elements.size()) {
            elements.push_back(val);
        } else {
            elements[index] = val;
        }

        ++index;
    }

    int pop() {
        int v = top();
        --index;
        return v;
    }

    int top() {
        return elements[index - 1];
    }
};

int evalRPN(vector<string>& tokens) {
    auto s = Stack();
    for (auto token: tokens) {
        int x, y, z;
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            y = s.pop();
            x = s.pop();
            if (token == "+") {
                z = x + y;
            } else if (token == "-") {
                z = x - y;
            } else if (token == "*") {
                z = x * y;
            } else {
                z = x / y;
            }

            s.push(z);
        } else {
            x = stoi(token);
            s.push(x);
        }
    }

    int r = s.pop();
    return r;
}

int main() {
}