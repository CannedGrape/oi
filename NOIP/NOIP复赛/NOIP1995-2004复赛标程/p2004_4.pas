program martian;
const maxn=10000;
var n,m,i,j,k,temp:integer;
    f:array[1..maxn]of integer;
begin
    assign(input,'martian.in');
    reset(input);
    readln(n);
    readln(m);
    for i:=1 to n do read(f[i]);
    close(input);
    for i:=1 to m do begin
        j:=n-1;
        while (j>0) and (f[j]>f[j+1]) do j:=j-1;
        k:=n;
        while f[k]<f[j] do k:=k-1;
        temp:=f[j];f[j]:=f[k];f[k]:=temp;
        k:=j+1;
        while k<=(j+1+n) div 2 do begin
            temp:=f[k];f[k]:=f[n+j+1-k];f[n+j+1-k]:=temp;
            k:=k+1;
        end;
    end;
    assign(output,'martian.out');
    rewrite(output);
    write(f[1]);
    for i:=2 to n do write(' ',f[i]);
    close(output);
end.
