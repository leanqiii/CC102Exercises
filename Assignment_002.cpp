#include <iostream>

using namespace std;

int analyzeGrades(int *grades, int students, int subjects) {
    int highest = *(grades);
    
    cout<< "\nGrade Matrix:\n";
    for (int i = 0; i < students; i++) {
        float sum = 0;
        
        for (int j = 0; j < subjects; j++) {
            int value = *(grades + i * subjects + j);
            cout<< value << "\t";
            
            sum += value;
            
            if (value > highest) {
                highest = value;
            }
        }
        
        cout << "| Average: " << sum / subjects << endl;
    }
    
    return highest;
    
}

int main() {
    int students, subjects;
    
    cout<< "Enter number of students: ";
    cin>> students;
    cout<< "Enter number of subjects: ";
    cin>> subjects;
    
    int grades[students][subjects];
    
    cout<< "\nEnter the grades:\n"; 
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout<< "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin>> grades[i][j];
        }
    }
    
    int hg = analyzeGrades(&grades[0][0], students, subjects);
    
    cout<< "\nHighest Grade in the Matrix: " << hg << endl;
      
   return 0; 
}