var a,map:array[1..1000,1..1000] of longint;
    f,l:array[1..1000] of longint;
    i,j,n,m,min,cti,kind:longint;
function stay(x:longint):boolean;
 var i,j:longint;
  begin
   stay:=true;min:=maxlongint;
   for i:=1 to l[x] do
    if f[a[x,i]]<min then begin min:=f[a[x,i]];cti:=a[x,i]; end;
   for i:=a[x,1] to a[x,l[x]] do
    if (f[i]>=min) and (map[x,i]=0) then exit(false);
  end;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
 read(n,m);
 for i:=1 to m do
  begin
   read(l[i]);
   for j:=1 to l[i] do
    begin
     read(a[i,j]);
     map[i,a[i,j]]:=1;
    end;
  end;
 for i:=1 to n do
  f[i]:=1;
 kind:=1;
 for i:=1 to m do
  begin
   while not stay(i) do
    begin inc(f[cti]);
     if f[cti]>kind then inc(kind);
    end;
  end;
 write(kind);
close(input);close(output);
end.
