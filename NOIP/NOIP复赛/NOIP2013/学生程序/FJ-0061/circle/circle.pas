program circle;
var n,m,k,ti,i:longint;
    x,y:int64;
    a:array[-1..100000000] of longint;
function f(t:longint):boolean;
var i,mid:longint;
begin
    if t mod 2 =1 then exit(false);
    mid:=t div 2;
    for i:=1 to mid do
     if a[i]<>a[mid+i] then exit(false);
    exit(true);
end;

procedure getT(m:longint);
var t,x:longint;
begin
    t:=0;
    a[0]:=1;
    repeat
     inc(t);
     a[t]:=10*a[t-1] mod m;
    until f(t)=true;
    ti:=t div 2;
end;
function power(k:longint):longint;
var y,x,i,r,q:longint;
begin
    x:=1;
    i:=0;
    getT(n);
    y:=k mod ti;
    exit (a[y]);

end;

begin
    assign(input,'circle.in');reset(input);
    assign(output,'circle.out');rewrite(output);
    readln(n,m,k,x);
    y:=(power(k)mod n)*(m mod n);
    x:=x+y mod n;
    writeln(x);
    close(input);close(output);
end.
