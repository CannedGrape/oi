var
  n,m,i,ans,j:longint;  ss,s:string;
begin
 assign(input,'count.in'); reset(input);
 assign(output,'count.out'); rewrite(output);
 readln(m,n);
 str(n,ss);
 for i:=1 to m do
 begin
   str(i,s);
   for j:=1 to length(s) do
     if s[j]=ss then
       inc(ans);
   s:='';
 end;
 writeln(ans);
  close(input); close(output);
end.
