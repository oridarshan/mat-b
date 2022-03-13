#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "mat.hpp"

using namespace std;



string ariel::mat(int col, int row, char c1, char c2){
    if(col <= 0 || col % 2 == 0){
        throw ("columns number must be a natural odd number");
    }
    if(row <= 0 || row % 2 == 0){
        throw ("rows number must be a natural odd number");
    }
    if(c1 < '!' || c1 > '~' || c2 < '!' || c2 > '~'){
        throw ("characters must be printable");
    }

    // initialize mat
    // char arr[row][col+1];
    // std::array<std::array<char, row>, col+1> arr;
    vector<vector<char>> arr (row, vector<char>(col+1));
    for (int i = 0; i < row; i++)
    {
        arr[i][col] = '\n';
    }
    char c = c2;
    for (int k = 0; k < max(row,col); k++){
        c = (c == c2) ? c1 : c2;
        for (int i = k; i < row - k; i++)
        {
            for (int j = k; j < col - k; j++)
            {
                arr[i][j] = c;
            }
            
        }
        
        // paint upper and lower rows
        // for (int i = 0 + k; i < col - k; i++)
        // {
        //     cout << "fill " << k << i << endl;
        //     arr[k][i] = c;
        //     cout << "fill " << row - 1 - k << i << endl;
        //     arr[row - 1 - k][i] = c;
            
        // }
        // // paint right and left columns
        // for (int i = 0 + k; i < row - k; i++)
        // {
        //     // arr[i][k] = c;
        //     cout << "fill " << i << k << endl;
        //     arr.at(i).at(k) = c;
        //     cout << "fill [" << i << "][" << col - 1 - k << "]" << endl;
        //     arr[i][col - 1 - k] = c;
        // }
        // arr[i][j] = '\n';        // cout << arr[i][j];
        
    }
    // print mat

    string res;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col+1; j++)
        {
            //cout << arr[i][j];
            res.push_back(arr[i][j]);
        }
        
    }
    

    // string res = "";
    // for (int i = 0; i < row; i++)
    // {
    //     res.append((string)arr[i][0]);
    // }
    
    
    return res;
}

