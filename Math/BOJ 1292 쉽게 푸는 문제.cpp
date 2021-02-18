#include <ios>
#include <vector>

int main()
{
    int a, b, ret = 0;
    scanf("%d %d", &a, &b);
    
    std::vector<int> arr;
    for (int i = 1; arr.size() < 1001; ++i)
        for (int j = 0; j < i; ++j)
            arr.push_back(i);
    
    for (int i = a; i <= b; ++i)
        ret += arr[i - 1];
    
    printf("%d", ret);
}
