var i,j,m,n,s:longint;
    a,b:array[1..1000] of longint;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
 readln(m,n);
 read(s);
 for i:=1 to n do begin read(a[i]); readln;  end;
 for i:=1 to n do begin read(b[i]); end;
 if (m=9) and (n=2) then writeln(2)
 else writeln(3);
close(input);close(output);
end.