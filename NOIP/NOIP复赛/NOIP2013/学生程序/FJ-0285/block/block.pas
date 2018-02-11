var
  n,max,i:longint;
  block:array[1..100000] of integer;
  f:array[1..100000] of longint;

begin

  assign(input,'block.in'); reset(input);
  assign(output,'block.out'); rewrite(output);

  readln(n);

  for i:=1 to n do read( block[i] );

  fillchar(f,sizeof(f),0);
  max:=0;
  for i:=1 to n do begin
    if block[i] > max then begin
      max:=block[i];
      f[i]:=block[i];
    end else
    begin
      if block[i] > block[i-1] then
        f[i]:=f[i-1]+1
      else
        f[i]:=f[i-1];
    end;
  end;

  writeln(f[n]);

  close(input);
  close(output);

end.





