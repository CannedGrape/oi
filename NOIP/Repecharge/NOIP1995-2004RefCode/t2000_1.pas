program t2000_1;
var c:array[1..20] of integer;
    n,n1,r,i:longint;

begin
    assign(input,'fjz.in');
    reset(input);
    readln(n,r);
    close(input);
    assign(output,'fjz.out');
    rewrite(output);
    i:=1;
    write(n,'=');
    while n<>0 do begin
        n1:=n div r;
        if (n<0) and (n<>n1*r) then n1:=n1+1;
        c[i]:=n-n1*r;
        i:=i+1;
        n:=n1;
    end;
    i:=i-1;
    while i>0 do begin
        if c[i]<10 then write(c[i])
           else write(chr(ord('A')+C[I]-10));
        i:=i-1;
     end;
    writeln('(base',r,')');
    close(output);
end.