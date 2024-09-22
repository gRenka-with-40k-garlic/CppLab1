#include <iostream>
#include <string>

//using namespace std; - я вспомнила что есть такое, но использовать пока не буду, чтобы впитывать синтаксис 

struct Person {
    std::string surname;
    int birthYear;
};

int main() {
    setlocale(LC_ALL, "Russian");

    Person person1, person2;

    std::cout << "Введите фамилию и год рождения первого человека: ";
    std::cin >> person1.surname >> person1.birthYear;

    std::cout << "Введите фамилию и год рождения второго человека: ";
    std::cin >> person2.surname >> person2.birthYear;

    int currentYear = 2024;

    int age1 = currentYear - person1.birthYear;
    int age2 = currentYear - person2.birthYear;

    std::cout << person1.surname << age1 << std::endl;
    std::cout << person2.surname << age2 << std::endl;

    if (person1.birthYear < person2.birthYear) {
        std::cout << "Фамилия самого старшего человека: " << person1.surname;
    }
    else {
        std::cout << "Фамилия самого старшего человека: " << person2.surname;
    }

    return 0;
}