#include "controller.h"
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
    
}