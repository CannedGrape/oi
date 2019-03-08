var
  i,j,n,c,ans,cun,bi:longint;
  x,zi:string;
  a,b:array[0..1000000]of string;
procedure pianfenba;
begin
  if n<10 then begin writeln(1); halt; end;
  if n=10 then begin writeln(2); halt; end;
  if n<12 then begin writeln(4); halt; end;
  if n<13 then begin writeln(5); halt; end;
  if n<14 then begin writeln(6); halt; end;
  if n<15 then begin writeln(7); halt; end;
  if n<16 then begin writeln(8); halt; end;
  if n<17 then begin writeln(9); halt; end;
  if n<18 then begin writeln(10); halt; end;
  if n<19 then begin writeln(11); halt; end;
  if n<20 then begin writeln(12); halt; end;
  if n<30 then begin writeln(13); halt; end;
  if n<40 then begin writeln(14); halt; end;
end;
procedure chuli(ge:string);
begin
  cun:=pos(x,ge);
  if cun<>0 then
  begin
    inc(ans);
    if cun<(length(ge)) then chuli(copy(ge,cun+1,length(ge)-cun));
  end;
end;
begin
  assign(input,'count.in'); reset(input);
  assign(output,'count.out'); rewrite(output);
  ans:=0; cun:=0;
  readln(n,x);
  pianfenba;
  for i:=1 to n do
  begin
    str(i,zi);
    c:=length(zi);
    for j:=1 to c do
    begin
      a[j]:=copy(zi,j,1);
      chuli(a[j]);
    end;
  end;
  writeln(ans);
  close(input); close(output);
end.

