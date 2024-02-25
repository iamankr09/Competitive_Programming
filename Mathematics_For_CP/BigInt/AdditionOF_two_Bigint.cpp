#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int charTodigit(char ch){
     return ch - '0';
}
char digitTochar(int num){
    return  num + '0';
}
string addTwoNumber(string s1 , string s2){
    if(s1.length()  > s2.length()){
         swap(s1 , s2); // swap to string
    }
     
    string result;
    reverse(s1.begin() , s1.end());
    reverse(s2.begin() , s2.end());

    int carry = 0;
    for(int i = 0 ; i < s1.length() ;  i++){
        int digit1 = charTodigit(s1[i]);
        int digit2 = charTodigit(s2[i]);
        int OutPut_Digit = digit1 + digit2 + carry;
        int rem = OutPut_Digit%10;
        result.push_back(digitTochar(rem));
        carry = OutPut_Digit/10;

    }

    for(int i = s1.length() ; i < s2.length() ; i++){
        int digit2 = charTodigit(s2[i]);
        int OutPut_Digit =  digit2 + carry;
        int rem = OutPut_Digit%10;
        result.push_back(digitTochar(rem));
        carry = OutPut_Digit/10;
    }

    if(carry) result.push_back('1');
    reverse(result.begin() , result.end());
    return result;

}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    string result = addTwoNumber(s1 , s2);
    cout<<result<<endl;
    return 0;
}