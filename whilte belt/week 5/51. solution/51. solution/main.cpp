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
        if (month <= 0 || month > 12) {
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

    if (stream >> y >> def1 >> m >> def2 >> d && stream.peek() == EOF) {
        try {
            result = Date(y, m, d);
        } catch (domain_error& er) {
            cout << er.what() << endl;
        }
    } else {
        cout << "Wrong date format: " << dateString << endl;
    }

    return result;
}

bool operator < (const Date& lhs, const Date& rhs) {
    return lhs.GetYear() < rhs.GetYear() || lhs.GetMonth() < rhs.GetMonth() || lhs.GetDay() > rhs.GetDay();
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
        unsigned long result = 0;

        if (db.count(date) == 1) {
            result = db[date].size();
            db.erase(date);
        }

        return (int)result;
    }

    set<string> Find(const Date& date) const {
        set<string> result;

        if (db.count(date) != 0) {
            result = db.at(date);
        }

        return result;
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
    Database db;

    string command;

    while (getline(cin, command)) {
        string c;
        stringstream stream(command);

        stream >> c;
        if (c.empty()) {

        } else if (c == "Add") {
            string d;
            string event;

            stream >> d >> event;
            db.AddEvent(dateFromString(d), event);
        } else if (c == "Del") {
            string d;

            stream >> d;

            if (stream.peek() == EOF) {
                int deletedDates = db.DeleteDate(dateFromString(d));
                cout << "Deleted " << to_string(deletedDates) << " events" << endl;
            } else {
                string event;
                stream >> event;

                if (db.DeleteEvent(dateFromString(d), event)) {
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Event not found" << endl;
                }
            }
        } else if (c == "Find") {
            string d;

            stream >> d;

            set<string> events = db.Find(dateFromString(d));
            for (const string& event : events) {
                cout << event << endl;
            }
        } else if (c == "Print") {
            db.Print();
        } else {
            cout << "Unknown command: " << c << endl;
        }
    }

    return 0;
}
