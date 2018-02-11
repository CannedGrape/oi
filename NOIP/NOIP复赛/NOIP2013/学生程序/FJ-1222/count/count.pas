var i,n,x,k,l,g:longint;
    s:string;
    x1:char;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
 readln(n,x);
 x1:=char(48+x);
 g:=0;
 s:='';
 for i:=1 to n do
 begin
  str(i,s);
  k:=pos(x1,s);
  while k<>0 do
  begin
   inc(g);
   delete(s,1,k);
   k:=pos(x1,s);
  end;
 end;
 write(g);
close(input);close(output);
end.