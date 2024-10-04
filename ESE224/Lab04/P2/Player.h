
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int wins;
    public:
        Player();
        void makeChoice();
        void incrementWins();
        int getWins();
        string getName();
};