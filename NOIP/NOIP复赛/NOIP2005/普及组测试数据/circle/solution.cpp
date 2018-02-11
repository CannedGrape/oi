#include <iostream>
#include <cassert>
#include <cstring>
#include <cctype>

using namespace std;

const int LEN=100;

struct bigint{
        int num[LEN];
        bigint(){
			memset(num, 0, sizeof(num));
        }
        bigint(const bigint& a){
                int i;
                for(i=0;i<LEN;i++)
                        num[i]=a.num[i];
        }
        bigint(int a) {
			memset(num, 0, sizeof(num));
			assert(a > 0);
			int i = 0;
			while(a > 0) {
				num[i] = a % 10;
				i++;
				a = a / 10;
			}
		}
        bigint(const char* str){
			int i, j;
			for (i = 0; str[i] != 0; i++) {
				assert(isdigit(str[i]));
			}
			assert(str[0] != '0' && i <= LEN);
			memset(num, 0, sizeof(num));
			for (j = i - 1; j >= 0 ; j--)
				num[j] = str[i - 1 - j] - '0';
        }

        bigint& operator=(const bigint& a){
				int i;
                for(i=0;i<LEN;i++)
                        num[i]=a.num[i];
                return *this;
        }

        bigint operator+(const bigint& b) const{
			bigint result;
			int tot;
			int i;
			int add = 0;
			for(i=0;i<LEN;i++){
				tot = num[i] + b.num[i] + add;
				result.num[i] = tot % 10;
				add = tot / 10;
			}
			return result;
		}

		bigint operator*(const bigint& b) const{
			bigint result;
			int i, j, tot, add;
		    for(i=0;i<LEN;i++){
		        if(b.num[i]==0)continue;
		        add=0;
		        for(j=0;i + j < LEN;j++){
		            tot=result.num[i+j]+num[j]*b.num[i]+add;
		            result.num[i+j]=tot%10;
		            add=tot/10;
		        }
		    }
			return result;
		}

		int getNum(int k) const{
			return num[k - 1];
		}

		void output(int k) const {
			int i;
			for (i = k - 1; i >=0; i--) cout << num[i];
		}
};

ostream& operator<<(ostream& out,const bigint& a){
    int i; bool flag = false;
    for(i=LEN-1;i>=0;i--) {
    	if (!flag) {
			if (a.num[i] != 0) flag = true;
		}
		if (flag) {
			cout << a.num[i];
		}
	}
    return out;
}

int main () {
	char buffer[1024];
	int used[10];
	int kk;
	cin >> buffer >> kk;
	bigint base(buffer);
	assert(1 <= kk && kk <= LEN);

	{char c; assert(!(cin >> c));}

	int i, j;
	bigint result(1);
	bigint multi = base;
	for (i = 1; i <= kk; i++) {
		memset(used, 0, sizeof(used));
		int p = base.getNum(i);
		used[p] = 1;
		int mm = 1;
		bigint now = base;

		//cout << "--------------" << endl;

		while(1) {

			//now.output(i); cout << endl;

			bigint then = now * multi;
			int q = then.getNum(i);
			if (!used[q]) {
				used[q] = 1;
				now = then;
				mm++;
			}
			else if (q != p) {
				cout << -1 << endl;
				return 0;
			}
			else break;
		}

		//cout << "--------------" << endl;

		result = result * bigint(mm);

		bigint temp(1);
		for (j = 0; j < mm; j++) {
			temp = temp * multi;
		}
		multi = temp;
	}
	cout << result << endl;

	return 0;
}
