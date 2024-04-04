#include <iostream>
#include <string>
#include <vector>

using namespace std;

string lpal(string &input) {
    int sz = input.size();
    vector<string> candidates;

    for (int i = 0; i < sz; i++) {
        if (i == 0 || i == sz - 1) continue;

        int left = i, right = i;
        string sub(1, input[i]);

        while (left >= 0 && right < sz) {
            left--;
            right++;

            if (input[left] == input[right]) {
                sub = input[left] + sub + input[right];
            } else {
                break;
            }
        }

        if (sub.size() > 2) {
            candidates.push_back(sub);
        }
    }

    if (candidates.empty()) {
        return "";
    }

    int mlen = 0, mi = 0;
    int cssz = candidates.size();

    for (int i = 0; i < cssz; i++) {
        int csz = candidates[i].size();
        if (csz > mlen) {
            mlen = csz;
            mi = i;
        }
    }

    return candidates[mi];
}

int main() {
    string input = "abababc";
    string output = lpal(input);

    cout << "Output: " << output << endl;

    return 0;
}
