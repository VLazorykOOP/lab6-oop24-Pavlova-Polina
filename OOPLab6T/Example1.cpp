#include "Lab6Example.h"
#include <iostream>
namespace SpaceExample1 {
    ///Задача. Створити дві ієрархії класів без віртуального та з віртуальним спадкуванням, 
    // з елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами. 
    // Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. 
    // Вивести розміри об’єктів даних класів.
    ///

        // 
        class Base {
        public:
            int baseData;

            Base(int bd) : baseData(bd) {}
            virtual ~Base() {}
    };

    class D1 : public Base {
    public:
        int d1Data;

        D1(int bd, int d1d) : Base(bd), d1Data(d1d) {}
    };

    class D2 : public Base {
    public:
        int d2Data;

        D2(int bd, int d2d) : Base(bd), d2Data(d2d) {}
    };

    class D3 : public D1, public D2 {
    public:
        int d3Data;

        D3(int bd1, int d1d, int bd2, int d2d, int d3d) : D1(bd1, d1d), D2(bd2, d2d), d3Data(d3d) {}
    };

    class D4 : public D2, public D3 {
    public:
        int d4Data;

        D4(int bd2, int d2d, int bd3, int d1d, int d3d, int d4d)
            : D2(bd2, d2d), D3(bd2, d1d, bd3, d2d, d3d), d4Data(d4d) {}
    };

    class D5 : public D2 {
    public:
        int d5Data;

        D5(int bd, int d2d, int d5d) : D2(bd, d2d), d5Data(d5d) {}
    };

    class D6 : public D5, public D1 {
    public:
        int d6Data;

        D6(int bd, int d1d, int d2d, int d5d, int d6d) : D5(bd, d2d, d5d), D1(bd, d1d), d6Data(d6d) {}
    };

    // 
    class BaseV {
    public:
        int baseData;

        BaseV(int bd) : baseData(bd) {}
        virtual ~BaseV() {}
    };

    class D1V : public virtual BaseV {
    public:
        int d1Data;

        D1V(int bd, int d1d) : BaseV(bd), d1Data(d1d) {}
    };

    class D2V : public virtual BaseV {
    public:
        int d2Data;

        D2V(int bd, int d2d) : BaseV(bd), d2Data(d2d) {}
    };

    class D3V : public D1V, public D2V {
    public:
        int d3Data;

        D3V(int bd, int d1d, int d2d, int d3d) : BaseV(bd), D1V(bd, d1d), D2V(bd, d2d), d3Data(d3d) {}
    };

    class D4V : public D2V, public D3V {
    public:
        int d4Data;

        D4V(int bd, int d2d, int d1d, int d3d, int d4d) : BaseV(bd), D2V(bd, d2d), D3V(bd, d1d, d2d, d3d), d4Data(d4d) {}
    };

    class D5V : public D2V {
    public:
        int d5Data;

        D5V(int bd, int d2d, int d5d) : BaseV(bd), D2V(bd, d2d), d5Data(d5d) {}
    };

    class D6V : public D5V, public D1V {
    public:
        int d6Data;

        D6V(int bd, int d1d, int d2d, int d5d, int d6d) : BaseV(bd), D5V(bd, d2d, d5d), D1V(bd, d1d), d6Data(d6d) {}
    };

    int mainExample1()
    {
        Base b(10);
        D1 d1(20, 30);
        D2 d2(40, 50);
        D3 d3(60, 70, 80, 90, 100);
        D4 d4(110, 120, 130, 140, 150, 160);
        D5 d5(170, 180, 190);
        D6 d6(200, 210, 220, 230, 240);

        std::cout << "Size of Base object: " << sizeof(b) << std::endl;
        std::cout << "Size of D1 object: " << sizeof(d1) << std::endl;
        std::cout << "Size of D2 object: " << sizeof(d2) << std::endl;
        std::cout << "Size of D3 object: " << sizeof(d3) << std::endl;
        std::cout << "Size of D4 object: " << sizeof(d4) << std::endl;
        std::cout << "Size of D5 object: " << sizeof(d5) << std::endl;
        std::cout << "Size of D6 object: " << sizeof(d6) << std::endl;

        BaseV bv(10);
        D1V d1v(20, 30);
        D2V d2v(40, 50);
        D3V d3v(60, 70, 80, 90);
        D4V d4v(100, 110, 120, 130, 140);
        D5V d5v(150, 160, 170);
        D6V d6v(180, 190, 200, 210, 220);

        std::cout << "Size of BaseV object: " << sizeof(bv) << std::endl;
        std::cout << "Size of D1V object: " << sizeof(d1v) << std::endl;
        std::cout << "Size of D2V object: " << sizeof(d2v) << std::endl;
        std::cout << "Size of D3V object: " << sizeof(d3v) << std::endl;
        std::cout << "Size of D4V object: " << sizeof(d4v) << std::endl;
        std::cout << "Size of D5V object: " << sizeof(d5v) << std::endl;
        std::cout << "Size of D6V object: " << sizeof(d6v) << std::endl;

        return 0;
    }

}