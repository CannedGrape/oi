Program HJF_expr;
var
   tot,ans,pointer,num1:longint;
   ch:char;
   stack:array[0..200001] of longint;
   s:ansistring;

Function getnum:longint;
var
   snum:ansistring;
begin
   snum:='';
   while s[pointer+1]>='0' do
   begin
      inc(pointer);
      snum:=snum+s[pointer];
   end;
   val(snum,getnum);
end;

begin
   assign(input,'expr.in');   reset(input);
   assign(output,'expr.out');   rewrite(output);

   tot:=1;
   ans:=0;
   pointer:=0;

   readln(s);
   stack[1]:=getnum;
   while pointer<length(s)-1 do
   begin
      inc(pointer);
      ch:=s[pointer];
      num1:=getnum;
      if ch='+' then
      begin
         inc(tot);
         stack[tot]:=num1;
      end
      else stack[tot]:=(stack[tot] mod 10000) * (num1 mod 10000);
   end;
   inc(tot);
   stack[tot]:=getnum;
   for pointer:=1 to tot do ans:=(ans+(stack[pointer] mod 10000)) mod 10000;
   writeln(ans);

   close(input);
   close(output);
end.
