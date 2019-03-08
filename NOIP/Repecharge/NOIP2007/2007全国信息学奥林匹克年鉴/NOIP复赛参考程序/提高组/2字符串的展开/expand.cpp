#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define print(c) for(int k = 0; k < p2; k++) printf("%c", (c))
using namespace std;
int p1, p2, p3;

char s[1000];
int main(){
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  scanf("%d%d%d%s", &p1, &p2, &p3, s);
  int len = strlen(s);
  for(int i = 0; i < len; i++)
    if(s[i] != '-') printf("%c", s[i]);
    else {
      if(i == 0 || i == len-1 || s[i-1] >= s[i+1]) { printf("-"); continue; }
      if((isalpha(s[i-1]) && isalpha(s[i+1])) || (isdigit(s[i-1]) && isdigit(s[i+1]))) {
        if(p1 == 3)
          for(int j = 0; j < s[i+1]-s[i-1]-1; j++) print('*');
        else if(p3 == 1)
          for(int c = s[i-1]+1; c < s[i+1]; c++) print(p1 == 1 ? c : toupper(c));
        else
          for(int c = s[i+1]-1; c > s[i-1]; c--) print(p1 == 1 ? c : toupper(c));
      }
	  else printf("-");
    }
  return 0;
}
