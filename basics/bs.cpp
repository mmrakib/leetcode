#include <iostream>
#include <vector>

using namespace std;

/**
 * Performs a simple binary search on a dynamic array.
 * Assumes the array is sorted.
 * 
 * Time complexity: O(log n)
*/
int bs(vector<int> &input, int target) {
    int sz = input.size();
    int low = 0, high = sz - 1;

    while (low < high) {
        int mid = (low + (high - low)) / 2;
        
        if (input[mid] == target) {
            return mid;
        }

        if (input[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> input = {1, 2, 6, 8, 11};

    int output = bs(input, 3);

    cout << output << endl;

    return 0;
}
