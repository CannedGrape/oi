const max=1000000;
var i,j,n,p,t,t2:integer;
    a,b,c:array[1..max] of integer;
begin
 assign(input,'number.in');
 assign(output,'number.out');
 reset(input);
 rewrite(output);
 read(n);
 readln(p);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do
  begin
   if i=1 then b[i]:=a[i];
   if i<>1 then
    begin
     b[i]:=b[i-1]+a[i];
    end;
  end;
 for i:=1 to n do
  begin
   if i=1 then c[i]:=b[i];
   if i<>1 then
    begin
     c[i]:=b[i-1]+c[i-1];
    end;
   end;
   for i:=1 to n do
  begin
   for j:=i+1 to n do
    begin
     if c[j]>c[i] then
      begin
       t:=c[j];
       c[j]:=c[i];
       c[i]:=t;
      end;
     end;
   end;
   t:=1;
   write(c[t]);
 close(input);
 close(output);
end.




