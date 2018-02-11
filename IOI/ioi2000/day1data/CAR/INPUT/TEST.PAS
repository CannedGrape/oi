var fo:text;
  i:integer;
  first:boolean;
begin
  assign(fo,'CAR9.IN');
  rewrite(fo);
  randomize;
  writeln(fo,'20000 50 10');
  first:=true;
  for i:=1 to 20000 do
   begin
    if not first then write(fo,' ');
    first:=false;
    if random>0.009 then write(fo,(i-1)div 400+1)
      else write(fo,random(50)+1);
   end;
  writeln(fo);
  close(fo);

end.
