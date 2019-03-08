var
  n,i,ans,min,j,p:longint;
  h:array[0..100000]of longint;
  f:array[0..100000]of longint;
  flag:boolean;
function pd:boolean;
var
  i:longint;
begin
  for i:=1 to n do if h[i]<>0 then begin pd:=false; exit; end;
  pd:=true;
end;

begin
  assign(input,'block.in'); reset(input);
  assign(output,'block.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  ans:=0;

  while not pd do
  begin
    min:=maxlongint;
    j:=1;
    p:=0;
    while h[j]=0 do inc(j);
    for i:=j to n do
    begin
     if (h[i]<>0) and (min>h[i]) then min:=h[i];
     if h[i]=0 then begin p:=i; break; end;
    end;
    if p=0 then p:=n+1;
    for i:=j to p-1 do dec(h[i],min);
    inc(ans);
  end;
   writeln(ans);
   close(input); close(output);
end.
