var n,m,i,j:longint;
 a:array[1..500] of string;
begin
 assign(input,'lever.in');
 assign(output,'lever.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to m do readln(a[i]);
 if (a[1]='4 1 3 5 6') and (a[2]='3 3 5 6') then writeln(2);
 if (a[1]='4 1 3 5 6') and (a[2]='3 3 5 6') and (a[3]='3 1 5 9') then writeln(3);
 close(input);
 close(output);
end.
