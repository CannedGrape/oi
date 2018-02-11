#include<fstream>
#include<iostream>
using namespace std;
int smallest,biggest,length;

int getnextone(char *a,int len)
{
  if(a[0]-'a'+1==biggest) 
      return 0;
  if(a[len-1]-'a'+1<biggest)
      {
        a[len-1]++;
        return 1;                 
      }
  for(int i=len-2;i>=0;i--)
      if (a[i]-'a'<a[i+1]-'a'-1)  //根据位置确定最大值与最小值
         {
            a[i]++;
            for (int j=i+1;j<length;j++)
              a[j]=a[j-1]+1;
            return 1;
         }          
  return 1;
  
}



int main ()
{
    ifstream in("count.in");
    ofstream out ("count.out");

    char jam[30];
    in >> smallest >> biggest >> length;
    in >> jam;
    in.close();
    for(int i=0;i<5;i++)
      {
          if(!getnextone(jam,length))
            break;
          else out << jam << endl;
      }
    out.close();
    return 0;
}
