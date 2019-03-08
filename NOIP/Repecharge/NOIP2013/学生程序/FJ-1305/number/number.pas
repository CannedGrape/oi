program number;
var
  i,j,n,p,ans:longint;
  num,spe,score:array[1..1000000] of longint;
function mo(a:longint):longint;
begin
  mo:=(a div abs(a))*(abs(a) mod p);
end;
function max:longint;
var
  a,ma,k:longint;
  flag:boolean;
begin
  k:=j-i+1;flag:=false;ma:=-maxlongint;
  repeat
    flag:=true;
    a:=0;
    if num[k]<0 then
      begin
        a:=num[k];
        k:=k+1;
        flag:=false;
      end;
    while flag and (num[k]>0) and (k<=j) do
      begin
        a:=a+num[k];
        k:=k+1;
      end;
    if a>ma then ma:=a;
  until k>=j;
  max:=ma;
end;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do
    begin
      read(num[i]);
      num[i]:=num[i];
    end;
  spe[1]:=num[1];
  for i:=2 to n do
    for j:=i to n do
  spe[j]:=max;
  score[1]:=spe[1];
  ans:=score[1];
  score[2]:=score[1]+spe[1];
  if score[2]>ans then ans:=score[2];
  for i:=3 to n do
    begin
      if spe[i-1]<0 then
        score[i]:=score[i-1]
      else
        score[i]:=score[i-1]+spe[i-1];
      if score[i]>ans then ans:=score[i];
    end;
  writeln(mo(ans));
  close(input);close(output);
end.