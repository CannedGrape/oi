var
  i,n,x:longint;
  w,sum,a,b:array[0..100000]of longint;
  ta,tb,ansb,ansa:longint;
begin
  assign(input,'flower.in');reset(input);

  assign(output,'flower.out');rewrite(Output);
  readln(n);
  for i:=1 to n do read(w[i]);

  tb:=1;  b[tb]:=w[1]; sum[tb]:=1;
  for i:=2 to n do
   begin
    x:=w[i];
    if x>=b[tb] then
     begin
      b[tb]:=x;
      inc(sum[tb]);
     end
    else
     begin
      inc(tb);
      b[tb]:=x;
      inc(sum[tb]);
     end;
   end;
  ansb:=1;
  for i:=2 to tb-1 do
    if sum[i]>=2  then ansb:=ansb+2;
  if sum[tb]=1 then inc(ansb) else inc(ansb,2);

  fillchar(sum,sizeof(sum),0);
  ta:=1; a[ta]:=w[1]; sum[ta]:=1;
  for i:=2 to n do
   begin
    x:=w[i];
    if x<=a[ta] then
     begin
      a[ta]:=x;
      inc(sum[ta]);
     end
     else
      begin
       inc(ta);
       a[ta]:=x;
       inc(sum[ta]);
      end;
   end;
  ansa:=1;
  for i:=2 to ta-1 do
   if sum[i]>=2 then inc(ansa,2);
  if sum[ta]=1 then inc(ansa) else inc(ansa,2);
  //writeln(ansa,' ',ansb);
  if ansa>ansb then writeln(ansa) else writeln(ansb);

  close(Input);close(output);
end.
