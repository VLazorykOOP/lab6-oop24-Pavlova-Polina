#include "Lab6Example.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cmath>
using namespace std; //  гоглг
namespace SpaceExample2 {
    // Abstract Class
// Створити абстрактний базовий клас домашня тварина із віртуальною функцією говорить. 
// Створити похідні класи: кішка, собака, корова, качка та курка. 
    using namespace std;


    class Figure {
    public:
        virtual double area() const = 0;
        virtual ~Figure() {}
    };

    class Rectangle : public Figure {
    private:
        double width, height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}
        double area() const override {
            return width * height;
        }
    };

    class Circle : public Figure {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
        double area() const override {
            return 3.14 * radius * radius;
        }
    };

    class RightTriangle : public Figure {
    private:
        double base, height;
    public:
        RightTriangle(double b, double h) : base(b), height(h) {}
        double area() const override {
            return 0.5 * base * height;
        }
    };

    class Trapezoid : public Figure {
    private:
        double base1, base2, height;
    public:
        Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}
        double area() const override {
            return 0.5 * (base1 + base2) * height;
        }
    };

    int mainExample2() {
        Figure* figures[4];

        figures[0] = new Rectangle(5.0, 3.0);
        figures[1] = new Circle(2.0);
        figures[2] = new RightTriangle(4.0, 2.5);
        figures[3] = new Trapezoid(3.0, 4.0, 2.0);

        for (int i = 0; i < 4; ++i) {
            std::cout << "Area #" << i + 1 << " = " << figures[i]->area() << std::endl;
        }

        for (int i = 0; i < 4; ++i) {
            delete figures[i];
        }

        return 0;
    }
