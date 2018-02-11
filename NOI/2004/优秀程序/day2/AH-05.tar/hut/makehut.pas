Const
    OutFile    = 'hut.in';

Var
    n , m	: longint;

Begin
    randomize;
    assign(OUTPUT , OutFile); ReWrite(OUTPUT);
      writeln((random(1000) + 1) / (random(1000) + 1) : 0 : 5);
      writeln((random(1000) + 1) / (random(1000) + 1) : 0 : 5);
      n := random(100) + 1; m := random(100) + 1;
      if n <= m
        then writeln(n , ' ' , m)
        else writeln(m , ' ' , n);
    Close(OUTPUT);
End.
