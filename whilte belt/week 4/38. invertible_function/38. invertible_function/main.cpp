//
//  main.cpp
//  38. invertible_function
//
//  Created by Yurii Mamurko on 12/4/19.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

struct FunctionPart {
public:
    FunctionPart(const char operation, const double value) {
        this->operation = operation;
        this->value = value;
    }

    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        } else {
            return source_value - value;
        }
    }

    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else {
            operation = '+';
        }
    }

private:
    char operation;
    double value;
};

struct Function {
public:
    void AddPart(const char c, double value) {
        parts.push_back({c, value});
    }

    double Apply(double value) const {
        for (const auto& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }

    void Invert() {
        for (auto& part : parts) {
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    }
private:
    vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('-', image.freshness * params.a + params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main(int argc, const char * argv[]) {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 46) << endl;

    return 0;
}
