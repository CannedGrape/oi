const size=1000;
var n,x,i,j:longint;
 sum:int64;
 m:array[1..size] of longint;
procedure chaishu(a,i:longint);
begin
 m[i]:=a mod 10;
 a:=a div 10;
 if (a<>0) then chaishu(a,i+1);
end;
begin
 assign(input,'count.in');
 assign(output,'count.out');
 reset(input);
 rewrite(output);
 readln(input,n,x);
 sum:=0;
 for i:=1 to size do m[i]:=-1;
 for i:=1 to n do
  begin
   chaishu(i,1);
   j:=1;
   while (m[j]<>-1) do
    begin
     if (m[j]=x) then inc(sum);
     inc(j);
    end;
  end;
 writeln(output,sum);
 close(input);
 close(output);
end.
