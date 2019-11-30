//
//  main.cpp
//  35. names - 3
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
    Person(const string& first_name, const string& last_name, int year) {
        first_name_to_year[year] = first_name;
        last_name_to_year[year] = last_name;
        birthday = year;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year < birthday) {
            return;
        }

        first_name_to_year[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        if (year < birthday) {
            return;
        }

        last_name_to_year[year] = last_name;
    }

    string GetFullName(int year) const {
        if (year < birthday) {
            return "No Person";
        }

        const vector<string> first_names = FindNamesHistory(first_name_to_year, year);
        const vector<string> last_names = FindNamesHistory(last_name_to_year, year);

        return first_names.back() + ' ' + last_names.back();
    }

    string GetFullNameWithHistory(int year) const {
        if (year < birthday) {
            return "No person";
        }

        const string joined_first_name = BuildJoinedName(FindNamesHistory(first_name_to_year, year));
        const string joined_last_name = BuildJoinedName(FindNamesHistory(last_name_to_year, year));

        return joined_first_name + ' ' + joined_last_name;
    }

private:
    int birthday;
    map<int, string> first_name_to_year;
    map<int, string> last_name_to_year;

    vector<string> FindNamesHistory(const map<int, string>& name_to_year, int year) const {
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

    string BuildJoinedName(vector<string> names) const {
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
};

int main(int argc, const char * argv[]) {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
