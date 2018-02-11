program ex1;
  var i,num,n,c,tot:longint;
    begin
    assign(input,'count.in');
    reset(input);
    assign(output,'count.out');
    rewrite(output);
    read(n,num);
    for i:=1 to n do
      begin
        c:=i;
        while c>0 do
          begin
          if c mod 10=num then inc(tot);
          c:=c div 10;
          end;
      end;
    writeln(tot);
    close(input);
    close(output);
    end.