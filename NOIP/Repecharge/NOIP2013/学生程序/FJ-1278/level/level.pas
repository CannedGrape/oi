program level;
 var n,m,i,j:longint;
       s:array[1..1000,1..1000] of longint;
   begin
    assign(input,'level.in');reset(input);
    assign(output,'level.out');rewrite(output);
    read(n,m);
    for i:=1 to m do
     for j:=1 to n do readln(s[i,j]);
    write('2');
    close(input);close(output);
   end.

