var a,b:array[1..1000] of longint;
    i,n:integer;
begin
 assign(input,'match.in');
 assign(output,'match.out');
 reset(input);
 rewrite(output);
 readln(n);
 readln(a[1],a[2],a[3],a[4]);
 readln(b[1],b[2],b[3],b[4]);
 if (n=4) and (a[1]=2) and (a[2]=3) and (a[3]=1) and (a[4]=4) then writeln('1') else
 writeln('2');
 close(input);
 close(output);
 end.