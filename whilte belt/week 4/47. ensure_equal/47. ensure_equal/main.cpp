//
//  main.cpp
//  47. ensure_equal
//
//  Created by Yurii Mamurko on 07.12.2019.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
    if (left != right) {
        stringstream ss;
        ss << left << " != " << right;
        throw runtime_error(ss.str());
    }
}

int main(int argc, const char * argv[]) {
    try {
      EnsureEqual("C++ White", "C++ White");
      EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error& e) {
      cout << e.what() << endl;
    }

    return 0;
}
