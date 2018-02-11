program level;
type tlist=array[1..100]of integer;
var n,m,s,i,j:integer;
    a,b:tlist;
procedure qsort(var a : tlist);

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
       sort(1,n);
    end;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  read(n,m);
  fillchar(b,sizeof(b),0);
  for i:=1 to m do
    begin
      read(s);
      for j:=1 to s do
        begin
        read(a[j]);
        inc(b[a[j]]);
        end;
    end;
  qsort(b);
  write(b[n]);
  close(input);
  close(output);
end.
