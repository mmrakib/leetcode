#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkpal(string &s) {
    int sz = s.size();

    if (sz < 2) {
        return false;
    }

    int i = 0, j = sz - 1;
    bool ispal = true;

    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else {
            ispal = false;
            break;
        }
    }

    return ispal;
}

/**
 * Brute forces through all possible substring of a given string to find 
*/
string lpal(string &input) {
    int sz = input.size();
    vector<string> candidates;
        
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            string sub = input.substr(i, j);
            if (checkpal(sub)) {
                candidates.push_back(sub);
            }
        }
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
