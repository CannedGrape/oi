uses math;
var
  n,x:longint;
function pp(a,b:longint):longint;
var i:longint;
begin
  pp:=1;
  for i:=1 to b do pp:=pp*a;
end;
function hhhhh(hh:longint):longint;
var i,j,k:longint;
begin
  j:=0;k:=1;
  for i:=1 to hh-2 do begin j:=j+k;k:=k*10;end;
  hhhhh:=j;
end;
function aa(m:longint):longint;
begin
  if m=1 then aa:=0
  else
   aa:=((n div pp(10,m-1))mod 10)*pp(10,m-2)+aa(m-1);
end;

function a(m:longint):longint;
var hehe:longint;
begin
  hehe:=(n div pp(10,m-1))mod 10;
  if m=1 then if hehe<x then a:=0 else a:=1
  else
   if hehe<x then a:=hehe*pp(10,m-2)+a(m-1)
    else
     if hehe=x then a:=hehe*pp(10,m-2)+a(m-1)+(n mod pp(10,m-1))+1
      else a:=hehe*pp(10,m-2)+a(m-1)+pp(10,m-1);
end;
begin
  assign(input,'count.in');assign(output,'count.out');
  reset(input);rewrite(output);
  readln(n,x);
  if n=0 then writeln('0')
  else
  if x=0 then writeln(aa(trunc(log10(n))+1)+hhhhh(trunc(log10(n))+1))
  else
   writeln(a(trunc(log10(n))+1));
  close(input);close(output);
end.                                   