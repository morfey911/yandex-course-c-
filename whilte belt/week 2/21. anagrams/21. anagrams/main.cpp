//
//  main.cpp
//  21. anagrams
//
//  Created by Yurii Mamurko on 11/22/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int>BuildCharCounters(const string& word) {
    map<char, int> result;

    for (char c : word) {
        ++result[c];
    }

    return result;
}

int main(int argc, const char * argv[]) {
    int quantity;

    cin >> quantity;

    for (int i = 0; i < quantity; ++i) {
        string a, b;
        cin >> a >> b;
        string isAnagramAnswer = BuildCharCounters(a) == BuildCharCounters(b) ? "YES" : "NO";
        cout << isAnagramAnswer << endl;
    }

    return 0;
}
