#include <iostream>
#include <string>
#include <algorithm>

struct Train {
    std::string destination;
    int trainNumber;
    int departureTime;
};

bool compareDestinations(const Train& a, const Train& b) {
    return a.destination < b.destination;
}

int main() {
    setlocale(LC_ALL, "rus");
    int N;
    std::cout << "Введите количество поездов: ";
    std::cin >> N;

    Train* trains = new Train[N];

    for (int i = 0; i < N; ++i) {
        std::cout << "Введите пункт назначения " << i + 1 << " поезда: ";
        std::cin >> trains[i].destination;
        std::cout << "Введите номер " << i + 1 << " поезда: ";
        std::cin >> trains[i].trainNumber;

        // Ввод времени отправления с проверкой
        do {
            std::cout << "Введите (целое) время отправления " << i + 1 << " поезда: ";
            std::cin >> trains[i].departureTime;

            if (trains[i].departureTime > 24) {
                std::cout << "Ошибка: время отправления не может быть больше 24. Пожалуйста, введите корректное время.\n";
            }
        } while (trains[i].departureTime > 24);
    }

    std::sort(trains, trains + N, compareDestinations);
    for (int i = 0; i < N; ++i) {
        std::cout << "Название пункта назначения " << i + 1 << " поезда:" << trains[i].destination << std::endl;
        std::cout << "Номер " << i + 1 << " поезда: " << trains[i].trainNumber << std::endl;
        std::cout << "Время отправления " << i + 1 << " поезда: " << trains[i].departureTime << std::endl;
        std::cout << std::endl;
    }

    std::string inputDestination;
    std::cout << "Введите время отправления поезда: ";
    int filterTime;
    std::cin >> filterTime;

    bool found = false;
    for (int i = 0; i < N; ++i) {
        if (trains[i].departureTime > filterTime) {
            if (!found) {
                found = true;
                std::cout << "Поезда, отправляющиеся после " << filterTime << ":\n";
            }
            std::cout << "Пункт назначения поезда: " << trains[i].destination << "\n";
            std::cout << "Номер поезда: " << trains[i].trainNumber << "\n";
            std::cout << "Время отправления поезда: " << trains[i].departureTime << "\n\n";
        }
    }

    if (!found) {
        std::cout << "Не найдено поездов после " << filterTime << "\n";
    }

    return 0;
}