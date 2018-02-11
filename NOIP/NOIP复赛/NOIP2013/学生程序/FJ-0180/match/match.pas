const p=99999997;
type rec=record
     v,t:longint;
     end;
var a1,a2:array [0..100001] of rec;
    n,i,j,ans:longint;
    c,t1,t2,oo,link:array [0..100001] of longint;
function lowbit(a:longint):longint;
begin exit(a and (-a)); end;
procedure sort1(l,r:longint);
var i,j:longint;
    x,y:rec;
begin
  i:=l;
  j:=r;
  x:=a1[(((l+r) div 2)+r) div 2];
  repeat
    while a1[i].v<x.v do inc(i);
    while x.v<a1[j].v do dec(j);
    if not(i>j)
    then
      begin
        y:=a1[i];
        a1[i]:=a1[j];
        a1[j]:=y;
        inc(i);
        dec(j);
      end;
  until i>j;
  if l<j then sort1(l,j);
  if i<r then sort1(i,r);
end;
procedure sort2(l,r:longint);
var i,j:longint;
    x,y:rec;
begin
  i:=l;
  j:=r;
  x:=a2[(((l+r) div 2)+r) div 2];
  repeat
    while a2[i].v<x.v do inc(i);
    while x.v<a2[j].v do dec(j);
    if not(i>j)
    then
      begin
        y:=a2[i];
        a2[i]:=a2[j];
        a2[j]:=y;
        inc(i);
        dec(j);
      end;
  until i>j;
  if l<j then sort2(l,j);
  if i<r then sort2(i,r);
end;
begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);

  fillchar(c,sizeof(c),0);
  fillchar(link,sizeof(link),0);
  readln(n);
  for i:=1 to n do begin read(a1[i].v); a1[i].t:=i; end;
  for i:=1 to n do begin read(a2[i].v); a2[i].t:=i; end;
  sort1(1,n);
  sort2(1,n);
  for i:=1 to n do
    begin
      t1[i]:=a1[i].t;
      t2[i]:=a2[i].t;
    end;
  for i:=1 to n do oo[t2[i]]:=i;
  for i:=1 to n do link[i]:=oo[t1[i]];
  ans:=0;
  for i:=n downto 1 do
    begin
      j:=link[i];
      while j>0 do
        begin
          ans:=(ans+c[j]) mod p;
          j:=j-lowbit(j);
        end;
      j:=link[i];
      while j<=n do
        begin
          c[j]:=(c[j]+1) mod p;
          j:=j+lowbit(j);
        end;
    end;
  writeln(ans);

close(input);
close(output);
end.
