var i,j,n,m,q,x,y,z,push:longint;
    a:array[0..10001,0..10001] of longint;

function max(a,b:longint):longint;
begin
  if a>b then exit(a)
  else exit(b);
end;

function min(a,b:longint):longint;
begin
  if a<b then exit(a)
  else exit(b);
end;

procedure go(l,m,r:longint);
begin
  push:=0;
  if (a[l,m]<>0) and (a[m,r]<>0) then push:=min(a[l,m],a[m,r]);
  a[l,r]:=max(a[l,r],push);
end;

begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input);
  rewrite(output);
  fillchar(a,sizeof(a),0);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y,z);
      if a[x,y]=0 then
        begin
          a[x,y]:=max(a[x,y],z);
          a[y,x]:=max(a[y,x],z);
        end;
      push:=0;
      for j:=1 to n do
        begin
          if (j<>x) and (j<>y) then
          begin
            go(j,x,y);
            go(x,j,y);
            go(x,y,j);
          end;
        end;
      push:=0;
      for j:=1 to n do
        begin
          if (j<>x) and (j<>y) then
          begin
            go(j,y,x);
            go(y,j,x);
            go(y,x,j);
          end;
        end;
    end;
  readln(q);
  for i:=1 to q do
    begin
      readln(x,y);
      if a[x,y]=0 then writeln(-1)
      else writeln(a[x,y]);
    end;
  close(input);
  close(output);
end.
