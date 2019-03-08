var
  a,b,c,d:array[1..100000] of longint;
  n,i,j,x,y,k:longint;
procedure qs(h,t:longint);
  var mid,o,p,r:longint;
  begin
    mid:=a[(h+t) div 2];o:=h; p:=t;
    repeat
    while a[o]<mid do inc(o);
    while a[p]>mid do dec(p);
    if o<=p then
      begin
        r:=c[o]; c[o]:=c[p]; c[p]:=r;
        inc(o); dec(p);
      end;
    until o>p;
    if o<t then qs(o,t);
    if h<p then qs(h,p);
  end;
procedure qsd(h,t:longint;
  var mid,o,p,r:longint;
  begin
    mid:=d[(h+t) div 2]; o:=h; p:=t;
    repeat
      while d[o]<mid do inc(o);
      while d[p]>mid do dec(p);
      if o<=p then
        begin
          r:=d[o]; d[o]:=d[p]; d[p]:=r;
          inc(o); dec(p);
        end;
    until o>p;
      if o<t then qsd(o,t);
      if h<p then qsd(h,p);
  end;
procedure qs(h,t:lo

begin
  assign(input,'match.in'); reset(intput);
  assign(output,'match.out'); rewrite(output);
  read(n);
  for i:=1 to n do
    begin
      read(a[i]);
      c[i]:=i;
    end;
  for i:=1 to n do
    begin
      read(b[i]);
      d[i]:=b[i];
    end;