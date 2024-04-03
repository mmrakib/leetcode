#include <iostream>
#include <vector>

using namespace std;

/**
 * Performs a brute force search of all possible pairs that add up to target.
 * For each element that it iterates over, iterates over the entire array again to see if another number gives a valid sum.
 * 
 * Time complexity: O(n^2)
 */
vector<int> two_sum(vector<int> &input, int target) {
    int sz = input.size();

    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (input[i] + input[j] == target && i != j) {
                return {i, j};
            }
        }
    }

    return {}; // No solution
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5};
    int target = 9;

    vector<int> output = two_sum(input, target);

    cout << output[0] << ", " << output[1] << endl;

    return 0;
}
