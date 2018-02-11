program count1;
  var i,j,n:longint; x:integer;
    procedure p(a:longint);
      var x1:integer; n:array[1..7]of integer;
        begin
          for x1:=1 to 7 do
            n[x1]:=-1;
          if a>0 then n[1]:=a mod 10;
          if a>9 then n[2]:=a mod 100 div 10;
          if a>99 then n[3]:=a div 100 mod 10;
          if a>999 then n[4]:=a div 1000 mod 10;
          if a>9999 then n[5]:=a div 10000 mod 10;
          if a>99999 then n[6]:=a div 100000 mod 10;
          if a>999999 then n[7]:=a div 1000000;
          for x1:=1 to 7 do
            if n[x1]=x then inc(i);
        end;
    begin
      assign(input,'count.in');
      assign(output,'count.out');
      reset(input);
      rewrite(output);
      i:=0;
      read(n);
      read(x);
      for j:=1 to n do
        p(j);
      writeln(i);
      close(input);
      close(output);
    end.
