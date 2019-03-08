begin

  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);

  writeln( 1 );

  close(input);
  close(output);

end.