//
//  main.cpp
//  17. reverse 2
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    auto result = v;
    const auto size = result.size();

    for (size_t i = 0; i < size; ++i) {
        result[i] = v[size - i - 1];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {1, 5, 3, 4, 2};
    numbers = Reversed(numbers);
    // numbers должен оказаться равен {2, 4, 3, 5, 1}

    return 0;
}
