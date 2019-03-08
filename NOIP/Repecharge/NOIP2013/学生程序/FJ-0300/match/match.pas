var n,i,ans:longint;
    bianb,biana,a,b,ba,bb,a1,b1:array[1..100000]of longint;
procedure sorta(x,y:longint);
  var l,r,t,m:longint;
  begin
    l:=x;r:=y;m:=a[(x+y) div 2];
    repeat
      while a[l]<m do inc(l);
      while a[r]>m do dec(r);
      if r>=l then
        begin
          t:=a[l];a[l]:=a[r];a[r]:=t;
          inc(l);dec(r);
        end;
    until l>r;
    if l<y then sorta(l,y);
    if r>x then sorta(x,r);
  end;
procedure sortb(x,y:longint);
  var l,r,t,m:longint;
  begin
    l:=x;r:=y;m:=b[(x+y) div 2];
    repeat
      while b[l]<m do inc(l);
      while b[r]>m do dec(r);
      if r>=l then
        begin
          t:=b[l];b[l]:=b[r];b[r]:=t;
          inc(l);dec(r);
        end;
    until l>r;
    if l<y then sortb(l,y);
    if r>x then sortb(x,r);
  end;
function finda(x:longint):longint;
  var l,r,mid:longint;
  begin
    l:=1;r:=n;
    while r>=l do
      begin
        mid:=(l+r) div 2;
        if a[mid]=x then exit(mid);
        if x<a[mid] then r:=mid-1
        else l:=mid+1;
      end;
  end;
function findb(x:longint):longint;
  var l,r,mid:longint;
  begin
    l:=1;r:=n;
    while r>=l do
      begin
        mid:=(l+r) div 2;
        if b[mid]=x then exit(mid);
        if x<b[mid] then r:=mid-1
        else l:=mid+1;
      end;
  end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  a1:=a;
  readln;
  for i:=1 to n do read(b[i]);
  b1:=b;
  sorta(1,n);
  sortb(1,n);
  for i:=1 to n do
    begin
      biana[i]:=finda(a1[i]);
      ba[biana[i]]:=i;
      bianb[i]:=findb(b1[i]);
      bb[bianb[i]]:=i;
    end;
  ans:=0;
  for i:=1 to n do
    begin
      ans:=ans+abs(ba[i]-bb[i]);
      ans:=ans mod 99999997;
    end;
  writeln(ans div 2);
  close(input);close(output);
end.