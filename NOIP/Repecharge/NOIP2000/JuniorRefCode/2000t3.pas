const
  maxn=20;
var
  s:array[1..maxn] of string;
  head:char;
  best,i,n:integer;
  add:array[1..maxn,1..maxn] of integer;
  used:array[1..maxn] of integer;

procedure calcadd;
var
  i,j,k,t,min:integer;
  ok:boolean;
begin
  for i:=1 to n do
    for j:=1 to n do
    begin
      if length(s[i])<length(s[j]) then min:=length(s[i]) else min:=length(s[j]);
      for k:=1 to min-1 do
      begin
        {check}
        ok:=true;
        for t:=1 to k do
          if s[j,t]<>s[i,length(s[i])-k+t] then
          begin
            ok:=false;
            break;
          end;
        if ok then break;
      end;
      if ok then
        add[i,j]:=length(s[j])-k
      else
        add[i,j]:=0;
    end;
end;

procedure search(last,len:integer);
var
  i:integer;
begin
  if len>best then
    best:=len;
  for i:=1 to n do
    if (add[last,i]>0)and(used[i]<2) then
    begin
      inc(used[i]);
      search(i,len+add[last,i]);
      dec(used[i]);
    end;
end;

begin
  readln(n);
  for i:=1 to n do
    readln(s[i]);
  readln(head);
  calcadd;
  best:=0;
  fillchar(used,sizeof(used),0);
  for i:=1 to n do
    if s[i,1]=head then
    begin
      used[i]:=1;
      search(i,length(s[i]));
      used[i]:=0;
    end;
  writeln(best);
end.
