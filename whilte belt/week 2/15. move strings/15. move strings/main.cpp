//
//  main.cpp
//  15. move strings
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto s : source) {
        destination.push_back(s);
    }
    source.clear();
}

int main(int argc, const char * argv[]) {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};

    MoveStrings(source, destination);
    // source должен оказаться пустым
    // destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
    return 0;
}
