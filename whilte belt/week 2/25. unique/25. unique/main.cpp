//
//  main.cpp
//  25. unique
//
//  Created by Yurii Mamurko on 11/26/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int q;
    set<string> words;

    cin >> q;

    for (int i = 0; i < q; ++i) {
        string word;

        cin >> word;

        words.insert(word);
    }

    cout << words.size() << endl;

    return 0;
}
