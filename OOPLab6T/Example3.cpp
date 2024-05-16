#include "Lab6Example.h"
#include <iostream>
#include <string>
using namespace std;
namespace SpaceExample3 {
    // MultipleiInherance.cpp 
// Ієрархія типів складається з сутностей: 
// машина, пасажирський транспорт і автобус.
//

    class Student {
    protected:
        std::string name;
        int student_id;
        std::string major;
    public:
        Student(const std::string& name, int student_id, const std::string& major)
            : name(name), student_id(student_id), major(major) {}

        virtual ~Student() {}

        virtual void display() const {
            std::cout << "Name: " << name << "\nStudent ID: " << student_id << "\nMajor: " << major << std::endl;
        }

        friend std::istream& operator>>(std::istream& is, Student& student) {
            is >> student.name >> student.student_id >> student.major;
            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, const Student& student) {
            os << "Name: " << student.name << "\nStudent ID: " << student.student_id << "\nMajor: " << student.major;
            return os;
        }
    };

    class Father {
    protected:
        int num_children;
        std::string occupation;
    public:
        Father(int num_children, const std::string& occupation)
            : num_children(num_children), occupation(occupation) {}

        virtual ~Father() {}

        virtual void display() const {
            std::cout << "Number of Children: " << num_children << "\nOccupation: " << occupation << std::endl;
        }

        friend std::istream& operator>>(std::istream& is, Father& father) {
            is >> father.num_children >> father.occupation;
            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, const Father& father) {
            os << "Number of Children: " << father.num_children << "\nOccupation: " << father.occupation;
            return os;
        }
    };

    class StudentFather : public Student, public Father {
    public:
        StudentFather(const std::string& name, int student_id, const std::string& major,
            int num_children, const std::string& occupation)
            : Student(name, student_id, major), Father(num_children, occupation) {}

        ~StudentFather() override {}

        void display() const override {
            Student::display();
            Father::display();
        }

        friend std::istream& operator>>(std::istream& is, StudentFather& student_father) {
            is >> static_cast<Student&>(student_father);
            is >> static_cast<Father&>(student_father);
            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, const StudentFather& student_father) {
            os << static_cast<const Student&>(student_father) << std::endl;
            os << static_cast<const Father&>(student_father);
            return os;
        }
    };

    int mainExample3()
    {
        StudentFather sf("John Doe", 12345, "Computer Science", 2, "Engineer");

        std::cout << "StudentFather details:" << std::endl;
        sf.display();

        std::cout << "\n<< StudentFather details:" << std::endl;
        std::cout << sf << std::endl;

        std::cout << "Enter details for a new StudentFather (name, student_id, major, num_children, occupation): ";
        StudentFather new_sf("", 0, "", 0, "");
        std::cin >> new_sf;

        std::cout << "\nNew StudentFather details:" << std::endl;
        new_sf.display();

        return 0;
    }


}