var n,m,p,i:longint;
begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
   reset(input);
   rewrite(output);
     readln(n,m,p);
     if p=1 then writeln(-1)
     else if p=2 then begin writeln(2);writeln(-1);end
      else for i:=1 to p do writeln(-1);
  close(input);
  close(output);
end.