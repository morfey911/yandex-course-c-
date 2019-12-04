//
//  main.cpp
//  44. students
//
//  Created by Yurii Mamurko on 12/4/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Birthday {
    int day;
    int month;
    int year;
};

struct Student {
    string name;
    string surname;
    Birthday date;
};

int main(int argc, const char * argv[]) {
    int N, M;
    vector<Student> students;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string name, surname;
        int day, month, year;

        cin >> name >> surname >> day >> month >> year;
        students.push_back({name, surname, {day, month, year}});
    }

    cin >> M;

    for (int i = 0; i < M; ++i) {
        string operation;
        int studentIndex;

        cin >> operation >> studentIndex;

        --studentIndex;

        if (operation == "name" && studentIndex >= 0 && studentIndex < N) {
            Student student = students[studentIndex];

            cout << student.name << ' ' << student.surname << endl;
        } else if (operation == "date" && studentIndex >= 0 && studentIndex < N) {
            Student student = students[studentIndex];

            cout << student.date.day << '.' << student.date.month << '.' << student.date.year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}
