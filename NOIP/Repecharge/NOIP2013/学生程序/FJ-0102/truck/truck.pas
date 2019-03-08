var f:array[0..10000,0..10000]of longint;
    i,j,k,p,e:longint;

function max(a,b:longint):longint;
begin
 if a>b then exit(a) else exit(b);
end;

function min(a,b:longint):longint;
begin
 if a<b then exit(a) else exit(b);
end;

begin
 assign(input,'truck.in');
 assign(output,'truck.out');
 reset(input);
 rewrite(output);
 read(p,e);
 for k:=1 to e do
  begin
   read(i,j);
   read(f[i,j]);
   f[j,i]:=f[i,j];
  end;
 for i:=1 to p do
  for j:=1 to p-1 do
   for k:=j+1 to p do
    begin
     f[j,k]:=max(f[j,k],min(f[j,i],f[i,k]));
     f[k,j]:=f[j,k];
    end;
 read(e);
 for k:=1 to e do
  begin
   read(i,j);
   if f[i,j]=0 then writeln(-1) else writeln(f[i,j]);
  end;
 close(input);
 close(output);
end.