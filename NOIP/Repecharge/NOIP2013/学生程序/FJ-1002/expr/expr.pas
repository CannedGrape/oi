program expr;
  var s,num,opa:ansistring;
      a:array[1..100001]of longint;
      p1,p2:longint;
      t,i,j,count:longint;

function min(a,b:longint):longint;
begin
  if a<b then min:=a else min:=b;
end;

procedure changefour(var num:ansistring);
begin
  if length(num)<4 then
    while length(num)<4 do
      num:='0'+num;
  if length(num)>4 then
    num:=copy(num,length(num)-3,4);
end;

function changenum(num:ansistring):longint;
  var ans:longint;
      k:longint;
begin
  ans:=0;
  for k:=1 to 4 do
    ans:=ans*10+ord(num[k])-ord('0');
  changenum:=ans;
end;

begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  t:=0;
  p1:=pos('+',s);
  p2:=pos('*',s);
  if p1=0 then p1:=maxlongint;
  if p2=0 then p2:=maxlongint;
  num:=copy(s,1,min(p1,p2)-1);
  changefour(num);
  t:=t+1;
  a[t]:=changenum(num);
  delete(s,1,min(p1,p2)-1);
  while s<>'' do
    begin
      opa:=copy(s,1,1);
      delete(s,1,1);
      p1:=pos('+',s);
      p2:=pos('*',s);
      if p1=0 then p1:=maxlongint;
      if p2=0 then p2:=maxlongint;
      num:=copy(s,1,min(p1,p2)-1);
      changefour(num);
      if opa='+' then
        begin
          t:=t+1;
          a[t]:=changenum(num);
        end;
      if opa='*' then
        a[t]:=a[t]*changenum(num) mod 10000;
      delete(s,1,min(p1,p2)-1);
    end;
  count:=0;
  for i:=1 to t do
    count:=count+a[i];
  count:=count mod 10000;
  writeln(count);
  close(input);
  close(output);
end.
