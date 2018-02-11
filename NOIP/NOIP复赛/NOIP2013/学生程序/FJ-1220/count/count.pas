program ex;
  var i,n,t,x:longint;
  procedure count(a:longint);
    begin
     while a>0 do
      begin
       if a mod 10=x then inc(t);
       a:=a div 10;
      end;
    end;
  begin
   assign(input,'count.in');
   reset(input);
   assign(output,'count.out');
   rewrite(output);
   readln(n,x);
   t:=0;
   for i:=1 to n do
    count(i);
   write(t);
   close(input);
   close(output);
  end.