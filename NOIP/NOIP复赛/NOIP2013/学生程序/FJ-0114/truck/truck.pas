program truck(input,output);
var
maxint,q,n,m,i,j,k,m1,m2,m3,q1,q2:longint;
a:array[1..10000,1..10000] of longint;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);
  maxint:=999999;
  read(n,m);
  for i:=1 to n do
    for j:=1 to n do
        a[i,j]:=maxint;
  for i:=1 to m do
    begin
      read(m1,m2,m3);
      if m3<a[m1,m2] then
        begin
          a[m1,m2]:=m3;
          a[m2,m1]:=m3;
        end;
    end;
  read(q);
  for i:=1 to q do
    begin
      read(q1,q2);
      for j:=1 to n do
        for k:=1 to n do
          if ((a[q1,k]<>maxint) and (a[k,q2]<>maxint)) then
            if ((a[q1,k]>a[q1,q2]) and (a[k,q2]>a[q1,q2])) then
              if a[q1,k]>a[k,q2] then a[q1,q2]:=a[k,q2] else
                a[q1,q2]:=a[q1,k];
        if a[q1,q2]=maxint then a[q1,q2]:=-1;
      writeln(a[q1,q2]);
    end;
  close(input);
  close(output);
end.


