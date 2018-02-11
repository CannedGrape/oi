#include <cstdio>
#include <cstring>
#include <algorithm>

FILE* input, *output;
const int max_inf = 11111111;

class mset
{
    int elem[10010];
    int data[10010];
public:
	mset()
	{
        for(int i = 0; i != 10009; ++i)
        {
		    elem[i] = i;
		    data[i] = max_inf;
	    }
    }
    
    int find(int v)
    {
	    if(elem[v] == v) return v;
	    return elem[v] = find(elem[v]);
	}
	
	int get_data(int v)
	{
	 	return data[find(v)];
	}
	
	bool merge(int u, int v, int k)
	{
        if((u = find(u)) != (v = find(v)))
        {
             elem[u] = v;
             data[v] = k;
             return true;
        }
        return false;
    }
} ms;

struct _edge
{
    int from, to, w;
	
	bool operator < (const _edge& v) const
	{
	 	 return v.w < w;
    }
} edge[50010];

struct ques
{
    int from, to;
    int ans, index;
    
    bool operator < (const ques& v) const
    {
	 	 if(from == v.from) return to < v.to;
	 	 return from < v.from;
    }
} ask[30010];

int answer[30010];
int N, M, Q;
int ask_left;
int main()
{
 	input = std::fopen("truck.in", "r");
 	output = std::fopen("truck.out", "w");
 	
 	std::fscanf(input, "%d %d", &N, &M);
 	for(int i = 0; i != M; ++i)
 	{
        std::fscanf(input, "%d %d %d", 
		    &edge[i].from, &edge[i].to, &edge[i].w);
    }
    std::fscanf(input, "%d", &Q);
    for(int i = 0; i != Q; ++i)
    {
	 	std::fscanf(input, "%d %d", 
		    &ask[i].from, &ask[i].to);
		ask[i].index = i;
		ask[i].ans = max_inf;	
    }
//    std::sort(ask, ask + Q);
    std::sort(edge, edge + M);
	ask_left = Q;
 	
 	for(int i = 0; i != M && ask_left;)
 	{
		bool merge_succeed = false;
		int init_weight = edge[i].w;
		while(i != M && init_weight == edge[i].w)
		{
            if(ms.merge(edge[i].from, edge[i].to, edge[i].w))
			    merge_succeed = true;
			++i;	
		}
        if(merge_succeed)
        {
		 	for(int j = 0; j != ask_left; ++j)
		 	{
	 		    if(ask[j].ans == max_inf && 
				     ms.find(ask[j].from) == ms.find(ask[j].to))
	 		    {
				    ask[j].ans = ms.get_data(ms.find(ask[j].from));
				    std::swap(ask[--ask_left], ask[j--]);
				}
		    }
        }
    }
    
    for(int i = 0; i != Q; ++i)
	    answer[ask[i].index] = ask[i].ans;
	
	for(int i = 0; i != Q; ++i)
	{
	 	if(answer[i] == max_inf)
		    std::fprintf(output, "-1\n");
		else std::fprintf(output, "%d\n", answer[i]);	
	}
 	
 	std::fclose(output);
 	std::fclose(input);
 	return 0;
}
