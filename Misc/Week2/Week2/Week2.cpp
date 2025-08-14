#include <iostream>
#include <string>

using namespace std;

int main()
{
    // dataType variableName;
    int age;
    float weight;
    double distance;
    bool isAlive;
    char initial;
    string name;

    unsigned short int betterAge;
    long double hugeDistance;

    age = 30;
    weight = 190.5f;
    distance = 1212.987;
    isAlive = true;
    initial = 'F';
    name = "Filip";

    cout << "My name is " << name << " and I am " << age << " years old." << endl;
    cout << "Am I alive: " << isAlive << endl;

    int newAge;
    newAge = age; // 30

    int newestAge = 25;
}
