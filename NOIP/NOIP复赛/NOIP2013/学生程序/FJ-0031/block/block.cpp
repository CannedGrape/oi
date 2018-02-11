#include <cstdio>

int seq[100010];
int main()
{
    int N;
    FILE* input, *output;
    input = std::fopen("block.in", "r");
    std::fscanf(input, "%d", &N);
    for(int i = 0; i != N; ++i)
        std::fscanf(input, "%d", seq + i);
    std::fclose(input);
    
    for(int i = N - 1; i != 0; --i)
        seq[i] -= seq[i - 1];
        
    int answer = 0;
    for(int i = 0; i != N; ++i)
        if(seq[i] > 0) answer += seq[i];
    
    output = std::fopen("block.out", "w");
    std::fprintf(output, "%d", answer);
    std::fclose(output);
    return 0;
}
