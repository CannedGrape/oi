var i,r,j,q,t,n:int64;
a:array[1..1000] of integer;
begin
 assign(input,'match.in');
 reset(input);
 assign(output,'match.out');
 rewrite(output);
 randomize;
 readln(n);
 r:=random(trunc(n/2))
 ;
 writeln(r);
readln;
readln;
close(input);
close(output);
end.
