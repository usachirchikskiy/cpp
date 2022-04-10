#ifndef WRITE_READ_H
#define WRITE_READ_H
#include "structures.h"
#include "utils.h"
#include <vector>
#include <fstream>

<<<<<<< HEAD
void write(vector<Student> &students);
void write(Student &student);
vector<Student> read();
=======
// void write(vector<Student> &students);
// void write(Student &student);
// vector<Student> read();
void writeData(vector<dataPerCourse> &data);
void write(string result);
vector<dataPerCourse> readUpdated(vector<dataPerCourse> &data);
vector<dataPerCourse> readCSV();
>>>>>>> lab3

#endif