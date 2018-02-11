var
 ai,n,x,i:longint;

 function ta(o:longint):longint;
  var
   k:longint;
  begin
   ta:=0;
   repeat
    k:=o mod 10;
    o:=o div 10;
    if k=x then inc(ta);
   until o<=0;
  end;
begin
 assign(input,'count.in'); reset(input);
 assign(output,'count.out'); rewrite(output);
 readln(n,x);
 ai:=0;
 for i:=1 to n do
   ai:=ai+ta(i);
 writeln(ai);
 close(input); close(output);
end.
