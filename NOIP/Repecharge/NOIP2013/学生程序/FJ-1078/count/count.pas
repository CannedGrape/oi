program count;
var
x:integer;
n:string;
j,i,la,h:integer;
sum:longint;
a:array[1..1000000] of integer;

procedure save;
var
n:string;
x:integer;
a:array[1..1000000] of integer;
la,i,j,h:integer;
sum:longint;
begin
 readln(n,x);
 sum:=0;
 la:=length(n);
 for i:=la downto  1 do a[la-i+1]:=ord(n[i])-ord('0');
 if a[la]=0 then dec(la);
 for i:=la downto 1 do
 begin
   for h:=la downto 1 do
 begin
   if a[h]=x then inc(sum);
 end;
   if a[i]<1 then
   begin
     a[i]:=a[i]+10;
     a[i-1]:=a[i-1]-1;
   end;
   a[i]:=a[i]-1;
   for j:=la downto 1 do
   begin
     if a[j]=x then inc(sum);
   end;
   end;
   writeln(sum);
end;

begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  close(input);}
  save;
  close(output);
end.










