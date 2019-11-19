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

void Worry(vector<int>& queue, const int value) {
    queue[value] = 1;
}

void Quiet(vector<int>& queue, const int value) {
    queue[value] = 0;
}

int WorryCount(const vector<int>& queue) {
    int result = 0;

    for (auto& x : queue) {
        result += x;
    }

    return result;
}

int main(int argc, const char * argv[]) {
    int count;
    vector<int> queue;

    cin >> count;

    for (int i = 0; i < count; ++i) {
        string command;
        int n;

        cin >> command;

        if (command == "COME") {
            cin >> n;
            Come(queue, n);
        } else if (command == "WORRY") {
            cin >> n;
            Worry(queue, n);
        } else if (command == "QUIET") {
            cin >> n;
            Quiet(queue, n);
        } else if (command == "WORRY_COUNT") {
            cout << WorryCount(queue) << endl;
        }
    }

    return 0;
}
