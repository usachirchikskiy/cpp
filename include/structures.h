#ifndef STRUCTURES_H
#define STRUCTURES_H
using namespace std;
#include <string>

struct Term
{
    int id;
    string name;
};

struct Course
{
    int id;
    int courseNumber;
    string sectionCode;
    Term term;
};

struct Student
{
    int id;
    Course course;
    char grade;
};


struct Instructor
{
    int id;
    Course course;
    Term term;
};
#endif