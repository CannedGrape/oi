var
 n,x,i,j,k:longint;
 s,s1:string;
begin
 assign(input,'count.in');
 reset(input);
 readln(n,x);
 close(input);
 assign(output,'count.out');
 rewrite(output);
 str(x,s);
 for i:=1 to n do
  begin
   str(i,s1);
   for j:=1 to length(s1) do
    if s1[j]=s then
     k:=k+1;
  end;
 writeln(k);
 close(output);
end.
