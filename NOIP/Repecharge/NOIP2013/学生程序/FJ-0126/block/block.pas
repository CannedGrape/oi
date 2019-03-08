var
  n,i,j,total,h:longint;
  a,x,c:array[0..10000] of longint;
  b:array[0..10000] of boolean;
function wrong:boolean;
begin
  for i:=0 to n do
   if a[h]<>0 then wrong:=true;
end;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  fillchar(x,sizeof(x),0);
  readln(n);
  for i:=0 to n do
  read(a[i]);
  repeat
    for i:=1 to n do
    for j:=1 to n do
     begin
      if wrong=false then break
      else
        if (a[i]<>0) and (wrong) and (c[i]<>0) and (c[j]<>0) then
        for h:=c[i] to c[j] do
        begin
        begin
        x[h]:=x[h+1];
        a[h]:=a[h-1];
        end;
        end;
      inc(total);
     end;
  until (a[i]=0) and (x[h]=a[i]);
  write(total);
  close(input);close(output);
end.
