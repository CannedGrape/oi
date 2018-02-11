var
 i,j,k,l,m,n,cs,swap:longint;
 a:array[1..2,1..100001]of qword;
 w:array[1..2,1..100001]of longint;

begin
 assign(input,'match.in');reset(input);
 assign(output,'match.out');rewrite(output);
 readln(n);
 for i:=1 to n do
  read(a[1,i]);
  readln;
 for i:=1 to n do
  read(a[2,i]);
 readln;

 for i:=1 to n do
  for j:=1 to n do
   if a[1,i]=a[2,j] then
   begin
    cs:=(cs+abs(i-j)) mod 99999997;
    end;


   writeln(cs div 2);
   close(input);  close(output);
   end.
