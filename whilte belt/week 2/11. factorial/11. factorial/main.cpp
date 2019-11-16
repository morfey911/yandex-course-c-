//
//  main.cpp
//  11. factorial
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>

using namespace std;

int Factorial(int a) {
    int result = a;

    if (a <= 0) {
        return 1;
    }

    for (int i = 1; i < a; ++i) {
        result *= i;
    }

    return result;
}

int main(int argc, const char * argv[]) {
    int a;

    cin >> a;
    cout << Factorial(a) << endl;

    return 0;
}
