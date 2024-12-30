#include <iostream>
#include <vector>
#include <chrono>
#include "graph.hpp"
#include "hash.hpp"
using namespace std;

int main() {
    const int initialTableSize = 1000;
    HashTable subjectToStudents(initialTableSize);
    HashTable studentToSubjects(initialTableSize);

    int numSubjectsInput;
    cin >> numSubjectsInput;
    vector<string> subjects(numSubjectsInput);


    for (int i = 0; i < numSubjectsInput; i++) {
        cin >> subjects[i];
        int numStudents;
        cin >> numStudents;

        for (int j = 0; j < numStudents; j++) {
            int studentID;
            cin >> studentID;
            subjectToStudents.insert(subjects[i], studentID);          
        }
    }

   
    graph* G1 = new edgeListGraph(numSubjectsInput);
    graph* G2 = new adjListGraph(numSubjectsInput);
    graph* G3 = new adjMatrixGraph(numSubjectsInput);

   
    for (int i = 0; i < numSubjectsInput; i++) {
        for (int j = i + 1; j < numSubjectsInput; j++) {
            const string& subjectI = subjects[i];
            const string& subjectJ = subjects[j];

            vector<int>* studentsI = subjectToStudents.get(subjectI);
            vector<int>* studentsJ = subjectToStudents.get(subjectJ);

            bool conflict = false;
            if (studentsI && studentsJ) {
                hashTable studentTable(studentsI->size());
                for (int studentI : *studentsI) {
                    studentTable.insert(studentI);
                }
                for (int studentJ : *studentsJ) {
                    if (studentTable.exists(studentJ)) {
                        conflict = true;
                        break;
                    }
                }
            }

            if (conflict) {
                G1->addEdge(i, j);
                G2->addEdge(i, j);
                G3->addEdge(i, j);
            }
        }
    }

   

    cout << "/**************************** BACK TRACKING SCHEDULING ****************************" << endl;
    cout << "*********************************** EDGELIST ************************************* " << endl;
    auto start = chrono::high_resolution_clock::now();
    G1->backTrackScheduling(numSubjectsInput, subjects);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Time taken by EDGELIST backTrackScheduling: " << elapsed.count() << " seconds" << endl;
    cout << "/*********************************************************/" << endl;

    cout << "************************************ ADJLIST *************************************** " << endl;
    start = chrono::high_resolution_clock::now();
    G2->backTrackScheduling(numSubjectsInput, subjects);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by ADJLIST backTrackScheduling: " << elapsed.count() << " seconds" << endl;
    cout << "/*********************************************************/" << endl;

   
    cout << "************************************ ADJMATRIX *************************************** " << endl;
    start = chrono::high_resolution_clock::now();
    G3->backTrackScheduling(numSubjectsInput, subjects);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Time taken by ADJMATRIX backTrackScheduling: " << elapsed.count() << " seconds" << endl;
    cout << "/*********************************************************/" << endl;



   return 0;
}
