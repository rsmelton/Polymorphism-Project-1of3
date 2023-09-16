#ifndef _CYLINDER_H_
#define _CYLINDER_H_

#include "Shape.h"

using namespace std;

class Cylinder:public Shape {
public:
   Cylinder();
   ~Cylinder() = default;

   void setRadius(const double&);
   double getRadius() const;

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
   double radius;
   double height;
   string type_of_shape;
};

#endif