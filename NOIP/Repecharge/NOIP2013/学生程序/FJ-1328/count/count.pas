program count;
var n,x,a,b,c,d,e,f:longint; y:array[1..1000000] of longint; s:string;
begin
  read(n,x); c:=0;
  for a:=1 to n do
   begin
     for b:=1 to n do y[b]:=a;

     if y[b]<10 then
     if y[b]=x then c:=c+1;

     if y[b]>=10 then
     begin
       str(y[b],s);
     end;
       begin
         for e:=1 to 6 do
          begin
          val(copy(s,e,1),y[e]);
          if y[e]=x then c:=c+1;

          end;
       end;
   end;
     write(c);
  end.
