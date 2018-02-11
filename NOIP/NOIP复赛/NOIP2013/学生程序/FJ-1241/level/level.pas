var lv:array[1..1000] of boolean;
    sta:array[1..3,1..1000] of longint;
    num:array[1..1000]of longint;
    tra,ls:array[1..1000,1..1000] of longint;
    i,j,a,b,n,m,o,k,f,c:longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      read(num[i]);
      for j:=1 to num[i] do begin read(o);tra[i,j]:=o;inc(sta[2,o]); end;
      sta[1,i]:=i;lv[i]:=true;
      readln;
    end;
  o:=0;a:=0;
  for i:=1 to n do
    if sta[2,i]=0 then begin sta[3,i]:=1;lv[1]:=false;end;
  for i:=1 to n do begin
    if lv[i] then inc(o);
    if o=3 then begin c:=1;write(i); end;
   end;
  if c<>1 then
    for i:=1 to n do
      begin
        if lv[i] then inc(a);
        if a=o then begin write(i);break; end;
      end;
  close(input);close(output);
end.
