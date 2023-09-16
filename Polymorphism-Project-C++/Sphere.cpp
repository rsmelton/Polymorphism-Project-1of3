#include "Sphere.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

Sphere::Sphere() : Shape(name) {
    this->type_of_shape = "sphere";
    this->radius = 0.0;
}

void Sphere::setRadius(const double& radius) {
    this->radius = radius;
}

double Sphere::getRadius() const {
    return radius;
}

double Sphere::getArea() const {
    double surface_area = 4 * PI * (radius * radius);
    return surface_area;
}

double Sphere::getVolume() const {
    double volume = 4.0/3.0 * PI * (radius * radius * radius);
    return volume;
}

bool Sphere::comparisonOfTypes(string op, string typeToBeComparedWith) const {
    string myShapeType = this->type_of_shape;

    if (op == "==") {
        if (myShapeType.compare(typeToBeComparedWith) == 0) {
            return true;
        }
    }
    else if (op == "!=") {
        if (myShapeType.compare(typeToBeComparedWith) != 0) {
            return true;
        }
    }
    else if (op == ">=") {
        if (myShapeType.compare(typeToBeComparedWith) >= 0) {
            return true;
        }
    }
    else if (op == "<=") {
        if (myShapeType.compare(typeToBeComparedWith) <= 0) {
            return true;
        }
    }
    else if (op == ">") {
        if (myShapeType.compare(typeToBeComparedWith) > 0) {
            return true;
        }
    }
    else if (op == "<") {
        if (myShapeType.compare(typeToBeComparedWith) < 0) {
            return true;
        }
    }
    return false;
}

bool Sphere::comparisonOfValues(string op, double myValue, double valueToBeComparedWith) const {
    // The values being compared will either be two areas or two volumes being compared.
    // Using one function instead of two considering the code would be the same.
    if (op == "==") {
        if (myValue == valueToBeComparedWith) {
            return true;
        }
    }
    else if (op == "!=") {
        if (myValue != valueToBeComparedWith) {
            return true;
        }
    }
    else if (op == ">=") {
        if (myValue >= valueToBeComparedWith) {
            return true;
        }
    }
    else if (op == "<=") {
        if (myValue <= valueToBeComparedWith) {
            return true;
        }
    }
    else if (op == ">") {
        if (myValue > valueToBeComparedWith) {
            return true;
        }
    }
    else if (op == "<") {
        if (myValue < valueToBeComparedWith) {
            return true;
        }
    }
    return false;
}

bool Sphere::test(const vector<string>& cond) const {
    // if the vector is empty always return true
    if (cond.empty() == true) {
        return true;
    }

    unsigned int i = 0;

    while (i < cond.size()) {
        // We are returning false in all these comparisons due to basically checking to see if 
        // every condition is true since they all have to be true to pass the test.
        // If any of them are false we are done checking.
        // We can increment i like this considering the conditions are in sets of threes.
        string name = cond.at(i);
        i++;
        string op = cond.at(i);
        i++;
        if (name == "type") {
            string typeToBeComparedWith = cond.at(i);
            if (comparisonOfTypes(op, typeToBeComparedWith) == false) {
                return false;
            }
        }
        else if (name == "area") {
            double areaToBeComparedWith = stod(cond.at(i));
            double myArea = getArea();
            if (comparisonOfValues(op, myArea, areaToBeComparedWith) == false) {
                return false;
            }
        }
        else if (name == "volume") { // Using else if for clarification of what name it is
            double volumeToBeComparedWith = stod(cond.at(i));
            double myVolume = getVolume();
            if (comparisonOfValues(op, myVolume, volumeToBeComparedWith) == false) {
                return false;
            }
        }
        i++;
    }
    return true;
}

string Sphere::formatInfoAsString(double value) const {
    stringstream ss;
    ss << fixed << setprecision(2) << value;
    return ss.str();
}

string Sphere::getInfo() const {
    string nameOfShape = getName();
    string radius_as_string = formatInfoAsString(radius);
    string surface_area_as_string = formatInfoAsString(getArea());
    string volume_as_string = formatInfoAsString(getVolume());

    string info = "Sphere: " + nameOfShape + ", Radius=" + radius_as_string + "\n" +
                  "        Surface Area: " + surface_area_as_string + ", Volume: " + volume_as_string;
    return info;
}