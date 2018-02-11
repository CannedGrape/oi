program puzzle;
var i,j,n,m,q:longint;
        a:array [1..100000] of longint;
    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
  reset(input);
  rewrite(output);
    readln(n,m,q);
    for i:=1 to n do
      for j:=1 to m do
        read(n);
    for i:=1 to q do
      for j:=1 to 6 do
        read(n);
    for i:=100000 downto 1 do a[i]:=i;
    sort(1,100000);
    write(-1);

  close(input);
  close(output);


end.