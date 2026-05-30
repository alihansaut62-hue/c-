#include <clocale>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Person
{
public:
    string name;
    int age;
    bool isHappy;
    string hobbies[3];

    ~Person()
    {
        cout << name << " is destroyed" << endl;
    }

    Person()
    {
        name = "Unknown";
        age = 0;
        isHappy = false;
    }

    Person(string name, int age, bool isHappy)
    {
        this->name = name;
        this->age = age;
        this->isHappy = isHappy;
    }

    void set_hobbis(string* p, int n);
    void get_hobbis();
    void set_data(string name, int age, bool isHappy);
    void set_data(string name, int age);
};

void Person::set_hobbis(string* p, int n)
{
    for (int i = 0; i < n && i < 3; i++)
    {
        hobbies[i] = p[i];
    }
}

void Person::get_hobbis()
{
    for (int i = 0; i < 3; i++)
    {
        cout << hobbies[i] << endl;
    }
}

void Person::set_data(string name, int age, bool isHappy)
{
    this->name = name;
    this->age = age;
    this->isHappy = isHappy;
}

void Person::set_data(string name, int age)
{
    this->name = name;
    this->age = age;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Person user1;

    user1.set_data("Alice", 30, true);

    Person* p_user = &user1;

    cout << "Возраст user1 через указатель: "
        << p_user->age << endl << endl;

    Person user2("Panda", 25, true);

    string hobbies[] =
    {
        "Gaming",
        "Cooking",
        "Traveling"
    };

    user2.set_hobbis(hobbies, 3);

    cout << "Хобби user2:" << endl;
    user2.get_hobbis();

    cout << endl;

    cout << "Имя: " << user2.name << endl;
    cout << "Возраст: " << user2.age << endl;
    cout << "Счастлив: ";

    if (user2.isHappy)
        cout << "Да" << endl;
    else
        cout << "Нет" << endl;

    cout << endl;

    cout << user1.name << endl;
    cout << user2.age << endl;
    cout << user1.age << endl;

    return 0;
}