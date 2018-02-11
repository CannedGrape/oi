program exam1;
var f:array[0..200000] of longint;
    sz:array[0..200000] of int64;
    i,j,len,headsz,headf,tailsz,tailf,code:longint;
    s,s1:ansistring;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(s);
  s:=s+'x';
  len:=length(s);
  j:=1;
  for i:=1 to len do
  begin
  case s[i] of
     '+':f[tailf+1]:=1;
     '*':f[tailf+1]:=2;
     'x':f[tailf+1]:=-1;
     end;
  if f[tailf+1]=0 then continue;
  inc(tailsz);
  s1:=copy(s,j,i-j);
  j:=i+1;
  val(s1,sz[tailsz],code);
  if f[tailf+1]<=f[tailf] then
     begin
     if f[tailf]=1 then
       begin
       sz[tailsz-1]:=sz[tailsz]+sz[tailsz-1] mod 10000;
       dec(tailsz);
       end
     else
     if f[tailf]=2 then
       begin
       sz[tailsz-1]:=sz[tailsz]*sz[tailsz-1] mod 10000;
       dec(tailsz);
       end;
     f[tailf]:=f[tailf+1];   f[tailf+1]:=0;
     end
  else inc(tailf);
  end;
  inc(tailsz);
  s1:=copy(s,j,len-j);
  val(s1,sz[tailsz],code);
  headsz:=1;
  while tailf>headf do
  begin
  inc(headf);
  inc(headsz);
  if f[tailf]=2 then
    begin
    sz[headsz]:=sz[headsz-1]*sz[headsz] mod 10000;
    end
  else
    sz[headsz]:=sz[headsz-1]+sz[headsz] mod 10000;
  end;
  writeln(sz[headsz-1] mod 10000);
  close(input);
  close(output);
end.
