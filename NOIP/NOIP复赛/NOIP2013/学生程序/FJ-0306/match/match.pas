program ex_2;
var  a,b:array[0..100001]of longint;
     f,d:array[0..1]of longint;
     n,i,j,k,l1,l2,t,t1,t2,x1,x2,y1,y2,p,p1:longint;
function min(a,b:longint):longint;
begin
  if a<b then
  exit(a)
  else
  exit(b);
end;
begin
  assign(input,'match.in');reset(input);
  read(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  close(input);
  f[1]:=0;
  d[1]:=(a[1]-b[1])*(a[1]-b[1]);
  x1:=a[1];x2:=a[1];y1:=b[1];y2:=b[1];
  for i:=2 to n do
    begin
      l1:=i mod 2;
      l2:=1-l1;
      if ((a[i]-y2)*(a[i]-y2))+((x1-b[i])*(x1-b[i]))<
         ((x2-b[i])*(x2-b[i]))+((a[i]-y1)*(a[i]-y1)) then
           begin
             t:=((a[i]-y2)*(a[i]-y2))+((x1-b[i])*(x1-b[i]));
             p:=x1;
             p1:=y2;
           end
      else
           begin
             t:=((x2-b[i])*(x2-b[i]))+((a[i]-y1)*(a[i]-y1));
             p:=x2;
             p1:=y1;
           end;
      t1:=(a[i]-b[i])*(a[i]-b[i]);
      t2:=(p-p1)*(p-p1);
      if d[l2]-t2+t<d[l2]+t1 then
        begin
          x1:=a[i];y1:=b[i];
          x2:=p;y2:=p1;
          d[l1]:=d[l2]-t2+t;
          f[l1]:=f[l2]+1;
        end
      else
        begin
          x1:=a[i];y1:=b[i];
          x2:=a[i];y2:=b[i];
          d[l1]:=d[l2]+t1;
          f[l1]:=f[l2];
        end;
    end;
  l1:=n mod 2;
  assign(output,'match.out');rewrite(output);
  write(f[l1]);
  close(output);
end.
