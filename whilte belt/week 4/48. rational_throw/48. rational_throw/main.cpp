//
//  main.cpp
//  48. rational_throw
//
//  Created by Yurii Mamurko on 07.12.2019.
//  Copyright © 2019 Yurii Mamurko. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <stdexcept>

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
        if (denominator == 0) {
            throw invalid_argument("Invalid syntax.");
        }

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

bool operator < (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator();
}

bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator += (const Rational& lhs, const Rational& rhs) {
    return {(lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator()), lhs.Denominator() * rhs.Denominator()};
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return lhs += rhs;
}

Rational operator -= (const Rational& lhs, const Rational& rhs) {
return {(lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator()), lhs.Denominator() * rhs.Denominator()};
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return lhs -= rhs;
}

Rational operator *= (const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return lhs *= rhs;
}

Rational operator /= (const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Numerator();

    if (denominator == 0) {
        throw domain_error("");
    }

    return {numerator, denominator};
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    return lhs /= rhs;
}

ostream& operator << (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& rational) {
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {

    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
