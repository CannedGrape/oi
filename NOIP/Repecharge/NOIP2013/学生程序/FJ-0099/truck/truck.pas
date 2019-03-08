var
  f:array[0..1001,0..1001]of longint;
  q:array[0..1001,0..1001]of boolean;
  n,m,i,j,l,t,k,x,y,z,w:longint;
  a,b,c:array[0..100000]of longint;

function min(x,y:longint):longint;
begin
  if x<y then exit(x);exit(y);
end;

function max(x,y:longint):longint;
begin
  if x>y then exit(x);exit(y);
end;

begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  fillchar(f,sizeof(f),$5f);
  fillchar(q,sizeof(q),false);
  w:=-1;
  for i:=1 to m do
    begin
      readln(x,y,z);
      if (z>f[x,y])or(not(q[x,y])) then f[x,y]:=z;
      if (z>f[y,x])or(not(q[y,x])) then f[y,x]:=z;
      q[x,y]:=true; q[y,x]:=true;
      if z>w then w:=z;
    end;
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
        if (i<>k)and(j<>k)and(i<>j)and(q[i,k])and(q[j,k]) then
          begin
            f[i,j]:=max(f[i,j],min(f[i,k],f[k,j]));
            f[j,i]:=f[i,j];
            q[i,j]:=true;q[j,i]:=true;
          end;
  readln(t);
  for i:=1 to t do
    begin
      readln(x,y);
      if f[x,y]<=w then writeln(f[x,y])
      else writeln('-1');
    end;
  readln;readln;
  close(input);close(output);
end.

