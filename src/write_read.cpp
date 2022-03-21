#include "write_read.h"
#include <iostream>

void write(vector<Student> &students)
{
    ofstream out("output.txt");

    if (out.is_open())
    {
        for (int i = 0; i < students.size(); i++)
        {
            out << students[i].id << " " << students[i].course.id << " " << students[i].course.courseNumber << " " << students[i].course.sectionCode
                << " " << students[i].course.term.id
                << " " << students[i].course.term.name << " " << students[i].grade;
        }

        out.close();
    }
}

void write(Student &student)
{
    ofstream out("output.txt", ios::app);

    if (out.is_open())
    {
        out << student.id << " " << student.course.id << " " << student.course.courseNumber << " " << student.course.sectionCode
            << " " << student.course.term.id
            << " " << student.course.term.name << " " << student.grade;
    }
    out.close();
}

vector<Student> read()
{
    vector<Student> students;
    ifstream in;
    in.open("output.txt");
    if (!in.fail())
    {
        string line;
        // bool skipFirstLine = true;
        while (getline(in, line))
        {
            // if (skipFirstLine)
            // {
            //     skipFirstLine = false;
            //     continue;
            // }
            vector<string> lineSplit = split(line, ' ');
            int studentId;
            stringToSomething<string, int>(lineSplit.at(0), studentId);

            int courseId;
            stringToSomething<string, int>(lineSplit.at(1), courseId);

            int courseNumber;
            stringToSomething<string, int>(lineSplit.at(2), courseNumber);

            string sectionCode = lineSplit.at(3);

            int termId;
            stringToSomething<string, int>(lineSplit.at(4), termId);

            string termName = lineSplit.at(5);

            char grade;
            stringToSomething<string, char>(lineSplit.at(6), grade);

            Term term{termId, termName};
            Course course{courseId, courseNumber, sectionCode, term};
            Student student{studentId, course, grade};

            students.push_back(student);
        }
    }
    in.close();
    return students;
}