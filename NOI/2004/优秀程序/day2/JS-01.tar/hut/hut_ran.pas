Program Hut_Ran;
 Var
   a,b:longint;
 Begin
      Assign(Output,'hut.in');
      Rewrite(Output);
      randomize;
      write(random*random(10):0:3,' ',random*random(10):0:3,' ');
      a:=random(5);
      repeat
            b:=a+random(5);
      until b<=10;
      writeln(a,' ',b);
      Close(Output);
 End.

