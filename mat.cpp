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

    // initialize mat as vetor of vectors of chars
    vector<vector<char>> arr (row, vector<char>(col+1));

    // add end of line for each row
    for (int i = 0; i < row; i++)
    {
        arr[i][col] = '\n';
    }

    char c = c2;
    // loop over edge sizes
    for (int k = 0; k < max(row,col); k++){
        // switch symbol for each iteration
        c = (c == c2) ? c1 : c2;
        for (int i = k; i < row - k; i++)
        // paint sub-mat with relevant symbol
        {
            for (int j = k; j < col - k; j++)
            {
                arr[i][j] = c;
            }         
        }
    }
    // create result string
    string res;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col+1; j++)
        {
            // append symbol from mat to result string
            res.push_back(arr[i][j]);

            //cout << arr[i][j]; //debuging
        }
        
    }
    
    return res;
}

