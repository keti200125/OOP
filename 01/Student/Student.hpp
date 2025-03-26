#ifndef STUDENT_HPP
#define STUDENT_HPP

#include<iostream>
#include <cstddef> 

class Student
{
private:
    char *mName;
    size_t mCountGrades;
    unsigned *mGrades;
    char *mQuote;
    double mAverageGrade;

    void free();
    void copy(const Student &other);

public:
    Student(const char *name, size_t countGrades, const unsigned *grades, const char *quite);
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    const char* getName() const;
    size_t getCountGrades() const;
    const unsigned* getGrades() const;
    const char* getQuote() const;
    double getAverageGrade() const;

    void setName(const char* name);
    void setGrades(const unsigned* grades, size_t countGrades);
    void setQuote(const char* quote);
    
};

#endif
