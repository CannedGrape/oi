var n,i:longint;
    ans:int64;
    ma,a,b,c:array[0..100050] of longint;


procedure swap(var x,y:longint);
var t:longint;
begin
    t:=x; x:=y; y:=t;
end;


procedure kp1(l,r:longint);
var i,j,mid:longint;
begin
    i:=l; j:=r; mid:=b[(i+j)>>1];
    repeat
     while b[i]<mid do inc(i);
     while b[j]>mid do dec(j);
     if i<=j then
     begin
      swap(b[i],b[j]);
      swap(ma[i],ma[j]);
      inc(i); dec(j);
     end;
    until i>j;
    if i<r then kp1(i,r);
    if l<j then kp1(l,j);
end;

procedure ls;
var i:longint;
begin
    kp1(1,n);
    for i:=1 to n do
     b[ma[i]]:=i;
end;

procedure ins(x:longint);
begin
    while x<=n do
    begin
      c[x]:=c[x]+1;
      x:=x+x and (-x);
    end;
end;

function find(x:longint):int64;
var sum:int64;
begin
    sum:=0;
    while x>0 do
    begin
     sum:=sum+c[x];
     x:=x-x and (-x);
    end;
    exit(sum);
end;




procedure kp(l,r:longint);
var i,j,mid:longint;
begin
    i:=l; j:=r; mid:=a[(i+j)>>1];
    repeat
     while a[i]>mid do inc(i);
     while a[j]<mid do dec(j);
     if i<=j then
     begin
      swap(a[i],a[j]);
      swap(b[i],b[j]);
      inc(i); dec(j);
     end;
    until i>j;
    if i<r then kp(i,r);
    if l<j then kp(l,j);
end;

begin
    assign(input,'match.in'); reset(input);
    assign(output,'match.out'); rewrite(output);
    readln(n);
    for i:=1 to n do
     read(a[i]);
    readln;
    for i:=1 to n do
    begin
     read(b[i]);
     ma[i]:=i;
    end;
    kp(1,n);
    ls;
    ans:=0;
    for i:=1 to n do
    begin
      ans:=(ans+find(b[i]-1)) mod 99999997;
      ins(b[i]);
    end;
    writeln(ans);
    close(input); close(output);
end.