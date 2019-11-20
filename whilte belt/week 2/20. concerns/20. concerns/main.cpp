//
//  main.cpp
//  20. concerns
//
//  Created by Yurii Mamurko on 11/19/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int> DAYS_IN_MONTH = {31,28,31,30,31,30,31,31,30,31,30,31};

void Dump(const vector<vector<string>>& calendar, const int day) {
    const vector<string>day_list = calendar[day - 1];

    cout << day_list.size();
    for (const auto& s : day_list) {
        cout << ' ' << s;
    }
    cout << endl;
}

vector<vector<string>> NextCalendar(const vector<vector<string>> calendar, const int current_month) {
    const int nextMonth = current_month == 11 ? 0 : current_month + 1;
    const int days_in_next_month = DAYS_IN_MONTH[nextMonth];
    vector<vector<string>> result = calendar;

    if (days_in_next_month < calendar.size()) {
        vector<string>& vector_to_put = result[days_in_next_month - 1];

        for (int i = days_in_next_month; i < DAYS_IN_MONTH[current_month]; ++i) {
            vector_to_put.insert(vector_to_put.end(), calendar[i].begin(), calendar[i].end());
        }
    }

    result.resize(days_in_next_month);

    return result;
}

int main(int argc, const char * argv[]) {
    int commands_count;
    int month = 0;
    vector<vector<string>> calendar(DAYS_IN_MONTH[month]);

    cin >> commands_count;

    for (int i = 0; i < commands_count; ++i) {
        string command;

        cin >> command;

        if (command == "ADD") {
            int day;
            string concern;
            cin >> day >> concern;
            calendar[day - 1].push_back(concern);
        } else if (command == "DUMP") {
            int day;
            cin >> day;
            Dump(calendar, day);
        } else if (command == "NEXT") {
            calendar = NextCalendar(calendar, month);
            if (month < 11) {
                ++month;
            } else {
                month = 0;
            }
        }
    }

    return 0;
}
