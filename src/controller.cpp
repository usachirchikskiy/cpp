#include "controller.h"
<<<<<<< HEAD
#include <iostream>
#include "write_read.h"

void controller::enroll(){
    int studentId;
    int courseId;
    int courseNumber;
    string sectionCode;
    int termId;
    string termName;
    char grade;

    cout<<"Enter the student's ID "<<endl;
    cin>>studentId;
    cout<<"Enter the course ID "<<endl;
    cin>>courseId;
    cout<<"Enter the course number "<<endl;
    cin>>courseNumber;
    cout<<"Enter the course section code "<<endl;
    cin>>sectionCode;
    cout<<"Enter the course term ID "<<endl;
    cin>>termId;
    cout<<"Enter the course term name "<<endl;
    cin>>termName;
    cout<<"Enter the student`s grade "<<endl;
    cin>>grade;

    Term term{termId,termName};
    Course course{courseId,courseNumber,sectionCode,term};
    Student student{studentId,course,grade};

    write(student); //IP 

}

void controller::update(){
    int studentId;
    char newGrade;
    cout<<"Enter the id of student to change the grade"<<endl;
    cin>>studentId;
    cout<<"Enter updated grade"<<endl;
    cin>>newGrade;

    vector<Student> students = read();
    vector<Student>::iterator it = students.begin();//указатель на элемент вектора
    for(it; it!=students.end(); it++){
        if(studentId==it->id){
            it->grade=newGrade;
        }
    }
    
    cout<<"Update "<<students[0].grade<<endl;

    write(students);
    
=======

Controller::Controller(vector<dataPerCourse> &data)
{
    this->data = data;
}

void Controller::searchStudent(string emplId)
{
    if (checkStudent(emplId, data))
    {
        dataPerCourse student;
        printf("The student's Id is %s\n", emplId.c_str());
        write("The student's Id is " + emplId + "\n");
        char *enumStrings[] = {"A", "A+", "A-", "AUD", "B", "B+", "B-", "C", "C+", "C-", "CR", "D", "D+", "D-", "F", "FIN", "INC", "NC", "P", "W", "WD", "WN", "WU"};

        for (int i = 0; i < data.size(); i++)
        {
            if (emplId == data[i].emplid)
            {
                student = data[i];

                printf("Course - %d; Instructor Id - %s; Term - %s; Section Id - %s; Grade - %s\n",
                       student.courseno, student.instructorid.c_str(),
                       student.termid.c_str(), student.sectionid.c_str(), enumStrings[student.grade]);
                string result = "Course - " + IntToString(student.courseno) + "; Instructor Id - " + student.instructorid + "; Term - " + student.termid + "; Section Id - " + student.sectionid + "; Grade - " + enumStrings[student.grade] + "\n";
                write(result);
            }
        }
    }
    else
    {
        printf("No such student");
        write("No such student");
    }
}

/*
A user-defined class with methods for enrollment operations
A constructor for define a new enrollment (i.e. it creates a student object with a new course). The enrollment should not be publicly accessible
Method(s) for updating objects (i.e. update grades for the student object(s))

*/
void Controller::enroll()
{

    string emplId;
    int courseno;
    string instructorId;
    string termId;
    string sectionId;
    string grade;

    cout << "Enter the student's ID " << endl;
    cin >> emplId;

    if (checkStudent(emplId, data) == false)
    {
        cout << "Enter the course number " << endl;
        cin >> courseno;
        cout << "Enter the instructor ID " << endl;
        cin >> instructorId;
        cout << "Enter the course term ID " << endl;
        cin >> termId;
        cout << "Enter the course section ID " << endl;
        cin >> sectionId;
        cout << "Enter the student`s grade " << endl;
        cin >> grade;
        Grades enumGrade = getEnumIndex(grade);
        dataPerCourse enrollData{emplId, courseno, instructorId, termId, sectionId, enumGrade};
        data.push_back(enrollData);
        writeData(data);
    }
    else{
        cout<<"Student already exists"<<endl;
    }
}

void Controller::update()
{
    vector<dataPerCourse> data = readUpdated(Controller::data);

    string emplId;
    cout<<"Enter student's ID to update the grade"<<endl;
    cin>>emplId;
    cout<<"Enter updated grade"<<endl;
    string newGrade;
    cin>>newGrade;
    Grades grade = getEnumIndex(newGrade);

    vector<dataPerCourse>::iterator it = data.begin();//указатель на элемент вектора
    for(it; it!=data.end(); it++){
        if(emplId==it->emplid){
            it->grade=grade;
        }
    }

    writeData(data);
>>>>>>> lab3
}