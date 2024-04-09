#include <iostream>
#include <string>

using namespace std;

int atoi(string &input) {
    int sz = input.size();
    int dec = 1;

    for (int i = 0; i < sz - 1; i++) {
        dec *= 10;
    }

    cout << dec << endl;

    return 0;
}

int main() {
    string input = "12031";
    int output = atoi(input);
    
    return 0;
}
