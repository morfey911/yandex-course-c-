//
//  main.cpp
//  34. reversible_string
//
//  Created by Yurii Mamurko on 11/30/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:

    ReversibleString() {}

    ReversibleString(const string& string) {
        this->string = string;
    }

    void Reverse() {
        reverse(string.begin(), string.end());
    }

    string ToString() const {
        return string;
    }

private:
    string string;
};

int main(int argc, const char * argv[]) {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
