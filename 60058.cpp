#include <string>
#include <iostream>
#include <vector>

using namespace std;
bool check(string str);

string solution(string p) {
    string answer = "";
    if(p.length() == 0)
        return p;
    
    int cnt1 = 0;
    int cnt2 = 0;
    int i = 0;
    
    while(1){
        if(p[i] == '(')
            cnt1++;
        else
            cnt2++;
        if(cnt1 == cnt2)
            break;
        i++;
    }
    string u = p.substr(0,i+1);
    string v = p.substr(i+1, p.length() - u.length());
    
    if(check(u))
       return u + solution(v);
    else{
        string temp = "(";
        temp += solution(v) + ")";
        for(int i = 1; i < u.length() - 1; i++){
            if(u[i] == '(')
                temp += ")";
            else
                temp += "(";
        }
        return temp;
    }
        
    
    return answer;
}

bool check(string str){
    int i = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    if(str[i] != '(')
        return false;
    for(i = 0; i < str.length(); i++){
        if(str[i] == '('){
            cnt1++;
        }
        else
            cnt2++;
        if(cnt1 < cnt2)
            return false;
    }
    return true;
}