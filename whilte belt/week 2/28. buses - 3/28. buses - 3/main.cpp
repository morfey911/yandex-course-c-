//
//  main.cpp
//  28. buses - 3
//
//  Created by Yurii Mamurko on 11/26/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int q;
    map<set<string>, unsigned long> route_to_number;

    cin >> q;

    for (int i = 0; i < q; ++i) {
        int stopCount;
        set<string> stops;

        cin >> stopCount;

        for (int j = 0; j < stopCount; ++j) {
            string stop;

            cin >> stop;

            stops.insert(stop);
        }

        if (route_to_number.count(stops) == 0) {
            unsigned long next_route_number = route_to_number.size() + 1;

            cout << "New bus " << next_route_number << endl;
            route_to_number[stops] = next_route_number;
        } else {
            cout << "Already exists for " << route_to_number[stops] << endl;
        }
    }

    return 0;
}
