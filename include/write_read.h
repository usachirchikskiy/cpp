#ifndef WRITE_READ_H
#define WRITE_READ_H
#include "structures.h"
#include "utils.h"
#include <vector>
#include <fstream>

// void write(vector<Student> &students);
// void write(Student &student);
// vector<Student> read();
void writeData(vector<dataPerCourse> &data);
void write(string result);
vector<dataPerCourse> readUpdated(vector<dataPerCourse> &data);
vector<dataPerCourse> readCSV();

#endif