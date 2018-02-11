program count;
var x,b:integer;
    n,m,i:longint;
    s,a:string;


begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  str(x,a);
  for i:=1 to n do
    begin
      str(i,s);


        for b:=1 to 7  do
        if  a=s[b] then
          m:=m+1;
        end;
      write(m);
      close(input);
      close(output);
end.

