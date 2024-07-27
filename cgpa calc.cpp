#include <iostream>
using namespace std;

struct Subject 
{
    string name;
    int credits;
    float gradePoint;
};

float calculateCGPA(Subject* subjects, int numSubjects) 
{
    int totalCredits = 0;
    float totalPoints = 0.0;

    for (int i = 0; i < numSubjects; ++i) 
    {
        totalCredits += subjects[i].credits;
        totalPoints += subjects[i].credits * subjects[i].gradePoint;
    }

    if (totalCredits == 0) return 0.0;
    return totalPoints / totalCredits;
}

int main() 
{
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    Subject* subjects = new Subject[numSubjects];
    for (int i = 0; i < numSubjects; ++i) {
        cout << "Enter details for subject " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> subjects[i].name;
        cout << "Credits: ";
        cin >> subjects[i].credits;
        cout << "Grade Point: ";
        cin >> subjects[i].gradePoint;
    }

    float cgpa = calculateCGPA(subjects, numSubjects);
    cout << "Your CGPA is: " << cgpa << endl;

    delete[] subjects;

    return 0;
}