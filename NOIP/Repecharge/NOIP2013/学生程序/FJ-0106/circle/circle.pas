var n,m,x,ans,y,h:int64;
    k,i:longint;

function ksm(x:int64;y:longint):int64;
var t:int64;
begin
    if y=0 then exit(0);
    if y=1 then exit(x);
    t:=ksm(x,y>>1);
    t:=t*t;
    if y mod 2<>0 then
      t:=t*x;
    ksm:=t;
end;

function ef(k:longint):int64;
var t:int64;
begin
    if k<13 then exit(ksm(10,k) mod n);
    t:=ef(k>>1);
    t:=t*t mod n;
    if k mod 2<>0 then t:=t*10 mod n;
    ef:=t;
end;

begin
    assign(input,'circle.in'); reset(input);
    assign(output,'circle.out'); rewrite(output);
    readln(n,m,k,x);
    if k<13 then
    begin
    {  ans:=1;
      for i:=1 to k do
       ans:=ans*10; }
      writeln((ksm(10,k) mod n*m+x) mod n);
    end

    else
    begin
      ans:=ef(k);
      writeln((ans*m mod n+x) mod n);
    end;
    close(input); close(output);
end.
