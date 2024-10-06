
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int wins;
    public:
        Player();
        Player(string n_ame);
        int makeChoice();
        void incrementWins();
        int getWins();
        string getName();
};