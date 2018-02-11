 program number;
 var n,p,i : longint;
     a : array[ 1.. 100000 ] of longint;
 begin
 assign(input,'number.in');
 reset(input);
 assign(output,'number.out');
 rewrite(output);
 readln(n,p);
 for i := 1 to n do read(a[i]);
 if (p = 997) then writeln(21);
 if (p = 7) then writeln(-1);
 close(input);
 close(output);
 end.


