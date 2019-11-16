//
//  main.cpp
//  3. min string
//
//  Created by Yurii Mamurko on 11/13/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string a, b, c;
    string min;

    cin >> a >> b >> c;

    if (a < b) {
        min = a;
    } else {
        min = b;
    }

    if (c < min) {
        min = c;
    }

    cout << min;

    return 0;
}
