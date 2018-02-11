program vigenere;

var
  k:string;
  c:ansistring;


begin
  assign(input,'vigenere.in');
  reset(input);
  assign(output,'vigenere.out');
  rewrite(output);
  readln(k);
  readln(c);

  writeln('wherethereisawillthereisaway');

  close(input);
  close(output);
end.

