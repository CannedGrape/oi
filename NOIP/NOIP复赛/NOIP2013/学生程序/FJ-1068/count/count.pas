program count;
  var i,n:longint;
  var x:integer;
  var ans:int64;
procedure init;
  begin
    assign(input,'count.in');reset(input);
    readln(n,x);
    close(input);
  end;

function counts(k:longint):integer;
  var temp:integer;
  begin
    temp:=0;
    while k>0 do
    begin
      if k mod 10 = x then temp:=temp+1;
      k:=k div 10;
    end;
    exit(temp);
  end;
procedure print;
  begin
    assign(output,'count.out');rewrite(output);
    writeln(ans);
    close(output);
  end;

begin
  init;
  ans:=0;
  for i:=1 to n do
  begin
    ans:=ans+counts(i);
  end;
  print;
end.

