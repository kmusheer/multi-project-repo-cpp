#include "./lib.h"

int main()
{
    cout << "Welcome to Student Management System" << endl;
    cout << "--------------------------------------" << endl;
    cout << "This program allows you to manage student records." << endl;
    cout << "You can add, delete, find, edit, and print student details." << endl;
    cout << "You can also save and load student records from a file." << endl;
    cout << "--------------------------------------" << endl;
    cout << "Please follow the prompts to manage student records." << endl;
    cout << "--------------------------------------" << endl;
    cout << "Loading existing student records..." << endl
         << endl;

    StudentManager ms;
    ms.loadFromFile("studentLib.json");
    int choice;
    while (true)
    {

        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
        for (int i = 0; i < 26; i++)
        {
            cout << idCountArr[i] << " ";
        }
        cout << endl;
        cout << endl;
        cout << endl
             << "1. Add Student\n2. Delete Student\n3. Find Student\n4. Print All Students\n5. Edit Student\n6. Save to File\n7. Load from File\n8. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 8)
            break;
        switch (choice)
        {
        case 1:
        {
            string id, name, email, contact;
            DOB dob;
            float ssc, preDegree, degree;
            char degreeType;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover newline just once
            while (true)
            {
                cout << "Enter name: ";
                // cin.ignore();
                getline(cin, name);
                if (Student::isValidName(name))
                    break;
                else
                    cout << "Invalid input. Please enter only letters and spaces.\n";
            }
            id = ms.generateID(name);
            cout << "Your student ID: " << id << endl;
            while (true)
            {
                cout << "Enter email: ";
                cin >> email;
                if (Student::isValidEmail(email))
                    break;
                else
                    cout << "Invalid email format. Please try again.\n";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (true)
            {
                cout << "Enter contact number: ";
                getline(cin, contact);
                if (Student::isValidContact(contact))
                    break;
                else
                    cout << "Invalid contact number. Use 10 digits or include a valid country code (e.g., +91).\n";
            }
            while (true)
            {
                cout << "Enter date of birth (dd mm yyyy): ";
                cin >> dob.day >> dob.month >> dob.year;
                if (Student::isValidDOB(dob))
                    break;
                else
                    cout << "Invalid dob format. Please try again.\n";
            }
            ssc = Student::isValidMarks("Enter SSC marks: ");
            preDegree = Student::isValidMarks("Enter Pre-Degree marks: ");
            degree = Student::isValidMarks("Enter Degree marks: ");

            while (true)
            {
                cout << "Enter Pre-Degree Type (a for diploma, b for inter): ";
                cin >> degreeType;

                if (degreeType == 'a' || degreeType == 'b')
                    break;
                else
                    cout << "Invalid input. Enter 'a' for diploma or 'b' for inter.\n";
            }

            Student stud(id, name, email, contact, dob, ssc, preDegree, degree, degreeType);
            if (ms.addStudent(stud))
                cout << "Student added successfully." << endl;
            else
                cout << "Failed to add student." << endl;
        }
        break;
        case 2:
        {
            string id;
            cout << "Enter student ID to delete: ";
            cin >> id;

            if (ms.deleteStudent(id))
                cout << "Student deleted successfully." << endl;
            else
                cout << "Failed to delete student." << endl;
        }
        break;
        case 3:
        {
            string id;
            cout << "Enter student ID to find: ";
            cin >> id;
            Student *student = ms.findStudent(id);

            if (student)
                student->display();
            else
                cout << "Student not found." << endl;
        }
        break;
        case 4:
            ms.printAll();
            break;
        case 5:
        {
            string id;
            cout << "Enter student ID to edit: ";
            cin >> id;

            Student *student = ms.findStudent(id);

            if (student)
            {
                string name, email, contact;
                DOB dob;
                float ssc, preDegree, degree;
                char degreeType;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // Email
                cout << "Enter new email (or press Enter to keep current): ";
                getline(cin, email);
                if (!email.empty() && Student::isValidEmail(email))
                    student->setEmail(email);

                // Contact
                cout << "Enter new contact number (or press Enter to keep current): ";
                getline(cin, contact);
                if (!contact.empty() && Student::isValidContact(contact))
                    student->setContact(contact);

                // DOB
                cout << "Enter new date of birth (dd mm yyyy): ";
                cin >> dob.day >> dob.month >> dob.year;
                if (!(dob.day == 0 && dob.month == 0 && dob.year == 0) && Student::isValidDOB(dob))
                    student->setDob(dob);

                // SSC Marks
                ssc = Student::isValidMarks("Enter SSC marks: ");
                student->setSSC(ssc);
                preDegree = Student::isValidMarks("Enter Pre-Degree marks: ");
                student->setPreDegree(preDegree);
                degree = Student::isValidMarks("Enter Degree marks: ");
                student->setDegree(degree);

                // Degree Type
                while (true)
                {
                    cout << "Enter new Degree Type (a for diploma, b for inter) (or press Enter to keep current): ";
                    cin >> degreeType;
                    if (degreeType == 'a' || degreeType == 'b')
                    {
                        student->setDegreeType(degreeType);
                        break;
                    }
                    else
                        cout << "Invalid input. Enter 'a' for diploma or 'b' for inter.\n";
                }
                cout << "Student updated successfully." << endl;
            }
            else
                cout << "Student not found." << endl;
        }
        break;
        case 6:
        {
            string fileName = "studentLib.json";

            ms.saveToFile(fileName);
            cout << "Data saved to " << fileName << endl;
        }
        break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}