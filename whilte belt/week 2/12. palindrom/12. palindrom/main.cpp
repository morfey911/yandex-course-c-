//
//  main.cpp
//  12. palindrom
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
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

int main(int argc, const char * argv[]) {
    string s;

    cin >> s;
    cout << IsPalindrom(s);

    return 0;
}
