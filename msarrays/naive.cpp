#include <iostream>
#include <vector>
#include <limits>

#define INF numeric_limits<int>::max()

using namespace std;

/**
 * Naive solution to finding the median of two sorted arrays.
 * Creates a merged array from the two sorted arrays, then finds the middle index, which varies depending on whether or not array length is odd or even.
 * Returns the median as either the middle value (if odd array length) or average of the two middle values (if even array length).
 * 
 * Time complexity: O(n)
*/
float median(vector<int> &input1, vector<int> &input2) {
    int m = input1.size(), n = input2.size();

    vector<int> merged;
    int i = 0, j = 0;

    for (int k = 0; k < m + n; k++) {
        if (input1[i] < input2[j]) {
            merged.push_back(input1[i]);
            if (i < m - 1) i++;
            else           input1[i] = INF;
        } else {
            merged.push_back(input2[j]);
            if (j < n - 1) j++;
            else           input2[j] = INF;
        }
    }

    float median = 0;

    if ((m + n) % 2 == 0) {
        int index1 = (m + n) / 2 - 1;
        int index2 = (m + n) / 2;

        median = ( ((float) merged[index1]) + ((float) merged[index2]) ) / 2;
    } else {
        int index = (m + n) / 2;

        median = ((float) merged[index]);
    }

    return median;
}

int main() {
    vector<int> input1 = {1, 3, 5, 6};
    vector<int> input2 = {2, 4, 7, 8};

    float output = median(input1, input2);

    cout << "Output: " << output << endl;

    return 0;
}
