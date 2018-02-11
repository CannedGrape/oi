var n,x,max,a,i:longint;
    s,c,y:string;
begin
 assign(input,'count.in'); reset(input);
 assign(output,'count.out');rewrite(output);
 readln(n,x);
 str(x,y);
 max:=0;
 for i:=1 to n do
  begin
  str(i,c);
  s:=s+c;
  end;
 for i:=1 to length(s) do
  if s[i]=y   then max:=max+1;
 writeln(max);
 close(input);close(output);
end.
