#include <string>
#include <vector>
using namespace std;

int solution(string name) {
    string tmp = name + name;
    int min = 0;
    int checkA = 0;
    for (int i = 0; i < name.size(); ++i) {
        if (i != 0 && name[i] == 'A') {
            checkA++;
            continue;
        }
        else if (name[i] != 'A') {
            min += checkA;
            checkA = 0;
        }
        
        char now = name[i] - 'A';
        if (now >= 13) now = 26 - now;
        min += now;
        if (i != 0) min++; 
    }

    for (int i = 0; i < name.size(); ++i) {
        int count = i;
        checkA = 0;
        for (int j = i + name.size(); j > i; --j) {
            if (j != i + name.size() && tmp[j] == 'A') {
                checkA++;
                continue;
            }
            else if (tmp[j] != 'A') {
                count += checkA;
                checkA = 0;
            }

            char now = tmp[j] - 'A';
            if (now >= 13) now = 26 - now;
            count += now;
            if (j != i + name.size()) count++;
        }
      
        if (min > count) min = count;
    }
    
    return min;
}
