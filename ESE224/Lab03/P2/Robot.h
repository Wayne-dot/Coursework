
#ifndef ROBOT_H
#define ROBOT_H

class Robot{
    private:
        float energy;
        float power;
        float speed;
    public:
        Robot();
        void applyEvent(const char*eventType, float effect);
        bool checkEvolution() const;
        void displayStats() const;
};

#endif