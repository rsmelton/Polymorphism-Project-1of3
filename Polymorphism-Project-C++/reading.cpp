#include "reading.h"
#include <fstream>
#include <sstream>
#include "Box.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Torus.h"

using namespace std;

vector<Shape*> *readFrom(string file_name) {
    // Open file for reading and if the file can't be opened for reading
    // return a pointer to an empty vector.
    ifstream shapes_file;
    shapes_file.open(file_name);

    // Create pointer to a vector of shape pointers
    vector<Shape*>* pointer = new vector<Shape*>;

    if (shapes_file.is_open() == false) { 
        printf("File could not be opened.\n");
        return pointer;
    }

    // Start reading from file and populating vector of shape pointers
    string information;
    while (getline(shapes_file, information)) {
        stringstream ss(information);
        string word;
        int i = 0;
        string nameOfShape;

        while (ss.eof() == false) {
            // Create new shape pointer here.
            Shape* myShape;
            getline(ss, word, ' ');
            if (i == 0) { // The first iteration the word will always be the name of the shape
                nameOfShape = word;
                i++;
            }
            else if (i == 1) { // The second iteration will always be the shape itself
                // Has to be one of four shapes: box, torus, cylinder, or sphere
                // The last items will be the info needed about the shape
                if (word == "box") {
                    Box* myBox = new Box();
                    myBox->setName(nameOfShape);
                    getline(ss, word, ' ');
                    myBox->setLength(stod(word));
                    getline(ss, word, ' ');
                    myBox->setWidth(stod(word));
                    getline(ss, word, ' ');
                    myBox->setHeight(stod(word));
                    // Set shape pointer to have all the fields of our new box.
                    myShape = myBox;
                }
                else if (word == "torus") {
                    Torus* myTorus = new Torus();
                    myTorus->setName(nameOfShape);
                    getline(ss, word, ' ');
                    myTorus->setSmallRadius(stod(word));
                    getline(ss, word, ' ');
                    myTorus->setBigRadius(stod(word));
                    myShape = myTorus;
                }
                else if (word == "cylinder") {
                    Cylinder* myCylinder = new Cylinder();
                    myCylinder->setName(nameOfShape);
                    getline(ss, word, ' ');
                    myCylinder->setRadius(stod(word));
                    getline(ss, word, ' ');
                    myCylinder->setHeight(stod(word));
                    myShape = myCylinder;
                }
                else if (word == "sphere") {
                    Sphere* mySphere = new Sphere();
                    mySphere->setName(nameOfShape);
                    getline(ss, word, ' ');
                    mySphere->setRadius(stod(word));
                    myShape = mySphere;
                }
                i = 0;
                // store info found into vector of shape pointers here:
                pointer->push_back(myShape);
            }
        }
    }
    return pointer;
}