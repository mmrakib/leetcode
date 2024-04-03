#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * For each element that it iterates over, hashes the complement of the value of the element. If not found in hash table, adds it to the hash table. If found, solution has been found.
 * Iterating over an array a second time to find a complement of a value is O(n).
 * Hashing the complement of a value and attempting to index a hashtable with it to see if such a complement exists is O(1).
 * Thus, a hash table makes the second search faster, and thus the whole algorithm faster.
 * 
 * Time complexity: O(n)
 */
vector<int> two_sum(vector<int> &input, int target) {
    int sz = input.size();
    unordered_map<int, int> map;

    for (int i = 0; i < sz; i++) {
        int complement = target - input[i];

        if (map.count(complement)) {
            int j = map[complement];
            return {i, j};
        }

        map[input[i]] = i;
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
