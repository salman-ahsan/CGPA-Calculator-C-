#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<cctype>
using namespace std;

double gpa_calculator(float marks[], int num_subjects, float max_gpa, float total_marks) {
    float semester_gpa = 0.0;
    for (int i = 0; i < num_subjects; i++)
        semester_gpa = semester_gpa + ((marks[i] / total_marks) * max_gpa);
    return semester_gpa / num_subjects;
}

string calculate_grade(float gpa) {
    string grade;
    if (gpa <= 4.0 && gpa >= 3.67)
        return "A";
    else if (gpa < 3.67 && gpa >= 3.3)
        return "A-";
    else if (gpa < 3.3 && gpa >= 3.0)
        return "B+";
    else if (gpa < 3.0 && gpa >= 2.67)
        return "B";
    else if (gpa < 2.7 && gpa >= 2.3)
        return "B-";
    else if (gpa < 2.3 && gpa >= 2.0)
        return "C+";
    else if (gpa < 2.0 && gpa >= 1.67)
        return "C";
    else if (gpa < 1.67 && gpa >= 1.3)
        return "C-";
    else if (gpa < 1.3 && gpa >= 1.0)
        return "D+";
    else 
        return "Ungraded.";
}

int main() {
    cout << "                              ---------------";
    cout << endl << "                             |CGPA Calculator|";
    cout << endl << "                              ---------------";
    cout << endl << endl << "Press any key to continue...";
    getch();
    system("cls");

    string choice;
    do {
        const int max_semesters = 8;
        const float max_gpa = 4.0, total_marks = 100.0;
        float semester_gpa, total_gpa = 0.0, cgpa, result_semester_gpa[max_semesters];
        int num_semesters, num_subjects, current_semester = 1;
        string result_semester_grade[max_semesters];

        cout << endl << "Enter the Number of Semesters: ";
        cin >> num_semesters;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << endl << "\nInvalid Data!\nEnter valid number of semesters: ";
            cin >> num_semesters;
        }
        system("cls");
        while (num_semesters <= 0 || num_semesters > 8) {
            cout << endl << "Enter Valid Number of Semesters: ";
            cin >> num_semesters;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << endl << endl << "Invalid Data!\nEnter valid number of semesters: ";
                cin >> num_semesters;
            }
            system("cls");
        }

        for (int i = 0; i < num_semesters; i++) {
            cout << endl << "Enter the number of subjects in semester " << current_semester << ": ";
            cin >> num_subjects;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << endl << "Invalid Data!\nEnter Valid number of subjects: ";
                cin >> num_subjects;
            }
            system("cls");
            while (num_subjects <= 0 || num_subjects > 10) {
                cout << endl << "Enter Valid Number of subjects: ";
                cin >> num_subjects;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << endl << endl << "Invalid Data!\nEnter correct number of subjects: ";
                    cin >> num_subjects;
                }
                system("cls");
            }

            int count = 1;
            float marks[num_subjects];
            cout << endl << "Enter the marks obtained in subjects: " << endl;
            for (int j = 0; j < num_subjects; j++) {
                cout << "Subject " << count << " : ";
                cin >> marks[j];
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << endl << endl << "Invalid Data!\nEnter Correct marks: ";
                    cin >> marks[j];
                }
                while (marks[j] < 0 || marks[j] > 100) {
                    cout << endl << "Enter Valid marks: ";
                    cin >> marks[j];
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << endl << endl << "Invalid Data!\nEnter correct marks: ";
                        cin >> marks[j];
                    }
                }
                count++;
            }
            system("cls");
            semester_gpa = gpa_calculator(marks, num_subjects, max_gpa, total_marks);
            result_semester_gpa[i] = semester_gpa;
            total_gpa = total_gpa + semester_gpa;
            cout << endl << "Semester " << current_semester << " Gpa: " << semester_gpa;
            cout << endl << "Grade: " << calculate_grade(semester_gpa);
            result_semester_grade[i] = calculate_grade(semester_gpa);
            if (current_semester < num_semesters) {
                cout << endl << endl << "Press any key to continue to next semester calculation...";
                current_semester++;
            } else
                cout << endl << endl << "Press any key to proceed to CGPA Calculation...";
            getch();
            system("cls");
        }

        for (int i = 0; i < num_semesters; i++) {
            cout << endl << "Semester " << (i + 1) << " GPA: " << result_semester_gpa[i] << endl;
            cout << "Semester " << (i + 1) << " Grade: " << result_semester_grade[i] << endl;
        }

        cgpa = total_gpa / num_semesters;
        cout << endl << "Cumulative Grade Point Average: " << cgpa << endl;
        cout << "Grade: " << calculate_grade(cgpa);

        do {
            cout << endl << "Do you want to calculate CGPA for another student? (yes/no): ";
            cin >> choice;

            for (char &ch : choice) {
                ch = tolower(ch);
            }

            if (choice != "yes" && choice != "no") {
                cout << "Invalid input! Please enter 'yes' or 'no'." << endl;
            }
        } while (choice != "yes" && choice != "no");

        system("cls");
    } while (choice == "yes");

    cout << endl << "Thank you for using CGPA Calculator.";
    return 0;
}
