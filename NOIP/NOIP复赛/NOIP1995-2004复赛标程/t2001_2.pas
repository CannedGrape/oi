program t2001_2;
var n,k:integer;

function f(s,t,k:integer):longint;
var i:integer;sum:longint;
begin
    if k=1 then f:=1
    else begin
        sum:=0;
        for i:=s to t div k do
           sum:=sum+f(i,t-i,k-1);
        f:=sum;
    end;
end;

begin
   assign(input,'t2.in');
   reset(input);
   readln(n,k);
   close(input);
   assign(output,'t2.out');
   rewrite(output);
   writeln(f(1,n,k));
   close(output);
end.
