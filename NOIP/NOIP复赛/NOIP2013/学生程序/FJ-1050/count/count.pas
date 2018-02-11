var n,x,i,j,k,p:longint;
    ans:int64;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  n:=0; x:=0; ans:=0;
  readln(n,x);
  i:=1;
  for i:=1 to n do
   begin
    p:=i;
    while (p>0) do
     begin
       k:=(p mod 10);
       p:=(p div 10);
       if (k=x) then ans:=ans+1;
     end;
   end;
  writeln(ans);
  close(input);
  close(output);
end.

