#include <fstream.h>
#include <string.h>

ifstream Fin("hut.in");
ofstream Fou("hut.out");

const int MaxN = 100 + 10;

long double k1,k2;
int m,n;

long double opt2[MaxN][MaxN], opt1[MaxN][MaxN][MaxN];
long double area1[MaxN], area2[MaxN];
char split[MaxN][MaxN][MaxN][2];

void Init()  {
     Fin>>k1>>k2>>n>>m;
     for (int i=0; i<=100; i++) area1[i] = k1*i*i, area2[i] = k2*i*i;
}

void answer(int i, int j, int k)  {
     if (i==0) return;
     int l = split[i][j][k][0], w = split[i][j][k][1];
     Fou<<"interval ("<<l<<"-"<<i<<") with "<<k-w<<" subblocks\n";
     answer(l,j-1,w);
}

void Doit()  {
     int i,j,k,l,w;

     for (i=0; i<MaxN; i++) for (j=0; j<MaxN; j++) opt2[i][j] = 1e100;
     memset(opt2[0], 0, sizeof(opt2[0]));
     for (i=1; i<=100; i++)
         for (j=1; j<=m; j++)
             for (k=i-1; k>=0; k--)
                 opt2[i][j] <?= opt2[k][j-1]+area2[i-k];
     for (i=0; i<MaxN; i++) for (j=0; j<MaxN; j++) for (k=0; k<MaxN; k++)
         opt1[i][j][k] = 1e100;
     memset(opt1[0], 0, sizeof(opt1[0]));
     for (i=1; i<=100; i++)
         for (j=1; j<=n; j++)  {
             int low = j, high = m;
             low >?= m*i/100-4;
             high <?= m*i/100+4;
             for (k=low; k<=high; k++)  {
                 for (l=i-1; l>=0; l--)  {
                     int low = j-1, high = k-1;
                     low >?= m*l/100-1;
                     high <?= m*l/100+2;
                     for (w=high; w>=low; w--)  {
                         if (opt1[l][j-1][w] + area1[i-l] + opt2[i-l][k-w] < opt1[i][j][k] ) {
                            opt1[i][j][k] = opt1[l][j-1][w] + area1[i-l] + opt2[i-l][k-w];
//                            split[i][j][k][0] = l;
//                            split[i][j][k][1] = w;
                         }
                     }
                 }
             }
         }
     Fou.setf(ios::fixed);
     Fou.precision(1);
     Fou<<opt1[100][n][m]<<endl;
//     answer(100,n,m);
}

int main()  {
    Init();
    Doit();
    return 0;
}


