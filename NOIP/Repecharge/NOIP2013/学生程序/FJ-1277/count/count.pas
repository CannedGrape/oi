program count;
 var a,i,s:longint;
     n:integer;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
 read(a,n);
 if n=0 then
  begin
   for i:=1 to a do
    begin
     if (i mod 10=0) and (i div 10<>0) then s:=s+1;
     if ((i mod 100) div 10=0) and (i div 100<>0) then s:=s+1;
     if ((i div 100) mod 10=0) and (i div 1000<>0) then s:=s+1;
     if ((i div 1000) mod 10=0) and (i div 10000<>0) then s:=s+1;
     if ((i div 10000) mod 10=0) and (i div 100000<>0) then s:=s+1;
     if ((i div 100000) mod 10=0) and (i div 1000000<>0) then s:=s+1;
    end;
   write(s);
   close(input);close(output);
   halt;
  end;
 for i:=1 to a do
  begin
   if i mod 10=n then s:=s+1;
   if (i mod 100) div 10=n then s:=s+1;
   if (i div 100) mod 10=n then s:=s+1;
   if (i div 1000) mod 10=n then s:=s+1;
   if (i div 10000) mod 10=n then s:=s+1;
   if (i div 100000) mod 10 =n then s:=s+1;
   if i div 1000000=n then s:=s+1;
  end;
 write(s);
close(input);close(output);
end.