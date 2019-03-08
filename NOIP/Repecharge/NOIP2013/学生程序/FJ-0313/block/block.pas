program ye;
var n,m,i,j,ji,high,k:longint;
    h:array[0..100001] of longint;
begin
 assign(input,'block.in'); reset(input);
 assign(output,'block.out'); rewrite(output);
 readln(n);
 high:=0;
 for i:=1 to n do
  begin
   read(h[i]);
   if h[i]>high then
    begin
     high:=h[i];
     k:=i;
    end;
  end;
 ji:=0;
 repeat
  for i:=k to n do
   if h[i]=high then dec(h[i])
    else break;
  for i:=k-1 downto 1 do
   if h[i]=high then dec(h[i])
    else break;
  dec(high);
  for i:=1 to n do
   if h[i]>high then
    begin
     high:=h[i];
     k:=i;
    end;
  inc(ji);
 until high=0;
 writeln(ji);
 close(input); close(output);
end.

