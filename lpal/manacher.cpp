#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string lpal(string &input) {
    int size = input.size();
    int psize = 2 * size + 1;

    string pre;
    int pi = 0;
    pre.resize(psize + 1);

    for (int i = 0; i < size; i++) {
        pre[pi] = '#';
        pre[pi + 1] = input[i];
        pi += 2;
    }
    pre[psize] = '#';

    vector<int> p(psize + 1, 0);
    int center = 0, right = 0;

    for (int i = 1; i < psize; i++) {
        if (i < right) p[i] = min(right - i, p[2 * center - i]);

        while (pre[i + 1 + p[i]] == pre[i - 1 - p[i]]) p[i] += 1;

        if (p[i] + i > right) {
            center = i;
            right = p[i] + 1;
        }
    }

    int index = 0, mlen = 0;

    for (int i = 0; i < psize + 1; i++) {
        if (p[i] > mlen) {
            mlen = p[i];
            index = i;
        }
    }

    return input.substr((index - mlen) / 2, mlen);
}

int main() {
    string input = "abaabc";
    string output = lpal(input);

    cout << "Output: " << output << '\n';

    return 0;
}
