#include "./lib.h"

// map<string, Student> database;
int idCountArr[26] = {0}; // for id track

string StudentManager::generateID(const string &name)
{
    string base = "V24HE2";
    char firstChar = name[0];
    if (islower(firstChar))
    {
        firstChar = toupper(firstChar);
    }
    if (!isalpha(firstChar))
    {
        cerr << "Invalid name for ID generation." << endl;
        return "";
    }
    int index = firstChar - 'A';
    int count = ++idCountArr[index];

    string id = base + firstChar + (count < 10 ? "0" + to_string(count) : to_string(count));

    return id;
}

bool StudentManager ::addStudent(const Student &s)
{
    string id = s.getId();
    if (database.find(id) != database.end())
    {
        cout << "Error: Student with ID " << id << " already exists." << endl;
        return false;
    }
    database[id] = s;
    return true;
}

void StudentManager ::printAll() const
{
    if (database.empty())
    {
        cout << "No student records available." << endl;
        return;
    }
    Student ::printHeader();
    for (const auto &pair : database)
    {
        pair.second.display();
    }
    cout << endl;
}

bool StudentManager ::deleteStudent(const string &id)
{

    auto it = database.find(id);
    if (it != database.end())
    {
        // cout << &it << endl;
        database.erase(it);
        return true;
    }
    return false;
}

Student *StudentManager::findStudent(const string &id)
{
    auto it = database.find(id);
    if (it != database.end())
    {
        return &(it->second);
    }
    return nullptr;
}

void StudentManager ::saveToFile(const string &fileName) const
{
    json jArray = json::array();

    for (const auto &pair : database)
    {
        const Student &s = pair.second;
        DOB dob = s.getDob();

        json jStudent = {
            {"id", s.getId()},
            {"name", s.getName()},
            {"email", s.getEmail()},
            {"contact", s.getContact()},
            {"dob", {{"day", dob.day}, {"month", dob.month}, {"year", dob.year}}},
            {"ssc", s.getSSC()},
            {"preDegree", s.getPreDegree()},
            {"degree", s.getDegree()},
            {"preDegreeType", string(1, s.getDegreeType())},
        };

        jArray.push_back(jStudent);
    }

    ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        cerr << "Failed to open file for writing." << endl;
        return;
    }
    outFile << jArray.dump(4); // Pretty print with 4-space indentation
    outFile.close();
}

void StudentManager ::loadFromFile(const string &fileName)
{
    string studentId, name, emailId, contactNumber;
    DOB dob;
    float ssc;
    float preDegree;
    float degree;
    char degreeType;

    ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        cerr << "Failed to open file for reading." << endl;
        return;
    }
    json jArray;
    try
    {
        inFile >> jArray;
    }
    catch (const exception &e)
    {
        cerr << "Failed to parse JSON: " << e.what() << endl;
        return;
    }

    for (const auto &jdata : jArray)
    {
        string name = jdata.at("name").get<string>();
        string id = jdata.at("id").get<string>();
        string email = jdata.at("email").get<string>();
        string contact = jdata.at("contact").get<string>();

        DOB dob;
        dob.day = jdata["dob"]["day"];
        dob.month = jdata["dob"]["month"];
        dob.year = jdata["dob"]["year"];

        float ssc = jdata.at("ssc").get<float>();
        float preDegree = jdata.at("preDegree").get<float>();
        float degree = jdata.at("degree").get<float>();
        char degreeType = jdata.at("preDegreeType").get<string>()[0];

        Student s(id, name, email, contact, dob, ssc, preDegree, degree, degreeType);
        database[id] = s;

        if (id.length() >= 8)
        {
            char ch = id[6];
            if (ch >= 'A' && ch <= 'Z')
            {
                int index = ch - 'A';
                int number = stoi(id.substr(7));
                if (number > idCountArr[index])
                {
                    idCountArr[index] = number;
                }
            }
        }
    }
    cout << "Student records loaded successfully from " << fileName << endl;
}
