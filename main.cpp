#include <iostream>
#include <cstdio>
#include <array>
#include <map>
#include <random>
#include <bits/stdc++.h>    

using namespace std;

class Question {
    private:
        std::string question;
        std::array<std::string, 4> answers;
        std::string correct;

    public:
        Question(std::string question, std::array<std::string, 4> answers, std::string correct)
            : question(question), answers(answers), correct(correct) {}

        std::string getQuestion() const {
            return this->question;
        };

        std::array<std::string, 4> getAnswers() const {
            return this->answers;
        }

        std::string getCorrect() const {
            return this->correct;
        }
};

static const std::array<Question, 3> questions = {
    Question("What's the sun's color", {"White", "Red", "Yellow", "Green"}, "White"),
    Question("What do cow's drink", {"Milk", "Nothing", "Juice", "Water"}, "Water"),
    Question("What is the capital of Canada", {"Vancouver", "Ottawa", "Toronto", "Montreal"}, "Toronto")
}; //You can add more questions, copy and paste, add "," before last question constructor

static const std::array<char, 7> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

char getCorrectAnswer(Question question, map<char, std::string> answers) {
    std::string correct = question.getCorrect();
    for (auto& i : answers) {
        if (correct == i.second) return i.first;
    }
    return '';
}

Question getRandomQuestion() {
    static std::random_device rd;
    static std::mt19937 gen(rd()); //i hate this

    std::uniform_int_distribution<> dist(0, questions.size() - 1);

    int index = dist(gen);
    return questions[index];
}

int main() {
    Question question = getRandomQuestion();

    cout << "Quiz Game!" << endl;
    cout << endl << "Question: " << question.getQuestion() << '?' << endl;

    map<char, std::string> answers; //create map and initialize it in the loop
    for (int i = 0; i < question.getAnswers().size(); i++) {
        char letter = letters[i];
        std::string answer = question.getAnswers()[i];
        cout << "    " << letter << ": " << answer << endl;
        answers[letter] = answer;
    }

    cout << endl << "What's the answer? ";
    std::string input;
    cin >> input;
    char answer = input[0];
    char correctAnswer = getCorrectAnswer(question, answers);
    
    if (answer == correctAnswer) {
        cout << "Correct!";
    } else {
        cout << "Wrong! Correct answer: " << correctAnswer;
    }

    return 0;
}