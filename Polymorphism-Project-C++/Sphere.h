#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Shape.h"

using namespace std;

class Sphere:public Shape {
public:
   Sphere();
   ~Sphere() = default;

   void setRadius(const double&);
   double getRadius() const;

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
   string type_of_shape;
};

#endif