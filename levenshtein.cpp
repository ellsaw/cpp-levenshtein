#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Memo {
    string strA;
    string strB;
    int lev;
};

char headOf(string arg){
    return arg[0];
} // Caclulating the head(str) part of the equation

string tailOf(string arg){
    return arg.erase(0, 1);
} // Caclulating the tail(str) part of the equation

int levenshtein(const string& strA, const string& strB, vector<Memo>& memo){
    for(const Memo mI : memo){
        if((mI.strA == strA && mI.strB == strB) || (mI.strB == strA && mI.strA == strB)){
            return mI.lev;
        };
    } // memoization control

    int result = 0; // Result integer to store the result and to memoize


    if(strB.length() == 0){
        result = strA.length();
    }else if(strA.length() == 0){
        result = strB.length();
    }else if (headOf(strA) == headOf(strB)){
        result = levenshtein(tailOf(strA), tailOf(strB), memo);
    }else{
        result = 1 + min(
            min(
                levenshtein(tailOf(strA), strB, memo),
                levenshtein(strA, tailOf(strB), memo)
            ),
            levenshtein(tailOf(strA), tailOf(strB), memo)
        );
    } // The actual levenshtein equation

    memo.push_back({strA, strB, result}); // Pushing result to memoization vector

    return result;
}

int main(){
    string string1;
    string string2;

    cout << "Enter string one: ";
    getline(cin, string1);

    cout << "Enter string two: ";
    getline(cin, string2);

    vector<Memo> memo;

    cout << "Levenshtein distance is: " << levenshtein(string1, string2, memo);

    return 0;
} // Testing function 