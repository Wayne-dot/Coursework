#include <string>

using namespace std;

class City{
    private:
        int id;
        char name[20];
        float rainfall[20];
    public:
        City();
        void setData(int new_id, string new_name, float new_data[20]);
        float getAverageRainfall() const;
        float getMinRainfall() const;
        float getMaxRainfall() const;
        void displayCityStats() const;
};