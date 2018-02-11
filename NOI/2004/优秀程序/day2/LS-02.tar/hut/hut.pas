program hut;
var
  f:text;
  k1,k2,tr:real;
  i,j,k,l,m,n,p,t:longint;
  res:array[1..100,1..100,1..100] of real;

begin
  assign(f,'hut.in');
  reset(f);
  readln(f,k1,k2,m,n);
  close(f);

  fillchar(res,sizeof(res),0);
  for i:=1 to 100 do
    for j:=trunc((i/100)*m)-5 to trunc((i/100)*m)+7 do
      if (j<=i) and (j>=1) and (j<=m) then
        for k:=trunc((i/100)*n)-5 to trunc((i/100)*n)+7 do
          if (k>=j) and (k<=n) then
            if j=1 then
            begin
              t:=i mod k;
              res[i,j,k]:=sqr(i)*k1+sqr(i div k)*k2*(k-t)+sqr(i div k+1)*k2*t;
            end
            else
            begin
              res[i,j,k]:=1e100;
              for l:=trunc((j-1)/m*100)-5 to i-trunc(100/m)+7 do
                if (l<i) and (l>0) then
                  for p:=trunc(n/m)-5 to trunc(n/m)+7 do
                    if (p>0) and (p<k) then
                      if res[l,j-1,k-p]>0 then
                      begin
                        t:=(i-l) mod p;
                        tr:=res[l,j-1,k-p]+sqr(i-l)*k1+sqr((i-l) div p)*k2*(p-t)+sqr((i-l) div p+1)*k2*t;
                        if tr<res[i,j,k] then res[i,j,k]:=tr;
                      end;
            end;

  assign(f,'hut.out');
  rewrite(f);
  writeln(f,res[100,m,n]:0:1);
  close(f);
end.
