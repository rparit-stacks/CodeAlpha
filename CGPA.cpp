#include <bits/stdc++.h>

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int user_input;

float percentag(vector<int> &subject_number) {
    // Calculate percentage
    float sum = 0.0;
    for (int i = 0; i < user_input; i++) {
        sum += subject_number[i];
    }

    return (sum / (user_input * 100)) * 100;
}
float grading(vector<int> &subject_number) {
    vector<vector<int> > numWithGrade(user_input, vector<int>(2, 0));
    for (int i = 0; i < user_input; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0)
                numWithGrade[i][j] = subject_number[i];
            else {
                if (subject_number[i] >= 41)
                    numWithGrade[i][j] = 5;
                if (subject_number[i] >= 51)
                    numWithGrade[i][j] = 6;
                if (subject_number[i] >= 51)
                    numWithGrade[i][j] = 6;
                if (subject_number[i] >= 61)
                    numWithGrade[i][j] = 7;
                if (subject_number[i] >= 71)
                    numWithGrade[i][j] = 8;
                if (subject_number[i] >= 81)
                    numWithGrade[i][j] = 9;
                if (subject_number[i] >= 91)
                    numWithGrade[i][j] = 10;
                if (subject_number[i] < 31)
                    numWithGrade[i][j] = 4;
            }
        }
    }

    cout << endl;
    for (int i = 0; i <= user_input; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == 0) {
                if (j == 0)
                    cout << "  |  " << "Number" << "  |  ";
                else if (j == 1)
                    cout << "  |  " << " Grade " << "  |  ";
            } else {
                cout << "   |   " << numWithGrade[i - 1][j] << "   |   ";
            }
        }
        cout << endl;
    }
    cout << endl;
    float grade_sum = 0.0;
    for (int i = 0; i < user_input; i++) {
        grade_sum += numWithGrade[i][1];
    }

    return grade_sum;
}

void CGPA(vector<int> &subject_number) {
    // Calculate percentage
    float sum = 0.0;
    for (int i = 0; i < user_input; i++) {
        sum += subject_number[i];
    }

    cout << endl;
    cout << "Congratulations! Your CGPA is: " << percentag(subject_number) / 9.5
         << "%" << endl;
}

void getchoice(vector<int> &subject_number) {
    int user_choice;
    cout << "1. CGPA " << endl
         << "2. Percentage" << endl
         << "3. CGPA to Percentage" << endl
         << "4. SGPA" << endl
         << "Please choose one of them : ";
    cin >> user_choice;

    if (user_choice == 1)
        CGPA(subject_number);
    else if (user_choice == 2)
        cout << "Congratulations! Your Percentage is: "
             << percentag(subject_number) << endl;
    else if (user_choice == 3) {
        float cgpa = 0.0;
        cout << "Please Enter your CGPA (for calculating cgpa enter 0) : ";
        cin >> cgpa;
        if (cgpa == 0)
            CGPA(subject_number);
        else
            cout << "Congratulations! Your CGPA is: " << cgpa * 9.5 << "%"
                 << endl;
    } else if (user_choice == 4) {
        cout << endl;
        cout << "Congratulations! Your SGPA is: "
             << grading(subject_number) / (float)user_input << endl;
        (int)user_input;
    }
    cout << endl;

    getchoice(subject_number);
}

int main() {
    cout << endl;
    cout << "Please enter number of subjects: ";
    cin >> user_input;
    vector<int> subject_number(user_input);
    vector<string> subject_name(user_input);

    // Input marks and subject names
    for (int i = 0; i < user_input; i++) {
        cout << "Please enter name of your subject: ";
        cin >> subject_name[i];
        cout << "Please enter marks of " << subject_name[i] << ": ";
        cin >> subject_number[i];
        cout << endl;
    }
    cout << endl;
    // Display marks and subject names
    for (int i = 0; i < user_input; i++) {
        cout << subject_name[i] << " = " << subject_number[i];
        cout << endl;
    }
    cout << endl;

    getchoice(subject_number);
}