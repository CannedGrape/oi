program p2;
var n,i,ans:longint;
    a,q,w:array[0..100010]of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);exit(b);
end;
function maxf:longint;
var i,t:longint;
begin
  t:=1;
  for i:=1 to n do
  begin
    if odd(t) then
    begin
      if a[i]>=q[t] then q[t]:=a[i]
      else begin
        inc(t);
        q[t]:=a[i];
      end;
    end else
    begin
      if a[i]<=q[t] then q[t]:=a[i]
      else begin
        inc(t);
        q[t]:=a[i];
      end;
    end;
  end;
  maxf:=t;
end;
function minf:longint;
var i,t:longint;
begin
  t:=1;
  for i:=1 to n do
  begin
    if odd(t) then
    begin
      if a[i]<=w[t] then w[t]:=a[i]
      else begin
        inc(t);
        w[t]:=a[i];
      end;
    end else
    begin
      if a[i]>=w[t] then w[t]:=a[i]
      else begin
        inc(t);
        w[t]:=a[i];
      end;
    end;
  end;
  minf:=t;
end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  w[1]:=maxlongint;
  ans:=max(maxf,minf);
  writeln(ans);
  close(input);close(output);
end.