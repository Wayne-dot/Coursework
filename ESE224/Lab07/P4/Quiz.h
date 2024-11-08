// Quiz.h
#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
using namespace std;

struct Question {
    string text;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctAnswer;
};

class Quiz {
private:
    vector<Question> questions; // List of questions
    int score;                  // Player's score

public:
    // Constructor to load questions from file
    Quiz(const string& filename);

    // Function to conduct the quiz
    void start();

    // Function to calculate the score percentage
    double calculateScore() const;
};

#endif // QUIZ_H
