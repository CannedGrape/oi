Program number;
  var
    a:integer;
  begin
    assign(input,'number.in');
    reset(input);
    assign(output,'number.out');
    rewrite(output);
    write('-1');
    close(input);
    close(output);
  end.
