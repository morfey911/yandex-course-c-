//
//  main.cpp
//  43. input_output_table
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
    ofstream output("output.txt");
    int rows, columns;

    if (input) {
        input >> rows >> columns;

        for (int i = 0; i < rows; ++i) {
            int lastRowIndex = columns * 2 - 1;

            for (int j = 0; j < lastRowIndex; ++j) {
                if (j % 2 == 0) {
                    int temp;
                    input >> temp;

                    cout << setw(10) << temp;

                    if (j != lastRowIndex - 1) {
                        cout << ' ';
                    } else {
                        cout << endl;
                    }
                } else {
                    input.ignore(1);
                }
            }

        }
    }

    return 0;
}
