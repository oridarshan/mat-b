#include <iostream>
#include <string>
#include "mat.hpp"


int main(int argc, char *argv[])
{
    bool mat_printed = false;
    string mat;
    if (argc == 5){
        try{
            // cout << (string)argv[1];
            // cout << stoi((string)argv[1]) << stoi((string)argv[2]) << *argv[3] << *argv[4] << endl;
            mat = ariel::mat(stoi((string)argv[1]), stoi((string)argv[2]), *argv[3], *argv[4]);
            cout << mat << endl;
            mat_printed = true;
        }
        catch(string e){
            cout << "Arguments not valid, Enter arguments manually" << endl;
        }
    }
    if (!mat_printed)
    {
        int num1, num2;
        char c1, c2;
        while(!mat_printed){
            cout << "enter number of columns: ";
            cin >> num1;
            cout << "enter number of rows: ";
            cin >> num2;
            cout << "enter first symbol: ";
            cin >> c1;
            cout << "enter second symbol: ";
            cin >> c2;
            try{
                mat = ariel::mat(num1, num2, c1, c2);
                cout << "Your carpet:" << endl;
                cout << mat << endl;
                mat_printed = true;
            }
            catch(...){
                cout << "follow the format!\n"
                 "numbers must be odd positive, chars must be printable" << endl;
            }
        }
    }
    return 0;
}