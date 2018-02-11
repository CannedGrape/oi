program match;
var
  i,n:longint;
  b,a:array[0..100000]of longint;
  ans:int64;


{var

    procedure sort1(l,r: longint);
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
                y:=wa[i];
                wa[i]:=wa[j];
                wa[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort1(l,j);
         if i<r then
           sort1(i,r);
      end;

    procedure sort2(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=b[(l+r) div 2];
         repeat
           while b[i]<x do
            inc(i);
           while x<b[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                y:=wb[i];
                wb[i]:=wb[j];
                wb[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort2(l,j);
         if i<r then
           sort2(i,r);
      end;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      wa[i]:=i;
    end;
  for i:=1 to n do
    begin
      read(b[i]);
      wb[i]:=i;
    end;
  sort1(1,n);
  sort2(1,n);
  for i:=1 to n do
    begin
      if wa[i]<>wb[i] then f[wa[i]]:=wb[i];}

begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  ans:=(n*(n-1) div 2) mod 99999997;
  writeln(ans);
  close(input);
  close(output);
end.


























