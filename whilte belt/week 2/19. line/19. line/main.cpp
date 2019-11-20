//
//  main.cpp
//  19. line
//
//  Created by Yurii Mamurko on 11/19/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Come(vector<int>& queue, const int count) {
    if (count > 0) {
        for (int i = 0; i < count; ++i) {
            queue.push_back(0);
        }
    } if (count < 0) {
        for (int i = 0; i > count; --i) {
            queue.pop_back();
            
        }
    }
}

int main(int argc, const char * argv[]) {
    int commandsCount;
    vector<int> queue;

    cin >> commandsCount;

    for (int i = 0; i < commandsCount; ++i) {
        string command;
        int value;

        cin >> command;

        if (command == "COME") {
            cin >> value;
            Come(queue, value);
        } else if (command == "WORRY" || command == "QUIET") {
            cin >> value;
            queue[value] = (command == "WORRY");
        } else if (command == "WORRY_COUNT") {
            cout << count(begin(queue), end(queue), 1) << endl;
        }
    }

    return 0;
}
