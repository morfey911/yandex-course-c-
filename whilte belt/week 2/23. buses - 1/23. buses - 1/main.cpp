//
//  main.cpp
//  23. buses - 1
//
//  Created by Yurii Mamurko on 11/23/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void New_bus(map<string, vector<string>>& stops_for_bus,
             map<string, vector<string>>& buses_for_stop,
             const string& bus,
             const vector<string>& stops)
{
    stops_for_bus[bus] = stops;
    for (const auto& stop : stops) {
        buses_for_stop[stop].push_back(bus);
    }
}

void Buses_for_stop(map<string, vector<string>>& buses_for_stop, const string& stop) {
    if (buses_for_stop.count(stop) == 0) {
        cout << "No stop" << endl;
        return;
    }
    for (const auto& bus : buses_for_stop[stop]) {
        cout << bus << ' ';
    }
    cout << endl;
}

void Stops_for_bus(map<string, vector<string>>& stops_for_bus, map<string, vector<string>>& buses_for_stop, const string& target_bus) {
    if (stops_for_bus.count(target_bus) == 0) {
        cout << "No bus" << endl;
        return;
    }

    for (auto& stop : stops_for_bus[target_bus]) {
        cout << "Stop " << stop << ": ";
        const auto bus_count = buses_for_stop[stop].size();
        if (bus_count == 1) {
            cout << "no interchange" << endl;
        } else {
            for (auto& bus : buses_for_stop[stop]) {
                if (bus != target_bus) {
                    cout << bus << ' ';
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

void Print_all_buses(const map<string, vector<string>>& stops_for_bus) {
    if (stops_for_bus.size() == 0) {
        cout << "No buses" << endl;
        return;
    }

    for (const auto& [bus, stops] : stops_for_bus) {
        cout << "Bus " << bus << ": ";
        for (const auto& stop : stops) {
            cout << stop << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    int q;
    map<string, vector<string>> stops_for_bus;
    map<string, vector<string>> buses_for_stop;

    cin >> q;

    for (int i = 0; i < q; ++i) {
        string request;
        cin >> request;

        if (request == "NEW_BUS") {
            string bus;
            int stop_count;
            vector<string> stops;

            cin >> bus >> stop_count;
            for (int j = 0; j < stop_count; ++j) {
                string stop;
                cin >> stop;
                stops.push_back(stop);
            }

            New_bus(stops_for_bus, buses_for_stop, bus, stops);
        } else if (request == "BUSES_FOR_STOP") {
            string stop;

            cin >> stop;
            Buses_for_stop(buses_for_stop, stop);
        } else if (request == "STOPS_FOR_BUS") {
            string bus;

            cin >> bus;
            Stops_for_bus(stops_for_bus, buses_for_stop, bus);
        } else if (request == "ALL_BUSES") {
            Print_all_buses(stops_for_bus);
        }
    }

    return 0;
}
