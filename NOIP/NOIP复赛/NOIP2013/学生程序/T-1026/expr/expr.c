#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  
char str[1110000], sum[20], st[20], tem[20]; 

int main(void){
	int pos = -1, sta = 0, temp = 0, k = 0, j = 0;
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	scanf("%s", str);
	temp = strlen(str); 
	str[temp++] = '+';
	str[temp] = 0;
	sum[0] = '0';
	sum[1] = '0';
	sum[2] = '0';
	sum[3] = '0'; 
	st[0] = '0';
	st[1] = '0';
	st[2] = '0';
	st[3] = '0';
	tem[0] = '0';
	tem[1] = '0';
	tem[2] = '0';
	tem[3] = '0';
	for(k = 0; k < strlen(str); k++){
		if(str[k] == '+'){
			if(sta){
				temp = (tem[pos] - '0');
				if(pos > 0){
					temp += (tem[pos - 1] - '0') * 10;
				}
				if(pos > 1){
					temp += (tem[pos - 2] - '0') * 100;
				}
				if(pos > 2){
					temp += (tem[pos - 3] - '0') * 1000;
				}
				temp *= (st[0] - '0') + (st[1] - '0') * 10 + (st[2] - '0') * 100 + (st[3] - '0') * 1000;
				tem[3] = temp / 1000 % 10 + '0';
				tem[2] = temp / 100 % 10 + '0';
				tem[1] = temp / 10 % 10 + '0';
				tem[0] = temp % 10 + '0';
			}
			temp = (sum[0] - '0') + (sum[1] - '0') * 10 + (sum[2] - '0') * 100 + (sum[3] - '0') * 1000;
			temp += (tem[0] - '0');
			temp += (tem[1] - '0') * 10;
			temp += (tem[2] - '0') * 100;
			temp += (tem[3] - '0') * 1000;
			sum[3] = temp / 1000 % 10 + '0';
			sum[2] = temp / 100 % 10 + '0';
			sum[1] = temp / 10 % 10 + '0';
			sum[0] = temp % 10 + '0';
			for(j = 0; j <= pos; j++){
				tem[j] = '0';
			}
			sta = 0;
			pos = -1;
		}else if(str[k] == '*'){
			if(sta){
				temp = (tem[pos] - '0');
				if(pos > 0){
					temp += (tem[pos - 1] - '0') * 10;
				}
				if(pos > 1){
					temp += (tem[pos - 2] - '0') * 100;
				}
				if(pos > 2){
					temp += (tem[pos - 3] - '0') * 1000;
				}
				temp *= (st[0] - '0') + (st[1] - '0') * 10 + (st[2] - '0') * 100 + (st[3] - '0') * 1000;
				st[3] = temp / 1000 % 10 + '0';
				st[2] = temp / 100 % 10 + '0';
				st[1] = temp / 10 % 10 + '0';
				st[0] = temp % 10 + '0';
			}else{
				if(pos > 2){
					st[3] = tem[pos - 3];
				}
				if(pos > 1){
					st[2] = tem[pos - 2];
				}
				if(pos > 0){
					st[1] = tem[pos - 1];
				}
				st[0] = tem[pos];
			}
			sta = 1;
			pos = -1;
		}else{
			tem[++pos] = str[k]; 
		}
	}
	temp = (sum[0] - '0') + (sum[1] - '0') * 10 + (sum[2] - '0') * 100 + (sum[3] - '0') * 1000;
	printf("%d", temp);
	return 0;
}

