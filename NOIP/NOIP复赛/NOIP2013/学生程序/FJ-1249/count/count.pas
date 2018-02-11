program Count;

var n,m,i,t:longint;

    function Double_M(x:longint):longint;
    begin
      Double_M:=0;
      while x div 10>0 do begin
        if x mod 10=m then inc(Double_M);
        x:=x div 10;
      end;
      if x mod 10=m then inc(Double_M);
    end;

begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);

  readln(n,m);

  t:=0;
  for i:=1 to n do
    t:=t+Double_M(i);

  writeln(t);

  close(input);close(output);
end.