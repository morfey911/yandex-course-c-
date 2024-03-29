//
//  main.cpp
//  33. names - 2
//
//  Created by Yurii Mamurko on 11/30/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_name_to_year[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        last_name_to_year[year] = last_name;
    }

    string GetFullName(int year) {
        const vector<string> first_names = FindNamesHistory(first_name_to_year, year);
        const vector<string> last_names = FindNamesHistory(last_name_to_year, year);

        string first_name;
        string last_name;

        if (!first_names.empty()) {
            first_name = first_names.back();
        }

        if (!last_names.empty()) {
            last_name = last_names.back();
        }

        return BuildFullName(first_name, last_name);
    }

    string GetFullNameWithHistory(int year) {
        const string joined_first_name = BuildJoinedName(FindNamesHistory(first_name_to_year, year));
        const string joined_last_name = BuildJoinedName(FindNamesHistory(last_name_to_year, year));

        return BuildFullName(joined_first_name, joined_last_name);
    }

private:
    map<int, string> first_name_to_year;
    map<int, string> last_name_to_year;

    vector<string> FindNamesHistory(map<int, string>& name_to_year, int year) {
        vector<string> names;
        string lastChangedName;

        for (const auto& [key, value] : name_to_year) {
            if (key > year) {
                break;
            }

            if (lastChangedName != value) {
                lastChangedName = value;
                names.push_back(value);
            }
        }

        return names;
    }

    string BuildJoinedName(vector<string> names) {
        string result;
        unsigned long size = names.size();

        if (size == 0) {
            return result;
        }

        reverse(names.begin(), names.end());

        result += names[0];

        if (size > 1) {
            result += " (";

            for (int i = 1; i < size; ++i) {
                result += names[i];

                if (i < size - 1) {
                    result += ", ";
                }
            }

            result += ')';
        }

        return result;
    }

    string BuildFullName(const string& first_name, const string& last_name) {
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        }

        return first_name + " " + last_name;
    }
};

int main(int argc, const char * argv[]) {
    Person person;

     person.ChangeFirstName(1965, "Polina");
     person.ChangeLastName(1967, "Sergeeva");
     for (int year : {1900, 1965, 1990}) {
       cout << person.GetFullNameWithHistory(year) << endl;
     }

     person.ChangeFirstName(1970, "Appolinaria");
     for (int year : {1969, 1970}) {
       cout << person.GetFullNameWithHistory(year) << endl;
     }

     person.ChangeLastName(1968, "Volkova");
     for (int year : {1969, 1970}) {
       cout << person.GetFullNameWithHistory(year) << endl;
     }

     person.ChangeFirstName(1990, "Polina");
     person.ChangeLastName(1990, "Volkova-Sergeeva");
     cout << person.GetFullNameWithHistory(1990) << endl;

     person.ChangeFirstName(1966, "Pauline");
     cout << person.GetFullNameWithHistory(1966) << endl;

     person.ChangeLastName(1960, "Sergeeva");
     for (int year : {1960, 1967}) {
       cout << person.GetFullNameWithHistory(year) << endl;
     }

     person.ChangeLastName(1961, "Ivanova");
     cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
