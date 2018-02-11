program number;

const MAXN=100000000;

var
 sum,num,score,tz:array[0..MAXN]of longint;
 i,j,k,max,n,p:longint;

begin
 //max:=-maxlongint;
 assign(input,'number.in'); reset(input);
 assign(output,'number.out');rewrite(output);
 readln(n,p);
 for i:=1 to n do tz[i]:=-maxlongint;
 for i:=1 to n do score[i]:=-maxlongint;
 for i:=1 to n do read(num[i]);
 for i:=1 to n do inc(sum[i],sum[i-1]+num[i]);
 for i:=1 to n do
 begin
  for j:=1 to i do
   for k:=j to i do
    if sum[k]-sum[j-1]>tz[i] then tz[i]:=sum[k]-sum[j-1];
 end;
 score[1]:=tz[1];
 max:=score[1];
 for i:=2 to n do
 begin
  for j:=1 to i-1 do
  begin
   if tz[j]+score[j]>score[i] then score[i]:=tz[j]+score[j];
  end;
  if score[i]>max then max:=score[i];
 end;
 if max<0 then write('-');
 writeln(abs(max) mod p);
 close(input); close(output);
end.
