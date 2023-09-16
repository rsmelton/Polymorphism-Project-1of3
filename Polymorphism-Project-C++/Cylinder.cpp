#include "Cylinder.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

Cylinder::Cylinder() : Shape(name) {
    this->type_of_shape = "cylinder";
    this->radius = 0.0;
    this->height = 0.0;
}

void Cylinder::setRadius(const double& radius) {
    this->radius = radius;
}

double Cylinder::getRadius() const {
    return radius;
}

void Cylinder::setHeight(const double& height) {
    this->height = height;
}

double Cylinder::getHeight() const {
    return height;
}

double Cylinder::getArea() const {
    double surface_area = (2 * PI * radius * height) + (2 * PI * (radius * radius));
    return surface_area;
}

double Cylinder::getVolume() const {
    double volume = PI * (radius * radius) * height;
    return volume;
}

bool Cylinder::comparisonOfTypes(string op, string typeToBeComparedWith) const {
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

bool Cylinder::comparisonOfValues(string op, double myValue, double valueToBeComparedWith) const {
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

bool Cylinder::test(const vector<string>& cond) const {
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

string Cylinder::formatInfoAsString(double value) const {
    stringstream ss;
    ss << fixed << setprecision(2) << value;
    return ss.str();
}

string Cylinder::getInfo() const {
    string nameOfShape = getName();
    string radius_as_string = formatInfoAsString(radius);
    string height_as_string = formatInfoAsString(height);
    string surface_area_as_string = formatInfoAsString(getArea());
    string volume_as_string = formatInfoAsString(getVolume());

    string info = "Cylinder: " + nameOfShape + ", Radius=" + radius_as_string + ", Height=" + height_as_string + "\n" +
                  "        Surface Area: " + surface_area_as_string + ", Volume: " + volume_as_string;
    return info;
}