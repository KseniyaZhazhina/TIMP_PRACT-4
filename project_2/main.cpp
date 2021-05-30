#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "AES.h"
#include "DES.h"

using namespace std;
using namespace CryptoPP;

int main ()
{
    cout << "Программа шифрования: " << endl;
    unsigned op, cip;
    string FIn, FOut, Pass;

    do {
        cout << "\nВыберете действие: (0 - exit, 1 - encrypt, 2 - decrypt): ";
        cin >> op;

        if (op != 0) {
            cout << "\nВыберете алгоритм: " << endl;
            cout << "1 - AES" << endl;
            cout << "2 - DES" << endl;

            cout << "Введите номер выбранного алгоритма: ";
            cin >> cip;
        }

        if (op > 2) {
            cerr << "Ошибка!\n";
        }

        else if (op > 0) {
            cout << "\Укажите путь файла : ";
            cin >> FIn;

            cout << "\Укажите путь файла для сохранения: ";
            cin >> FOut;

            cout << "\nВведите пароль: ";
            cin >> Pass;

            if (cip == 1) {
                AES_Cryptor aes(FIn, FOut, Pass);

                if (op == 1) {
                    if (aes.AES_Encrypt())
                        cout << "Успешно зашифровано." << endl;
                    else
                        cout << "Не удалось зашифровать." << endl;
                } else {
                    if (aes.AES_Decrypt())
                        cout << "Успешно расшифровано." << endl;
                    else
                        cout << "Не удалось расшифровать" << endl;
                }
            }

            else if (cip == 2) {
                DES_Cryptor des(FIn, FOut, Pass);

                if (op == 1) {
                    if (des.DES_Encrypt())
                        cout << "Успешно зашифровано." << endl;
                    else
                        cout << "Не удалось зашифровать." << endl;
                } else {
                    if (des.DES_Decrypt())
                        cout << "Успешно расшифровано." << endl;
                    else
                        cout << "Не удалось расшифровать." << endl;
                }
            }

            else {
                cerr << "Ошибка!\n";
            }
        }

    } while (op != 0);

    return 0;
}