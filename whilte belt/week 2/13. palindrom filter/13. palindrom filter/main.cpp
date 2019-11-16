//
//  main.cpp
//  13. palindrom filter
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string s) {
    size_t middle = s.size() / 2;

    for (size_t i = 0, j = s.size() - 1; i < middle; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }

    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result;

    for (string s : words) {
        if (IsPalindrom(s) && s.length() >= minLength) {
            result.push_back(s);
        }
    }

    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"weew", "bro", "code"};

    vector<string >result = PalindromFilter(words, 4);

    return 0;
}
