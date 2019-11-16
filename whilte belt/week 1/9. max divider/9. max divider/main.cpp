//
//  main.cpp
//  9. max divider
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
    int a, b;

    cin >> a >> b;
    cout << gcd(a, b);

    return 0;
}
