//
//  main.cpp
//  26.map_values
//
//  Created by Yurii Mamurko on 11/26/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;

    for (const auto& [key, value] : m) {
        result.insert(value);
    }

    return result;
}
