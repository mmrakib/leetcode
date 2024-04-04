#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * Finds the longest substring without repeating characters.
 * Uses a sliding window approach, with a set data structure. The set is used to maintain the uniqueness of each character within the sliding window.
 * 
 * Time complexity: O(n)
*/
int lsubstr(string &input) {
    int sz = input.size();
    int mlen = 0;

    int left = 0, right = 0;
    unordered_set<char> set;
    
    while (right < sz) {
        if (set.count(input[right])) {
            while (set.count(input[right])) {
                set.erase(input[left]);
                left++;
            }
            set.insert(input[right]);
        } else {
            set.insert(input[right]);
            mlen = max(mlen, right - left + 1);
        }
        right++;
    }

    return mlen;
}

int main() {
    string input = "abcabcbb";
    int output = lsubstr(input);

    cout << output << endl;

    return 0;
}
