#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "User.h"
#include "ChatApp.h"
#include "GroupChat.h"
#include "Message.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    
    /*printf("\n");
    printf("\x1B[31mTexting\033[0m\t\t");
    printf("\x1B[32mTexting\033[0m\t\t");
    printf("\x1B[33mTexting\033[0m\t\t");
    printf("\x1B[34mTexting\033[0m\t\t");
    printf("\x1B[35mTexting\033[0m\n");

    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[37mTexting\033[0m\t\t");
    printf("\x1B[93mTexting\033[0m\n");

    printf("\033[3;42;30mTexting\033[0m\t\t");
    printf("\033[3;43;30mTexting\033[0m\t\t");
    printf("\033[3;44;30mTexting\033[0m\t\t");
    printf("\033[3;104;30mTexting\033[0m\t\t");
    printf("\033[3;100;30mTexting\033[0m\n");

    printf("\033[3;47;35mTexting\033[0m\t\t");
    printf("\033[2;47;35mTexting\033[0m\t\t");
    printf("\033[1;47;35mTexting\033[0m\t\t");
    printf("\t\t");
    printf("\n");*/

    ChatApp app;
    char choice;
    string login, password;
    User* currentUser = nullptr;

    while (true)
    {
        if (currentUser == nullptr)
        {
            cout << "\x1B[36m1. Регистрация\n2. Войти\n3. Выход из программы\nВведите выбор: \033[0m";
            cin >> choice;
            cin.ignore();
            if (choice == '1')
            {
                cout << "\x1B[93mВведите имя пользователя: ";
                getline(cin, login);
                cout << "Введите пароль: ";
                getline(cin, password);
                app.registerUser(login, password);
            }
            else if (choice == '2')
            {
                cout << "\x1B[93mВведите имя пользователя: ";
                getline(cin, login);
                cout << "Введите пароль: ";
                getline(cin, password);
                currentUser = app.loginUser(login, password);
            }
            else if (choice == '3')
            {
                app.exitApp(); // Завершаем программу
            }
        }
        else {
            while (true)
            {
                cout << "\x1B[93m\n1. Отправить сообщение в общий чат\n2. Отправить личное сообщение\n3. Посмотреть общий чат\n4. Посмотреть личный чат\n5. Выйти\nВведите выбор: ";
                cin >> choice;
                cin.ignore();

                if (choice == '1')
                {
                    string message;
                    cout << "Введите сообщение для общего чата: ";
                    getline(cin, message);

                    // Отправляем сообщение в общий чат
                    app.sendMessageToGeneralChat(currentUser->getUserLogin(), message);
                    cout << "\x1B[32mСообщение отправлено в общий чат!\n\033[0m";
                }
                else if (choice == '2')
                {
                    string recipient, message;
                    cout << "Введите имя получателя: ";
                    getline(cin, recipient);
                    cout << "Введите сообщение: ";
                    getline(cin, message);

                    bool recipientExists = false;
                    for (const auto& u : app.getUsers())
                    {
                        if (u.getUserLogin() == recipient)
                        {
                            recipientExists = true;
                            break;
                        }
                    }
                    if (!recipientExists)
                    {
                        cout << "\x1B[32mПользователь с таким именем не существует!\n\033[0m";
                    }
                    else
                    {
                        GroupChat& chat = app.getChat(currentUser->getUserLogin(), recipient);
                        chat.sendMessage(currentUser->getUserLogin(), recipient, message, true); // true для личного сообщения
                        cout << "\x1B[32mСообщение отправлено пользователю \033[0m" << "\x1B[33m" << recipient << "\x1B[32m!\n\033[0m";
                    }
                }
                else if (choice == '3')
                {
                    app.showGeneralChat();
                }
                else if (choice == '4')
                {
                    cout << "\x1B[33mЛичный чат с вами:\n\033[0m";
                    // Показываем сообщения, относящиеся к текущему пользователю
                    for (const auto& chat : app.getChats())
                    {
                        chat.showPrivateMessage(currentUser->getUserLogin());
                    }
                }
                else if (choice == '5')
                {
                    currentUser = nullptr;
                    break;
                }
            }
        }
    }
    return 0;
}

