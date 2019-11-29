//
//  main.cpp
//  29. sort
//
//  Created by Yurii Mamurko on 11/27/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> numbers;
    int q;

    cin >> q;

    for (int i = 0; i < q; ++i) {
        int temp;

        cin >> temp;

        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });

    for (const auto& n : numbers) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
