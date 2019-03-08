#include <cstdio>
#include <algorithm>

FILE* input, *output;
int da[100010], db[100010];
int sa[100010], sb[100010];
int dest[100010];
int N;
const int mod_const = 99999997;

bool sort_a(int a, int b)
{
 	 return da[a] < da[b]; 	 
}

bool sort_b(int a, int b)
{
 	 return db[a] < db[b]; 	 
}

int main()
{
 	input = std::fopen("match.in", "r");
 	output = std::fopen("match.out", "w");
 	
 	std::fscanf(input, "%d", &N);
 	for(int i = 0; i != N; ++i)
 	{
        sa[i] = i;
        std::fscanf(input, "%d", da + i);
    }
 	for(int i = 0; i != N; ++i)
 	{
		sb[i] = i;
        std::fscanf(input, "%d", db + i);
    }
    std::sort(sa, sa + N, sort_a);
    std::sort(sb, sb + N, sort_b);
    for(int i = 0; i != N; ++i)
		dest[sb[i]] = sa[i]; 	
    
    int step = 0;
    for(int i = 0; i != N; ++i)
    {
	    step = (step + dest[i] - i) % mod_const;
	    for(int k = 0; k != N; ++k)
	    {
	 		if(dest[k] >= i && dest[k] < dest[i])
	   		    ++dest[k];
		}
		dest[i] = i;
    }
    
    std::fprintf(output, "%d\n", step);
    
 	std::fclose(output);
 	std::fclose(input);
 	return 0;
}
