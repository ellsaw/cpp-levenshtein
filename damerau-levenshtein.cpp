#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int lev(vector<vector<int>>& matrix, const int& i, const int& j, string& a, string& b){
    vector<int> result;

    if(min(i, j) == 0){
        return max(i, j);
    }

    if(i > 0){
        result.push_back(matrix[i][j - 1] + 1);
    }
    if(j > 0){
        result.push_back(matrix[i - 1][j] + 1);
    }
    if(i > 0 && j > 0){
        result.push_back(matrix[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1));
    }
    if(i > 1 && j > 1 && a[i] == b[j - 1]){
        result.push_back(matrix[i - 2][j - 2] + (a[i] == b[j] ? 0 : 1));
    }

    auto min_result = min_element(result.begin(), result.end());

    if(min_result != result.end()){
        return *min_result;
    } else{
        throw runtime_error("Result vector empty.");
    }
} // levenshtein function


int damerauLevenshtein(string& strA, string& strB){
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
    string string1 = "Emilia";
    string string2 = "Eimlia";

    cout << "Enter string one: ";
    getline(cin, string1);

    cout << "Enter string two: ";
    getline(cin, string2);

    cout << "Levenshtein distance is: " << damerauLevenshtein(string1, string2);

    return 0;
} // Testing function 