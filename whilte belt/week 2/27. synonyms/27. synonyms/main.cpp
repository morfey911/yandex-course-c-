//
//  main.cpp
//  27. synonyms
//
//  Created by Yurii Mamurko on 11/26/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

void Add(map<string, set<string>>& word_to_synonyms, const string& first, const string& second) {
    word_to_synonyms[first].insert(second);
    word_to_synonyms[second].insert(first);
}

unsigned long Count(map<string, set<string>>& word_to_synonyms, const string& word) {
    if (word_to_synonyms.count(word) == 0) {
        return 0;
    }

    return word_to_synonyms[word].size();
}

bool Check(map<string, set<string>>& word_to_synonyms, const string& first, const string& second) {
    return word_to_synonyms.count(first) != 0 && word_to_synonyms[first].count(second) != 0;
}

int main(int argc, const char * argv[]) {
    int q;
    map<string, set<string>> word_to_synonyms;

    cin >> q;

    for (int i = 0; i < q; ++i) {
        string request;

        cin >> request;

        if (request == "ADD") {
            string first, second;

            cin >> first >> second;
            Add(word_to_synonyms, first, second);
        } else if (request == "COUNT") {
            string word;

            cin >> word;
            cout << Count(word_to_synonyms, word) << endl;
        } else if (request == "CHECK") {
            string first, second;

            cin >> first >> second;
            string isSynonymWord = Check(word_to_synonyms, first, second) ? "YES" : "NO";
            cout << isSynonymWord << endl;
        }
    }

    return 0;
}
