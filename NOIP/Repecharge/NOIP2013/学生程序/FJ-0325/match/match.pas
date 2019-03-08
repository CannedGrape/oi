const q=99999997;
var a,b,z1,z2,d1,d2,num1,num2:array[0..100001]of int64;
    n,i,j,z,ans:longint;
procedure pai1(i,j:longint);
var l,r,x,temp:longint;
begin
  l:=i; r:=j;
  x:=z1[(i+j) shr 1];
  repeat
    while z1[l]<x do inc(l);
    while z1[r]>x do dec(r);
    if l<=r then
      begin
        temp:=z1[l]; z1[l]:=z1[r]; z1[r]:=temp;
        temp:=num1[l]; num1[l]:=num1[r]; num1[r]:=temp;
        inc(l); dec(r);
      end;
  until l>r;
  if l<j then pai1(l,j);
  if r>i then pai1(i,r);
end;

procedure pai2(i,j:longint);
var l,r,x,temp:longint;
begin
  l:=i; r:=j;
  x:=z2[(i+j) shr 1];
  repeat
    while z2[l]<x do inc(l);
    while z2[r]>x do dec(r);
    if l<=r then
      begin
        temp:=z2[l]; z2[l]:=z2[r]; z2[r]:=temp;
        temp:=num2[l]; num2[l]:=num2[r]; num2[r]:=temp;
        inc(l); dec(r);
      end;
  until l>r;
  if l<j then pai2(l,j);
  if r>i then pai2(i,r);
end;

begin
  assign(input,'match.in');  reset(input);
  assign(output,'match.out');  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;
  for i:=1 to n do read(b[i]);
  z1:=a;  z2:=b;
  for i:=1 to n do
    begin num1[i]:=i; num2[i]:=i; end;
  pai1(1,n);
  pai2(1,n);
  for i:=1 to n do
    begin
      d1[num1[i]]:=num2[i];
      d2[num2[i]]:=num1[i];
    end;
  ans:=0;
  for i:=1 to n do
    begin
      if d1[i]=i then continue;
      ans:=(ans+d1[i]-i)mod q;
      for j:=i to d1[i]-1 do inc(d1[d2[j]]);
      for j:=d1[i] downto i+1 do d2[j]:=d2[j-1];
      d2[i]:=i;
      d1[i]:=i;
    end;
  writeln(ans);
  close(input);  close(output);
end.
