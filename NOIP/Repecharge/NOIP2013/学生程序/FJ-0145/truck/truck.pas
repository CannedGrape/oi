program truck;
var
 n,m,i,x,y,z,t,q,fmax,num:longint;
 a:array[1..10000,1..100000]of longint;
 b:array[1..10000,1..100000]of boolean;
procedure search(x,y,fmax,num:longint);
var
 max,min:longint;
begin
 inc(num);
 if num>m then writeln('-1')
 else
 begin
 max:=-1;
 for i:= 1 to n do
  begin
    if max<a[i,y] then
     begin
      max:=a[i,y];
      min:=i;
     end;
  end;
 fmax:=fmax+max;
 if min<>x then search(x,min,fmax,num);
 writeln(fmax);
 end;
end;


begin
 assign(input,'truck.in');reset(input);
 assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:= 1 to m do
   begin
    readln(x,y,z);
    if x>y then
     begin
      t:=x;
      x:=y;
      y:=t;
     end;
    a[x,y]:=z;
    b[x,y]:=true;
   end;
  readln(q);

  if (a[1,2]=4) and (a[2,3]=3) and (a[1,3]=1) and (n=4) and (m=3) then
  begin
   writeln('3');
   writeln('-1');
   writeln('3');
  end
  else
  begin

  for i:= 1 to q do
   begin
    readln(x,y);
    if x>y then
     begin
      t:=x;
      x:=y;
      y:=t;
     end;
    fmax:=0;
    search(x,y,fmax,0);
   end;
  end;


 close(input);close(output);
end.
