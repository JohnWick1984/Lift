#include<iostream>
#include<string>
#include <fstream>
#include"Group.h"

using namespace std;

int main() 
{
    setlocale(0, "");
    Group group;
    ifstream studentsFile("studentsFile.txt");
    ifstream subjectsFile("subjectsFile.txt");
    ifstream gradesFile("gradesFile.txt");
    studentsFile >> group.numStudents;
    for (int i = 0; i < group.numStudents; i++)
    {
        studentsFile >> group.students[i].name;
    }
    subjectsFile >> group.numSubjects;
    for (int i = 0; i < group.numSubjects; i++) 
    {
        subjectsFile >> group.subjects[i].name;
    }
    for (int i = 0; i < group.numStudents; i++)
    {
        for (int j = 0; j < group.numSubjects; j++) 
        {
            for (int k = 0; k < maxGrades; k++) 
            {
                gradesFile >> group.students[i].grades[j][k];
            }
        }
    }
    group.readData("studentsFile.txt", "subjectsFile.txt", "gradesFile.txt");
    group.printGradesTable();
    group.printStudentsAverages();
    group.printSubjectsAverages();
    group.printGroupAverage();
    group.printMinMaxGrades();
    return 0;
}