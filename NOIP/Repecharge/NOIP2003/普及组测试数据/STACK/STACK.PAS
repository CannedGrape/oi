program stack1(input,output);
const max=18;
var f:array[0..max] of longint;
    i,j,n:integer;
begin
   assign(input,'stack.in');
   reset(input);
   readln(n);
   close(input);
   f[0]:=1;
   for i:=1 to n do
      begin
        f[i]:=0;
        for j:=0 to i-1 do f[i]:=f[i]+f[j]*f[i-j-1]
     end;
   assign(output,'stack.out');
   rewrite(output);
   writeln(f[n]);
   close(output);
end.