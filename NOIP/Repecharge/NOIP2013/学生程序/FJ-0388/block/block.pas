program block;
var a,b,c,n,d,f,g,h,i:longint;
e:array[1..10000,1..10000]of longint;
x,y,z:array[1..10000]of longint;
begin
 assign(input,'block.in');
 reset(input);
 assign(output,'block.out');
 rewrite(output);
 readln(n);

 for a:=1 to n do
  read(x[a]);

 for a:=1 to n do
  if x[a]>d then d:=x[a];

 for a:=1 to n do
  begin
   for b:=1 to (x[a]) do
    begin
     e[a,b]:=1;
    end;
  end;

 f:=0;
 g:=0;
 for a:=1 to n do
  begin
   i:=0;
   for b:=1 to n do
    begin

     if (e[b,a]=0)and(b>1)and(b<n) then
        begin
         for c:=b+1 to n do
          if e[c,a]>0 then g:=1;
         for c:=1 to b-1 do
          if e[c,a]>0 then h:=1;
         if (g=1) and (h=1) and (i<>1) then
          begin
           f:=f+1;
           i:=1;
          end;
         g:=0;
         h:=0;
        end;
       end;
    end;
 f:=f+d;
 write(f);

 close(input);
 close(output);
end.