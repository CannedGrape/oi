var n,i,j,sum,dcr,icr,ii,k:longint;
    f:array[-1..1010,-1..1010] of integer;
    m:array[-1..1010] of longint;
function min(a,b:integer):integer;
begin
    if a<b then exit(a) else exit(b);
end;
begin
    assign(input,'block.in');reset(input);
    assign(output,'block.out');rewrite(output);
    readln(n);
    for i:=1 to n do
    begin
     read(j);f[i,i]:=j;end;

    for j:=1 to n-1 do
     for i:=1 to n-j do
      f[i,i+j]:=min(f[i+1,i+j],f[i,i+j-1]);
    for j:=n-1 downto 0 do
     for i:=1 to n-j do
     if f[i,i+j]>0 then begin
      inc(sum,f[i,i+j]);
      for k:=0 to j do
      for ii:=0 to j-k do
       dec(f[i+ii,i+ii+k],f[i,i+j]);end;
    writeln(sum);
    close(input);close(output);
end.

