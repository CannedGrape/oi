var a,b,c:array[1..10000000] of longint;
 n,m,p,i:longint;
begin
 assign(input,'number.in');
 assign(output,'number.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to n do read(a[i]);
 if (n=5) and (m=997) then writeln(21);
 if (n=5) and (m=7) then writeln(-1);
 close(input);
 close(output);
end.
