Program number;
var  i,j,n,p,x,max:integer;
  a,score,feature:array[1..1000]of integer;
procedure fi(var i:integer);
begin
  if (a[i]+a[i+1])<0 then
  begin
    i:=i+2;
    if i<j do fi(i);
  end;
end;
procedure fj(var j:integer);
begin
  if (a[j]+a[j-1])<0 then
  begin
    j:=j-2;
    if j>i do fj(j);
  end;
end;
function num(k:integer)of integer;
var p,sum:integer;
begin
  sum:=a[1];
  for i:=1 to k do if sum<a[i] then sum:=a[i];
  if sum<0 then exit(sum);
  i:=1;
  while a[i]<0 do inc(i);
  j:=n;
  while a[n]<0 do dec(j);
  fi(i);fi(j);
  num:=0;
  for p:=i to j do num:=num+a[p];
end;

begin
  assign(input,'number.in');  reset(input);
  assigh(output,'number,out');  rewrite(output);
  readln(n,p);
  for x:=1 to n do readln(a[x]);
  score[1]:=a[1]; feature[1]:=score[1];
  for x:=2 to n do score[x]:=num(x);
  max:=score[1];
  for x:=3 to n do
  begin
    if max<feature[x-1]+score[x-1] then max:=feature[x-1]+score[x-1];
    score[x]:=max;
  end;
  for x:=1 to n do if max<score[x] then max:=score[x];
  if max<0 then write('-');
  max:=abs(max);
  writeln(max mod q);
  close(input);
  close(output);
end.




