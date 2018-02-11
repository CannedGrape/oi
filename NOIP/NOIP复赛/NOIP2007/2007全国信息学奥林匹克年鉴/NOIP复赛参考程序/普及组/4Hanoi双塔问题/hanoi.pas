program hanoi;
const N=100;
type arr1=array[0..N] of integer;
var a: arr1;
    file1:string[30];
    text1,text2:text;
    nn,count:longint;

procedure form1(var c:arr1);
var i:integer;
begin
 for i:=1 to N-10 do
   if (c[i]>9) then
     begin
       c[i+1]:=c[i+1]+c[i] div 10;
       c[i]:=c[i] mod 10;
     end;
end;

procedure mult2(var a:arr1);
var j:integer;
begin
  for j:=1 to N-10 do a[j]:=a[j]*2;
  form1(a);
end;

procedure readdata_hanoi1; {输入原始数据 }
begin
  writeln('input filename for input:');
  readln(file1);
  assign(text1,file1); reset(text1);
  readln(text1,nn);
  close(text1);
end;

procedure calcul;
var i,k:integer;
begin
 count:=1;
 if nn<26 then
  begin
    for i:=1 to nn+1 do
     count:=count*2;
   count:=count-2;
  end
 else
begin
 a[1]:=1;
 for i:=2 to N-1 do a[i]:=0;
 for i:=1 to nn+1 do
   mult2(a);
 a[1]:=a[1]-2;
 k:=1;
 while (a[k]<0) do
  begin
    a[k]:=a[k]+10; dec(a[k+1]); inc(k);
  end;
end;
 end;

procedure out_hanoi1;
var j,k:integer;
begin
 writeln('input filename for output:');
 readln(file1);
  assign(text2,file1); rewrite(text2);
  if(nn<26) then
    writeln(text2,count)
   else
    begin
     j:=N-1;
     while (a[j]=0) do dec(j);
     for k:=j downto 1 do
       write(text2,a[k]:1);
     writeln(text2);
    end;
 close(text2);
end;

begin
  readdata_hanoi1;
  calcul;
  out_hanoi1;
end.
