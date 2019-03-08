program number;
type tlist=array[1..1000000] of longint;
var n,p,i,j,k:longint;
    a,b,c,d:tlist;
procedure qsort(var a : tlist;x:longint);

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
       sort(1,x);
    end;
procedure tezh;

begin
  b[1]:=a[1];
  for i:=2 to n do
    begin
      fillchar(c,sizeof(c),0);
      for j:=1 to i do
        begin
          for k:=1 to j do
               c[j]:=c[j]+a[k];
        end;
      qsort(c,i);
      b[i]:=c[i];
    end;
  fillchar(c,sizeof(c),0);
end;
procedure fs;

begin
  c[1]:=a[1];
  for i:=2 to n do
    begin
      fillchar(d,sizeof(d),0);
      for j:=1 to i-1 do
      begin
        d[j]:=c[j]+b[j];
      end;
      qsort(d,i-1);
      c[i]:=d[i-1];
    end;
end;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  read(n,p);
  for i:=1 to n do
  read(a[i]);
  tezh;
  fs;
  qsort(c,n);
  if c[n]>=0 then write((c[n]mod p));
  if c[n]<0 then write('-',(abs(c[n])mod p))
  close(input);
  close(output);
end.