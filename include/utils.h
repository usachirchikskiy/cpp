#ifndef UTILS_H
#define UTILS_H
<<<<<<< HEAD

using namespace std;
#include <vector>
#include <sstream>
=======
#include "structures.h"
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;
>>>>>>> lab3

//Common functions
vector<string> split(string s, char delim);

<<<<<<< HEAD

=======
int isPass(Grades grade);

map<Grades, int> dataGrade(int courseno,vector<dataPerCourse> &data);

string fallOrSpring(string termId);

Grades getEnumIndex( string grade);

void printData(vector<dataPerCourse> &data);

string IntToString(int number);

bool checkStudent(string id,vector<dataPerCourse> &data);

bool checkCourse(int id);

bool checkInstructor(string id,vector<dataPerCourse> &data);
>>>>>>> lab3
//Шаблонные функции всегда надо реализовывать в headers file
template <typename Text, typename TypeToConvert>
void stringToSomething(Text stringText, TypeToConvert &typeConvert)
{
    stringstream syear(stringText);
    syear >> typeConvert;
}

#endif