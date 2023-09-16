#include "Box.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

Box::Box() : Shape(name) {
    this->type_of_shape = "box";
    this->length = 0.0;
    this->width = 0.0;
    this->height = 0.0;
}

void Box::setLength(const double& length) {
    this->length = length;
}

double Box::getLength() const {
    return length;
}

void Box::setWidth(const double& width) {
    this->width = width;
}

double Box::getWidth() const {
    return width;
}

void Box::setHeight(const double& height) {
    this->height = height;
}

double Box::getHeight() const {
    return height;
}

double Box::getArea() const {
    double surface_area = 2 * ((length * width) + (length * height) + (width * height));
    return surface_area;
}

double Box::getVolume() const {
    double volume = length * width * height;
    return volume;
}

bool Box::comparisonOfTypes(string op, string typeToBeComparedWith) const {
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

bool Box::comparisonOfValues(string op, double myValue, double valueToBeComparedWith) const {
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

bool Box::test(const vector<string>& cond) const {
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

string Box::formatInfoAsString(double value) const {
    stringstream ss;
    ss << fixed << setprecision(2) << value;
    return ss.str();
}

string Box::getInfo() const {
    string nameOfShape = getName();
    string length_as_string = formatInfoAsString(length);
    string width_as_string = formatInfoAsString(width);
    string height_as_string = formatInfoAsString(height);
    string surface_area_as_string = formatInfoAsString(getArea());
    string volume_as_string = formatInfoAsString(getVolume());

    string info = "Box: " + nameOfShape + ", Length=" + length_as_string + ", Width=" + width_as_string + ", Height=" + height_as_string + "\n" +
                  "        Surface Area: " + surface_area_as_string + ", Volume: " + volume_as_string;
    return info;
}