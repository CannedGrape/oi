program number;
var i,n,p,num:longint;
    point,max3,max1:int64;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do
  begin
    read(num);
    if i=1then
    begin
      max1:=num;
      point:=max1;
      max3:=num;
    end
    else
    if i=2 then
    begin
      if max1+num>max1 then max1:=max1+num;
      if num>max1 then max1:=num;
      max3:=max3+max3;
      if max3>point then point:=max3;
    end
    else
    begin
      if max3>point then point:=max3;
      if max3+max1>max3 then max3:=max3+max1;
      if max1+num>max1 then max1:=max1+num;
      if num>max1 then max1:=num;
    end;
  end;
  if max3>point then point:=max3;
  if point<0then write('-');
  write(abs(point)mod p);
close(input);close(output);
end.
