#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int size = s.size();
    int min = size;
    int n = 1;
    while (n <= size / 2)
    {
        int now = size;
        int cost = 0;
        for (int i=0; i<size; i+=n)
        {
            string tmp = s.substr(i, n);
            
            if (i + n <= size)
            {
                int count = 1;
                while (!s.compare(i + n, n, tmp))
                {
                    cost += n;
                    count++;
                    i += n;
                }
                if (count != 1)
                {
                    string str_count = to_string(count);
                    cost -= str_count.size();
                }
            }
        }
        
        now -= cost;
        if (now < min)
            min = now;
        n++;
    }

    return min;
}
