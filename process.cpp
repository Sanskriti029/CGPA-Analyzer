#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main() {
    unordered_map<string, double> gradePoints = {
        {"S", 10}, {"A", 9}, {"B", 8}, {"C", 7}, {"C", 5}, {"D", 4}, {"F", 0}
    };

    ifstream file("input.txt");
    if (!file) {
        cout << "Error: Could not open input.txt";
        return 1;
    }

    string grade;
    int credit;
    double totalPoints = 0, totalCredits = 0;

    while (file >> grade >> credit) {
        if (gradePoints.find(grade) != gradePoints.end()) {
            totalPoints += gradePoints[grade] * credit;
            totalCredits += credit;
        } else {
            cout << "Invalid grade detected: " << grade << endl;
            return 1;
        }
    }

    if (totalCredits == 0) {
        cout << "Error: Total credits cannot be zero.";
    } 
    else {
        double cgpa = totalPoints / totalCredits;
        cout << fixed << setprecision(2) << cgpa;
    }

    return 0;
}
