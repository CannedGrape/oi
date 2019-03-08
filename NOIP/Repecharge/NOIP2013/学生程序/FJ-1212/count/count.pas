program count;
var n,m,i,z,x:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
    read(n,m);
    z:=0;
    for i:=1 to n do
      begin
        x:=i;
        while x>0 do
          begin
            if x mod 10=m then inc(z);
            x:=x div 10;
          end;
      end;
    write(z);
  close(input);
  close(output);
end.