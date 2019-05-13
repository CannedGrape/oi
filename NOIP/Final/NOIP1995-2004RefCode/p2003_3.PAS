program abc(input,output);
var i,j,n:integer;
    f:array[0..18,-1..18] of longint;

begin
    assign(input,'stack.in');
    reset(input);
    readln(n);
    close(input);
    f[0,-1]:=1;
    for i:=0 to n do
      for j:=0 to n-i do
         begin
            if i=0 then f[i,j]:=f[i,j-1]
            else if j=0 then f[i,j]:=f[i-1,j+1]
            else f[i,j]:=f[i-1,j+1]+f[i,j-1]
         end;
    assign(output,'stack.out');
    rewrite(output);
    writeln(f[n,0]);
    close(output);
end.
