
class Weather{
    private:
        int rainfall[7];
        int daysToHigherRain[7];
    public:
        Weather();
        void inputRainFall();
        void calculateDaysToHigherRain();
        void displayRainfall();
        void displayDaysToHigherRain();
};