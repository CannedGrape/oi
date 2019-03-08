const
  maxn=10000;

var
  a:array[1..maxn,0..maxn]of longint;
  s:array[1..maxn,1..maxn]of longint;
  f:array[1..10*maxn]of longint;
  e:array[1..maxn]of boolean;
  d:array[1..maxn]of longint;
  n,m,q,i,j,k,x,y,z,h,t:longint;
  ans:boolean;

function min(x,y:longint):longint;
begin
  if x<y then min:=x else min:=y;
end;

function max(x,y:longint):longint;
begin
  if x>y then max:=x else max:=y;
end;

begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do a[i,0]:=0;
  for i:=1 to n do 
    for j:=1 to n do s[i,j]:=-1;
  for i:=1 to m do begin
    readln(x,y,z);
    if s[x,y]=-1 then begin
      inc(a[x,0]);
      a[x,a[x,0]]:=y;
      inc(a[y,0]);
      a[y,a[y,0]]:=x;
      s[x,y]:=z;
      s[y,x]:=z;
    end else begin
      s[x,y]:=max(s[x,y],z);
      s[y,x]:=s[x,y];
    end;
  end;
  readln(q);
  for i:=1 to q do begin
    readln(x,y);
    for j:=1 to n do e[j]:=true;
    e[x]:=true;
    for j:=1 to n do d[j]:=-1;
    d[x]:=maxlongint;
    h:=1;
    t:=1;
    f[1]:=x;
    repeat
      k:=f[h];
      for j:=1 to a[k,0] do
        if min(d[k],s[k,a[k,j]])>d[a[k,j]] then begin
          d[a[k,j]]:=min(d[k],s[k,a[k,j]]);
          if e[a[k,j]] then begin
            inc(t);
            f[t]:=a[k,j];
            e[a[k,j]]:=false;
          end;
        end;
      e[k]:=true;
      inc(h);
    until h>t;
    writeln(d[y]);
  end;
  close(input);
  close(output);
end.


