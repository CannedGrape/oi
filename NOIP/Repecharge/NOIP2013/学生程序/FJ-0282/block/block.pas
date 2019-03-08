program ex;
var top,ans,i,q1,j,m,n,k:longint;
   a:array[0..100001] of longint;
begin
 assign(input,'block.in');
 reset(input);
 assign(output,'block.out');
 rewrite(output);
 readln(n);
 top:=0;
 ans:=0;
 for i:=1 to n do
  begin
   read(m);
   if m>=a[top] then
    begin
     inc(top);
     a[top]:=m;
    end
   else
    begin
     q1:=a[top];
     while (m<a[top])and(top>0) do dec(top);
     ans:=ans+q1-m;
     inc(top);
     a[top]:=m;
    end;
  end;
 q1:=0;
 for i:=1 to top do
  if a[i]>q1 then q1:=a[i];
 ans:=ans+q1;
 writeln(ans);
 close(input);
 close(output);
end.
