#include <iostream>
#include <limits>

#include "str_ops.h"

int read_menu_choice() {
    int choice;

    while (true) {
        std::cout << "> ";
        std::cin >> choice;

        if (!std::cin.fail()) {
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );
            return choice;
        }

        std::cout << "Ошибка: введите целое число.\n";

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}


char* read_line() {
    std::size_t capacity = 16;
    std::size_t length = 0;

    char* buffer = new char[capacity];
    buffer[0] = '\0';

    char ch;

    while (std::cin.get(ch) && ch != '\n') {
        if (length + 1 >= capacity) {
            const std::size_t new_capacity = capacity * 2;
            char* new_buffer = new char[new_capacity];

            for (std::size_t i = 0; i <= length; ++i) {
                new_buffer[i] = buffer[i];
            }

            delete[] buffer;
            buffer = new_buffer;
            capacity = new_capacity;
        }

        buffer[length] = ch;
        ++length;
        buffer[length] = '\0';
    }

    return buffer;
}

void print_menu() {
    std::cout
        << "1. Ввести строку\n"
        << "2. Напечатать строку\n"
        << "3. Узнать длину\n"
        << "4. Скопировать в буфер и напечатать\n"
        << "5. Алгоритм варианта 12\n"
        << "0. Выход\n";
}

void run_variant_12(char* text) {
    if (text == nullptr) {
        std::cout << "Сначала введите строку.\n";
        return;
    }

    std::cout
        << "\n1. Перевести строку в верхний регистр\n"
        << "2. Посчитать вхождения символа\n";

    const int choice = read_menu_choice();

    if (choice == 1) {
        str_to_upper(text);

        std::cout << "Результат: ";
        str_print(text);
        std::cout << '\n';
    } else if (choice == 2) {
        char ch;

        std::cout << "Введите один символ: ";
        std::cin.get(ch);

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        const std::size_t count = str_count_char(text, ch);

        std::cout << "Символ '" << ch
                  << "' встречается: " << count << " раз(а).\n";
    } else {
        std::cout << "Такого пункта нет.\n";
    }
}

int main() {
    char* text = nullptr;
    bool running = true;

    while (running) {
        print_menu();

        const int choice = read_menu_choice();

        switch (choice) {
            case 1: {
                std::cout << "Введите строку: ";

                str_delete(text);

                text = read_line();

                std::cout << "Строка сохранена.\n";
                break;
            }

            case 2: {
                if (text == nullptr) {
                    std::cout << "Строка ещё не введена.\n";
                } else {
                    std::cout << "Строка: ";
                    str_print(text);
                    std::cout << '\n';
                }
                break;
            }

            case 3: {
                if (text == nullptr) {
                    std::cout << "Строка ещё не введена.\n";
                } else {
                    std::cout << "Длина: "
                              << str_len(text)
                              << '\n';
                }
                break;
            }

            case 4: {
                if (text == nullptr) {
                    std::cout << "Строка ещё не введена.\n";
                    break;
                }

                char* copy = str_alloc(text);

                std::cout << "Копия: ";
                str_print(copy);
                std::cout << '\n';

                str_delete(copy);
                break;
            }

            case 5:
                run_variant_12(text);
                break;

            case 0:
                running = false;
                break;

            default:
                std::cout << "Такого пункта меню нет.\n";
                break;
        }
    }

    str_delete(text);

    std::cout << "Программа завершена.\n";
    return 0;
}