var t,num,f:array[1..1000000]of int64;
    s:array[1..1000000]of int64;
    i,j,k,n,p:longint;
    best,m,b:int64;
    bo:boolean;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);

  readln(n,p);
  for i:=1 to n do read(num[i]);
  fillchar(t,sizeof(t),0);
  t[1]:=num[1];
  s[1]:=num[1];
  for i:=2 to n do s[i]:=num[i]+s[i-1];
  for i:=2 to n do
   begin
   if s[i]>t[i-1] then t[i]:=s[i] else t[i]:=t[i-1];
   for k:=1 to i-1 do
    begin
     s[i]:=s[i]-num[k];
     if s[i]>t[i] then t[i]:=s[i];
    end;
   end;
  f[1]:=t[1];
  b:=-10000000005;
  for i:=2 to n do
   begin
     best:=-10000000000;
     for j:=1 to i-1 do
        if f[j]+t[j]>best then best:=f[j]+t[j];
     f[i]:=best;
     if best>b then b:=best;
   end;
  if f[1]>b then b:=f[1];
  if (b<0) then write('-');
  writeln(abs(b) mod p);

  close(input);
  close(output);
end.

