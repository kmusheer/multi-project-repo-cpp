#include "./lib.h"

// Student :: Student(const string &id, const string &name, const string email, const string contact, const DOB &dob, float ssc, float preDegree, float degree, char degreeType) : studentId(id), name(name), emailId(email), contactNumber(contact), dob(dob),ssc(ssc), preDegree(preDegree), degree(degree), degreeType(degreeType) {}

void Student ::printHeader()
{
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(25) << "Email"
         << setw(15) << "Contact"
         << setw(12) << "DOB"
         << setw(10) << "SSC"
         << setw(10) << "PreDeg"
         << setw(10) << "Degree"
         << setw(14) << "PreDegreeType"
         << endl;
    cout << string(125, '-') << endl; // Separator line
}

void Student::display() const
{
    cout << left << setw(10) << studentId
         << setw(20) << name
         << setw(25) << emailId
         << setw(15) << contactNumber
         << setw(12) << (to_string(dob.day) + "/" + to_string(dob.month) + "/" + to_string(dob.year))
         << setw(10) << ssc
         << setw(10) << preDegree
         << setw(10) << degree
         << setw(14) << (degreeType == 'a' ? "Diploma" : "Inter")
         << endl;
}

// Getters
string Student ::getId() const { return studentId; }
string Student ::getName() const { return name; }
string Student ::getEmail() const { return emailId; }
string Student ::getContact() const { return contactNumber; }
DOB Student ::getDob() const { return dob; }
float Student ::getSSC() const { return ssc; }
float Student ::getPreDegree() const { return preDegree; }
float Student ::getDegree() const { return degree; }
char Student ::getDegreeType() const { return degreeType; }

// setters
void Student ::setId(const string &id) { studentId = id; }
void Student ::setName(const string &name) { this->name = name; }
void Student ::setEmail(const string &email) { emailId = email; }
void Student ::setContact(const string &contact) { contactNumber = contact; }
void Student ::setDob(const DOB &db)
{
    dob.day = db.day;
    dob.month = db.month;
    dob.year = db.year;
}
void Student ::setSSC(float &ssc) { this->ssc = ssc; }
void Student ::setPreDegree(float &preDegree) { this->preDegree = preDegree; }
void Student ::setDegree(float &degree) { this->degree = degree; }
void Student ::setDegreeType(char& degreeType) { this->degreeType = degreeType; }

bool Student::isValidName(const string &name)
{
    regex nameRegex("^[A-Za-z ]+$");
    return regex_match(name, nameRegex);
}
bool Student::isValidEmail(const string &email)
{
    regex emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    return regex_match(email, emailRegex);
}
bool Student::isValidContact(const string &contact)
{
    regex contactRegex(R"(^(\+?\d{1,4}[- ]?)?\d{10}$)");
    return regex_match(contact, contactRegex);
}
bool Student::isValidDOB(const DOB &dob)
{
    if (dob.year < 1900 || dob.year > 2025)
        return false;
    if (dob.month < 1 || dob.month > 12)
        return false;

    int leapyear = dob.year % 4 == 0 && (dob.year % 100 != 0 || dob.year % 400 == 0) ? 29 : 28;
    int daysInMonth[] = {31, leapyear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dob.day < 1 || dob.day > daysInMonth[dob.month - 1])
        return false;

    return true;
}

float Student::isValidMarks(const string &prompt)
{
    float marks;
    while (true)
    {
        cout << prompt;
        cin >> marks;
        if (cin.fail() || marks < 0 || marks > 100)
        {
            cout << "Invalid marks. Enter a number between 0 and 100.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return marks;
        }
    }
}
