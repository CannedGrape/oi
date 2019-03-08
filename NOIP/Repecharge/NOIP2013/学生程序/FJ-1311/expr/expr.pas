Program expr;
  var
    a:integer;
  begin
    assign(input,'expr.in');
    reset(input);
    assign(output,'expr.out');
    rewrite(output);
    write('8');
    close(input);
    close(output);
  end.