#include <string>
#include <vector>
using namespace std;

string stringCountOne(int n) {
    int k = 1, d = 1;
    string s = "";
    while (n / k) {
        d *= 3;
        k += d;
        s += "1";
    }
    return s;
}

int convertNext(int n) {
    int k = 1, d = 1;
    while (n / k) {
        d *= 3;
        k += d;
    }
    return n - k + d;
}

string addString(string& answer, string& now) {
    if (answer == "")
        return now;
 
    string tmp = "";
    for (int i=0; i<answer.size() - now.size(); i++)
        tmp += "0";
    now = tmp + now;
    
    string result = "";
    for (int i=0; i<answer.size() + 1; i++)
        result += "0";
    
    bool checkedUp = false;
    for (int i=now.size() - 1; i>=0; i--)
    {
        int number = (now[i] - 48) + (answer[i] - 48);
        if (now[i] == '0' || answer[i] == '0')
            answer[i] = number + 48;
        else if (number == 2)
            answer[i] = '2';
        else if (number == 3)
            answer[i] = '4';
        else if (number == 4 || number == 5)
        {
            answer[i] = '1';
            result[i] = '1';
            checkedUp = true;
        }
        else if (number == 6)
        {
            answer[i] = '2';
            result[i] = '1';
            checkedUp = true;
        }
        else if (number == 8)
        {
            answer[i] = '4';
            result[i] = '1';
            checkedUp = true;
        }
    }

    if (checkedUp)
        answer = addString(result.substr(1), answer);
    return answer;
}

//#1
string solution(int n) {
    string answer = "";
    while (n) {
        string nowString = stringCountOne(n);
        answer = addString(answer, nowString);
        n = convertNext(n);
    }
    return answer;
}

//#2
/*
string solution(int n) {
    string answer = "";
    while (n) {
        int a = n % 3;
        n /= 3;
        if (a == 0)
            n -= 1;
    
        answer = "412"[a] + answer;
    }

    return answer;
}
*/
