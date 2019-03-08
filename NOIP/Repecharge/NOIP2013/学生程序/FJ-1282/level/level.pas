var a:array[1..1000,1..1000] of boolean;
    i,j,ans,n,m,t,s:longint;  c:boolean;
//=========================================
 begin
 assign(input,'level.in');reset(input);
 assign(output,'level.out');rewrite(output);
  read(n,m);
  for i:=1 to m do
   begin
    read(t);
     for j:=1 to t do
      begin
      read(s);
      a[i,s]:=true;
      end;
    end;
writeln(m);

close(input);close(output)
 end.