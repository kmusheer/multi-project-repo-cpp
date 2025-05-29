#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <fstream>
#include <iomanip>
#include "json.hpp"

using json = nlohmann::json;

using namespace std;
extern int idCountArr[26]; // for id track

struct DOB
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

class Student
{
    string studentId, name, emailId, contactNumber;
    DOB dob;
    float ssc, preDegree, degree;
    char degreeType; // 'a' for diploma, 'b' for inter

public:
    Student() = default;
    // Student(const string &, const string &, const string &, const string &, const DOB &, float, float, float, char);
    Student(const string &id, const string &name, const string email, const string contact, const DOB &dob, float ssc, float preDegree, float degree, char degreeType) : studentId(id), name(name), emailId(email), contactNumber(contact), dob(dob), ssc(ssc), preDegree(preDegree), degree(degree), degreeType(degreeType) {}
    // Getters
    string getId() const;
    string getName() const;
    string getEmail() const;
    string getContact() const;
    DOB getDob() const;
    float getSSC() const;
    float getPreDegree() const;
    float getDegree() const;
    char getDegreeType() const;

    // Setters
    void setId(const string &id);
    void setName(const string &name);
    void setEmail(const string &email);
    void setContact(const string &contact);
    void setDob(const DOB &dob);
    void setSSC(float &ssc);
    void setPreDegree(float &preDegree);
    void setDegree(float &degree);
    void setDegreeType(char &degreeType);

    void display() const;

    // Static validation
    static void printHeader();
    static bool isValidName(const string &);
    static bool isValidEmail(const string &);
    static bool isValidContact(const string &);
    static bool isValidDOB(const DOB &);
    static float isValidMarks(const string &);
};

class StudentManager
{
    map<string, Student> database;

public:
    bool addStudent(const Student &);
    bool deleteStudent(const string &id);
    Student *findStudent(const string &id);
    void printAll() const;
    // void reversePrint() const;
    // bool editStudent(const string &id, const Student &update);
    void saveToFile(const string &) const;
    void loadFromFile(const string &fileName);
    string generateID(const string &);
};

#endif // STUDENT_H
