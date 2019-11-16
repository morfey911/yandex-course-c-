//
//  main.cpp
//  4. equation
//
//  Created by Yurii Mamurko on 11/13/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    double a, b, c;
    double D;

    cin >> a >> b >> c;

    if (a == 0 && b != 0 && c != 0) {
        cout << -c / b;
    }

    if (b == 0 && c == 0) {
        cout << 0;
    }

    if (c != 0 && b == 0) {
        if (-(c / a) >= 0) {
            auto sqr = sqrt(-c/a);
            cout << +sqr << ' ' << -sqr;
        }
    }

    if (b != 0 && c == 0) {
        cout << 0 << ' ' << - (b / a);
    }

    if (a != 0 && b != 0 && c != 0) {
        D = pow(b, 2) - 4 * a * c;

        if (D == 0) {
            auto sqrtD = sqrt(D);
            auto sqr = (-b + sqrtD) / (2 * a);

            cout << sqr;

        } else if (D > 0) {
            auto sqrtD = sqrt(D);
            auto sqr1 = (-b + sqrtD) / (2 * a);
            auto sqr2 = (-b - sqrtD) / (2 * a);

            cout << sqr1 << ' ' << sqr2;
        }
    }

    return 0;
}
