//
//  main.cpp
//  37. LectureTitle
//
//  Created by Yurii Mamurko on 12/4/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string value;

    explicit Specialization(const string& value) {
        this->value = value;
    }
};

struct Course {
    string value;

    explicit Course(const string& value) {
        this->value = value;
    }
};

struct Week {
    string value;

    explicit Week(const string& value) {
        this->value = value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization specialization, Course course, Week week) {
        this->specialization = specialization.value;
        this->course = course.value;
        this->week = week.value;
    }
};

int main(int argc, const char * argv[]) {
    // can
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    // can't
//    LectureTitle title("C++", "White belt", "4th");
//
//    LectureTitle title(string("C++"), string("White belt"), string("4th"));
//
//    LectureTitle title = {"C++", "White belt", "4th"};
//
//    LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
//
//    LectureTitle title(
//        Course("White belt"),
//        Specialization("C++"),
//        Week("4th")
//    );
//
//    LectureTitle title(
//        Specialization("C++"),
//        Week("4th"),
//        Course("White belt")
//    );

    return 0;
}
