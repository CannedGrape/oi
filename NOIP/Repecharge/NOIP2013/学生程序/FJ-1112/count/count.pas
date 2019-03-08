var
  a,b,c,d,f,g:integer;
  begin
    assign(input,'count.in');
    reset(input);
    assign(output,'count.out');
    rewrite(output);
    f:=0;
    read(a,b);
    for c:=1 to a do
    begin
    if c mod 10=b  then f:=f+1;
       if c div 10=b then f:=f+1;
    end;
    write(f);
close(input);
close(output);
end.

