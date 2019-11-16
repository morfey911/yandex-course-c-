//
//  main.cpp
//  16. reverse
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    const auto copy = v;
    const auto size = copy.size();

    for (size_t i = 0; i < size; ++i) {
        v[i] = copy[size - i - 1];
    }
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    // numbers должен оказаться равен {2, 4, 3, 5, 1}

    return 0;
}
