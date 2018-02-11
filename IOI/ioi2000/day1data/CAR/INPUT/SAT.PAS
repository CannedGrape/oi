var fo:text;
  i:integer;
  first:boolean;
begin
  assign(fo,'CAR10.IN');
  rewrite(fo);
  writeln(fo,'20000 50 50');
  first:=true;
  for i:=1 to 20000 do
   begin
    if not first then write(fo,' ');
    first:=false;
    if random>0.97 then write(fo,(i-1)div 400+1)
      else write(fo,random(50)+1);
   end;
  writeln(fo);
  close(fo);

end.
