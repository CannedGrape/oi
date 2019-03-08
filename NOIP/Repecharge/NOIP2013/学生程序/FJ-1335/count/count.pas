program count;
var n,i,sum:longint;x:integer;
    s:string;
    ls:integer;
    f1,f2:text;
    j:integer;
begin
 assign(f1,'count.in');
 reset(f1);
 assign(f2,'count.out');
 rewrite(f2);
 read(f1,n,x);
 for i:=1 to n do
  begin
   s:='';
   str(i,s);
    ls:=length(s);
     for j:=1 to ls do
      begin
       if ord(s[j])-ord('0')=x then
        sum:=sum+1;
      end;
   end;
 write(f2,sum);
 close(f1);close(f2);
end.

