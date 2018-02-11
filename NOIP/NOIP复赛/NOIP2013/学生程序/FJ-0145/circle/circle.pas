program circle;
var
 n,m,k,x,i,num,a,c:longint;
begin
 assign(input,'circle.in');reset(input);
 assign(output,'circle.out');rewrite(output);
  read(n,m,k,x);

  num:=0;
  while num mod m<>0 do
   num:=num+n;
  num:=num mod m;

  if num=0 then write(x)
  else
   begin
  a:=0;c:=1;
  while c<>k do
   begin
    inc(a);
    c:=c*10;
   end;

  num:=c mod num;
     write(num);

  if num=0 then write(x);
  if num<>0 then
   begin
    for i:= 1 to num do
     x:=(x+m) mod n;
    write(x);
   end;
  end;

 close(input);close(output);
end.
