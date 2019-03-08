var a,b,n,ans:longint;
    p:array[0..200000]of longint;

procedure add(i:longint);
begin
 if (p[i]>p[i+1])and(p[i]>p[i-1]) then inc(ans,p[i]);
 if (p[i]<p[i+1])and(p[i]<p[i-1]) then dec(ans,p[i]);
end;

begin
 assign(input,'block.in');
 assign(output,'block.out');
 reset(input);
 rewrite(output);
 read(b);
 n:=0;
 for a:=1 to b do
  begin
   read(p[n+1]);
   if p[n+1]<>p[n] then inc(n);
  end;
 for a:=1 to n-1 do
  if p[a]<p[a+1] then p[a]:=0 else break;
 for a:=n downto 2 do
  if p[a]<p[a-1] then p[a]:=0 else break;
 ans:=0;
 for a:=1 to n do add(a);
 write(ans);
 close(input);
 close(output);
end.
