

class Box {
    private:
        double length;
        double width;
        double height;
    public:
        Box(double len, double wid, double he);
        Box operator+(const Box& other) const;
        Box operator-(const Box& other) const;
        void display();
};