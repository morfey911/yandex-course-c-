//
//  main.cpp
//  6. discount
//
//  Created by Yurii Mamurko on 11/14/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    double N, A, B, X, Y;
    double price;

    cin >> N >> A >> B >> X >> Y;

    price = N;

    if (N > A) {
        double discountedValue = N * (X / 100);
        price = N - discountedValue;
    }

    if (N > B) {
        double discountedValue = N * (Y / 100);
        price = N - discountedValue;
    }

    cout << price << endl;

    return 0;
}
