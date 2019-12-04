//
//  main.cpp
//  42. output_with_precision
//
//  Created by Yurii Mamurko on 12/4/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input("input.txt");

    if (input) {
        double temp;
        while (input >> temp) {
            cout << fixed << setprecision(3) << temp << endl;
        }
    }

    return 0;
}
