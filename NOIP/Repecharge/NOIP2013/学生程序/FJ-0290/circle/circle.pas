Var n,m,k,x,ans:int64;
Function fastmi(s:int64):int64;
 var t:int64;
 begin
  if s=1 then exit(10);
  t:=fastmi(s div 2) mod n;
  if s mod 2=0 then fastmi:=t*t mod n
   else fastmi:=((t*t) mod n)*10 mod n;
 end;
Begin
        Assign(Input,'circle.in');Reset(Input);
        Assign(Output,'circle.out');Rewrite(Output);
 readln(n,m,k,x);
 ans:=((m*fastmi(k))mod n+x) mod n;
 writeln(ans);
        Close(Input);Close(Output);
End.
