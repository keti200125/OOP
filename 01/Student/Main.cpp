#include "Student.hpp"


int main()
{
    unsigned grades[] = {6, 6, 6, 5};
    size_t countGrades = sizeof(grades) / sizeof(unsigned);
    Student st1("Aleksandur", countGrades, grades, "Smile bright");
    std::cout<<"Name: "<<st1.getName()<<"\n";
    std::cout<<"Average grade: "<<st1.getAverageGrade()<<"\n";
    std::cout<<"Quote: "<<st1.getQuote();
}