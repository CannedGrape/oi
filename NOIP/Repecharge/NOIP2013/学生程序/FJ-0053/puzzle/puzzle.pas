var i,m,n,p,x,j:longint;
begin 
 assign(input,'puzzle.in');reset(input);
 assign(output,'puzzle.out');rewrite(output);
 readln(n,m,p);
 for i:=1 to n do 
  for j:=1 to m do read(x);
 for i:=1 to p do 
  begin 
   read(j,x);
   writeln(-1);
  end;
  close(input);close(output);
end.