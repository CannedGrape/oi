program t2003_3(input,output);{Jia Fen Er Sha Shu}
const maxn=30;
var n,i,j,k,p:integer;
    r:array[1..maxn,0..maxn]of integer;
    f:array[1..maxn,0..maxn]of comp;
    first:boolean;
procedure out(i,j:integer);
var k:integer;
begin
    k:=r[i,j];
    if k<>0 then begin
        if first then
          begin write(k);first:=false;end
         else write(' ',k);
        out(i,k-1);
        out(k+1,j);
    end;
end;

begin
    assign(input,'binary.in');
    reset(input);
    readln(n);
    for i:=1 to n do
        for j:=0 to n do begin r[i,j]:=0;f[i,j]:=1;end;
    for i:=1 to n do begin read(f[i,i]);r[i,i]:=i;end;
    close(input);
    for k:=1 to n-1 do
    for i:=1 to n-k do begin
        j:=i+k;
        for p:=i to j do
        if f[i,j]<f[i,p-1]*f[p+1,j]+f[p,p] then begin
             f[i,j]:=f[i,p-1]*f[p+1,j]+f[p,p];
             r[i,j]:=p;end;
    end;
    assign(output,'binary.out');
    rewrite(output);
    writeln(f[1,n]:0:0);
    first:=true;
    out(1,n);
    writeln;
    close(output);
 end.
