program block;
var
  q:array[1..100000]of longint;
  n,i,min,max,tot,tem,mit,st,lm,t:longint;
  ok,ok1:boolean;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  read(n);
  read(q[1]);
  ok:=false;tot:=0;ok1:=false;
  max:=q[1];min:=q[1];
  for i:=2 to n do
  begin
    read(q[i]);
    if q[i]<q[i-1]then
    begin
     tot:=tot+max;
     max:=q[i];min:=q[i];
     ok1:=true;
     break;
    end;
    if max<q[i] then max:=q[i];
    if q[i]<min then min:=q[i];
  end;
  if not ok1 then begin
   writeln(max);
   close(input);close(output);
   halt;
  end;
  for i:=i+1 to n do
  begin
    read(q[i]);
    if q[i]<q[i-1]then
    begin
     tot:=tot+max-min;
     max:=q[i];min:=q[i];
     if i=n then ok:=true;
    end;
    if max<q[i] then max:=q[i];
    if q[i]<min then min:=q[i];
  end;
  if not ok then tot:=tot+max-min;
  writeln(tot);
  close(output);close(input);
end.
