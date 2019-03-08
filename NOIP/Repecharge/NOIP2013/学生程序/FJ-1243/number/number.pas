program exprr;
var a,a2,a3:array[1..1000000]of longint;
n,p,i,j,ans:longint;
function max(b,bb:longint):longint;
begin
   if b>bb then max:=b
   else max:=bb;
end;
begin
   assign(input,'number.in');reset(input);
   assign(output,'number.out');rewrite(output);
   read(n);readln(p);
   for i:=1 to n do read(a[i]);
   a2[1]:=a[1];
   a3[1]:=a2[1];
   ans:=a3[1];
   for i:=2 to n do
   begin
      a2[i]:=max(a2[i-1]+a[i],a[i]);
      a3[i]:=max(a3[i-1]+a2[i-1],a3[i-1]);
      if i=2 then a3[i]:=a2[i-1]+a3[i-1];
      if a3[i]>ans then ans:=a3[i];
   end;
   if p>ans then
   write(p)
   else write(ans);
   close(input);
   close(output);
end.
