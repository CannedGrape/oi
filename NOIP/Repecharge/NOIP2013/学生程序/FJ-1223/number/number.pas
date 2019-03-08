program number1;
  var a:longint;
    begin
      assign(input,'level.in');
      assign(output,'level.out');
      reset(input);
      rewrite(output);
      randomize;
      a:=random(1000);
      writeln(a);
      writlen(a);
      close(input);
      close(output);
    end.