var p:array[0..200000]of longint;
    a,b,n,ans:longint;

function chk(i:longint):boolean;
begin
 if (p[i]>p[i+1])and(p[i]>p[i-1]) then exit(true);
 if (p[i]<p[i+1])and(p[i]<p[i-1]) then exit(true);
 exit(false);
end;

begin
 assign(input,'flower.in');
 assign(output,'flower.out');
 reset(input);
 rewrite(output);
 read(b);
 ans:=2;
 n:=0;
 for a:=1 to b do
  begin
   read(p[n+1]);
   if p[n+1]<>p[n] then inc(n);
  end;
 if n=1 then write(1) else
  begin
   for a:=2 to n-1 do if chk(a) then inc(ans);
   write(ans);
  end;
 close(input);
 close(output);
end.
