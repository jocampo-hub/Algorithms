#ifndef COURSEGRADEBOOK_H
#define COURSEGRADEBOOK_H

#include <algorithm>
#include <unordered_map>
#include <vector>
#include "Gradebook.h"
using namespace std;

class CourseGradebook : public Gradebook {
protected:

    unordered_map<string, unordered_map<int, double>> myGradeBook;


public:
    virtual ~CourseGradebook() {}

    unordered_map<int, double> GetAssignmentScores(string assignmentName) override {
        return myGradeBook[assignmentName];
    }

    double GetScore(string assignmentName, int studentID) override {
        if (myGradeBook.count(assignmentName) == 0 ||
            myGradeBook[assignmentName].count(studentID) == 0) {
            return NAN;
        }
        return myGradeBook[assignmentName][studentID];
    }

    vector<string> GetSortedAssignmentNames() override {
        vector<string> myAssignmentNames;
        for (const auto& entry : myGradeBook) {
           myAssignmentNames.push_back(entry.first);
        }
        sort(myAssignmentNames.begin(), myAssignmentNames.end());
        return myAssignmentNames;
    }

    vector<int> GetSortedStudentIDs() override {
        std::unordered_map<int, bool> studentIDMap;
        for (const auto& item : myGradeBook) {
            for (const auto& item : item.second) {
                studentIDMap[item.first] = true;
            }
        }
        std::vector<int> studentIDs;
        for (const auto& item : studentIDMap) {
            studentIDs.push_back(item.first);
        }
        std::sort(studentIDs.begin(), studentIDs.end());
        return studentIDs;
    }

    unordered_map<string, double> GetStudentScores(int studentID) override {
        unordered_map<string, double> studentScores;
        for (auto &item : myGradeBook) {
            if (item.second.count(studentID) != 0) {
                studentScores[item.first] = item.second[studentID];
            }
        }
        return studentScores;
    }

    void SetScore(string assignmentName, int studentID, double score) override {
        myGradeBook[assignmentName][studentID] = score;
    }
};


#endif
