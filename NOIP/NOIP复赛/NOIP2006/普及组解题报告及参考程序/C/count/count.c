#include<stdio.h>
int smallest,biggest,length;
//smallest最小的数，biggest最大的数，length长度 
int getnextone(char *a,int len)//获取下一个jam数字的函数
//返回1为成功
//返回0为失败 
{
  int i,j; 
  if(a[len-1]-'a'+1<biggest)//如果最后一位还没达到最大，那么最后一位+1 就是下一个数 
      {
        a[len-1]++;
        return 1;                 
      }
  for(i=len-2;i>=0;i--)
      if (a[i]<a[i+1]-1)
//如果前一位与后一位相差大于1，那么下一个数字就是前一位+1 
//不明白的可以推一下 
//原始是 if (a[i]-'a'<a[i+1]-'a'-1)
//但可以看出，两边都减了一'a' ，所以优化成上面的式子 
         {
            a[i]++;//已经找到这一位了 
            for (j=i+1;j<length;j++)
              a[j]=a[j-1]+1;
/****************************************************
   因为这个序列是递增的， 所以后面的数都是前面的数+1
   所以就有了上面的这个语句 
*****************************************************/
			  
//这可是直接在原来的jam数字上改，节省了空间 
            return 1;
         }          
  return 0;
//如果在 上面那个for语句一直没有return 1说明 一直都没找到那个数
//所以就没有了。return 0; 
}



int main ()
{
    FILE *in=fopen("count.in","r");
    FILE *out=fopen("count.out","w");

    char jam[30];//记录jam数字的数组，开多点不要紧 
    int i;
    fscanf(in,"%d %d %d",&smallest,&biggest,&length);
    fscanf(in,"%s",jam);
    fclose(in);
    for(i=0;i<5;i++)
      {
          if(!getnextone(jam,length))//如果函数返回0就说明后面没有了，直接退出 
            break;
          else fprintf(out,"%s\n",jam);//否则输出这个jam数字 
      }
    fclose(out);
    return 0;
}
