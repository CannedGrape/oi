var n,x,i,j,ans:longint;
    s,st:string;
//=======================
 begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
 read(n,x);
 str(x,st);
  for i:=1 to n do
   begin
    str(i,s);
    for j:=1 to length(s) do
    if s[j]=st then inc(ans);
   end;
  writeln(ans);
  close(input);close(output);
 end.