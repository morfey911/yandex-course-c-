//
//  main.cpp
//  8. second match
//
//  Created by Yurii Mamurko on 11/16/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string text;
    int matchCount = -2;
    int secondMatchLetterPlace;

    cin >> text;

    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == 'f') {
            matchCount += 1;

            if (matchCount > -1) {
                secondMatchLetterPlace = i;
                cout << i << endl;
                break;
            }
        }
    }

    if (matchCount <= -1) {
        cout << matchCount << endl;
    }

    return 0;
}
