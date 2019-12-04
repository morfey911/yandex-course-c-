//
//  main.cpp
//  41. input_output
//
//  Created by Yurii Mamurko on 12/4/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (input) {
        string temp;
        while (getline(input, temp)) {
            output << temp << endl;
        }
    }

    return 0;
}
