#include <iostream>
#include <vector>
#include <string>

using namespace std;


int lev(vector<vector<int>>& matrix, const int& i, const int& j, string& a, string& b){
    if(min(i, j) == 0){
        return max(i, j);
    } else {
        return min(
            min(
                matrix[i - 1][j] + 1,
                matrix[i][j - 1] + 1
            ),
            matrix[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)
        );
    };
} // levenshtein function


int levenshtein(string& strA, string& strB){
    int rows = strA.length() + 1;
    int cols = strB.length() + 1;


    vector<vector<int>> matrix(rows, vector<int>(cols, 0));


    for(int i = 0; i < matrix.size(); i++){

        for(int j = 0; j < matrix[i].size(); j++){
            matrix[i][j] = lev(matrix, i, j, strA, strB);
        }

    };

    return matrix[rows - 1][cols - 1];
} // Function that builds and fills matrix using levenshtein function. Returns last column of last row aka levenshtein distance

int main(){
    string string1;
    string string2;

    cout << "Enter string one: ";
    getline(cin, string1);

    cout << "Enter string two: ";
    getline(cin, string2);

    cout << "Levenshtein distance is: " << levenshtein(string1, string2);

    return 0;
} // Testing function 