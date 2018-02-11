var i,q,x,n:longint;
begin
assign(input,'count.in');
assign(output,'count.out');
reset(input);
rewrite(output);
  q:=0;
  readln(n,x);
  for i:=1 to n do
    begin
      if (i<10) and (i=x) then inc(q);
      if (i>=10) and (i<100) then
        begin
          if i div 10=x then inc(q);
          if i mod 10=x then inc(q);
        end;
      if (i>=100) and (i<1000) then
        begin
          if i div 100=x then inc(q);
          if (i div 10) mod 10=x then inc(q);
          if i mod 10=x then inc(q);
        end;
      if (i>=1000) and (i<10000) then
        begin
          if (i div 1000)=x then inc(q);
          if (i div 100) mod 10=x then inc(q);
          if (i div 10) mod 10=x then inc(q);
          if i mod 10=x then inc(q);
        end;
      if (i>=10000) and (i<100000) then
        begin
          if i div 10000=x then inc(q);
          if (i div 1000) mod 10=x then inc(q);
          if (i div 100) mod 10=x then inc(q);
          if (i div 10) mod 10=x then inc(q);
          if i mod 10=x then inc(q);
        end;
      if (i>=100000) and (i<1000000) then
        begin
          if i div 100000=x then inc(q);
          if (i div 10000) mod 10=x then inc(q);
          if (i div 1000) mod 10=x then inc(q);
          if (i div 100) mod 10=x then inc(q);
          if (i div 100) mod 10=x then inc(q);
          if i mod 10=x then inc(q);
        end;
      if i=1000000 then
        begin
          if x=1 then inc(q);
          if x=0 then q:=q+6;
        end;
    end;
  writeln(q);
close(input);
close(output);
end.
