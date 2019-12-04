//
//  main.cpp
//  40. input
//
//  Created by Yurii Mamurko on 12/4/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include "fstream"

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input("input.txt");

    if (input) {
        string temp;

        while (getline(input, temp)) {
            cout << temp << endl;
        }
    }

    return 0;
}
