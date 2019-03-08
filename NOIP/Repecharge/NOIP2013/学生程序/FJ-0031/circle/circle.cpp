#include <fstream>

std::ifstream ifs("circle.in");
std::ofstream ofs("circle.out");
long long n, m, k, x;

long long power()
{
    long long base = 10;
    long long result = 1;
    while(k)
    {
        if(k & 1) result = result * base % n;
        base = base * base % n;
        k >>= 1;
    }
    return result;
}
   
int main()
{
    ifs >> n >> m >> k >> x;
    long long result = power();
    ofs << (m * result + x) % n << std::endl;
    return 0;
}
