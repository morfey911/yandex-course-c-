//
//  main.cpp
//  31. sorted_strings
//
//  Created by Yurii Mamurko on 11/29/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
      strings.push_back(s);
  }

  vector<string> GetSortedStrings() {
      vector<string> originalStrings = strings;

      sort(originalStrings.begin(), originalStrings.end());

      return originalStrings;
  }

private:
    vector<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main(int argc, const char * argv[]) {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
