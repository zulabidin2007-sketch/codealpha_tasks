#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int numCourses;
    
    cout << "--- CGPA Calculator ---" << endl;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    
    vector<double> grades(numCourses);
    vector<int> credits(numCourses);
    
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << ":" << endl;
        cout << "Enter credit hours: ";
        cin >> credits[i];
        
        cout << "Enter grade point (e.g., 4.0, 3.5, 2.7): ";
        cin >> grades[i];

        totalGradePoints += (grades[i] * credits[i]);
        totalCredits += credits[i];
    }

    cout << "\n-----------------------------------\n";
    cout << "Course\tCredits\tGrade Point\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << i + 1 << "\t" << credits[i] << "\t" << fixed << setprecision(1) << grades[i] << "\n";
    }
    cout << "-----------------------------------\n";

    if (totalCredits > 0) {
        double cgpa = totalGradePoints / totalCredits;
        cout << fixed << setprecision(2);
        cout << "\nTotal Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << totalGradePoints << endl;
        cout << "Final CGPA: " << cgpa << endl;
    } else {
        cout << "\nNo credits entered. Cannot calculate CGPA." << endl;
    }

    return 0;
}