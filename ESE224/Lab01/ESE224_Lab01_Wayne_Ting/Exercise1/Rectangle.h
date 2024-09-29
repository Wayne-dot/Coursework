
#ifndef REACTANGLE_H
#define REACTANGLE_H

class Rectangle{
    private:
        double length;
        double width;
    public:
        Rectangle();
        Rectangle(double len, double wid);

        double getLength() const;
        double getWidth() const;

        void setLength(double len);
        void setWidth(double wid);

        double area() const;
        double perimeter() const;

};


#endif