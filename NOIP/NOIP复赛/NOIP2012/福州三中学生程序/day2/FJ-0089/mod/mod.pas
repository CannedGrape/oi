program xxx;
var a,b,c,d,x:int64; i:longint;
begin
 assign(input,'mod.in');
 assign(output,'mod.out');
 reset(input); rewrite(output);
 read(a,b);
 for i:=1 to 8000000 do
   if (a*i) mod b=1 then begin write(i); break; end;
 close(input); close(output);
end.