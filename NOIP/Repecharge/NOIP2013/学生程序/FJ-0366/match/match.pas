var a,b:array[1..100000,1..2] of longint;
    c,d,t:array[1..100000] of longint;
    i,j,k,ans,n:longint;

procedure px(l,r:longint);
var i,j,k,t,p:longint;
begin
  i:=l;j:=r;
  k:=a[(i+j) shr 1,1];
  repeat
    while a[i,1]<k do inc(i);
    while a[j,1]>k do dec(j);
    if i<=j then
      begin
        for p:=1 to 2 do
          begin
            t:=a[i,p];a[i,p]:=a[j,p];a[j,p]:=t;
          end;
        inc(i);dec(j);
      end;
  until i>j ;
  if l<j then px(l,j);
  if i<r then px(i,r);
end;

procedure gui(l,r:longint);
var mid,temp,i,j,t,p:longint;
begin
  if l=r then exit;
  mid:=(l+r) shr 1;
  gui(l,mid);gui(mid+1,r);
  i:=l;j:=mid+1;t:=l;
  while (i<=mid)and(j<=r) do
    if c[i]<c[j] then begin d[t]:=c[i];inc(i);inc(t); end else
        begin
          d[t]:=c[j];inc(j);inc(t);
        end;
   ans:=ans+mid-i+1;
  if i<=mid then for p:=i to mid do begin d[t]:=c[i]; inc(t);end;
  if j<=r then for p:=j to r do begin d[t]:=c[j];inc(t); end;
  for p:=l to r do c[p]:=d[p];
end;


BEGIN
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  ans:=0;
  for i:=1 to n do
    begin
      read(a[i,1]);
      a[i,2]:=i
    end;
  readln;
  px(1,n);
  for i:=1 to n do
    d[i]:=a[i,2];
  for i:=1 to n do
    begin
      read(a[i,1]);
      a[i,2]:=i;
    end;
  px(1,n);
  for i:=1 to n do
    c[a[i,2]]:=d[i];
  gui(1,n);
  writeln(ans);
  close(input);
  close(output);
end.