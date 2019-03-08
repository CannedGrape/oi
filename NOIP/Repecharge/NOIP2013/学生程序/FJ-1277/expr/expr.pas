program expr;
 var a:string;
     i,n,s,t,let:integer;
     q,z:char;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 read(a);
 let:=length(a);
 for i:=1 to let do
   if (ord(a[i])>=48) and (ord(a[i])<=57) then ord(a[i]):=ord(a[i])-48;
 i:=2;
 repeat
  if a[i]='*' then
   begin
    ord(a[i]):=ord(a[i-1])*ord(a[i+1]);
    delete(a,i-1,1);delete(a,i+1,1);
   end;
  inc(i);
 until i>let-1;
 let:=length(a);
 i:=2;
 repeat
  if a[i]='+' then
   begin
    ord(a[i]):=ord(a[i-1])+ord(a[i+1]);
    delete(a,i-1,1);delete(a,i+1,1);
   end;
  inc(i);
 until i>let-1;
 let:=length(a);
 if let<=4 then
  begin
   for i:=1 to let do write(ord(a[i]));
   close(input);close(output);
   halt;
  end;
 if let>4 then
  begin
   for i:=let-3 to let do s:=ord(a[i]);
   if s div 1000=0 then s:=s mod 1000;
   if s div 100=0 then s:=s mod 100;
   if s div 10=0 then s:=s mod 10;
   if s=0 then s:=s;
   write(s);
  end;
close(input);close(output);
end.




