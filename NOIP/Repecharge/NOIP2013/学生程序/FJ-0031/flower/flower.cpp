#include <cstdio>

int N;
int f[100010];

int main()
{
    FILE* input, *output;
    input = std::fopen("flower.in", "r");
    output = std::fopen("flower.out", "w");
    
    std::fscanf(input, "%d", &N);
    for(int i = 0; i != N; ++i)
        std::fscanf(input, "%d", f + i);
    
    int total = 0;
    for(int i = 2; i != N; ++i)
    {
        if(f[i] < f[i - 1] && f[i - 1] > f[i - 2]
          || f[i] > f[i - 1] && f[i - 1] < f[i - 2])
            ++total;
    }
    
    std::fprintf(output, "%d", total + 2);
    
    std::fclose(input);
    std::fclose(output);
    return 0;
}
