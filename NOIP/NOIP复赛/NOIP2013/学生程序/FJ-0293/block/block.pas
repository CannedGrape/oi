var
  i,n,x,t:longint;
  ans:qword;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
  read(n);t:=0;ans:=0;
  for i:=1 to n do
     begin
       read(x);
       if x>t then ans:=ans+(x-t);
       t:=x;
     end;
  writeln(ans);
close(input);close(output);
end.