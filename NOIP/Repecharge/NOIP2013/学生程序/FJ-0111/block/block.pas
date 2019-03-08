var
  h:array[1..10000]of longint;
  b:boolean;
  n,l,r,i,j,t,s:longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n); s:=0;
  for i:=1 to n do
    read(h[i]);
  repeat
    b:=true;  t:=0;
    for i:=1 to n do
      begin
        if h[i]=0 then inc(t);
        if h[i]<>0 then begin dec(h[i]); b:=false; end
        else if b=false then break;
      end;
      if b=false then inc(s);
  until t=n;
  writeln(s);
  close(input);close(output);
end.


