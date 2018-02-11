program flower;
var
 n,i,num,max,wei:longint;
 h,g:array[1..1000000]of longint;

procedure flower(num,max,wei,n:longint);
begin
 inc(num);
 if num>n then
  begin
   write(max);
   halt;
  end;
 for i:=num to n do
  begin
   if ((h[i]<h[wei]) and (h[i]<h[i+1])) or ((h[i]>h[wei]) and (h[i]>h[i+1])) then
    begin
     if i=n-1 then flower(num+1,max+1,i+1,n);
     flower(num+1,max+2,i+1,n);
    end;
   if i=n then flower(num,max,wei,n);
  end;
end;

begin
 assign(input,'flower.in');reset(input);
 assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
   read(h[i]);

  num:=1;max:=1;wei:=1;
  flower(num,max,wei,n);
 close(input);close(output);
end.
