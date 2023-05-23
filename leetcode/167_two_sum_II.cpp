// PROBLEM: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(const vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;

    while (i != j) {
        int t = numbers[i] + numbers[j];
        if (t == target) {
            return vector<int>{i,j};
        } else if (t < target) {
            ++i;
        } else {
            --j;
        }
    }

    return vector<int>{-1,-1};
}

int main() {

}