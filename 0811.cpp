#include <iostream>
#include <string>
using namespace std;

/*
* TODO: добавить в класс методы получения и установки значения поля name,
* ограничьте возможность записи в поле name (ограничения придумать самостоятельно)
*/

class Department {
    // private:
        // class members / члены класса
    int id; // class fields / поля класса
    string name;
public:
    void setName(string inputName) {
        if (size(inputName) > 30) throw exception("Validation error: name should not be longer than 30 characters");
        this->name = inputName;
    }
    string getName() {
        return this->name;
    }
    
    void setId(int id) // class method / метод класса
    {
        if (id <= 0 || id >= 1000000)
        {
            throw exception("Validation error: id must be greater than 0 and less than 1000000");
        }
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
};

int main()
{
    // создан объект / object (экземпляр / instance) типа Department,
    // и записан в переменную d1
    Department d1;
    // на объекте типа Department, хранящемся в переменной d1,
    // вызван метод установки значения в поле id
    // d1.setId(-100);
    // d1.setId(100);
    int id;
    cout << "Input id (greater than 0 and less than 1000000): " << endl;
    cin >> id;
    
    try {
        d1.setId(id);
        cout << "ID " << d1.getId() << " is saved." << endl;
    }
    catch (exception ex) {
        cerr << ex.what() << endl;
        return 0;
    }
    
    string name;
    cout << "Input name (not longer than 30 characters): ";
    cin >> name;

    try {
        d1.setName(name);
        cout << "Name " << d1.getName() << " for ID " << d1.getId() << " is saved." << endl;
    }
    catch (exception ex) {
        cerr << ex.what() << endl;
        return 0;
    }
}
