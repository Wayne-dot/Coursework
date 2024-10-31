

#include <vector>
using namespace std;

class Matrix{
    private:
        vector<vector<int> > matrix;
        int row;
        int column;
    public:
        Matrix();
        void readFromFile(const string& filename);
        vector<int> getSpiralOrder() const;
        void writeSpiralOrderToFile(const string& filename) const;
        
};