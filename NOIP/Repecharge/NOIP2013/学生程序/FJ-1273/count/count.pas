program exam1;
var n,i,j,count,find:longint;
    s,s1:ansistring;
    x:string;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
 read(n,find);
 str(find,x);
 for i:=1 to n do
  begin
   str(i,s1);
   s:=s+s1;
  end;
 if pos(x,s)=0 then begin writeln('0'); halt; end;
 while pos(x,s)<>0 do
  begin
   delete(s,1,pos(x,s));
   inc(count);
  end;
 write(count);
close(input);close(output);
end.


