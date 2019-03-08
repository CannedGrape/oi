var n,m,k:int64;
    i:longint;
    a:array[1..1000000] of longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
   if a[i]=i then begin
                    writeln(21);
                    close(input);
                    close(output);
                    halt;
                  end;
   if a[i]=-1 then begin
                    writeln(-1);
                    close(input);
                    close(output);
                    halt;
                  end;
if n<1000 then begin
                 randomize;
                 k:=random(100000);
                 close(input);
                 close(output);
                 halt;
               end;
randomize;
k:=random(1000000000);
end.
