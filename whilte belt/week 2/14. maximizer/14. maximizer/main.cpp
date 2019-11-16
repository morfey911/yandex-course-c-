//
//  main.cpp
//  14. maximizer
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void UpdateIfGreater(const int first, int& second) {
    if (first > second) {
        second = first;
    }
}

int main(int argc, const char * argv[]) {
    int a, b;

    cin >> a >> b;

    UpdateIfGreater(a, b);

    cout << a << ' ' << b;

    return 0;
}
