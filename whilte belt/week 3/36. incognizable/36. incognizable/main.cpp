//
//  main.cpp
//  36. incognizable
//
//  Created by Yurii Mamurko on 11/30/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>

class Incognizable {
public:
    Incognizable() {};
    Incognizable(int a) {
        this->a = a;
    }
    Incognizable(int a, int b) {
        this->a = a;
        this->b = b;
    }

private:
    int a, b;
};

int main(int argc, const char * argv[]) {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};

    return 0;
}
