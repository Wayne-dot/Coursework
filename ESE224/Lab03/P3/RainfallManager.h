
#include "City.h"

class RainfallManager{
    private:
        City cities[10];
        int num_of_cities;
    public:
        RainfallManager();
        void loadDataFromFile(const char* filename);
        City getCityWithMaxRainfall() const;
        City getCityWithMinRainfall() const;
        void displayAllStats() const;
};