program ex_3;
var a,b,f,d:array[0..50001]of longint;
    n,m,x,y,z,q,i,j,ans:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;
function find(a:longint):longint;
begin
  if (f[a]=1) then begin find:=0;exit;end;
  if (f[a]=y) then exit;
  find:=min(d[a],find(f[a]));
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  read(n,m);
  for i:=1 to m do
    begin
      read(x,y,z);
      if x<y then
        begin
          a[i]:=x;b[i]:=y;
          f[y]:=x;
          d[y]:=z;
        end
      else
        begin
          a[i]:=y;b[i]:=x;
          f[x]:=y;
          d[x]:=z;
        end;
    end;

  f[1]:=1;
  read(q);
  for i:=1 to q do
    begin
      ans:=0;
      read(x,y);
      if find(x)<>0 then ans:=find(x);
      if find(y)<>0 then ans:=find(y);
      if ans<>0 then writeln(ans) else writeln(-1);
    end;
  close(output);
  close(input);
end.
