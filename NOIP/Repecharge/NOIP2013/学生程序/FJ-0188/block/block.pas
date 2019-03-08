program block;

const
maxn=100000;
maxa=10000;

var
n,i,j,k,mins:0..maxn+2;
a:array[-0..maxn+3] of longint;
ans:int64;
minss:longint;
a0:boolean;

procedure work;
begin
  repeat
    while a[i+1]=0 do inc(i);
    j:=i+2;
    while a[j]<>0 do inc(j);
    for k:=i+1 to j-1 do
    begin
      if (a[k]<a[mins]) or (mins=0) then
      begin
         mins:=k;
         minss:=a[k];
      end;
    end;
    for k:=i+1 to j-1 do
      a[k]:=a[k]-minss;
    ans:=ans+minss;
    j:=mins;
    a0:=true;
    mins:=0;
    for k:=1 to n+2 do if a[k]<>0 then a0:=false;
  until a0;
end;

procedure getting;
begin
  assign(input,'block.in');
  reset(input);
  readln(n);
  for i:=2 to n+1 do read(a[i]);
  close(input);
end;

procedure gotting;
begin
  assign(output,'block.out');
  rewrite(output);
  writeln(ans);
  close(output);
end;

begin
  getting;
  i:=1;
  j:=2;
  work;
  gotting;
end.
