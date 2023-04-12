#pragma once
#include<iostream>
#include<string>
#include <fstream>
using namespace std;


const int maxStudents = 100;
const int maxSubjects = 10;
const int maxGrades = 5;

class Student {
public:
    string name;
    int grades[maxSubjects][maxGrades];
};

class Subject {
public:
    string name;
};

class Group {
public:
    string name;
    Student students[maxStudents];
    Subject subjects[maxSubjects];
    int numStudents;
    int numSubjects;

    void readData(string studentsFile, string subjectsFile, string gradesFile);
    void printGradesTable();
    void printStudentsAverages();
    void printSubjectsAverages();
    void printGroupAverage();
    void printMinMaxGrades();
};
void Group::readData(string studentsFile, string subjectsFile, string gradesFile) {
    // Чтение с файла имена студентов
    ifstream studentsIn(studentsFile);
    numStudents = 0;
    while (getline(studentsIn, students[numStudents].name))
    {
        numStudents++;
    }
    studentsIn.close();

    // Чтение с файла названия предметов
    ifstream subjectsIn(subjectsFile);
    numSubjects = 0;
    while (getline(subjectsIn, subjects[numSubjects].name))
    {
        numSubjects++;
    }
    subjectsIn.close();

    // Чтение с файла оценок
    ifstream gradesIn(gradesFile);
    for (int i = 0; i < numStudents; i++)
    {
        for (int j = 0; j < numSubjects; j++)
        {
            for (int k = 0; k < maxGrades; k++)
            {
                gradesIn >> students[i].grades[j][k];
            }
        }
    }
    gradesIn.close();
}

void Group::printGradesTable()
{
    cout << "******Таблица успеваимости*******" << endl << endl;
    cout << "                 Предметы\n";
    cout << "Имя    ";
    //Выводит название предметов
    for (int j = 0; j < numSubjects; j++)
    {
        cout << subjects[j].name << "      \t";
    }
    cout << endl;
    // Выводит оценки для каждого студента
    for (int i = 0; i < numStudents; i++)
    {
        cout << students[i].name << "\t";
        for (int j = 0; j < numSubjects; j++)
        {
            for (int k = 0; k < maxGrades; k++)
            {
                if (students[i].grades[j][k] != 0)
                {
                    cout << students[i].grades[j][k] << " ";
                }
            }
            cout << "\t";
        }
        cout << "\n";
    }
}

void Group::printStudentsAverages()
{
    cout << "Средние оценки у студентов:" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        int sum = 0;
        int count = 0;
        for (int j = 0; j < numSubjects; j++)
        {
            for (int k = 0; k < maxGrades; k++)
            {
                if (students[i].grades[j][k] != 0)
                {
                    sum += students[i].grades[j][k];
                    count++;
                }
            }
        }
        if (count > 0)
        {
            cout << students[i].name << ": " << (double)sum / count << endl;
        }
    }
}
void Group::printSubjectsAverages()
{
    cout << "Средние оценки по предметам:\n";
    for (int i = 0; i < numSubjects; i++)
    {
        double subjectAvg = 0.0;
        for (int j = 0; j < numStudents; j++)
        {
            double studentAvg = 0.0;
            for (int k = 0; k < maxGrades; k++)
            {
                studentAvg += students[j].grades[i][k];
            }
            studentAvg /= maxGrades;
            subjectAvg += studentAvg;
        }
        subjectAvg /= numStudents;
        cout << subjects[i].name << ": " << subjectAvg << endl;
    }
    cout << endl;
}

void Group::printGroupAverage()
{
    cout << "Средний балл по предметам: ";
    double groupAvg = 0.0;
    int count = 0;
    for (int i = 0; i < numStudents; i++)
    {
        double studentAvg = 0.0;
        for (int j = 0; j < numSubjects; j++)
        {
            for (int k = 0; k < maxGrades; k++)
            {
                studentAvg += students[i].grades[j][k];
                count++;
            }
        }
        studentAvg /= (numSubjects * maxGrades);
        groupAvg += studentAvg;
    }
    groupAvg /= numStudents;
    cout << groupAvg << endl << endl;
}

void Group::printMinMaxGrades()
{
    for (int i = 0; i < numSubjects; i++)
    {
        int maxGrade = 0, minGrade = 10;
        string maxStudent, minStudent;
        for (int j = 0; j < numStudents; j++)
        {
            for (int k = 0; k < maxGrades; k++)
            {
                if (students[j].grades[i][k] > maxGrade)
                {
                    maxGrade = students[j].grades[i][k];
                    maxStudent = students[j].name;
                }
                if (students[j].grades[i][k] < minGrade)
                {
                    minGrade = students[j].grades[i][k];
                    minStudent = students[j].name;
                }
            }
        }
        cout << "Subject: " << subjects[i].name << endl;
        cout << "Высший балл: " << maxGrade << " (студент: " << maxStudent << ")" << endl;
        cout << "Низший балл: " << minGrade << " (студент: " << minStudent << ")" << endl << endl;
    }
}