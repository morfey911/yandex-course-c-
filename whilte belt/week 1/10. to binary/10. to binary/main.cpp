//
//  main.cpp
//  10. to binary
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int a;
    int base = 2;
    vector<int> v;

    cin >> a;

    while (a > 0) {
        v.push_back(a % base);
        a /= base;
    }

    for (unsigned long i = v.size(); i > 0; --i) {
        cout << v[i - 1];
    }

    return 0;
}
