#ifndef CONTROLLER_H
#define CONTROLLER_H
<<<<<<< HEAD

class controller
{
private:
    void enroll();

public:
    controller()
    {
        enroll();
    }

    void update();
=======
#include "structures.h"
#include <vector>
#include <iostream>
#include "write_read.h"
#include "utils.h"

class Controller
{
private:
    vector<dataPerCourse> data;
    

public:
    Controller(vector<dataPerCourse> &data);
    void enroll();
    void update();
    void searchStudent(string emplId);
>>>>>>> lab3
};
#endif
