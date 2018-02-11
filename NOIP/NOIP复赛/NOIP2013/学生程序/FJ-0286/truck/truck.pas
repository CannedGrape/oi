var a:array[1..100000,1..3] of longint;
    b,h,w,t:array[1..10000] of longint;
    n,m,x,y,z,q,i:longint;
function min(p,q:longint):longint;
begin
  if p<q then min:=p
  else min:=q;
end;
procedure spfa;
var i,l,r,new:longint;
begin
  for i:=1 to n do
  begin
    w[i]:=-1;t[i]:=0;
  end;
  w[x]:=maxlongint;t[x]:=1;
  l:=0;r:=1;h[1]:=x;
  repeat
    inc(l);i:=b[h[l]];
    while i>0 do
    begin
      new:=min(w[h[l]],a[i,2]);
      if new>w[a[i,1]] then
      begin
        w[a[i,1]]:=new;t[a[i,1]]:=0;
      end;
      if t[a[i,1]]=0 then
      begin
        t[a[i,1]]:=1;
        inc(r);h[r]:=a[i,1];
      end;
      i:=a[i,3];
    end;
  until l>=r;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    a[i,1]:=y;a[i,2]:=z;a[i,3]:=b[x];b[x]:=i;
    a[m+i,1]:=x;a[m+i,2]:=z;a[m+i,3]:=b[y];b[y]:=m+i;
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(x,y);spfa;writeln(w[y]);
  end;
  close(input);close(output);
end.
