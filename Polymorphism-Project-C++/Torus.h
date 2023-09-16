#ifndef _TORUS_H_
#define _TORUS_H_

#include "Shape.h"

using namespace std;

class Torus:public Shape {
public:
   Torus();
   ~Torus() = default;

   void setSmallRadius(const double&);
   double getSmallRadius() const;

   void setBigRadius(const double&);
   double getBigRadius() const;

   double getArea() const;          
   double getVolume() const;       

   bool comparisonOfTypes(string, string) const;
   bool comparisonOfValues(string, double, double) const;  
   bool test(const vector<string>& cond) const;
   
   string formatInfoAsString(double) const;
   string getInfo() const;

private:
   string name;
   double small_radius;
   double big_radius;
   string type_of_shape;
};

#endif