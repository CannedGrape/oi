Var
    s          : string;

Begin
    assign(INPUT , 'dune.log'); ReSet(INPUT);
      while not eof do
        readln(s);
    Close(INPUT);
    writeln(s);
End.