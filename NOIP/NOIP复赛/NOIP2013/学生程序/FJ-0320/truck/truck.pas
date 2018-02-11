var n,m,x,y,z,q,i,j,k,t,p:longint;
    a,d:array[0..1001,0..1001] of longint;
    b:array[0..1001] of longint;
    c:array[0..1001] of boolean;
    ans,l,r,max:longint;
    bo:boolean;
procedure search(x:longint);
var i,j,t:longint;
begin
  if x=y then
  begin
    bo:=true;
    exit;
  end;
  c[x]:=false;
  for i:=1 to b[x] do
    if c[a[x,i]] and (d[x,i]>=ans) then
      search(a[x,i]);
end;
begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out'); rewrite(output);
  fillchar(a,sizeof(a),0);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    inc(b[x]);
    a[x,b[x]]:=y;
    d[x,b[x]]:=z;
    inc(b[y]);
    a[y,b[y]]:=x;
    d[y,b[y]]:=z;
    if z>max then max:=z;
  end;
  readln(q);
  for p:=1 to q do
  begin
    readln(x,y);
    ans:=max;
    l:=1; r:=max;
    while r-l>1 do
    begin
      bo:=false;
      fillchar(c,sizeof(c),true);
      search(x);
      if bo then
      begin
        l:=ans;
        ans:=(l+r) div 2;
      end
      else
      begin
        r:=ans;
        ans:=(l+r) div 2;
      end;
    end;
    if ans<>1 then writeln(ans)
    else
    begin
      bo:=false;
      fillchar(c,sizeof(c),true);
      search(x);
      if bo then writeln('1') else writeln('-1');
    end;
  end;
  close(input); close(output);
end.
