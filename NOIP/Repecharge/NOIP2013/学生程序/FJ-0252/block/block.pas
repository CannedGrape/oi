program block;
var
  input,output:text;
  h:array[0..100000] of longint;
  i,n,max,maxn,count,k:longint;
  pd:boolean;
begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  read(input,n);
  for i:=1 to n do
    begin
      read(input,h[i]);
      if h[i]>max then
        begin
          max:=h[i];
          maxn:=i;
        end;
    end;
  i:=1;
  repeat
    pd:=false;
    while h[i]<>0 do
      begin
        pd:=true;
        dec(h[i]);
        inc(i);
        if i>n then
          begin
            i:=0;
            break;
          end;
      end;
    if pd then
      inc(count);
    inc(i);
    if i>n then
      i:=0;
  until h[maxn]=0;
  write(output,count);
  close(input);
  close(output);
end.
