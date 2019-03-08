 var s:string;
     c:char;
     i,j,tot,n:longint;
     x:integer;
 begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
  readln(n,x);  c:=chr(x+48); tot:=0;
  for i:=1 to n do begin
   str(i,s);
   for j:=1 to length(s) do
    if s[j]=c then inc(tot);
  end;

  writeln(tot);
  close(input);close(output);
  end.