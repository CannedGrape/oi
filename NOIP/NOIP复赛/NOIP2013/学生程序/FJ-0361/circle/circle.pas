var
    n,m,k,x,ans,t:int64;
function qiumod(n,k,x:int64):int64;
var
   t,tt:int64;
begin
    if k=1 then exit(x mod n);
     t:=((x mod n)*(x mod n)) mod n;
    tt:=(qiumod(n,k div 2,t)) mod n;
    if k mod 2=0 then exit(tt mod n)
    else exit((tt mod n)*(x mod n) mod n);


end;

begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input); rewrite(output);
    readln(n,m,k,x);
    ans:=x;
    t:=qiumod(n,k,10);
    t:=((t mod n)*(m mod n)) mod n;
    ans:=((ans mod n)+t) mod n;
    writeln(ans);
close(input); close(output);
end.






