Program mxpiii;
Var
   n,m,k,x:longint;
   p,i:longint;

Function f(a,b,n:int64):int64;
Var
   t,y:int64;
Begin
  t:=1; y:=a;
  while b<>0 do
    begin
      if (b and 1=1) then t:=t*y mod n;
      y:=y*y mod n;
      b:=b shr 1;
    end;
  exit(t);
End;

Begin
   assign(input,'circle.in');
   assign(output,'circle.out');
   reset(input);
   rewrite(output);
   readln(n,m,k,x);
   p:=f(10,k,n);
   for i:=1 to p do
     x:=(x+m+n) mod n;
   writeln(x);
   close(input);
   close(output);
End.
