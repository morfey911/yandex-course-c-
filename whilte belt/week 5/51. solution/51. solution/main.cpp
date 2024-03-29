//
//  main.cpp
//  51. solution
//
//  Created by Yurii Mamurko on 11.12.2019.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Date {
public:
    Date(int year = 1, int month = 1, int day = 1) {
        if (month < 1 || month > 12) {
            throw domain_error("Month value is invalid: " + to_string(month));
        } else if (day < 1 || day > 31) {
            throw domain_error("Day value is invalid: " + to_string(day));
        }

        this->year = year;
        this->month = month;
        this->day = day;
    }

    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }

private:
    int day, month, year;
};

Date dateFromString(const string& dateString) {
    Date result;
    int y, m, d;
    char def1, def2;
    stringstream stream(dateString);

    if (stream >> y >> def1 >> m >> def2 >> d && stream.peek() == EOF && def1 == '-' && def2 == '-') {
        result = Date(y, m, d);
    } else {
        throw domain_error("Wrong date format: " + dateString);
    }

    return result;
}

bool operator < (const Date& lhs, const Date& rhs) {
    return lhs.GetYear() * 365 + lhs.GetMonth() * 31 + lhs.GetDay() < rhs.GetYear() * 365 + rhs.GetMonth() * 31 + rhs.GetDay();
}

ostream& operator << (ostream& stream, const Date& date) {
    stream << setfill('0')
           << setw(4) << date.GetYear() << "-"
           << setw(2) << date.GetMonth() << "-"
           << setw(2) << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        db[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (db.count(date) == 1 ) {
            auto& events = db[date];
            const auto& it = events.find(event);

            if (it != events.end()) {
                events.erase(it);
                return true;
            }
        }

        return false;
    }

    int DeleteDate(const Date& date) {
        int result = 0;

        try {
            result = db.at(date).size();
        } catch (out_of_range &) {
            return 0;
        }

        db.erase(date);

        return result;
    }

    set<string> Find(const Date& date) const {
        if (db.count(date) != 0) {
            return db.at(date);
        }

        return {};
    }

    void Print() const {
        for (const auto& [date, events] : db) {
            for (const auto& event : events) {
                cout << date << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> db;
};

int main(int argc, const char * argv[]) {
    try {
        Database db;

        string command;

        while (getline(cin, command)) {
            string c;
            stringstream stream(command);

            stream >> c;
            if (c.empty()) {

            } else if (c == "Add") {
                string d, event;
                stream >> d >> event;

                db.AddEvent(dateFromString(d), event);
            } else if (c == "Del") {
                string d;
                stream >> d;
                const Date& date = dateFromString(d);

                if (stream.peek() == EOF) {
                    int deletedDates = db.DeleteDate(date);
                    cout << "Deleted " << to_string(deletedDates) << " events" << endl;
                } else {
                    string event;
                    stream >> event;

                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                }
            } else if (c == "Find") {
                string d;
                stream >> d;
                const Date& date = dateFromString(d);
                set<string> events = db.Find(date);

                for (const string& event : events) {
                    cout << event << endl;
                }
            } else if (c == "Print") {
                db.Print();
            } else {
                cout << "Unknown command: " << c << endl;
                return 0;
            }
        }
    } catch (domain_error& er) {
        cout << er.what() << endl;
        return 0;
    }

    return 0;
}
