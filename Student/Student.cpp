#include "Student.hpp"
#include <cstring>

void Student::free()
{
    if (mName)
    {
        delete[] mName;
        mName = nullptr;
    }
    if (mGrades)
    {
        delete[] mGrades;
        mGrades = nullptr;
    }
    if (mQuote)
    {
        delete[] mQuote;
        mQuote = nullptr;
    }
    mCountGrades = 0;
    mAverageGrade = 0.0;
}

void Student::copy(const Student &other)
{
    setName(other.mName);
    setGrades(other.mGrades, other.mCountGrades);
    setQuote(other.mQuote);
}

Student::Student(const char *name, size_t countGrades, const unsigned *grades, const char *quote)
    : mName(nullptr), mGrades(nullptr), mQuote(nullptr), mCountGrades(0), mAverageGrade(0.0)
{
    setName(name);
    setGrades(grades, countGrades);
    setQuote(quote);
}

Student::Student(const Student &other)
{
    copy(other);
}

Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Student::~Student()
{
    free();
}

const char *Student::getName() const
{
    return this->mName;
}

size_t Student::getCountGrades() const
{
    return this->mCountGrades;
}

const unsigned *Student::getGrades() const
{
    return this->mGrades;
}

const char *Student::getQuote() const
{
    return this->mQuote;
}

double Student::getAverageGrade() const
{
    return this->mAverageGrade;
}

void Student::setName(const char *name)
{
    if (!name)
        return;
    delete[] this->mName;
    this->mName = new char[strlen(name) + 1];
    strcpy(this->mName, name);
}

void Student::setGrades(const unsigned *grades, size_t countGrades)
{
    if (!grades || countGrades == 0)
        return;
    delete[] this->mGrades;
    int sum = 0;
    this->mCountGrades = countGrades;
    this->mGrades = new unsigned[this->mCountGrades];
    for (size_t i = 0; i < countGrades; i++)
    {
        this->mGrades[i] = grades[i];
        sum += grades[i];
    }
    this->mAverageGrade = static_cast<double>(sum) / countGrades;
}

void Student::setQuote(const char *quote)
{
    if (!quote)
        return;
    delete[] this->mQuote;
    this->mQuote = new char[strlen(quote) + 1];
    strcpy(this->mQuote, quote);
}
