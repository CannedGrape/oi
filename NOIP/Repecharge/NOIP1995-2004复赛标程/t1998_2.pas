program t1998_2;
const maxn=20;
var n,i,j,k,temp:integer;
    f:array[1..maxn]of integer;

function small(a,b:integer):boolean;
var a1,b1,i:integer;
    ab,ba:array[1..10] of integer;
begin
    b1:=b;a1:=a;i:=0;
    while b1<>0 do begin
        i:=i+1;
        ab[i]:=b1 mod 10;
        b1:=b1 div 10;
    end;
    while a1<>0 do begin
        i:=i+1;
        ab[i]:=a1 mod 10;
        a1:=a1 div 10;
    end;
    i:=0;
    while a<>0 do begin
        i:=i+1;
        ba[i]:=a mod 10;
        a:=a div 10;
    end;
    while b<>0 do begin
        i:=i+1;
        ba[i]:=b mod 10;
        b:=b div 10;
    end;
    while (i>0) and (ab[i]=ba[i]) do i:=i-1;
    if i=0 then small:=false
    else if ab[i]<ba[i] then small:=true
    else small:=false;
end;

begin
    assign(input,'quee.in');
    reset(input);
    readln(n);
    for i:=1 to n do read(f[i]);
    close(input);
    assign(output,'quee.out');
    rewrite(output);
    for i:=1 to n-1 do begin
        k:=i;
        for j:=i+1 to n do
           if small(f[k],f[j]) then  {f[k]<f[j]}
               k:=j;
        temp:=f[i];f[i]:=f[k];f[k]:=temp;
    end;
    for i:=1 to n do write(f[i]);
    writeln;
    close(output);
end.
