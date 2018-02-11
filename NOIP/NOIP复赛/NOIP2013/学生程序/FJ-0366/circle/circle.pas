var n,m,k,x,p,t:longint;
    i,j,temp:int64;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  i:=k;temp:=m;j:=x;
  while i>0 do
    begin
      if i>12 then
        begin
          j:=(j+temp*1000000000000)mod n;
          temp:=temp*1000000000000 mod n;
          i:=i-12;
        end else
          begin
            t:=1;
            for p:=1 to i do t:=t*10;
            j:=(j+temp*t)mod n;
            i:=0;
          end;
    end;
  writeln(j);
  close(input);close(output);
end.