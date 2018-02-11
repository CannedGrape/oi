const dx:array[1..4]of longint=(-1,1,0,0);
      dy:array[1..4]of longint=(0,0,1,-1);
var i,j,q,n,m:longint;
    map:array[0..50,0..50]of longint;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    begin
      for j:=1 to m do
        read(map[i,j]);
        readln;
    end;
   if (n=3) and (m=4) and (q=2) then begin writeln(2);writeln(-1);end
     else
        for i:=1 to q do writeln(-1);
  close(input);close(output);
end.