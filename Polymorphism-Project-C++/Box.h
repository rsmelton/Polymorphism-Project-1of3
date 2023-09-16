#ifndef _BOX_H_
#define _BOX_H_

#include "Shape.h"

using namespace std;

class Box:public Shape { // Box Inherits all of class Shape
public:
   Box();
   ~Box() = default;

   void setLength(const double&);
   double getLength() const;

   void setWidth(const double&);
   double getWidth() const;

   void setHeight(const double&);
   double getHeight() const;

   double getArea() const;         
   double getVolume() const;

   bool comparisonOfTypes(string, string) const;
   bool comparisonOfValues(string, double, double) const;
   bool test(const vector<string>& cond) const;
   
   string formatInfoAsString(double) const;
   string getInfo() const;

private:
   string name;
   double length;
   double width;
   double height;
   string type_of_shape;
};

#endif