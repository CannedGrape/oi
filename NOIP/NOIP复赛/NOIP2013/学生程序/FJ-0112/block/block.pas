var
 i,j,k,n,min,w,tot,www,hh,max:longint;
 a:array[0..100010]of longint;
 b:array[0..100010]of boolean;
 function chk:boolean;
var

 ii:longint;
begin
chk:=false;
 for ii:=1 to n do
   if a[ii]<>0 then chk:=true;end;
begin
 assign(input,'block.in');reset(input);
 assign(output,'block.out');rewrite(output);
 fillchar(b,sizeof(b),true);
 readln(n); min:=maxlongint;  max:=0;
 for i:=1 to n do
 begin
  read(a[i]);
  if min>a[i] then begin min:=a[i];w:=i;end;
  if max<a[i] then max:=a[i];
 end;
 for i:=1 to n do
 begin
  a[i]:=a[i]-min;
   end;
 tot:=min; i:=0;
 for hh:=1 to max do  begin  i:=0;
  fillchar(b,sizeof(b),true);
 repeat
  inc(i);
  if (a[i]<>0)and(b[i]) then
    begin
    b[i]:=false; a[i]:=a[i]-1;
     while (a[i+1]>0)and(i<n) do
     begin

      b[i+1]:=false;
      a[i+1]:=a[i+1]-1;

      i:=i+1;
     end;

  tot:=tot+1;
  end;
  until i=n; end;

 writeln(tot);
 close(input);close(output);
 end.

