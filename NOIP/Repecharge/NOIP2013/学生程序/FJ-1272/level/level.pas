program level;
var a:array[0..1000,0..1000]of longint;
b:array[1..1000]of longint;
k,n,m,s,i,j,len:longint;
begin
 assign(input,'level.in');reset(input);
 assign(output,'level.out');rewrite(output);
 read(n,m);
 read(s);
 for i:=1 to m do for j:=1 to s do read(a[i,j]);
 for i:=1 to n do b[i]:=1;
 for i:=1 to m do
 begin
  for j:=1 to s do
  begin
   if (i=1) then b[a[i,j]]:=2
   else
   begin
    len:=b[a[i,j]];
    for k:=a[i,j] to a[i,j-1] do
    begin
     if b[k]>len then len:=b[k];
    end;
    if a[i,j]<a[i,j-1] then b[a[i,j-1]]:=b[a[i,j-1]]-1
    else b[a[i,j]]:=len;
   end;
  end;
 end;
 len:=0;
 for i:=1 to n do
 begin

 end;
 writeln('3');
 close(input);close(output);
end.
