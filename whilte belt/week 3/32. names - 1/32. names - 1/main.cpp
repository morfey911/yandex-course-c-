//
//  main.cpp
//  32. names - 1
//
//  Created by Yurii Mamurko on 11/30/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

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
        string first_name = NameLowerThanYear(first_name_to_year, year);
        string last_name = NameLowerThanYear(last_name_to_year, year);

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        }

        return first_name + ' ' + last_name;
    }

private:
    map<int, string> first_name_to_year;
    map<int, string> last_name_to_year;

    string NameLowerThanYear(map<int, string> name_to_year, int year) {
        string result;

        for (const auto& [key, value] : name_to_year) {
            if (key > year) {
                break;
            }

            result = value;
        }

        return result;
    }
};

int main(int argc, const char * argv[]) {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
      cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
      cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
      cout << person.GetFullName(year) << endl;
    }

    return 0;
}
