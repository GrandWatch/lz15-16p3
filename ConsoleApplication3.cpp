// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>   // для роботи з файлами
#include <string>
using namespace std;

// Оголошення структури абітурієнта
struct Abiturient {
    char prizv[30];
    char name[30];
    char specialist[50];
    int ukr_mova;      // Бали з української мови
    int matematika;    // Бали з математики
    int istoriya;      // Бали з історії України
};

int main() {
    // Ініціалізація списку абітурієнтів
    Abiturient abitur[] = {
        {"Фурман", "Олена", "Середня освіта математика", 145, 170, 160},
        {"Петров", "Андрій", "Середня освіта Літерболіст", 180, 200, 155},
        {"Гриценко", "Петро", "Середня освіта математика", 130, 150, 140},
        {"Коваленко", "Марія", "Середня освіта математика", 150, 160, 170}
    };

    int n = sizeof(abitur) / sizeof(abitur[0]);  // Кількість абітурієнтів у списку
    int count = 0;   // Лічильник студентів, які подали заяви на "Середня освіта математика"

    // Відкриваємо файл для запису результатів
    ofstream outFile("results.txt");
    if (!outFile) {
        cerr << "Не вдалося відкрити файл results.txt" << endl;
        return 1;
    }

    outFile << "Студенти, що подали заяви на спеціальність 'Середня освіта математика' та їх бали:\n\n";

    // Перевірка кожного абітурієнта
    for (int i = 0; i < n; i++) {
        if (string(abitur[i].specialist) == "Середня освіта математика") {
            // Запис інформації про абітурієнта у файл
            outFile << "Прізвище: " << abitur[i].prizv
                << ", Ім'я: " << abitur[i].name
                << ", Українська мова: " << abitur[i].ukr_mova
                << ", Математика: " << abitur[i].matematika
                << ", Історія України: " << abitur[i].istoriya << endl;
            count++;   // Збільшуємо лічильник
        }
    }

    // Записуємо загальну кількість студентів у файл
    outFile << "\nКількість студентів: " << count << endl;

    // Закриваємо файл
    outFile.close();

    cout << "Результати записані у файл results.txt" << endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
