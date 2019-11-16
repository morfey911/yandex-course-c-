//
//  main.cpp
//  5. division
//
//  Created by Yurii Mamurko on 11/14/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;

    cin >> a >> b;

    if (b == 0) {
        cout << "Impossible";
    } else {
        cout << a / b;
    }

    return 0;
}
