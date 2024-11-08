// main.cpp
#include <iostream>
#include "Quiz.h"
using namespace std;

int main() {
    Quiz quiz("quiz_questions.txt");

    // Start the quiz
    quiz.start();

    // Display final score
    double finalScore = quiz.calculateScore();
    cout << "Your final score: " << finalScore << "%" << endl;

    return 0;
}
