var
 ans,i,j,k,n,x:longint;
 a:array[1..10] of longint;

function fj(n,x:longint):longint;
 var
  i,j,y:longint;
 begin
  fj:=0;
  fillchar(a,sizeof(a),0);
  i:=0;
  while n>0 do
   begin
    inc(i);
    a[i]:=n mod 10;
    n:=n div 10;
   end;
  for j:=1 to i do
   if a[j]=x
    then
     inc(fj);
 end;

begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
 readln(n,x);
 for i:=1 to n do
  ans:=ans+fj(i,x);
 writeln(ans);
 close(input);
 close(output);
end.