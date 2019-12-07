//
//  main.cpp
//  46. rational_eq_add_sub
//
//  Created by Yurii Mamurko on 06.12.2019.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        int divisor = gcd(numerator, denominator);

        num = numerator / divisor;
        den = denominator / divisor;

        if (num * den < 0) {
            if (den < 0) {
                num = num * -1;
                den = den * -1;
            }
        }

        if (num < 0 && den < 0) {
            num = num * -1;
            den = den * -1;
        }

        if (num == 0) {
            den = 1;
        }
    }

    int Numerator() const {
        return this->num;
    }

    int Denominator() const {
        return this->den;
    }

    Rational& operator= (const Rational& rat) {
        num = rat.Numerator();
        den = rat.Denominator();

        return *this;
    }

private:
    int num, den;
};

bool operator< (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator();
}

bool operator== (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+= (const Rational& lhs, const Rational& rhs) {
    return {(lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator()), lhs.Denominator() * rhs.Denominator()};
}

Rational operator+ (const Rational& lhs, const Rational& rhs) {
    return lhs += rhs;
}

Rational operator-= (const Rational& lhs, const Rational& rhs) {
return {(lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator()), lhs.Denominator() * rhs.Denominator()};
}

Rational operator- (const Rational& lhs, const Rational& rhs) {
    return lhs -= rhs;
}

Rational operator*= (const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator* (const Rational& lhs, const Rational& rhs) {
    return lhs *= rhs;
}

Rational operator/= (const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
    return lhs /= rhs;
}

ostream& operator<< (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>> (istream& stream, Rational& rational) {
    if (stream.peek() == EOF) {
        return stream;
    }

    int a, b;

    stream >> a;
    stream.ignore(1);
    stream >> b;

    rational = Rational(a, b);

    return stream;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
