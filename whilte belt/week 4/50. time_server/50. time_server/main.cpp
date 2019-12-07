//
//  main.cpp
//  50. time_server
//
//  Created by Yurii Mamurko on 07.12.2019.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <exception>
#include <string>

using namespace std;

string AskTimeServer() {
    return "00:05:00";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        } catch (system_error& se) {

        }

        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
