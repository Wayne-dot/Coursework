// Quiz.cpp
#include "Quiz.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor to load questions from the file
Quiz::Quiz(const string& filename) : score(0) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    string line;
    while (getline(inputFile, line)) {
        Question q;
        q.text = line;                      // First line is the question text
        getline(inputFile, q.optionA);       // Next four lines are the options
        getline(inputFile, q.optionB);
        getline(inputFile, q.optionC);
        getline(inputFile, q.optionD);
        inputFile >> q.correctAnswer;        // Correct answer on the following line
        inputFile.ignore();                  // Skip newline after correct answer

        questions.push_back(q);              // Add question to the list
    }

    inputFile.close();
}

// Function to conduct the quiz
void Quiz::start() {
    for (const auto& q : questions) {
        cout << q.text << endl;
        cout << q.optionA << endl;
        cout << q.optionB << endl;
        cout << q.optionC << endl;
        cout << q.optionD << endl;

        // Prompt for user's answer
        char answer;
        cout << "Your answer: ";
        cin >> answer;
        answer = toupper(answer);  // Convert to uppercase for consistency

        // Check if answer is correct
        if (answer == q.correctAnswer) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. The correct answer was " << q.correctAnswer << "." << endl;
        }
        cout << endl;
    }
}

// Function to calculate the score percentage
double Quiz::calculateScore() const {
    return (static_cast<double>(score) / questions.size()) * 100;
}
