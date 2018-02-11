type
  ji=record
       t,f:longint;
     end;
var
  n,i,j,t,k2,k1:longint;
  a:array[1..100000]of longint;
  b:array[0..100000]of ji;
begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input); rewrite(output);
  readln(n);  t:=1;   b[0].t:=0; b[0].f:=0;
  for i:=1 to n do read(a[i]);
  b[1].t:=1; b[1].f:=1;
  for i:=2 to n do
    begin
      k1:=0; k2:=0;
      for j:=1 to i-1 do
        begin
          if(a[i]>a[j])and(b[j].t>b[k1].t) then k1:=j;
          if(a[i]<a[j])and(b[j].f>b[k2].f) then k2:=j;
        end;
      b[i].f:=b[k1].t+1;  b[i].t:=b[k2].f+1;
    end;
  for i:=2 to n do
    if b[i].t>t then t:=b[i].t
      else
        if b[i].f>t then t:=b[i].f;
  writeln(t);           close(input); close(output);
end.
