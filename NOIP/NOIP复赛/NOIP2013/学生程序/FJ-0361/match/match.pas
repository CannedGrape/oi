var
      f:boolean;
      ans:int64;
      n,i,p:longint;
      a,b:array[1..500000] of longint;
begin
assign(input,'match.in');
assign(output,'match.out');
reset(input); rewrite(output);
   readln(n);
   for i:=1 to n do
   read(a[i]);
   for i:=1 to n do
   read(b[i]);
   ans:=0;
   repeat
   f:=false;
   for i:=1 to n do
   begin
   if (a[i]<a[i+1]) xor (b[i]<b[i+1]) then
    begin
    f:=true;
    p:=a[i]; a[i]:=a[i+1]; a[i+1]:=p;
    inc(ans);
    ans:=ans mod 99999997;
    end;
   end;
   until f=false;
   writeln(ans);

close(input); close(output);
end.
