var n,m,s,z,i:longint;
begin
    assign(input,'count.in');
    assign(output,'count.out');
    reset(input);
    rewrite(output);
    readln(n,m);
    for i:=1 to n do
        begin
            s:=i;
            while s>0 do
                  begin
                      if s mod 10=m then inc(z);
                      s:=s div 10;
                  end;
        end;
    writeln(z);
    close(input);
    close(output);
end.
