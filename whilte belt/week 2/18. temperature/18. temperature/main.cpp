//
//  main.cpp
//  18. temperature
//
//  Created by Yurii Mamurko on 17.11.2019.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int Average(const vector<int>& numbers) {
    int sum = 0;
    
    for (auto n : numbers) {
        sum += n;
    }

    return sum / numbers.size();
}

int main(int argc, const char * argv[]) {
    int size = 0;
    int average = 0;
    
    cin >> size;
    
    vector<int> temperatures(size);
    
    for (int i = 0; i < size; ++i) {
        cin >> temperatures[i];
    }
    
    average = Average(temperatures);
    
    vector<int> resultIndices;
    for (int i = 0; i < size; ++i) {
        if (temperatures[i] > average) {
            resultIndices.push_back(i);
        }
    }
    
    cout << resultIndices.size() << endl;
    for (auto index : resultIndices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
