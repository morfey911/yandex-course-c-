//
//  main.cpp
//  24. buses - 2
//
//  Created by Yurii Mamurko on 11/26/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int q;
    map<vector<string>, unsigned long> route_to_number;

    cin >> q;

    for (int i = 0; i < q; ++i) {
        int stopCount;
        vector<string> stops;

        cin >> stopCount;

        for (int j = 0; j < stopCount; ++j) {
            string stop;

            cin >> stop;

            stops.push_back(stop);
        }

        if (route_to_number.count(stops) == 0) {
            unsigned long nextRouteNumber = route_to_number.size() + 1;

            cout << "New bus " << nextRouteNumber << endl;
            route_to_number[stops] = nextRouteNumber;
        } else {
            cout << "Already exists for " << route_to_number[stops] << endl;
        }
    }

    return 0;
}
