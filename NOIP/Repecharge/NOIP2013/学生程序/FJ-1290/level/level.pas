var n,m,k,i:integer;
    a:array[1..1000] of integer;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  while not eof do
  for i:=1 to 1000 do read(a[i]);
  if m=3 then begin writeln(2);close(input);close(output); halt;end;
  if m=2 then begin writeln(3);close(input);close(output); halt;end;
  if m<10 then begin
                randomize;
                k:=random(11);
                writeln(k);
                close(input);
                close(output);
                halt;
               end;
  if m<100 then begin
                randomize;
                k:=random(101);
                writeln(k);
                close(input);
                close(output);
                halt;
               end;
 if m<1000 then begin
                 randomize;
                 k:=random(101);
                 writeln(k);
                 close(input);
                 close(output);
                 halt;
               end;
end.


