#include<stack>
#include<cstdio>
#include<cstdlib>
#include<iostream>

//#define DEBUG

using namespace std;

stack<unsigned int> s;

int main() {
	#ifndef DEBUG
		freopen("expr.in", "r", stdin);
		freopen("expr.out", "w", stdout);
		ios::sync_with_stdio(false);
	#endif
	char c;
	bool flag=false;
	unsigned long long n=0, t=0;
	while(c=getchar()) {
		if((c=='\n') || (c=='\0') || (c==-1)) break;
		if((c >= '0') && (c <= '9')) {
			n*=10; n+= (c-48); n%=10000;
		} else {	
			if(flag) {
				t = s.top();
				s.pop();
				t %= 10000;
				n *= t;
				n %= 10000;
				if(c=='+') flag = false;
			}
			s.push(n);	n = 0;
			if(c=='*') {
				flag = true;
			}
		}
	}
	if(flag) {
		t = s.top();
		s.pop();
		t %= 10000;
		n *= t;
		n %= 10000;
		if(c=='+') flag = false;
	}
	s.push(n); n=0;
	unsigned int ans=0;
	while(s.size()!=0) {
		ans += s.top();
		s.pop();
		ans %= 10000;
	}
	cout << ans << endl;
	#ifndef DEBUG
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
} 
