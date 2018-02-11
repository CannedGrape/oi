var s:ansistring;
   i:longint;
   q,w,t:int64;
   flag:boolean;
begin
assign(input,'expr.in');
assign(output,'expr.out');
reset(input);
rewrite(output);
  readln(s);
  q:=0;t:=1;
  flag:=false;
  s:=s+'+';
  for i:=1 to length(s) do
    if ('0'<=s[i])and(s[i]<='9') then
      begin
        q:=q*10+ord(s[i])-48;
      end
    else
      if s[i]='+' then
        begin
          if flag then begin t:=t*q mod 10000;q:=t;end;
          w:=w+q;
          t:=1;q:=0;
          flag:=false;
          w:=w mod 10000;
        end
    else
      if s[i]='*' then
        begin
          t:=t*q mod 10000;
          flag:=true;
          q:=0;
        end;
  writeln(w);
close(input);
close(output);
end.



