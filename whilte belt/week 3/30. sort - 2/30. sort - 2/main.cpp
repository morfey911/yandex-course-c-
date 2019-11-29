//
//  main.cpp
//  30. sort - 2
//
//  Created by Yurii Mamurko on 11/29/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string ToLower(const string& s) {
    string result;

    for (const auto& i : s) {
        result.push_back(tolower(i));
    }

    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> strings;
    int q;

    cin >> q;

    for (int i = 0; i < q; ++i) {
        string temp;

        cin >> temp;

        strings.push_back(temp);
    }

    sort(strings.begin(), strings.end(), [](const string& a, const string& b) {
        return ToLower(a) < ToLower(b);
    });

    for (const auto& s : strings) {
        cout << s << ' ';
    }
    cout << endl;

    return 0;
}
