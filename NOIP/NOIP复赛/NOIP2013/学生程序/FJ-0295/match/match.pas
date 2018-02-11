program match;
var a,b:array[1..100000]of longint;
    n,i,j,ans,p:longint;
    bo:boolean;
procedure qsort(l,r:longint);
var i,j,m,p:longint;
begin
    i:=l;   j:=r;   m:=a[(l+r) div 2];
    repeat
      while a[i]<m do inc(i);
      while a[j]>m do dec(j);
      if i<=j then
      begin
        p:=a[i];   a[i]:=a[j];   a[j]:=p;
        p:=b[i];   b[i]:=b[j];   b[j]:=p;
        inc(i);   dec(j);
      end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
end;
begin
    assign(input,'match.in');
    assign(output,'match.out');
    reset(input);
    rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);
    for i:=1 to n do read(b[i]);
    qsort(1,n);
    ans:=0;
    repeat
      for i:=1 to n-1 do
        if b[i]>b[i+1] then
        begin
          p:=b[i];   b[i]:=b[i+1];   b[i+1]:=p;
          ans:=(ans+1) mod 99999997;
        end;
      bo:=true;
      for i:=1 to n-1 do
        if b[i]>b[i+1] then
        begin
          bo:=false;
          break;
        end;
    until bo;
    writeln(ans);
    close(input);
    close(output);
end.
