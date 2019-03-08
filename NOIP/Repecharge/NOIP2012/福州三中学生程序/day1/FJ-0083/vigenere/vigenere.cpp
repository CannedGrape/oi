#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;
int keyborad[26][26];
char key[111]; int keylen=0;
char wrd[1111];int wlen=0;
int main()
{
	freopen("vigenere.in","r",stdin);
	freopen("vigenere.out","w",stdout);
	for (int i = 0;i < 26 ; i++)
		for (int j = 0; j < 26 ; j++)
			keyborad[i][j]=(j+i)%26;
	scanf("%s",key+0);keylen=strlen(key);
	scanf("%s",wrd+0);wlen=strlen(wrd);
	for (int i=0;i<keylen;i++)
	{
		bool big=(key[i]>='A'&&key[i]<='Z');
		key[i]-=big?'A':'a';
	}
	for (int i=0,j=0;i<wlen;i++,j++,j%=keylen)
	{
		bool big=(wrd[i]>='A'&&wrd[i]<='Z');
		wrd[i]-=big?'A':'a';
		for (int ii=0;ii<26;ii++) 
			if (keyborad[key[j]][ii]==wrd[i]){wrd[i]=ii;break;}
		wrd[i]+=big?'A':'a';
	}
	printf("%s\n",wrd);
	return 0;
}
