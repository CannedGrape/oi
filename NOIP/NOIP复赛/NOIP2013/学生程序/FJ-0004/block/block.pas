const
  maxn = 100000;

type
  tnode = record
    a: integer;
    p, sub: longint;
  end;

var
  stk: array[1..maxn] of tnode;
  i, p, h, n: longint;
  ans, size, height, temp: longint;

procedure independent(var p: longint; a: integer);
begin
  if stk[p].sub=0 then begin
    inc(size);
    stk[size].a:=a;
    stk[size].p:=p;
    stk[size].sub:=0;
    stk[p].sub:=size;
    p:=size;
  end
  else begin
    p:=stk[p].sub;
    stk[p].a:=a;
  end;
end;

begin
  assign(input, 'block.in');
  reset(input);
  assign(output, 'block.out');
  rewrite(output);
  readln(n);
  read(height);
  size:=1;
  p:=1;
  stk[p].a:=height;
  stk[p].p:=0;
  stk[p].sub:=0;
  ans:=height;
  for i:=2 to n do begin
    read(h);
    while (height>h) and (stk[p].p<>0) do begin
      height:=height-stk[p].a;
      p:=stk[p].p;
    end;
    if height=h then continue;
    if height>h then begin
      independent(p, height-h);
      p:=stk[p].p;
      stk[p].a:=h;
    end
    else begin
      temp:=h-height;
      independent(p, temp);
      ans:=ans+temp;
    end;
    height:=h;
  end;
  writeln(ans);
  close(input);
  close(output);
end.