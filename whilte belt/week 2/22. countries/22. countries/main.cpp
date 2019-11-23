//
//  main.cpp
//  22. countries
//
//  Created by Yurii Mamurko on 11/23/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

void ChangeCapital(map<string, string>& country_to_capital, const string& country, const string& new_capital) {
    if (country_to_capital.count(country) == 0) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        country_to_capital[country] = new_capital;
    } else if (country_to_capital[country] == new_capital) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
        const string old_capital = country_to_capital[country];
        cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
        country_to_capital[country] = new_capital;
    }
}

void RenameCountry(map<string, string>& country_to_capital, const string& old_country_name, const string& new_country_name ) {
    if (old_country_name == new_country_name ||
        country_to_capital.count(old_country_name) == 0 ||
        country_to_capital.count(new_country_name) == 1)
    {
        cout << "Incorrect rename, skip" << endl;
    } else {
        const string capital = country_to_capital[old_country_name];

        cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
        country_to_capital.erase(old_country_name);
        country_to_capital[new_country_name] = capital;
    }
}

void About(map<string, string>& country_to_capital, const string& country) {
    if (country_to_capital.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
    }
}

void Dump(const map<string, string>& country_to_capital) {
    if (country_to_capital.size() == 0) {
        cout << "There are no countries in the world" << endl;
        return;
    }

    for (const auto& [key ,value] : country_to_capital) {
        cout << key << "/" << value << ' ';
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int q;
    map<string, string> country_to_capital;

    cin >> q;

    for (int i = 0; i < q; ++i) {
        string request;
        cin >> request;

        if (request == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            ChangeCapital(country_to_capital, country, new_capital);
        } else if (request == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            RenameCountry(country_to_capital, old_country_name, new_country_name);
        } else if (request == "ABOUT") {
            string country;
            cin >> country;
            About(country_to_capital, country);
        } else if (request == "DUMP") {
            Dump(country_to_capital);
        }
    }

    return 0;
}
