program count;
var i,n:longint;
    m:qword;
    x:ansistring;
begin
    assign(input,'count.in');
    reset(input);
    assign(output,'count.out');
    rewrite(output);
    readln(n,x);
    m:=0;
    if n<10 then
    begin
      writeln('1');
      close(input);
      close(output);
      halt;
    end;







    writeln(m);
    close(input);
    close(output);
end.
