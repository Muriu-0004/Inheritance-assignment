/* ENE211-0004/2020 FRANCIS MURIU.
Qustion 1
Demonstrate how hierarchical inheritance can be implemented with the following class design computer - server + client.
NB. Include class members (data and functions of your choice). Ensure you implement the classes
using an object in the main() function.*/
#include <iostream>
#include <string>

using namespace std;

// Base class Computer
class Computer {
public:
  string brand;
  int year;

  void display() {
    cout << "Brand: " << brand << endl;
    cout << "Year: " << year << endl;
  }
};

// Derived class Client
class Client : public Computer {
public:
  int numUsers;

  void display() {
    Computer::display();
    cout << "Number of Users: " << numUsers << endl;
  }
};

// Derived class Server
class Server : public Computer {
public:
  int storageCapacity;

  void display() {
    Computer::display();
    cout << "Storage Capacity: " << storageCapacity << " GB" << endl;
  }
};

int main() {
  Client client;
  client.brand = "Dell";
  client.year = 2019;
  client.numUsers = 10;
  cout << "Client Computer:" << endl;
  client.display();

  Server server;
  server.brand = "HP";
  server.year = 2020;
  server.storageCapacity = 1000;
  cout << "Server Computer:" << endl;
  server.display();

  return 0;
}



/* Question 2
ENE211-0004/2020 FRANCIS MURIU
(i) Define a class called person with the members age, firstname and lastname and two member
methods getValues and setValues as well as a constructor to initialise all the class data members
(ii) Define a class Student that inherits the Person class but adds member variables institution,
year (year of study) and registration number.*/
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int age;
    string firstname;
    string lastname;

public:
    Person(int a, string f, string l) {
        age = a;
        firstname = f;
        lastname = l;
    }

    void setValues(int a, string f, string l) {
        age = a;
        firstname = f;
        lastname = l;
    }

    void getValues() {
        cout << "Age: " << age << endl;
        cout << "First Name: " << firstname << endl;
        cout << "Last Name: " << lastname << endl;
    }
};

class Student : public Person {
private:
    string institution;
    int year;
    string registrationNumber;

public:
    Student(int a, string f, string l, string i, int y, string r) : Person(a, f, l) {
        institution = i;
        year = y;
        registrationNumber = r;
    }

    void setValues(int a, string f, string l, string i, int y, string r) {
        Person::setValues(a, f, l);
        institution = i;
        year = y;
        registrationNumber = r;
    }

    void getValues() {
        Person::getValues();
        cout << "Institution: " << institution << endl;
        cout << "Year: " << year << endl;
        cout << "Registration Number: " << registrationNumber << endl;
    }
};

int main() {
    Student s(20, "John", "Doe", "ABC University", 2, "1234");
    s.getValues();

    s.setValues(21, "Jane", "Doe", "XYZ University", 3, "5678");
    s.getValues();

    return 0;
}




/*Question 3.
ENE211-0004/2020 FRANCIS MURIU.
A university has students taking ICT, Law and Business courses. In the Faculty of ICT, there are
Certificate, Diploma and a Degree courses (BSC-IT). BSC-IT has three stages: Stage 1, Stage 2 and
Stage 3.
(i) Briefly explain how inheritance can assist in the capture and processing of student details in the
above scenario.
(ii) Develop a program to implement the design in (i)

Inheritance is a fundamental concept in object-oriented programming that allows a class to inherit properties and behaviors from a parent or base class. In the scenario described above, inheritance can be used to model the different levels of courses and stages in the Faculty of ICT.

For example, we can define a base class called "Course" that contains common attributes and behaviors shared by all courses, such as course code, course name, and course instructor. We can then define three child classes, namely "CertificateCourse", "DiplomaCourse", and "BSCITCourse", each inheriting from the Course class. These child classes can add additional attributes and behaviors specific to their respective levels.

Likewise, we can define another base class called "Stage" that contains common attributes and behaviors shared by all stages of the BSC-IT course, such as stage code, stage name, and stage coordinator. We can then define three child classes, namely "Stage1", "Stage2", and "Stage3", each inheriting from the Stage class. These child classes can add additional attributes and behaviors specific to their respective stages.

Using inheritance in this way allows us to capture and process student details more easily and efficiently. For example, we can create a "Student" class that inherits from the appropriate course and stage classes to represent each individual student in the system. This would allow us to easily access and manipulate student details such as their course, stage, grades, and other relevant information.

in c++ A university has students taking ICT, Law and Business courses. In the Faculty of ICT, there are
Certificate, Diploma and a Degree courses (BSC-IT). BSC-IT has three stages: Stage 1, Stage 2 and
Stage 3.
(i) Briefly explain how inheritance can assist in the capture and processing of student details in the
above scenario.
(ii) Develop a program to implement the design in (i)
(i) Inheritance is a powerful feature of object-oriented programming that allows a derived class to inherit the properties and behaviors of a base class. In the scenario described, inheritance can be used to model the different levels of courses and stages in the Faculty of ICT, which can help in the capture and processing of student details.

For example, we can define a base class called "Course" that contains common attributes such as course code, course name, and course instructor. We can then define three derived classes, namely "CertificateCourse", "DiplomaCourse", and "BSCITCourse", each inheriting from the Course class. These derived classes can add additional attributes specific to their respective levels.

Likewise, we can define another base class called "Stage" that contains common attributes such as stage code, stage name, and stage coordinator. We can then define three derived classes, namely "Stage1", "Stage2", and "Stage3", each inheriting from the Stage class. These derived classes can add additional attributes specific to their respective stages.

Using inheritance in this way allows us to create a hierarchy of classes that reflect the different levels of courses and stages in the Faculty of ICT. We can then use these classes to create objects that represent students, and easily capture and process student details such as their course, stage, grades, and other relevant information.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course {
public:
    Course(string code, string name, string instructor) : code_(code), name_(name), instructor_(instructor) {}
    string code() const { return code_; }
    string name() const { return name_; }
    string instructor() const { return instructor_; }
private:
    string code_;
    string name_;
    string instructor_;
};

class CertificateCourse : public Course {
public:
    CertificateCourse(string code, string name, string instructor, int duration) : Course(code, name, instructor), duration_(duration) {}
    int duration() const { return duration_; }
private:
    int duration_;
};

class DiplomaCourse : public Course {
public:
    DiplomaCourse(string code, string name, string instructor, int duration) : Course(code, name, instructor), duration_(duration) {}
    int duration() const { return duration_; }
private:
    int duration_;
};

class BSCITCourse : public Course {
public:
    BSCITCourse(string code, string name, string instructor, int duration) : Course(code, name, instructor), duration_(duration) {}
    int duration() const { return duration_; }
private:
    int duration_;
};

class Stage {
public:
    Stage(string code, string name, string coordinator) : code_(code), name_(name), coordinator_(coordinator) {}
    string code() const { return code_; }
    string name() const { return name_; }
    string coordinator() const { return coordinator_; }
private:
    string code_;
    string name_;
    string coordinator_;
};

class Stage1 : public Stage {
public:
    Stage1(string code, string name, string coordinator, vector<string> subjects) : Stage(code, name, coordinator), subjects_(subjects) {}
    vector<string> subjects() const { return subjects_; }
private:
    vector<string> subjects_;
};

class Stage2 : public Stage {
public:
    Stage2(string code, string name, string coordinator, vector<string> subjects) : Stage(code, name, coordinator), subjects_(subjects) {}
    vector<string> subjects() const { return subjects_; }
private:
    vector<string> subjects_;
};

class Stage3 : public Stage {
public:
    Stage3




